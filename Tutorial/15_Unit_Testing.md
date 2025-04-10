# Chapter 15: C++ Unit Testing

## 15.1 Introduction
Unit testing ensures that individual components of your program work as expected. This chapter explores unit testing frameworks like Google Test and Catch2.

---

## 15.2 Google Test
Google Test is a popular C++ testing framework.

### Example: Writing a Test with Google Test
```cpp
#include <gtest/gtest.h>
#include "utils.h"

TEST(AdditionTest, PositiveNumbers) {
    EXPECT_EQ(add(3, 4), 7);
}

TEST(AdditionTest, NegativeNumbers) {
    EXPECT_EQ(add(-3, -4), -7);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

---

## 15.3 Catch2
Catch2 is a lightweight testing framework.

### Example: Writing a Test with Catch2
```cpp
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "utils.h"

TEST_CASE("Addition works correctly", "[add]") {
    REQUIRE(add(3, 4) == 7);
    REQUIRE(add(-3, -4) == -7);
}
```

---

## 15.4 Best Practices
1. Write tests for all critical components.
2. Use descriptive test names.
3. Run tests frequently during development.

---

## 15.5 Exercises
1. Write unit tests for a function that calculates the factorial of a number.
2. Use Google Test to test a class that manages a collection of items.
3. Write Catch2 tests for a function that checks if a number is prime.

---

## 15.6 Summary
- Unit testing ensures the correctness of individual components.
- Google Test and Catch2 are popular frameworks for C++ unit testing.
- Follow best practices to write effective and maintainable tests.

---
