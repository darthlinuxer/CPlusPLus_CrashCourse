// Building a portuguese to english dictionary using structured bindings
#include <iostream>
#include <map>
#include <string>
#include <tuple>

int main()
{
    // Create a map to hold Portuguese to English translations
    std::map<std::string, std::string> dictionary = {
        {"olá", "hello"},
        {"mundo", "world"},
        {"livro", "book"},
        {"computador", "computer"},
        {"programação", "programming"}};

    // Using structured bindings to iterate over the map
    std::cout << "Portuguese to English Dictionary:" << std::endl;
    for (const auto &[portuguese, english] : dictionary)
        std::cout << portuguese << " -> " << english << std::endl;

    { // Adding a new translation using structured bindings
        auto [result_iter, success] = dictionary.insert({"código", "code"});
        if (success)
            std::cout << "\nAdded new translation: código -> code" << std::endl;
        else
            std::cout << "\nTranslation for 'código' already exists." << std::endl;
    }

    { // Adding again the same translation using structured bindings
        auto [result_iter, success] = dictionary.insert({"código", "code"});
        if (success)
            std::cout << "\nAdded new translation: código -> code" << std::endl;
        else
            std::cout << "\nTranslation for 'código' already exists." << std::endl;
    }

    std::cout << "\nAfter adding a new translation:" << std::endl;
    for (const auto &[portuguese, english] : dictionary)
        std::cout << portuguese << " -> " << english << std::endl;

    return 0;
}