#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Vectors
    vector<int> nums = {1, 2, 3};
    nums.push_back(4);
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;

    // Multidimensional array
    int matrix[2][2] = {{1, 2}, {3, 4}};
    cout << "Matrix[1][1]: " << matrix[1][1] << endl;

    // Pointers
    int x = 10;
    int* ptr = &x;
    cout << "Pointer value: " << *ptr << endl;

    // nullptr
    int* nullPtr = nullptr;

    // new/delete
    int* dynArr = new int[3]{5, 6, 7};
    cout << "Dynamic array: " << dynArr[0] << endl;
    delete[] dynArr;

    return 0;
}
// Output:
/*
1 2 3 4 
Matrix[1][1]: 4
Pointer value: 10
Dynamic array: 5
*/
