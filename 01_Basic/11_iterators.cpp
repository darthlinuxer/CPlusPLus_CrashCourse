#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

int main()
{
    std::vector<std::string> words = {"Hello", "from", "C++", "Crash", "Course"};

    // Using iterator to traverse the vector
    for (std::vector<std::string>::iterator it = words.begin(); it != words.end(); ++it)
    {
        std::cout << *it << " ";
        if (*it == "C++")
        {
            std::cout << "(found C++) ";
            // I could have changed it here but will do it later
        }
    }
    std::cout << std::endl;

    std::cout << "Modifying the first occurrence of 'C++' to 'C++20+':" << std::endl;
    if (
        const auto it = std::find(std::begin(words), std::end(words), "C++");
        it != std::end(words))
    {
        *it = "C++20+"; // Modify the element
    }

    // Using const_iterator to traverse the vector
    // (elements cannot be modified)
    std::cout << "Using const_iterator to traverse the vector:" << std::endl;
    for (std::vector<std::string>::const_iterator cit = words.cbegin(); cit != words.cend(); ++cit)
    {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    return 0;
}