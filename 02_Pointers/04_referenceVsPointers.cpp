#include <iostream> // For std::cout and std::endl

/*
Reference & and * Pointers :
Reference is an alias for an existing variable, while a pointer is a variable that stores the address of another variable.
References cannot be null and must be initialized when declared, while pointers can be null and can be reassigned to point to different variables.
References are automatically dereferenced when used, while pointers require explicit dereferencing using the * operator.
References cannot be reassigned to refer to a different variable after initialization, while pointers can be reassigned to point to different variables.
References are generally safer and easier to use than pointers, as they do not require manual memory management and do not have the risk of dangling pointers.
*/

class referencemember
{
private:
	int &ri; // Reference to an integer
public:
	referencemember(int &j) : ri(j) {} // Constructor initializes the reference
	referencemember(const referencemember &rm) : ri(rm.ri) {} // Copy constructor (reference still points to j)
	referencemember& operator=(const referencemember &rm) = delete; // Copy assignment operator is deleted
	int reportvalue() { return ri; }   // Returns the value of the referenced integer
};

class pointermember
{
private:
	int *pi = nullptr; // Pointer to an integer, initialized to nullptr
public:
	pointermember(int *pj) : pi(pj) {} // Constructor initializes the pointer
	pointermember(const pointermember &pm) : pi(pm.pi) {} // Copy constructor (pointer still points to j)
	int reportvalue()
	{
		if (pi)
		{
			return *pi; // Dereference the pointer if it's not null
		}
		else
		{
			return -9999; // Return a default value if the pointer is null
		}
	}
	void setpointer(int *newpointer) { pi = newpointer; } // Update the pointer
};

int main()
{
	std::cout << "============================" << std::endl;
	std::cout << "Reference vs Pointer Example" << std::endl;
	std::cout << "============================" << std::endl;
	int i = 0;
	int &ri = i;											  // Reference to i, ri is now an alias to i
	ri++;													  // Increment i through the reference, it is the same as doing i++
	std::cout << "Value of i after ri++: " << i << std::endl; // result is 1

	int j = 3;
	ri = j;														// ri will always reference i, so ri=j means i is now equal to j's value
	std::cout << "Value of i after ri = j: " << i << std::endl; // result is 3

	// int k = 5;
	//&ri = k; // This line will cause a compilation error because references cannot be reassigned

	int *pi = &i;											   // Pointer to i initialized with the address of i
	int k = *pi;											   // Dereference the pointer to get the value of i
	std::cout << "Value of k (copy of i): " << k << std::endl; // result is 3
	std::cout << "Address of i: " << &i << std::endl;		   // Address of i
	std::cout << "Address of k: " << &k << std::endl;		   // Address of k

	*pi = 7;													 // Modify i through the pointer
	std::cout << "Value of i after *pi = 7: " << i << std::endl; // result is 7

	(*pi)++;													 // Increment i through the pointer
	std::cout << "Value of i after (*pi)++: " << i << std::endl; // result is 8

	pi = &j;																	   // Pointer pi now has the address of j
	std::cout << "Pointer pi now points to j, value of *pi: " << *pi << std::endl; // result is 3

	pi = nullptr; // Set pointer to null
	if (pi)
	{
		(*pi)++; // This block won't execute because pi is null
	}
	else
	{
		std::cout << "Pointer pi is null, skipping dereference." << std::endl;
	}

	referencemember rm(j);																	 // Reference member initialized with j
	std::cout << "Value of j through referencemember rm: " << rm.reportvalue() << std::endl; // result is 3

	referencemember rm2 = rm;																   // Copy constructor (reference still points to j)
	std::cout << "Value of j through referencemember rm2: " << rm2.reportvalue() << std::endl; // result is 3

	// rm = rm2; // compilation error: function "referencemember::operator=(const referencemember &)" (declared implicitly) cannot be referenced -- it is a deleted function

	pointermember pm(&j);																   // Pointer member initialized with address of j
	std::cout << "Value of j through pointermember pm: " << pm.reportvalue() << std::endl; // result is 3

	pointermember pm2 = pm;																	 // Copy constructor (pointer still points to j)
	std::cout << "Value of j through pointermember pm2: " << pm2.reportvalue() << std::endl; // result is 3

	pm.setpointer(&i);																						// Update pointer in pm to point to i
	std::cout << "Value of i through pointermember pm after setpointer: " << pm.reportvalue() << std::endl; // result is 8

	pm = pm2;																								// Assignment operator (pointer in pm now points to j again)
	std::cout << "Value of j through pointermember pm after assignment: " << pm.reportvalue() << std::endl; // result is 3

	pointermember uninit(nullptr);														 // Pointer member initialized with nullptr
	int what = uninit.reportvalue();													 // Attempt to dereference null pointer
	std::cout << "Value reported by uninitialized pointermember: " << what << std::endl; // result is -9999

	return 0;
}

/*
============================
Reference vs Pointer Example
============================
Value of i after ri++: 1
Value of i after ri = j: 3
Value of k (copy of i): 3
Address of i: 00F3FA08
Address of k: 00F3F9F8
Value of i after *pi = 7: 7
Value of i after (*pi)++: 8
Pointer pi now points to j, value of *pi: 3
Pointer pi is null, skipping dereference.
Value of j through referencemember rm: 3
Value of j through referencemember rm2: 3
Value of j through pointermember pm: 3
Value of j through pointermember pm2: 3
Value of i through pointermember pm after setpointer: 8
Value of j through pointermember pm after assignment: 3
Value reported by uninitialized pointermember: -9999
*/