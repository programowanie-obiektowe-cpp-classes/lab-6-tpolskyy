#pragma once

#include "Human.hpp"
#include <algorithm>
#include <list>
#include <vector>

std::vector<char> foo(std::list<Human>& people) {
    std::vector<char> retval(people.size());

    // Inkrementacja wieku wszystkich obiektów
    std::for_each(people.begin(), people.end(), [](Human& h) { h.birthday(); });

    // Przypisanie wartości do wektora wynikowego bez lambdy w transform
    auto it = retval.rbegin();
    std::for_each(people.begin(), people.end(), [&it](const Human& h) {
        *it++ = h.isMonster() ? 'n' : 'y';
    });

    return retval;
}