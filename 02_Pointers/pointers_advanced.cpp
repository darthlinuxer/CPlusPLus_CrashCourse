#include <iostream>
#include <string>

// Resource class
class Resource
{
public:
    Resource(std::string n) : name(n)
    {
        std::cout << "Resource created with name: " << name << std::endl;
    }

    std::string GetName() const { return name; }

    ~Resource()
    {
        std::cout << "Resource destroyed with name: " << name << std::endl;
    }

private:
    std::string name; // Holds the name of the resource
};

// Person class
class Person
{
public:
    Person() : pResource(nullptr) // Initialize pResource to nullptr
    {
        std::cout << "Person created" << std::endl;
    }

    /**
     * @brief Creates a new resource with the given name and assigns it to the global pointer `pResource`.
     *
     * Deletes the existing resource (if any) before assigning a new one.
     * This ensures no memory leaks but requires careful management of `pResource`.
     */
    void CreateResource(std::string name)
    {
        delete pResource;               // Free the existing resource to avoid memory leaks
        pResource = new Resource(name); // Allocate a new resource
    }

    std::string GetResourceName() const
    {
        return pResource ? pResource->GetName() : "No Resource"; // Return resource name or "No Resource" if null
    }

    // Note: The following methods are not needed in this example, but they are included to demonstrate copy/move semantics.
    // In a real-world scenario, you would want to implement these methods to manage the resource correctly.

    // Copy constructor and assignment operator are needed to manage the resource correctly.
    // If not defined, the default copy constructor and assignment operator will perform shallow copies,
    // leading to double deletion of the resource when both objects go out of scope.
    // This can cause undefined behavior and memory leaks.

    // Copy constructor
    // This constructor is used to create a new object as a copy of an existing object.
    // It is called when a new object is initialized with an existing object of the same type.
    Person(const Person &p)
    {
        // Deep copy the resource if it exists
        pResource = p.pResource ? new Resource(p.GetResourceName()) : nullptr;
        std::cout << "Person copied" << std::endl;
    }

    // Copy assignment operator
    // This operator is used to assign one object to another of the same type.
    // It is called when an object is assigned to another object of the same type.
    Person &operator=(const Person &p)
    {
        if (this != &p) // Avoid self-assignment
        {
            delete pResource; // Free the existing resource
            // Deep copy the resource if it exists
            pResource = p.pResource ? new Resource(p.GetResourceName()) : nullptr;
        }
        std::cout << "Person copy-assigned" << std::endl;
        return *this;
    }

    // Move constructor
    // This constructor is used to create a new object by transferring ownership of the resource from an existing object.
    // It is called when an object is initialized with an rvalue (temporary object) of the same type.
    // The existing object is left in a valid but unspecified state.
    // This is useful for optimizing performance by avoiding unnecessary copies.
    Person(Person &&p) noexcept : pResource(p.pResource) // Transfer ownership of the resource
    {
        // The move constructor takes an rvalue reference to another Person object.
        // This allows the constructor to "steal" the resource from the source object (p).
        p.pResource = nullptr; // Nullify the source pointer to avoid double deletion
        std::cout << "Person moved" << std::endl;
    }

    // Move assignment operator
    // This operator is used to assign one object to another by transferring ownership of the resource.
    // It is called when an object is assigned an rvalue (temporary object) of the same type.
    // The existing object is left in a valid but unspecified state.
    // This is useful for optimizing performance by avoiding unnecessary copies.
    // The noexcept specifier indicates that this function does not throw exceptions.
    Person &operator=(Person &&p) noexcept
    {
        // The move assignment operator takes an rvalue reference to another Person object.
        // This allows the operator to "steal" the resource from the source object (p).
        if (this != &p) // Avoid self-assignment
        {
            delete pResource;        // Free the existing resource
            pResource = p.pResource; // Transfer ownership of the resource
            p.pResource = nullptr;   // Nullify the source pointer
        }
        std::cout << "Person move-assigned" << std::endl;
        return *this;
    }

    ~Person()
    {
        delete pResource; // Free the resource to avoid memory leaks
        std::cout << "Person destroyed" << std::endl;
    }

private:
    Resource *pResource; // Raw pointer to manage the resource
};

// Scope class
class Scope
{
public:
    Scope(Person *person) : pPerson(person) // Takes ownership of the Person object
    {
        std::cout << "Scope created, managing Person object." << std::endl;
    }

    ~Scope()
    {
        delete pPerson; // Deletes the managed Person object
        std::cout << "Scope destroyed, Person object deleted." << std::endl;
    }

    Person *GetPerson() const
    {
        return pPerson; // Provides access to the managed Person object
    }

private:
    Person *pPerson; // Raw pointer to manage the Person object
};

// New PersonSmart class using std::unique_ptr
class PersonSmart
{
public:
    PersonSmart() = default; // Default constructor

    void CreateResource(std::string name)
    {
        pResource = std::make_unique<Resource>(name); // Allocate a new resource
    }

    std::string GetResourceName() const
    {
        return pResource ? pResource->GetName() : "No Resource"; // Return resource name or "No Resource" if null
    }

    // Destructor is no longer needed explicitly because std::unique_ptr handles cleanup automatically

private:
    std::unique_ptr<Resource> pResource; // Smart pointer to manage the resource
};

// Main function
int main()
{
    std::cout << "============================" << std::endl;
    std::cout << "Demonstrating Scope and PersonSmart" << std::endl;
    {
        Scope scope(new Person());                      // Create a Scope object managing a new Person object
        scope.GetPerson()->CreateResource("Resource1"); // Create a resource for the Person object

        // Demonstrate copy semantics
        Person copiedPerson = *scope.GetPerson();      // Copy the Person object by using the copy constructor
        copiedPerson.CreateResource("CopiedResource"); // Create a new resource for the copied Person

        // Demonstrate move semantics
        Person movedPerson = std::move(*scope.GetPerson()); // Move the Person object by using the move constructor
        movedPerson.CreateResource("MovedResource");        // Create a new resource for the moved Person

        //create more examples of move assigment and assigment operator
        Person anotherPerson;
        anotherPerson.CreateResource("AnotherResource"); // Create a resource for another Person object
        anotherPerson = std::move(movedPerson);         // Move assignment operator
        std::cout << "MovedPerson resource: " << movedPerson.GetResourceName() << std::endl; // Should be empty after move
        std::cout << "AnotherPerson resource: " << anotherPerson.GetResourceName() << std::endl; // Should show the moved resource

        // Accessing the original Person object after move is unsafe
        // Uncommenting the line below would lead to undefined behavior
        try
        {
            scope.GetPerson()->CreateResource("InvalidAccess"); // Unsafe access to a moved-from object
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n'; // Catch and print any exceptions
        }
    } // Scope goes out of scope, deleting the managed Person object

    std::cout << "\n--- Demonstrating PersonSmart ---\n";

    {
        // Demonstrate the new PersonSmart class
        PersonSmart smartPerson;
        smartPerson.CreateResource("SmartResource1"); // Create a resource for the smart person
        std::cout << "SmartPerson resource: " << smartPerson.GetResourceName() << std::endl;

        // No need to demonstrate copy/move semantics explicitly, as std::unique_ptr handles it automatically
        // If needed, you can move the smartPerson object like this:
        PersonSmart movedSmartPerson = std::move(smartPerson);
        std::cout << "MovedSmartPerson resource: " << movedSmartPerson.GetResourceName() << std::endl;
        std::cout << "SmartPerson resource after move: " << smartPerson.GetResourceName() << std::endl;
    } // smartPerson and movedSmartPerson go out of scope, and resources are automatically cleaned up

    std::cout << "End of main function" << std::endl;
    return 0;
}

/*
============================
Demonstrating Scope and PersonSmart       
Person created
Scope created, managing Person object.    
Resource created with name: Resource1     
Resource created with name: Resource1     
Person copied
Resource destroyed with name: Resource1   
Resource created with name: CopiedResource
Person moved
Resource destroyed with name: Resource1
Resource created with name: MovedResource
Person created
Resource created with name: AnotherResource
Resource destroyed with name: AnotherResource
Person move-assigned
MovedPerson resource: No Resource
AnotherPerson resource: MovedResource
Resource created with name: InvalidAccess
Resource destroyed with name: MovedResource
Person destroyed
Person destroyed
Resource destroyed with name: CopiedResource
Person destroyed
Resource destroyed with name: InvalidAccess
Person destroyed
Scope destroyed, Person object deleted.

--- Demonstrating PersonSmart ---
Resource created with name: SmartResource1
SmartPerson resource: SmartResource1
MovedSmartPerson resource: SmartResource1
SmartPerson resource after move: No Resource
Resource destroyed with name: SmartResource1
End of main function
*/