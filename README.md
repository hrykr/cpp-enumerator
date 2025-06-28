# C++ Enumerator

Small header-only C++ function to mimic Python-style `enumerate()` ranges in for loops.\
Used to automatically get index and value when enumerating lists with   for loop.\
Function works simillar to Python's `enumerate()` or Rust's `iter().enumerate()`

## Example

```cpp
#include <enumerator.hpp>

std::vector<std::string> v = {"a", "b", "c"};
for (auto [i, value] : enumerator::enumerate(v)) {
    std::cout << "String " << value << " has index " << i << std::endl;
}
```
#### Output

```
String a has index 0
String b has index 1
String c has index 2
```

## Installation

Add this to `CMakeLists.txt`
```cmake
include(FetchContent)

FetchContent_Declare(
  enumerator
  GIT_REPOSITORY https://github.com/hrykr/cpp-enumerator.git
  GIT_TAG v1.0.0
)

FetchContent_MakeAvailable(enumerator)

target_link_libraries(my_app PRIVATE enumerator)
``` 

Then use it by

```cpp
#include <enumerator.hpp>
```