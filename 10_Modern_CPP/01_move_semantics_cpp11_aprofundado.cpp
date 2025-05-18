/**
 * Move Semantics em C++11 e C++23 (Versão Aprofundada)
 * 
 * Este exemplo demonstra o uso avançado de move semantics em C++,
 * explorando rvalue references, perfect forwarding, e otimizações relacionadas.
 * 
 * Comparação com C#:
 * C# não tem um conceito equivalente a move semantics, pois gerencia objetos por referência.
 */

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <chrono>
#include <algorithm>
#include <functional>
#include <type_traits>

// Classe para demonstrar move semantics com recursos pesados
class RecursoPesado {
private:
    std::string nome;
    std::unique_ptr<int[]> dados;
    size_t tamanho;
    
    // Função auxiliar para preencher dados
    void preencherDados() {
        for (size_t i = 0; i < tamanho; ++i) {
            dados[i] = static_cast<int>(i);
        }
    }
    
public:
    // Construtor padrão
    RecursoPesado() : nome("Sem nome"), dados(nullptr), tamanho(0) {
        std::cout << "Construtor padrão: RecursoPesado sem nome criado." << std::endl;
    }
    
    // Construtor com parâmetros
    RecursoPesado(const std::string& n, size_t tam) 
        : nome(n), dados(new int[tam]), tamanho(tam) {
        preencherDados();
        std::cout << "Construtor: RecursoPesado '" << nome << "' criado com " 
                  << tamanho << " elementos." << std::endl;
    }
    
    // Construtor de cópia - operação cara
    RecursoPesado(const RecursoPesado& outro) 
        : nome(outro.nome + " (cópia)"), dados(new int[outro.tamanho]), tamanho(outro.tamanho) {
        // Copiar todos os dados - operação potencialmente cara
        for (size_t i = 0; i < tamanho; ++i) {
            dados[i] = outro.dados[i];
        }
        std::cout << "Construtor de cópia: RecursoPesado '" << nome << "' criado copiando " 
                  << tamanho << " elementos." << std::endl;
    }
    
    // Operador de atribuição por cópia - operação cara
    RecursoPesado& operator=(const RecursoPesado& outro) {
        if (this != &outro) {
            // Liberar recursos existentes
            nome = outro.nome + " (cópia atribuída)";
            
            // Realocar e copiar dados
            dados.reset(new int[outro.tamanho]);
            tamanho = outro.tamanho;
            
            // Copiar todos os dados - operação potencialmente cara
            for (size_t i = 0; i < tamanho; ++i) {
                dados[i] = outro.dados[i];
            }
            
            std::cout << "Operador de atribuição por cópia: RecursoPesado '" << nome 
                      << "' atualizado copiando " << tamanho << " elementos." << std::endl;
        }
        return *this;
    }
    
    // Construtor de movimento - operação barata
    RecursoPesado(RecursoPesado&& outro) noexcept
        : nome(std::move(outro.nome)), dados(std::move(outro.dados)), tamanho(outro.tamanho) {
        // Deixar o outro objeto em estado válido mas vazio
        outro.tamanho = 0;
        
        std::cout << "Construtor de movimento: RecursoPesado '" << nome 
                  << "' criado movendo " << tamanho << " elementos." << std::endl;
    }
    
    // Operador de atribuição por movimento - operação barata
    RecursoPesado& operator=(RecursoPesado&& outro) noexcept {
        if (this != &outro) {
            // Mover recursos
            nome = std::move(outro.nome);
            dados = std::move(outro.dados);
            tamanho = outro.tamanho;
            
            // Deixar o outro objeto em estado válido mas vazio
            outro.tamanho = 0;
            
            std::cout << "Operador de atribuição por movimento: RecursoPesado '" << nome 
                      << "' atualizado movendo " << tamanho << " elementos." << std::endl;
        }
        return *this;
    }
    
    // Destrutor
    ~RecursoPesado() {
        std::cout << "Destrutor: RecursoPesado '" << nome << "' destruído";
        if (tamanho > 0) {
            std::cout << " (tinha " << tamanho << " elementos)";
        }
        std::cout << "." << std::endl;
    }
    
    // Método para obter o nome
    const std::string& obterNome() const {
        return nome;
    }
    
    // Método para obter o tamanho
    size_t obterTamanho() const {
        return tamanho;
    }
    
    // Método para somar todos os elementos
    int somarElementos() const {
        int soma = 0;
        for (size_t i = 0; i < tamanho; ++i) {
            soma += dados[i];
        }
        return soma;
    }
};

// ===== Fundamentos de Move Semantics =====

void demonstrarFundamentosMove() {
    std::cout << "\n=== Fundamentos de Move Semantics ===" << std::endl;
    
    // Criando um objeto com recursos pesados
    RecursoPesado original("Original", 1000000);
    
    std::cout << "\n--- Cópia vs. Movimento ---" << std::endl;
    
    // Cópia - invoca construtor de cópia (caro)
    {
        auto inicio = std::chrono::high_resolution_clock::now();
        RecursoPesado copia = original;  // Construtor de cópia
        auto fim = std::chrono::high_resolution_clock::now();
        auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio).count();
        
        std::cout << "Tempo para copiar: " << duracao << " microssegundos" << std::endl;
        std::cout << "Soma dos elementos na cópia: " << copia.somarElementos() << std::endl;
    }
    
    // Movimento - invoca construtor de movimento (barato)
    {
        auto inicio = std::chrono::high_resolution_clock::now();
        RecursoPesado movido = std::move(original);  // Construtor de movimento
        auto fim = std::chrono::high_resolution_clock::now();
        auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio).count();
        
        std::cout << "Tempo para mover: " << duracao << " microssegundos" << std::endl;
        std::cout << "Soma dos elementos no objeto movido: " << movido.somarElementos() << std::endl;
        
        // original agora está em estado "movido" - ainda é válido, mas vazio
        std::cout << "Tamanho do objeto original após movimento: " << original.obterTamanho() << std::endl;
    }
}

// ===== Retorno por Valor e RVO (Return Value Optimization) =====

// Função que retorna um objeto por valor
RecursoPesado criarRecursoPorValor(const std::string& nome, size_t tamanho) {
    RecursoPesado recurso(nome, tamanho);
    return recurso;  // O compilador pode aplicar RVO aqui
}

// Função que retorna um objeto temporário explícito
RecursoPesado criarRecursoTemporario(const std::string& nome, size_t tamanho) {
    return RecursoPesado(nome, tamanho);  // O compilador pode aplicar RVO aqui
}

// Função que retorna um objeto movido explicitamente
RecursoPesado criarRecursoMovido(const std::string& nome, size_t tamanho) {
    RecursoPesado recurso(nome, tamanho);
    return std::move(recurso);  // Isso impede RVO! Não faça isso!
}

void demonstrarRetornoPorValor() {
    std::cout << "\n=== Retorno por Valor e RVO ===" << std::endl;
    
    std::cout << "\n--- Retorno de variável local ---" << std::endl;
    RecursoPesado r1 = criarRecursoPorValor("RetornoLocal", 1000);
    
    std::cout << "\n--- Retorno de temporário explícito ---" << std::endl;
    RecursoPesado r2 = criarRecursoTemporario("RetornoTemporario", 1000);
    
    std::cout << "\n--- Retorno com std::move explícito (anti-padrão) ---" << std::endl;
    RecursoPesado r3 = criarRecursoMovido("RetornoMovido", 1000);
    
    std::cout << "\nObservação: Nos dois primeiros casos, o compilador pode aplicar RVO (Return Value Optimization)" << std::endl;
    std::cout << "ou NRVO (Named Return Value Optimization) para eliminar cópias/movimentos desnecessários." << std::endl;
    std::cout << "No terceiro caso, std::move impede essas otimizações, resultando em uma operação de movimento extra." << std::endl;
}

// ===== Move Semantics com Containers =====

void demonstrarMoveContainers() {
    std::cout << "\n=== Move Semantics com Containers ===" << std::endl;
    
    // Vetor de objetos pesados
    std::vector<RecursoPesado> vetor;
    
    std::cout << "\n--- Inserindo com push_back (cópia) ---" << std::endl;
    {
        RecursoPesado recurso("VetorCopia", 10000);
        vetor.push_back(recurso);  // Cria uma cópia
        std::cout << "Após push_back, o recurso original ainda tem tamanho: " << recurso.obterTamanho() << std::endl;
    }
    
    std::cout << "\n--- Inserindo com push_back (movimento) ---" << std::endl;
    {
        RecursoPesado recurso("VetorMove", 10000);
        vetor.push_back(std::move(recurso));  // Move o recurso
        std::cout << "Após push_back com move, o recurso original tem tamanho: " << recurso.obterTamanho() << std::endl;
    }
    
    std::cout << "\n--- Inserindo com emplace_back (construção in-place) ---" << std::endl;
    {
        // emplace_back constrói o objeto diretamente no vetor, sem cópias ou movimentos extras
        vetor.emplace_back("VetorEmplace", 10000);
    }
    
    std::cout << "\n--- Realocação de vetor ---" << std::endl;
    {
        std::vector<RecursoPesado> vetorPequeno;
        vetorPequeno.reserve(1);  // Reservar espaço para apenas 1 elemento
        
        std::cout << "Adicionando primeiro elemento (sem realocação):" << std::endl;
        vetorPequeno.emplace_back("Elemento1", 1000);
        
        std::cout << "Adicionando segundo elemento (com realocação):" << std::endl;
        vetorPequeno.emplace_back("Elemento2", 1000);
        // A realocação move todos os elementos existentes para a nova memória
    }
}

// ===== Perfect Forwarding =====

// Função que aceita uma referência lvalue
void processar(RecursoPesado& recurso) {
    std::cout << "Processando lvalue: " << recurso.obterNome() << std::endl;
}

// Função que aceita uma referência rvalue
void processar(RecursoPesado&& recurso) {
    std::cout << "Processando rvalue: " << recurso.obterNome() << std::endl;
}

// Template que encaminha perfeitamente o argumento
template<typename T>
void encaminhar(T&& arg) {
    std::cout << "Encaminhando argumento..." << std::endl;
    processar(std::forward<T>(arg));
}

// Template que demonstra dedução de tipo com referências universais
template<typename T>
void mostrarTipoArgumento(T&& arg) {
    if constexpr (std::is_lvalue_reference_v<T>) {
        std::cout << "Argumento é lvalue reference" << std::endl;
    } else {
        std::cout << "Argumento é rvalue reference" << std::endl;
    }
}

void demonstrarPerfectForwarding() {
    std::cout << "\n=== Perfect Forwarding ===" << std::endl;
    
    RecursoPesado recurso("PerfectForwarding", 1000);
    
    std::cout << "\n--- Encaminhando lvalue ---" << std::endl;
    encaminhar(recurso);  // recurso é lvalue
    
    std::cout << "\n--- Encaminhando rvalue ---" << std::endl;
    encaminhar(std::move(recurso));  // std::move(recurso) é rvalue
    
    std::cout << "\n--- Dedução de tipo com referências universais ---" << std::endl;
    RecursoPesado r("DeducaoTipo", 100);
    mostrarTipoArgumento(r);  // lvalue
    mostrarTipoArgumento(std::move(r));  // rvalue
    mostrarTipoArgumento(RecursoPesado("Temporario", 100));  // rvalue
}

// ===== Move Semantics com Herança =====

// Classe base com move semantics
class Base {
private:
    std::string dados;
    
public:
    Base(const std::string& d) : dados(d) {
        std::cout << "Construtor Base: " << dados << std::endl;
    }
    
    Base(const Base& outro) : dados(outro.dados) {
        std::cout << "Construtor de cópia Base: " << dados << std::endl;
    }
    
    Base(Base&& outro) noexcept : dados(std::move(outro.dados)) {
        std::cout << "Construtor de movimento Base: " << dados << std::endl;
    }
    
    Base& operator=(const Base& outro) {
        if (this != &outro) {
            dados = outro.dados;
            std::cout << "Operador de atribuição por cópia Base: " << dados << std::endl;
        }
        return *this;
    }
    
    Base& operator=(Base&& outro) noexcept {
        if (this != &outro) {
            dados = std::move(outro.dados);
            std::cout << "Operador de atribuição por movimento Base: " << dados << std::endl;
        }
        return *this;
    }
    
    virtual ~Base() {
        std::cout << "Destrutor Base: " << dados << std::endl;
    }
    
    const std::string& obterDados() const {
        return dados;
    }
};

// Classe derivada com move semantics
class Derivada : public Base {
private:
    std::unique_ptr<int[]> maisRecursos;
    size_t tamanho;
    
public:
    Derivada(const std::string& d, size_t tam) 
        : Base(d), maisRecursos(new int[tam]), tamanho(tam) {
        std::cout << "Construtor Derivada: " << obterDados() << " com " << tamanho << " elementos" << std::endl;
    }
    
    // Construtor de cópia
    Derivada(const Derivada& outro) 
        : Base(outro), maisRecursos(new int[outro.tamanho]), tamanho(outro.tamanho) {
        std::cout << "Construtor de cópia Derivada: " << obterDados() << std::endl;
    }
    
    // Construtor de movimento
    Derivada(Derivada&& outro) noexcept
        : Base(std::move(outro)), maisRecursos(std::move(outro.maisRecursos)), tamanho(outro.tamanho) {
        outro.tamanho = 0;
        std::cout << "Construtor de movimento Derivada: " << obterDados() << std::endl;
    }
    
    // Operador de atribuição por cópia
    Derivada& operator=(const Derivada& outro) {
        if (this != &outro) {
            Base::operator=(outro);
            maisRecursos.reset(new int[outro.tamanho]);
            tamanho = outro.tamanho;
            std::cout << "Operador de atribuição por cópia Derivada: " << obterDados() << std::endl;
        }
        return *this;
    }
    
    // Operador de atribuição por movimento
    Derivada& operator=(Derivada&& outro) noexcept {
        if (this != &outro) {
            Base::operator=(std::move(outro));
            maisRecursos = std::move(outro.maisRecursos);
            tamanho = outro.tamanho;
            outro.tamanho = 0;
            std::cout << "Operador de atribuição por movimento Derivada: " << obterDados() << std::endl;
        }
        return *this;
    }
    
    ~Derivada() override {
        std::cout << "Destrutor Derivada: " << obterDados();
        if (tamanho > 0) {
            std::cout << " (tinha " << tamanho << " elementos)";
        }
        std::cout << std::endl;
    }
};

void demonstrarMoveHeranca() {
    std::cout << "\n=== Move Semantics com Herança ===" << std::endl;
    
    std::cout << "\n--- Construção e movimento de objeto derivado ---" << std::endl;
    Derivada original("ObjetoDerivado", 1000);
    
    std::cout << "\n--- Movendo objeto derivado ---" << std::endl;
    Derivada movida = std::move(original);
    
    std::cout << "\n--- Atribuição por movimento de objeto derivado ---" << std::endl;
    Derivada outra("OutroDerivado", 500);
    outra = std::move(movida);
}

// ===== Move-Only Types =====

// Classe que só pode ser movida, não copiada
class RecursoNaoCopiavelMovivel {
private:
    std::unique_ptr<int[]> dados;
    size_t tamanho;
    std::string nome;
    
public:
    RecursoNaoCopiavelMovivel(const std::string& n, size_t tam) 
        : dados(new int[tam]), tamanho(tam), nome(n) {
        std::cout << "Construtor: RecursoNaoCopiavelMovivel '" << nome << "' criado." << std::endl;
    }
    
    // Desabilitar cópia
    RecursoNaoCopiavelMovivel(const RecursoNaoCopiavelMovivel&) = delete;
    RecursoNaoCopiavelMovivel& operator=(const RecursoNaoCopiavelMovivel&) = delete;
    
    // Permitir movimento
    RecursoNaoCopiavelMovivel(RecursoNaoCopiavelMovivel&& outro) noexcept
        : dados(std::move(outro.dados)), tamanho(outro.tamanho), nome(std::move(outro.nome)) {
        outro.tamanho = 0;
        std::cout << "Construtor de movimento: RecursoNaoCopiavelMovivel '" << nome << "' movido." << std::endl;
    }
    
    RecursoNaoCopiavelMovivel& operator=(RecursoNaoCopiavelMovivel&& outro) noexcept {
        if (this != &outro) {
            dados = std::move(outro.dados);
            tamanho = outro.tamanho;
            nome = std::move(outro.nome);
            outro.tamanho = 0;
            std::cout << "Operador de atribuição por movimento: RecursoNaoCopiavelMovivel '" << nome << "' movido." << std::endl;
        }
        return *this;
    }
    
    ~RecursoNaoCopiavelMovivel() {
        std::cout << "Destrutor: RecursoNaoCopiavelMovivel '" << nome << "' destruído";
        if (tamanho > 0) {
            std::cout << " (tinha " << tamanho << " elementos)";
        }
        std::cout << "." << std::endl;
    }
    
    void usar() const {
        std::cout << "Usando RecursoNaoCopiavelMovivel '" << nome << "'" << std::endl;
    }
};

// Função que aceita um recurso por valor (requer movimento)
void processarRecursoMovivel(RecursoNaoCopiavelMovivel recurso) {
    std::cout << "Processando recurso movível..." << std::endl;
    recurso.usar();
}

void demonstrarMoveOnlyTypes() {
    std::cout << "\n=== Move-Only Types ===" << std::endl;
    
    RecursoNaoCopiavelMovivel recurso("MoveOnly", 1000);
    
    // Não é possível copiar
    // RecursoNaoCopiavelMovivel copia = recurso;  // Erro de compilação
    
    // Mas é possível mover
    RecursoNaoCopiavelMovivel movido = std::move(recurso);
    movido.usar();
    
    // Passando para função (requer movimento)
    processarRecursoMovivel(std::move(movido));
    
    // Exemplos de tipos move-only na biblioteca padrão
    std::cout << "\n--- Exemplos de tipos move-only na biblioteca padrão ---" << std::endl;
    std::cout << "1. std::unique_ptr - propriedade exclusiva" << std::endl;
    std::cout << "2. std::thread - representa uma thread de execução" << std::endl;
    std::cout << "3. std::future - representa um resultado futuro" << std::endl;
    std::cout << "4. std::promise - armazena um valor para ser recuperado por um future" << std::endl;
    std::cout << "5. std::packaged_task - encapsula uma função para execução assíncrona" << std::endl;
}

// ===== Move Semantics em C++17 e C++20 =====

// Classe que demonstra guaranteed copy elision (C++17)
class ObjetoGrande {
private:
    std::unique_ptr<int[]> dados;
    size_t tamanho;
    
public:
    ObjetoGrande(size_t tam) : dados(new int[tam]), tamanho(tam) {
        std::cout << "Construtor: ObjetoGrande criado com " << tamanho << " elementos." << std::endl;
    }
    
    ObjetoGrande(const ObjetoGrande& outro) : dados(new int[outro.tamanho]), tamanho(outro.tamanho) {
        std::cout << "Construtor de cópia: ObjetoGrande copiado." << std::endl;
    }
    
    ObjetoGrande(ObjetoGrande&& outro) noexcept : dados(std::move(outro.dados)), tamanho(outro.tamanho) {
        outro.tamanho = 0;
        std::cout << "Construtor de movimento: ObjetoGrande movido." << std::endl;
    }
    
    ~ObjetoGrande() {
        std::cout << "Destrutor: ObjetoGrande destruído";
        if (tamanho > 0) {
            std::cout << " (tinha " << tamanho << " elementos)";
        }
        std::cout << "." << std::endl;
    }
};

// Função que retorna um objeto temporário
ObjetoGrande criarObjetoGrande(size_t tamanho) {
    return ObjetoGrande(tamanho);  // Antes do C++17: RVO opcional, depois: garantido
}

// Função que retorna um objeto temporário através de uma condição
ObjetoGrande criarObjetoGrandeCondicional(size_t tamanho, bool condicao) {
    if (condicao) {
        return ObjetoGrande(tamanho);  // Antes do C++17: RVO opcional, depois: garantido
    } else {
        ObjetoGrande obj(tamanho);
        return obj;  // Antes do C++17: NRVO opcional, depois: NRVO ainda opcional
    }
}

void demonstrarCpp17Cpp20Features() {
    std::cout << "\n=== Move Semantics em C++17 e C++20 ===" << std::endl;
    
    std::cout << "\n--- Guaranteed Copy Elision (C++17) ---" << std::endl;
    std::cout << "Criando objeto diretamente com temporário:" << std::endl;
    ObjetoGrande obj1 = ObjetoGrande(1000);  // Construtor chamado apenas uma vez
    
    std::cout << "\nCriando objeto através de função:" << std::endl;
    ObjetoGrande obj2 = criarObjetoGrande(1000);  // Construtor chamado apenas uma vez
    
    std::cout << "\nCriando objeto através de função condicional (true):" << std::endl;
    ObjetoGrande obj3 = criarObjetoGrandeCondicional(1000, true);  // Construtor chamado apenas uma vez
    
    std::cout << "\nCriando objeto através de função condicional (false):" << std::endl;
    ObjetoGrande obj4 = criarObjetoGrandeCondicional(1000, false);  // NRVO ainda é opcional
    
    std::cout << "\n--- Outras melhorias em C++20 ---" << std::endl;
    std::cout << "1. Constrained move constructors e assignment operators" << std::endl;
    std::cout << "2. Conditional explicit para construtores de conversão" << std::endl;
    std::cout << "3. Melhores regras para inicialização de agregados" << std::endl;
}

// ===== Comparação com C# =====

void compararComCSharp() {
    std::cout << "\n=== Comparação com C# ===" << std::endl;
    
    std::cout << "C++ Move Semantics vs C# Referências:" << std::endl;
    std::cout << "1. C# não tem um conceito equivalente a move semantics" << std::endl;
    std::cout << "2. Em C#, objetos são sempre gerenciados por referência" << std::endl;
    std::cout << "3. O garbage collector de C# lida com a liberação de memória" << std::endl;
    std::cout << "4. C# tem 'ref' e 'out' para passagem por referência, mas não é o mesmo que move semantics" << std::endl;
    
    std::cout << "\nExemplo equivalente em C#:" << std::endl;
    std::cout << "```csharp" << std::endl;
    std::cout << "// Em C#, não há necessidade de move semantics" << std::endl;
    std::cout << "class RecursoPesado {" << std::endl;
    std::cout << "    private string nome;" << std::endl;
    std::cout << "    private int[] dados;" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "    public RecursoPesado(string nome, int tamanho) {" << std::endl;
    std::cout << "        this.nome = nome;" << std::endl;
    std::cout << "        this.dados = new int[tamanho];" << std::endl;
    std::cout << "        // Preencher dados..." << std::endl;
    std::cout << "    }" << std::endl;
    std::cout << "}" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "// Atribuição apenas copia a referência, não o objeto inteiro" << std::endl;
    std::cout << "RecursoPesado original = new RecursoPesado(\"Original\", 1000000);" << std::endl;
    std::cout << "RecursoPesado referencia = original; // Apenas copia a referência" << std::endl;
    std::cout << "```" << std::endl;
    
    std::cout << "\nCasos onde C# tem comportamento similar:" << std::endl;
    std::cout << "1. Structs em C# são tipos de valor e são copiados quando atribuídos" << std::endl;
    std::cout << "2. ref struct em C# são tipos de valor que só podem ser usados em pilha (como tipos move-only)" << std::endl;
    std::cout << "3. Span<T> em C# é um ref struct que não pode ser armazenado no heap" << std::endl;
}

int main() {
    std::cout << "=== Demonstração Avançada de Move Semantics em C++ ===" << std::endl;
    
    demonstrarFundamentosMove();
    demonstrarRetornoPorValor();
    demonstrarMoveContainers();
    demonstrarPerfectForwarding();
    demonstrarMoveHeranca();
    demonstrarMoveOnlyTypes();
    demonstrarCpp17Cpp20Features();
    compararComCSharp();
    
    return 0;
}

/*
 * Notas para programadores C#:
 * 
 * 1. Move Semantics vs Referências em C#:
 *    - C# gerencia objetos por referência, então "mover" um objeto significa apenas copiar a referência
 *    - C++ tem semântica de valor por padrão, então move semantics otimiza transferências de propriedade
 *    - Move semantics em C++ é uma otimização para evitar cópias desnecessárias
 * 
 * 2. Tipos de Valor vs Tipos de Referência:
 *    - Em C#, structs são tipos de valor e classes são tipos de referência
 *    - Em C++, structs e classes são essencialmente o mesmo, ambos com semântica de valor por padrão
 *    - Para obter semântica de referência em C++, você precisa usar ponteiros ou referências
 * 
 * 3. Otimizações de Compilador:
 *    - C++ tem RVO (Return Value Optimization) e NRVO (Named Return Value Optimization)
 *    - C# não precisa dessas otimizações para objetos, pois apenas copia referências
 * 
 * 4. Perfect Forwarding:
 *    - C++ usa std::forward para preservar a categoria de valor (lvalue/rvalue) em templates
 *    - C# não tem um conceito equivalente, pois não distingue entre lvalues e rvalues
 * 
 * 5. Move-Only Types:
 *    - C++ permite criar tipos que só podem ser movidos, não copiados
 *    - C# tem ref struct (como Span<T>) que são semelhantes em alguns aspectos
 * 
 * 6. Quando usar Move Semantics em C++:
 *    - Ao transferir propriedade de recursos pesados
 *    - Ao implementar containers e estruturas de dados eficientes
 *    - Ao retornar objetos grandes de funções
 *    - Ao trabalhar com tipos move-only como std::unique_ptr
 */
