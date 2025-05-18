#include <vector>
#include <fstream>
#include <iostream>
int main()
{
    std::vector<int> v{};
    std::ifstream inputfile {"data.txt"};
    int n{};
    while (inputfile >> n)
    {
        v.push_back(n);
    }
    inputfile.close();
    for (auto x:v){
        std::cout << x << std::endl;
    }

    std::cout << "#############  Reading strings from file ##############" << std::endl;
    std::ifstream inputfile2 {"README.md"};
    std::vector<std::string> lines{};
    std::string line{};
    while (getline(inputfile2, line))
    {
        lines.push_back(line);
    }
    for(const auto& x:lines){
        std::cout << x << std::endl;
    }
    inputfile2.close();

    return 0;    
}