# C++ Collections

This directory contains examples demonstrating various collection types available in the C++ Standard Template Library (STL):

## Array-Based Collections

- **01_arrays.cpp**: Demonstrates both C-style arrays and the safer `std::array` container, including initialization, access methods, and size calculations.

- **02_vector.cpp**: Shows how to use `std::vector`, a dynamic array that can resize itself automatically. Examples include adding elements, accessing, modifying, resizing, capacity management, sorting, and using iterators.

## List-Based Collections

- **03_list_example.cpp**: Explores `std::list`, a doubly-linked list that allows efficient insertions and deletions at any position. Demonstrates operations like push_front/back, insertion, removal, splicing, and list-specific algorithms.

## Set-Based Collections

- **04_set_example.cpp**: Demonstrates `std::set`, an ordered collection that stores unique elements according to a specific ordering. Covers initialization, insertion, searching, removal, and set algorithms.

- **11_unordered_set_example.cpp**: Shows the use of `std::unordered_set`, a hash table implementation that stores unique elements in no particular order, providing average constant-time operations.

## Map-Based Collections

- **05_map_example.cpp**: Illustrates `std::map`, an ordered key-value container that stores elements in key order. Examples include insertion, accessing elements with operator[] and at(), searching, and iterating.

- **06_multimap_example.cpp**: Demonstrates `std::multimap`, an ordered map that allows multiple entries with the same key.

- **10_unordered_map_example.cpp**: Shows `std::unordered_map`, a hash table implementation that stores key-value pairs in no particular order, providing average constant-time operations.

## Double-Ended Queue

- **07_deque_example.cpp**: Explores `std::deque` (double-ended queue), a sequence container with dynamic size that can expand/contract at both ends, supporting efficient insertion/deletion at both the beginning and end.

## Stack and Queue Adaptors

- **08_stack_example.cpp**: Demonstrates `std::stack`, a container adaptor that gives LIFO (Last-In, First-Out) behavior, using the underlying container for element storage.

- **09_queue_example.cpp**: Shows `std::queue`, a container adaptor that gives FIFO (First-In, First-Out) behavior, also using an underlying container for storage.

## Key Points About Collections

- Each collection has specific performance characteristics for different operations
- Choose the appropriate collection type based on your specific needs
- Consider factors like:
  - Element access patterns (random vs sequential)
  - Frequency of insertions and deletions
  - Whether ordering is important
  - Memory usage requirements
  - Need for key-value associations