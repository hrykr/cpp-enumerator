#pragma once
#include <cstddef>
#include <ranges>
#include <utility>

namespace enumerator
{
    template <std::ranges::range T>
    inline auto enumerate(T& container)
    {
        struct iterator {
            std::size_t i;
            decltype(container.begin()) iter;

            bool operator!=(const iterator& other) const { return iter != other.iter; }
            void operator++() { ++i, ++iter; }
            auto operator*() const { return std::pair{ i, *iter }; }
        };

        struct iterable {
            T& container;

            auto begin() { return iterator{ 0, container.begin() }; }
            auto end() { return iterator{ 0, container.end() }; }
        }

        return iterable{ container };
    }
}