#include <iostream>
#include <memory> // For smart pointers
#include <vector> // For demonstrating vector behavior

// Function to demonstrate stack vs. heap allocation
void stackVsHeap() {
    std::cout << "\n--- Stack vs. Heap Demonstration ---\n";

    // Stack Allocation (Automatic Storage Duration)
    std::cout << "Stack Allocation:\n";
    int stackVar = 10; // 'stackVar' is allocated on the stack
    std::cout << "  - stackVar (int): Value = " << stackVar << ", Address = " << &stackVar << " (Stack)\n";

    // Heap Allocation (Dynamic Storage Duration)
    std::cout << "Heap Allocation:\n";
    int* heapVar = new int(20); // 'heapVar' points to memory allocated on the heap
    std::cout << "  - heapVar (int*): Value = " << *heapVar << ", Address = " << heapVar << " (Heap)\n";
    delete heapVar; // Remember to deallocate heap memory!
    heapVar = nullptr;

    // Stack allocation with a struct
    struct StackStruct {
        int a;
        double b;
    };
    StackStruct stackStructVar = {1, 2.0};
    std::cout << "  - stackStructVar (struct): Value = {" << stackStructVar.a << ", " << stackStructVar.b << "}, Address = " << &stackStructVar << " (Stack)\n";

    // Heap allocation with a struct
    struct HeapStruct {
        int a;
        double b;
    };
    HeapStruct* heapStructVar = new HeapStruct{3, 4.0};
    std::cout << "  - heapStructVar (struct*): Value = {" << heapStructVar->a << ", " << heapStructVar->b << "}, Address = " << heapStructVar << " (Heap)\n";
    delete heapStructVar;
    heapStructVar = nullptr;

    // Stack allocation with a vector
    std::vector<int> stackVector = {1, 2, 3};
    std::cout << "  - stackVector (std::vector): Values = {";
    for (int val : stackVector) {
        std::cout << val << " ";
    }
    std::cout << "}, Address = " << &stackVector << " (Stack)\n";

    // Heap allocation with a vector
    std::vector<int>* heapVector = new std::vector<int>({4, 5, 6});
    std::cout << "  - heapVector (std::vector*): Values = {";
    for (int val : *heapVector) {
        std::cout << val << " ";
    }
    std::cout << "}, Address = " << heapVector << " (Heap)\n";
    delete heapVector;
    heapVector = nullptr;

    std::cout << "--- End of Stack vs. Heap Demonstration ---\n";
}

int main() {
    // Basic pointer example
    std::cout << "\n--- Basic Pointer Example ---\n";
    int value = 42; // Declare an integer variable (Stack)
    int* ptr = &value; // Pointer stores the address of 'value' (Stack)

    // Output the value, address, and dereferenced pointer
    std::cout << "Value: " << value << " (Stack)\n"; // Prints the value of 'value'
    std::cout << "Pointer Address: " << ptr << " (Stack, points to Stack)\n"; // Prints the address stored in 'ptr'
    std::cout << "Pointer Dereference: " << *ptr << " (Stack)\n"; // Prints the value at the address stored in 'ptr'

    // Modifying value through pointer
    *ptr = 100; // Dereference the pointer and modify the value it points to
    std::cout << "Modified Value through Pointer: " << value << " (Stack)\n"; // Prints the updated value of 'value'

    // Null pointer example
    std::cout << "\n--- Null Pointer Example ---\n";
    int* nullPtr = nullptr; // A null pointer points to nothing (Stack)
    if (nullPtr == nullptr) {
        std::cout << "nullPtr is null. (Stack)\n";
    }

    // Pointer to another pointer (double pointer)
    std::cout << "\n--- Double Pointer Example ---\n";
    int** doublePtr = &ptr; // Pointer to a pointer (Stack)
    std::cout << "Address of ptr: " << doublePtr << " (Stack, points to Stack)\n"; // Prints the address of 'ptr'
    std::cout << "Value pointed by doublePtr: " << **doublePtr << " (Stack)\n"; // Dereferences twice to get the value of 'value'

    // Dynamic memory allocation
    std::cout << "\n--- Dynamic Memory Allocation Example ---\n";
    int* dynamicPtr = new int(55); // Dynamically allocate memory for an integer and initialize it (Heap)
    std::cout << "Dynamically Allocated Value: " << *dynamicPtr << " (Heap)\n"; // Prints the value stored in the dynamically allocated memory
    delete dynamicPtr; // Free the allocated memory
    dynamicPtr = nullptr; // Set the pointer to null after deletion (Stack)

    // Array and pointer relationship
    std::cout << "\n--- Array and Pointer Relationship Example ---\n";
    int arr[5] = {1, 2, 3, 4, 5}; // Declare an array (Stack)
    int* arrPtr = arr; // Pointer to the first element of the array (Stack)
    std::cout << "Array Elements via Pointer:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << *(arrPtr + i) << " "; // Access array elements using pointer arithmetic
    }
    std::cout << "\n";

    // Constant pointer (pointer itself cannot change)
    std::cout << "\n--- Constant Pointer Example ---\n";
    int anotherValue = 10; // (Stack)
    int* const constPtr = &value; // constPtr must always point to 'value' (Stack)
    *constPtr = 200; // Allowed: modifying the value pointed to
    std::cout << "Modified Value via constPtr: " << value << " (Stack)\n";
    // constPtr = &anotherValue; // Not allowed: changing the pointer itself

    // Pointer to constant (value cannot be modified through the pointer)
    std::cout << "\n--- Pointer to Constant Example ---\n";
    const int* ptrToConst = &anotherValue; // Pointer to a constant value (Stack)
    std::cout << "Value via ptrToConst: " << *ptrToConst << " (Stack)\n";
    // *ptrToConst = 20; // Not allowed: modifying the value through the pointer

    // Constant pointer to constant
    std::cout << "\n--- Constant Pointer to Constant Example ---\n";
    const int* const constPtrToConst = &anotherValue; // (Stack)
    std::cout << "Value via constPtrToConst: " << *constPtrToConst << " (Stack)\n";
    // *constPtrToConst = 30; // Not allowed: modifying the value
    // constPtrToConst = &value; // Not allowed: changing the pointer

    // Complex pointer operations
    std::cout << "\n--- Complex Pointer Operations Example ---\n";
    // Pointer to a dynamically allocated array
    int* dynamicArray = new int[5]{10, 20, 30, 40, 50}; // (Heap)
    std::cout << "Dynamically Allocated Array Elements:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << dynamicArray[i] << " "; // Access elements using array indexing
    }
    std::cout << "\n";
    delete[] dynamicArray; // Free the dynamically allocated array

    // Using smart pointers (unique_ptr)
    std::cout << "\n--- Smart Pointer (unique_ptr) Example ---\n";
    std::unique_ptr<int> smartPtr(new int(77)); // Unique pointer managing a dynamically allocated integer (Heap)
    std::cout << "Value via smartPtr: " << *smartPtr << " (Heap)\n";

    // Pointer to a function
    std::cout << "\n--- Pointer to Function Example ---\n";
    auto add = [](int a, int b) -> int { return a + b; }; // Lambda function (Stack)
    int (*funcPtr)(int, int) = add; // Pointer to the lambda function (Stack)
    std::cout << "Result of add(5, 10) via funcPtr: " << funcPtr(5, 10) << " (Stack)\n";

    // Pointer to a struct
    std::cout << "\n--- Pointer to Struct Example ---\n";
    struct Point {
        int x, y;
    };
    Point point = {3, 4}; // (Stack)
    Point* pointPtr = &point; // (Stack)
    std::cout << "Point coordinates via pointer: (" << pointPtr->x << ", " << pointPtr->y << ") (Stack)\n";

    // Stack vs Heap
    stackVsHeap();

    class Person{
        private:
            std::string name;
        public:
            Person(std::string n) : name(n) {}
            void introduce() {
                std::cout << "Hello, my name is " << name << ".\n";
            }       

    };

    Person Camilo("Camilo"); // Object on the stack
    std::cout << "\n--- Pointer to Class Example ---\n";
    std::cout << "Class object address: " << &Camilo << " (Stack)\n"; // Address of the object
    Person* pCamilo = &Camilo; // Pointer to the object (Stack)
    (pCamilo->introduce()); // Call method using pointer
    (*pCamilo).introduce(); // Call method using dereferenced pointer

    std::cout << "\n--- Const Pointers Example ---\n";
    int a = 10; // (Stack)
    int * const cPtr = &a; // Constant pointer to 'a' (Stack)
    //cPtr = new int(20); // Not allowed: changing the pointer itself
    *cPtr = 20; // Allowed: modifying the value pointed to
    std::cout << "Value Changed via cPtr: " << *cPtr << " (Heap)\n"; // Prints the value pointed to by 'cPtr' 

    int const * cPtr2 = &a; // Pointer to a constant integer (Stack)
    // *cPtr2 = 30; // Not allowed: modifying the value through the pointer
    cPtr2 = new int(30); // Allowed: changing the pointer itself
    std::cout << "Value Changed via cPtr2: " << *cPtr2 << " (Heap)\n"; // Prints the value pointed to by 'cPtr2'

    int const * const cPtr3 = &a; // Constant pointer to a constant integer (Stack)
    // *cPtr3 = 40; // Not allowed: modifying the value through the pointer
    // cPtr3 = new int(40); // Not allowed: changing the pointer itself

    return 0;
}

/* output
--- Basic Pointer Example ---
Value: 42 (Stack)
Pointer Address: 0x7fff1feab5d4 (Stack, points to Stack)
Pointer Dereference: 42 (Stack)
Modified Value through Pointer: 100 (Stack)

--- Null Pointer Example ---
nullPtr is null. (Stack)

--- Double Pointer Example ---
Address of ptr: 0x7fff1feab5e8 (Stack, points to Stack)
Value pointed by doublePtr: 100 (Stack)

--- Dynamic Memory Allocation Example ---
Dynamically Allocated Value: 55 (Heap)

--- Array and Pointer Relationship Example ---
Array Elements via Pointer:
1 2 3 4 5 

--- Constant Pointer Example ---
Modified Value via constPtr: 200 (Stack)

--- Pointer to Constant Example ---
Value via ptrToConst: 10 (Stack)

--- Constant Pointer to Constant Example ---
Value via constPtrToConst: 10 (Stack)

--- Complex Pointer Operations Example ---
Dynamically Allocated Array Elements:
10 20 30 40 50 

--- Smart Pointer (unique_ptr) Example ---
Value via smartPtr: 77 (Heap)

--- Pointer to Function Example ---
Result of add(5, 10) via funcPtr: 15 (Stack)

--- Pointer to Struct Example ---
Point coordinates via pointer: (3, 4) (Stack)

--- Stack vs. Heap Demonstration ---
Stack Allocation:
  - stackVar (int): Value = 10, Address = 0x7fff1feab4fc (Stack)
Heap Allocation:
  - heapVar (int*): Value = 20, Address = 0x564f1a7402e0 (Heap)
  - stackStructVar (struct): Value = {1, 2}, Address = 0x7fff1feab550 (Stack)
  - heapStructVar (struct*): Value = {3, 4}, Address = 0x564f1a7402e0 (Heap)
  - stackVector (std::vector): Values = {1 2 3 }, Address = 0x7fff1feab560 (Stack)
  - heapVector (std::vector*): Values = {4 5 6 }, Address = 0x564f1a740300 (Heap)
--- End of Stack vs. Heap Demonstration ---

--- Pointer to Class Example ---
Class object address: 0x7fff1feab690 (Stack)
Hello, my name is Camilo.
Hello, my name is Camilo.

--- Const Pointers Example ---
Value Changed via cPtr: 20 (Heap)
Value Changed via cPtr2: 30 (Heap)
*/