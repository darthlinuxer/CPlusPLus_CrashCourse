// This file demonstrates the importance of understanding class member initialization order in C++.
// Why this is the right way:
// - It ensures that members are initialized in the order they are declared, avoiding undefined behavior.
// - It highlights the importance of writing constructors carefully to avoid issues.
// How a noob might do it:
// - A noob might assume that members are initialized in the order they appear in the initializer list, leading to bugs.

#include <iostream>
#include <cstddef>

// Demonstrating the initialization order of class members
class View {
public:
    View(unsigned char *start, std::size_t size) : m_start{start}, m_end{m_start + size} {
        std::cout << "View constructor: " << static_cast<void *>(m_start) << ", " << static_cast<void *>(m_end) << '\n';
    }

private:
    unsigned char *m_start; // Members are initialized in the order they are declared
    unsigned char *m_end;
};

int main() {
    View v(nullptr, 1);
    return 0;
}

/* Expected Output:
View constructor: 0x0, 0x1
*/