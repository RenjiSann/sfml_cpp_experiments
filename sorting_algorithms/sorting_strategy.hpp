#pragma once

#include <SFML/Graphics.hpp>

#include "sortable.hpp"
#include "sorting_view.hpp"

class SortingStrategy
{
public:
    SortingStrategy(SortingView &v, Sortable &data)
        : sview{ v }
        , data{ data } {};

    ~SortingStrategy() = default;

    virtual void run() const = 0;

protected:
    SortingView &sview;
    Sortable &data;
};
