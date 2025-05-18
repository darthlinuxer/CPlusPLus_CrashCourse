# Templates in C++

This directory demonstrates template programming in C++:

- **Function Templates**: Generic functions that work with any data type.
- **Class Templates**: Generic classes for creating reusable components.
- **Template Specialization**: Custom behavior for specific types.
- **Variadic Templates**: Functions or classes that accept a variable number of template arguments.

### Parallels with C#

Templates in C++ are similar to C#'s generics, providing type safety and reusability. However, there are some key differences:

1. **Template Specialization**:
   - In C++, you can specialize templates for specific types to provide custom behavior.
   - In C#, generics do not support specialization, but you can achieve similar behavior using method overloading or type constraints.

2. **Variadic Templates**:
   - C++ supports variadic templates, allowing functions or classes to accept a variable number of template arguments.
   - In C#, you can use `params` for variable-length arguments, but it is not tied to generics.

3. **Compile-Time Evaluation**:
   - C++ templates are resolved at compile time, enabling powerful metaprogramming techniques.
   - C# generics are resolved at runtime (except for value types, which are resolved at compile time).

4. **Performance**:
   - C++ templates can lead to faster code due to compile-time optimizations.
   - C# generics are more flexible but may have a slight runtime overhead.

### Examples

#### Function Templates
C++:
```cpp
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}
```

C#:
```csharp
public static T FindMax<T>(T a, T b) where T : IComparable<T> {
    return (a.CompareTo(b) > 0) ? a : b;
}
```

#### Class Templates
C++:
```cpp
template <typename T>
class Box {
    T value;
public:
    Box(T val) : value(val) {}
    T getValue() const { return value; }
};
```

C#:
```csharp
public class Box<T> {
    private T value;
    public Box(T val) { value = val; }
    public T GetValue() { return value; }
}
```

#### Variadic Templates
C++:
```cpp
template <typename... Args>
auto sum(Args... args) {
    return (args + ...); // Fold expression
}
```

C#:
```csharp
public static int Sum(params int[] args) {
    return args.Sum();
}
```