# C++ Enumerator

Small header-only C++ function to mimic Python-style `enumerate()` ranges in for loops.\
Used to automatically get index and value when enumerating lists with   for loop.\
Function works simillar to Python's `enumerate()` or Rust's `.iter().enumerate()`

## Example

```c++
#include "enumerator.hpp"

std::vector<std::string> v = {"a", "b", "c"};
for (const auto& [i, value] : enumerator::enumerate(v)) {
    std::cout << "String " << value << " has index " << i << std::endl;
}
```
>### Output
>```
>String a has index 0
>String b has index 1
>String c has index 2
>```

## Installation 
> ### 1. Using CMake 
> ```cmake
> FetchContent_Declare(
>         enumerator
>         GIT_REPOSITORY https://github.com/hrykr/cpp-enumerator.git
>         GIT_TAG v1.2.0
> )
> FetchContent_MakeAvailable(enumerator)
> 
> # Your add_executable or add_library
> target_link_libraries(your_project PRIVATE enumerator::enumerator)
> ```
> Then use it by:
> ```c++
> #include <enumerator/enumerator.hpp>
> ```

>### 2. Copy to project
> Copy `include/enumerator/` into your project
> 
> Then use it by:
> ```c++
> #include "enumerator/enumerator.hpp"
> ```