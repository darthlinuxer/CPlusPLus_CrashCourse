#include <iostream>

namespace FirstNamespace
{
    void display()
    {
        std::cout << "Inside FirstNamespace\n";
    }
}
namespace SecondNamespace
{
    void display()
    {
        std::cout << "Inside SecondNamespace\n";
    }
}

namespace First::Second::Third{
    void show(){
        std::cout << "Inside First::Second::Third namespace\n";
    }
}

int main()
{
    FirstNamespace::display();  // Calls display from FirstNamespace
    SecondNamespace::display(); // Calls display from SecondNamespace

    using namespace FirstNamespace;
    display(); // Calls display from FirstNamespace due to 'using' directive

    {
        using SecondNamespace::display;
        display(); // Calls display from SecondNamespace due to 'using' declaration
    }

    display(); // Calls display from FirstNamespace again

    First::Second::Third::show(); // Calls show from nested namespace

    return 0;
}
