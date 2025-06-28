#include "enumerator.hpp"
#include <vector>
#include <string>
#include <cassert>

int main() {
    std::vector<std::string> v = {"a", "b", "c"};
    int expected = 0;
    for (auto [i, value] : enumerator::enumerate(v)) {
        assert(i == expected);
        ++expected;
    }
}