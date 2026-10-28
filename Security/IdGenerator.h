#pragma once
#include <type_traits>
#include <cstddef>
using namespace std;

class Person;
class Item;
class Order;
class Publisher;

class IdGenerator {
    static size_t personCount;
    static size_t itemCount;
    static size_t orderCount;
    static size_t publisherCount;
public:
    template<typename T> static void generate(T* O) {
        int id;
        if constexpr (std::is_base_of_v<Person, T>) id = 1 * 10000 + static_cast<int>(++personCount);
        else if constexpr (std::is_base_of_v<Item, T>) id = 2 * 10000 + static_cast<int>(++itemCount);
        else if constexpr (std::is_base_of_v<Order, T>) id = 3 * 10000 + static_cast<int>(++orderCount);
        else if constexpr (std::is_base_of_v<Publisher, T>) id = 4 * 10000 + static_cast<int>(++publisherCount);
        else { static_assert(sizeof(T) == 0, "Invalid type"); return; }

        O->setId(id);
    }
};

