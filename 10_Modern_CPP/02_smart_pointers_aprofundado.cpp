/**
 * Smart Pointers em C++11 e C++23 (Versão Aprofundada)
 * 
 * Este exemplo demonstra o uso avançado de smart pointers em C++,
 * com foco especial em shared_ptr e seus casos de uso complexos.
 * 
 * Comparação com C#:
 * C# gerencia memória automaticamente com garbage collection,
 * enquanto C++ oferece controle manual através de smart pointers.
 */

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <thread>
#include <mutex>

// Classe para demonstrar o ciclo de vida dos objetos
class Recurso {
private:
    std::string nome;
    static int contador;
    int id;
    
public:
    Recurso(const std::string& n) : nome(n) {
        id = ++contador;
        std::cout << "Construtor: Recurso '" << nome << "' #" << id << " criado." << std::endl;
    }
    
    ~Recurso() {
        std::cout << "Destrutor: Recurso '" << nome << "' #" << id << " destruído." << std::endl;
    }
    
    void usar() const {
        std::cout << "Usando recurso '" << nome << "' #" << id << std::endl;
    }
    
    std::string obterNome() const {
        return nome + " #" + std::to_string(id);
    }
};

int Recurso::contador = 0;

// ===== Uso Básico de shared_ptr =====

void demonstrarSharedPtrBasico() {
    std::cout << "\n=== Uso Básico de shared_ptr ===" << std::endl;
    
    // Criando um shared_ptr
    std::shared_ptr<Recurso> ptr1 = std::make_shared<Recurso>("Compartilhado");
    std::cout << "Contagem de referências após criação: " << ptr1.use_count() << std::endl;
    
    // Criando uma cópia do shared_ptr (aumenta a contagem de referências)
    std::shared_ptr<Recurso> ptr2 = ptr1;
    std::cout << "Contagem de referências após cópia: " << ptr1.use_count() << std::endl;
    
    // Criando outra cópia em um escopo interno
    {
        std::shared_ptr<Recurso> ptr3 = ptr1;
        std::cout << "Contagem de referências no escopo interno: " << ptr1.use_count() << std::endl;
        ptr3->usar();
        
        // ptr3 será destruído ao sair do escopo
    }
    
    std::cout << "Contagem de referências após escopo interno: " << ptr1.use_count() << std::endl;
    
    // Usando o recurso através dos ponteiros
    ptr1->usar();
    ptr2->usar();
    
    // Liberando manualmente um dos ponteiros
    ptr1.reset();
    std::cout << "Contagem de referências após reset de ptr1: " << ptr2.use_count() << std::endl;
    
    // ptr2 ainda mantém o recurso vivo
    ptr2->usar();
    
    // Ao sair da função, ptr2 será destruído e o recurso será liberado
}

// ===== Compartilhamento de Propriedade com shared_ptr =====

// Classe que representa um objeto complexo com dependências compartilhadas
class Sistema {
private:
    std::string nome;
    std::vector<std::shared_ptr<Recurso>> recursos;
    
public:
    Sistema(const std::string& n) : nome(n) {
        std::cout << "Sistema '" << nome << "' criado." << std::endl;
    }
    
    ~Sistema() {
        std::cout << "Sistema '" << nome << "' destruído." << std::endl;
    }
    
    void adicionarRecurso(std::shared_ptr<Recurso> recurso) {
        recursos.push_back(recurso);
        std::cout << "Recurso '" << recurso->obterNome() << "' adicionado ao sistema '" << nome << "'" << std::endl;
    }
    
    void listarRecursos() const {
        std::cout << "Recursos no sistema '" << nome << "':" << std::endl;
        for (const auto& recurso : recursos) {
            std::cout << "  - " << recurso->obterNome() 
                      << " (contagem de referências: " << recurso.use_count() << ")" << std::endl;
        }
    }
    
    void usarTodosRecursos() const {
        for (const auto& recurso : recursos) {
            recurso->usar();
        }
    }
};

void demonstrarCompartilhamentoPropriedade() {
    std::cout << "\n=== Compartilhamento de Propriedade com shared_ptr ===" << std::endl;
    
    // Criando recursos compartilhados
    auto recurso1 = std::make_shared<Recurso>("Banco de Dados");
    auto recurso2 = std::make_shared<Recurso>("Arquivo de Log");
    auto recurso3 = std::make_shared<Recurso>("Conexão de Rede");
    
    std::cout << "Contagens iniciais: BD=" << recurso1.use_count() 
              << ", Log=" << recurso2.use_count()
              << ", Rede=" << recurso3.use_count() << std::endl;
    
    // Criando sistemas que compartilham recursos
    auto sistema1 = std::make_shared<Sistema>("Sistema Principal");
    auto sistema2 = std::make_shared<Sistema>("Sistema de Backup");
    
    // Sistema 1 usa todos os recursos
    sistema1->adicionarRecurso(recurso1);
    sistema1->adicionarRecurso(recurso2);
    sistema1->adicionarRecurso(recurso3);
    
    // Sistema 2 compartilha alguns recursos com Sistema 1
    sistema2->adicionarRecurso(recurso1);  // Banco de dados compartilhado
    sistema2->adicionarRecurso(recurso2);  // Log compartilhado
    
    // Verificando contagens de referência
    std::cout << "Contagens após configuração: BD=" << recurso1.use_count() 
              << ", Log=" << recurso2.use_count()
              << ", Rede=" << recurso3.use_count() << std::endl;
    
    // Listando recursos em cada sistema
    sistema1->listarRecursos();
    sistema2->listarRecursos();
    
    // Usando recursos através dos sistemas
    std::cout << "\nUsando recursos através do Sistema Principal:" << std::endl;
    sistema1->usarTodosRecursos();
    
    // Liberando um sistema
    std::cout << "\nLiberando Sistema Principal..." << std::endl;
    sistema1.reset();
    
    // Verificando contagens de referência após liberar Sistema 1
    std::cout << "Contagens após liberar Sistema Principal: BD=" << recurso1.use_count() 
              << ", Log=" << recurso2.use_count()
              << ", Rede=" << recurso3.use_count() << std::endl;
    
    // Recursos ainda estão disponíveis através do Sistema 2
    std::cout << "\nRecursos ainda disponíveis no Sistema de Backup:" << std::endl;
    sistema2->listarRecursos();
    
    // Ao sair da função, sistema2 e todos os recursos serão liberados
}

// ===== Referências Circulares e weak_ptr =====

// Classes com referência circular
class Pessoa;  // Declaração antecipada

// Adicionando herança de enable_shared_from_this para permitir shared_from_this()
class Equipe : public std::enable_shared_from_this<Equipe> {
private:
    std::string nome;
    std::vector<std::shared_ptr<Pessoa>> membros;
    
public:
    Equipe(const std::string& n) : nome(n) {
        std::cout << "Equipe '" << nome << "' criada." << std::endl;
    }
    
    ~Equipe() {
        std::cout << "Equipe '" << nome << "' destruída." << std::endl;
    }
    
    void adicionarMembro(std::shared_ptr<Pessoa> pessoa);
    
    std::string obterNome() const { return nome; }
    
    void listarMembros() const;
};

class Pessoa {
private:
    std::string nome;
    // Problema: referência circular com shared_ptr
    // std::shared_ptr<Equipe> equipe;
    
    // Solução: usar weak_ptr para evitar referência circular
    std::weak_ptr<Equipe> equipe;
    
public:
    Pessoa(const std::string& n) : nome(n) {
        std::cout << "Pessoa '" << nome << "' criada." << std::endl;
    }
    
    ~Pessoa() {
        std::cout << "Pessoa '" << nome << "' destruída." << std::endl;
    }
    
    void definirEquipe(std::shared_ptr<Equipe> e) {
        equipe = e;  // Armazena como weak_ptr
        std::cout << "Pessoa '" << nome << "' agora faz parte da equipe '" << e->obterNome() << "'" << std::endl;
    }
    
    std::string obterNome() const { return nome; }
    
    void descreverEquipe() const {
        // Tentando obter um shared_ptr a partir do weak_ptr
        if (auto e = equipe.lock()) {
            std::cout << nome << " é membro da equipe '" << e->obterNome() << "'" << std::endl;
            e->listarMembros();
        } else {
            std::cout << nome << " não pertence a nenhuma equipe (equipe foi destruída)" << std::endl;
        }
    }
};

// Implementação dos métodos que dependem da definição completa de Pessoa
void Equipe::adicionarMembro(std::shared_ptr<Pessoa> pessoa) {
    membros.push_back(pessoa);
    pessoa->definirEquipe(shared_from_this());  // Usa shared_from_this() para obter shared_ptr para this
}

void Equipe::listarMembros() const {
    std::cout << "Membros da equipe '" << nome << "':" << std::endl;
    for (const auto& membro : membros) {
        std::cout << "  - " << membro->obterNome() << std::endl;
    }
}

void demonstrarReferenciaCircular() {
    std::cout << "\n=== Referências Circulares e weak_ptr ===" << std::endl;
    
    // Criando uma equipe
    auto equipe = std::make_shared<Equipe>("Desenvolvimento");
    
    // Criando pessoas
    auto pessoa1 = std::make_shared<Pessoa>("Alice");
    auto pessoa2 = std::make_shared<Pessoa>("Bob");
    auto pessoa3 = std::make_shared<Pessoa>("Charlie");
    
    // Adicionando pessoas à equipe
    equipe->adicionarMembro(pessoa1);
    equipe->adicionarMembro(pessoa2);
    equipe->adicionarMembro(pessoa3);
    
    // Verificando a estrutura
    pessoa1->descreverEquipe();
    
    // Demonstrando o problema de referência circular
    std::cout << "\nLiberando referência externa à equipe..." << std::endl;
    equipe.reset();
    
    std::cout << "\nVerificando se a pessoa ainda pode acessar a equipe:" << std::endl;
    pessoa1->descreverEquipe();
    
    // Ao sair da função, todas as pessoas serão destruídas
    // Se usássemos shared_ptr para a equipe dentro de Pessoa, teríamos um vazamento de memória
}

// ===== Uso Avançado: Callbacks e Observers com shared_ptr e weak_ptr =====

// Sistema de eventos usando shared_ptr e weak_ptr
class EventManager {
public:
    // Tornando Callback público para permitir acesso externo
    using Callback = std::function<void(const std::string&)>;
    
    EventManager() {
        std::cout << "EventManager criado." << std::endl;
    }
    
    ~EventManager() {
        std::cout << "EventManager destruído." << std::endl;
    }
    
    // Registra um callback para um evento
    void subscribe(const std::string& eventType, std::shared_ptr<Callback> callback) {
        std::lock_guard<std::mutex> lock(mutex);
        subscribers[eventType].push_back(callback);
        std::cout << "Callback registrado para evento '" << eventType << "'" << std::endl;
    }
    
    // Dispara um evento
    void fireEvent(const std::string& eventType, const std::string& eventData) {
        std::lock_guard<std::mutex> lock(mutex);
        std::cout << "Disparando evento '" << eventType << "' com dados: " << eventData << std::endl;
        
        if (subscribers.find(eventType) != subscribers.end()) {
            auto& callbackList = subscribers[eventType];
            
            // Remover callbacks expirados (objetos destruídos)
            callbackList.erase(
                std::remove_if(callbackList.begin(), callbackList.end(),
                    [](const std::weak_ptr<Callback>& weakCallback) {
                        return weakCallback.expired();
                    }),
                callbackList.end()
            );
            
            // Chamar callbacks ativos
            for (auto& weakCallback : callbackList) {
                if (auto callback = weakCallback.lock()) {
                    (*callback)(eventData);
                }
            }
        }
    }

private:
    std::unordered_map<std::string, std::vector<std::weak_ptr<Callback>>> subscribers;
    std::mutex mutex;
};

class EventListener {
private:
    std::string nome;
    std::shared_ptr<EventManager> eventManager;
    std::shared_ptr<EventManager::Callback> callback;
    
public:
    EventListener(const std::string& n, std::shared_ptr<EventManager> em)
        : nome(n), eventManager(em) {
        std::cout << "EventListener '" << nome << "' criado." << std::endl;
        
        // Criar um callback que captura 'this'
        callback = std::make_shared<EventManager::Callback>(
            [this](const std::string& data) {
                this->onEvent(data);
            }
        );
        
        // Registrar o callback
        eventManager->subscribe("update", callback);
    }
    
    ~EventListener() {
        std::cout << "EventListener '" << nome << "' destruído." << std::endl;
        // Não precisamos cancelar a inscrição explicitamente
        // O EventManager usará weak_ptr para detectar callbacks expirados
    }
    
    void onEvent(const std::string& data) {
        std::cout << "Listener '" << nome << "' recebeu evento com dados: " << data << std::endl;
    }
};

void demonstrarCallbacksObservers() {
    std::cout << "\n=== Callbacks e Observers com shared_ptr e weak_ptr ===" << std::endl;
    
    // Criar gerenciador de eventos
    auto eventManager = std::make_shared<EventManager>();
    
    // Criar listeners em um escopo
    {
        auto listener1 = std::make_shared<EventListener>("Listener1", eventManager);
        auto listener2 = std::make_shared<EventListener>("Listener2", eventManager);
        
        // Disparar evento - ambos os listeners devem receber
        std::cout << "\nDisparando evento com ambos os listeners ativos:" << std::endl;
        eventManager->fireEvent("update", "Dados iniciais");
        
        // Destruir um listener
        std::cout << "\nDestruindo Listener1..." << std::endl;
        listener1.reset();
        
        // Disparar evento novamente - apenas listener2 deve receber
        std::cout << "\nDisparando evento após destruir Listener1:" << std::endl;
        eventManager->fireEvent("update", "Dados atualizados");
        
        // listener2 será destruído ao sair do escopo
    }
    
    // Disparar evento após todos os listeners serem destruídos
    std::cout << "\nDisparando evento após todos os listeners serem destruídos:" << std::endl;
    eventManager->fireEvent("update", "Dados finais");
    
    // eventManager será destruído ao sair da função
}

// ===== Uso Avançado: Custom Deleters =====

// Recurso externo que requer limpeza especial
struct RecursoExterno {
    int id;
    
    RecursoExterno(int i) : id(i) {
        std::cout << "RecursoExterno #" << id << " alocado." << std::endl;
    }
    
    // Não tem destrutor - precisa ser liberado explicitamente
};

// Função para liberar o recurso externo
void liberarRecursoExterno(RecursoExterno* recurso) {
    std::cout << "Liberando RecursoExterno #" << recurso->id << " com função personalizada." << std::endl;
    delete recurso;
}

// Functor para liberar o recurso externo
struct LiberadorRecurso {
    void operator()(RecursoExterno* recurso) const {
        std::cout << "Liberando RecursoExterno #" << recurso->id << " com functor personalizado." << std::endl;
        delete recurso;
    }
};

void demonstrarCustomDeleters() {
    std::cout << "\n=== Custom Deleters com shared_ptr ===" << std::endl;
    
    // Usando função como deleter
    {
        std::shared_ptr<RecursoExterno> recurso1(new RecursoExterno(1), liberarRecursoExterno);
        std::cout << "Recurso1 criado com deleter de função." << std::endl;
        
        // recurso1 será liberado com liberarRecursoExterno ao sair do escopo
    }
    
    // Usando functor como deleter
    {
        std::shared_ptr<RecursoExterno> recurso2(new RecursoExterno(2), LiberadorRecurso());
        std::cout << "Recurso2 criado com deleter de functor." << std::endl;
        
        // recurso2 será liberado com LiberadorRecurso ao sair do escopo
    }
    
    // Usando lambda como deleter
    {
        auto deleter = [](RecursoExterno* recurso) {
            std::cout << "Liberando RecursoExterno #" << recurso->id << " com lambda personalizado." << std::endl;
            delete recurso;
        };
        
        std::shared_ptr<RecursoExterno> recurso3(new RecursoExterno(3), deleter);
        std::cout << "Recurso3 criado com deleter de lambda." << std::endl;
        
        // recurso3 será liberado com o lambda ao sair do escopo
    }
}

// ===== Uso Avançado: enable_shared_from_this =====

class GerenciadorTarefas : public std::enable_shared_from_this<GerenciadorTarefas> {
private:
    std::string nome;
    std::vector<std::function<void()>> tarefas;
    
public:
    GerenciadorTarefas(const std::string& n) : nome(n) {
        std::cout << "GerenciadorTarefas '" << nome << "' criado." << std::endl;
    }
    
    ~GerenciadorTarefas() {
        std::cout << "GerenciadorTarefas '" << nome << "' destruído." << std::endl;
    }
    
    // Método que cria uma tarefa que mantém uma referência ao gerenciador
    void adicionarTarefa(const std::string& descricao) {
        // Captura shared_ptr para this usando shared_from_this()
        std::shared_ptr<GerenciadorTarefas> self = shared_from_this();
        
        tarefas.push_back([self, descricao]() {
            std::cout << "Executando tarefa '" << descricao << "' no gerenciador '" << self->nome << "'" << std::endl;
        });
        
        std::cout << "Tarefa '" << descricao << "' adicionada ao gerenciador '" << nome << "'" << std::endl;
    }
    
    void executarTarefas() {
        std::cout << "Executando todas as tarefas do gerenciador '" << nome << "':" << std::endl;
        for (const auto& tarefa : tarefas) {
            tarefa();
        }
        tarefas.clear();
    }
};

void demonstrarEnableSharedFromThis() {
    std::cout << "\n=== enable_shared_from_this ===" << std::endl;
    
    // IMPORTANTE: O objeto deve ser inicialmente gerenciado por um shared_ptr
    // para que shared_from_this() funcione
    auto gerenciador = std::make_shared<GerenciadorTarefas>("Principal");
    
    // Adicionar tarefas que capturam o gerenciador
    gerenciador->adicionarTarefa("Processar dados");
    gerenciador->adicionarTarefa("Gerar relatório");
    gerenciador->adicionarTarefa("Enviar notificações");
    
    // Executar as tarefas
    gerenciador->executarTarefas();
    
    // gerenciador será destruído ao sair da função
}

// ===== Uso Avançado: Alocadores Personalizados =====

// Alocador personalizado que rastreia alocações
template<typename T>
class AlocadorRastreador {
public:
    using value_type = T;
    
    AlocadorRastreador() noexcept {
        std::cout << "AlocadorRastreador criado." << std::endl;
    }
    
    template<typename U>
    AlocadorRastreador(const AlocadorRastreador<U>&) noexcept {
        std::cout << "AlocadorRastreador copiado." << std::endl;
    }
    
    T* allocate(std::size_t n) {
        std::cout << "Alocando " << n << " objetos do tipo " << typeid(T).name() << std::endl;
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }
    
    void deallocate(T* p, std::size_t n) noexcept {
        std::cout << "Desalocando " << n << " objetos do tipo " << typeid(T).name() << std::endl;
        ::operator delete(p);
    }
};

void demonstrarAlocadoresPersonalizados() {
    std::cout << "\n=== Alocadores Personalizados com shared_ptr ===" << std::endl;
    
    // Usando alocador personalizado com shared_ptr
    {
        // Definindo o tipo de shared_ptr com alocador personalizado
        using RecursoComAlocador = std::shared_ptr<Recurso>;
        
        // Criando o shared_ptr com alocador personalizado
        std::cout << "Criando shared_ptr com alocador personalizado:" << std::endl;
        RecursoComAlocador recurso = std::allocate_shared<Recurso>(AlocadorRastreador<Recurso>(), "AlocadorPersonalizado");
        
        // Usando o recurso
        recurso->usar();
        
        // recurso será desalocado com o alocador personalizado ao sair do escopo
    }
}

// ===== Uso Avançado: Multithreading com shared_ptr =====

void funcaoThread(std::shared_ptr<Recurso> recurso, int id) {
    std::cout << "Thread " << id << " iniciada com contagem de referências: " << recurso.use_count() << std::endl;
    
    // Simular trabalho
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * id));
    
    // Usar o recurso
    std::cout << "Thread " << id << " usando recurso: ";
    recurso->usar();
    
    std::cout << "Thread " << id << " finalizada com contagem de referências: " << recurso.use_count() << std::endl;
}

void demonstrarMultithreading() {
    std::cout << "\n=== Multithreading com shared_ptr ===" << std::endl;
    
    // Criar um recurso compartilhado
    auto recurso = std::make_shared<Recurso>("ThreadSafe");
    std::cout << "Contagem inicial de referências: " << recurso.use_count() << std::endl;
    
    // Criar várias threads que compartilham o recurso
    std::vector<std::thread> threads;
    for (int i = 1; i <= 5; ++i) {
        threads.emplace_back(funcaoThread, recurso, i);
    }
    
    // Esperar todas as threads terminarem
    for (auto& t : threads) {
        t.join();
    }
    
    std::cout << "Todas as threads finalizadas." << std::endl;
    std::cout << "Contagem final de referências: " << recurso.use_count() << std::endl;
    
    // recurso será destruído ao sair da função
}

// ===== Comparação com C# =====

void compararComCSharp() {
    std::cout << "\n=== Comparação com C# ===" << std::endl;
    
    std::cout << "C++ shared_ptr vs C# referências:" << std::endl;
    std::cout << "1. Em C#, todos os objetos de classe são gerenciados por referência automaticamente" << std::endl;
    std::cout << "2. Em C++, você precisa usar explicitamente shared_ptr para compartilhar propriedade" << std::endl;
    std::cout << "3. C# usa garbage collection, enquanto C++ usa contagem de referências com shared_ptr" << std::endl;
    std::cout << "4. Em C#, referências circulares são resolvidas pelo GC, em C++ você precisa usar weak_ptr" << std::endl;
    std::cout << "5. C# não tem equivalente direto para weak_ptr, mas tem WeakReference" << std::endl;
    
    std::cout << "\nExemplo equivalente em C#:" << std::endl;
    std::cout << "```csharp" << std::endl;
    std::cout << "// C# gerencia automaticamente a memória" << std::endl;
    std::cout << "class Recurso {" << std::endl;
    std::cout << "    public string Nome { get; }" << std::endl;
    std::cout << "    public Recurso(string nome) { Nome = nome; }" << std::endl;
    std::cout << "}" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "// Para referências fracas em C#" << std::endl;
    std::cout << "WeakReference<Recurso> referenciaFraca = new WeakReference<Recurso>(new Recurso(\"Exemplo\"));" << std::endl;
    std::cout << "if (referenciaFraca.TryGetTarget(out Recurso recurso)) {" << std::endl;
    std::cout << "    // Usar recurso" << std::endl;
    std::cout << "}" << std::endl;
    std::cout << "```" << std::endl;
}

int main() {
    std::cout << "=== Demonstração Avançada de Smart Pointers em C++ ===" << std::endl;
    
    demonstrarSharedPtrBasico();
    demonstrarCompartilhamentoPropriedade();
    demonstrarReferenciaCircular();
    demonstrarCallbacksObservers();
    demonstrarCustomDeleters();
    demonstrarEnableSharedFromThis();
    demonstrarAlocadoresPersonalizados();
    demonstrarMultithreading();
    compararComCSharp();
    
    return 0;
}

/*
 * Notas para programadores C#:
 * 
 * 1. shared_ptr vs Referências em C#:
 *    - C# gerencia automaticamente o ciclo de vida dos objetos através do garbage collector
 *    - C++ requer gerenciamento explícito, com shared_ptr fornecendo semântica similar
 *    - Em C#, você não precisa se preocupar com quem "possui" um objeto
 *    - Em C++, shared_ptr implementa propriedade compartilhada com contagem de referências
 * 
 * 2. weak_ptr vs WeakReference:
 *    - C# tem WeakReference<T> que não impede o GC de coletar o objeto
 *    - C++ tem weak_ptr que não aumenta a contagem de referências do shared_ptr
 *    - Em ambos os casos, você precisa verificar se o objeto ainda existe antes de usá-lo
 * 
 * 3. Referências Circulares:
 *    - Em C#, o GC pode detectar e coletar referências circulares
 *    - Em C++, referências circulares com shared_ptr causam vazamentos de memória
 *    - A solução em C++ é usar weak_ptr para quebrar o ciclo
 * 
 * 4. Thread Safety:
 *    - Em C#, referências a objetos são thread-safe
 *    - Em C++, a contagem de referências em shared_ptr é thread-safe, mas o objeto apontado não é
 *    - Você precisa implementar sua própria sincronização para acesso thread-safe ao objeto
 * 
 * 5. Deleters Personalizados:
 *    - C# tem IDisposable para limpeza de recursos
 *    - C++ permite definir comportamento personalizado de limpeza com deleters em shared_ptr
 * 
 * 6. enable_shared_from_this:
 *    - Não há equivalente direto em C#, pois objetos já são gerenciados por referência
 *    - Em C++, permite que um objeto obtenha um shared_ptr para si mesmo de forma segura
 */
