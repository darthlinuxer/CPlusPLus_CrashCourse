#include<iostream>
#include<string>
#include<type_traits> // For std::is_integral
using namespace std;

// if we remove constexpr the code will not compile
// because both branches of the if statement must be valid
// even if only one branch is taken at runtime.
// and it won't compile for integral types
// since they don't have a length() method.
template <typename T>
auto length(T const& value){
    if constexpr(is_integral<T>::value) return value;
    else return value.length();
}

int main(){
    cout << length(12345) << endl; // Outputs: 12345
    cout << length(string("Hello, World!")) << endl; // Outputs: 13
    return 0;
}