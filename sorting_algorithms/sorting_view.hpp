#pragma once

#include <SFML/Graphics.hpp>

#include "sortable.hpp"

using namespace sf;

class SortingView
{
public:
    SortingView(RenderWindow &rw, Sortable &s, const Color &base = Color::White,
                const Color &highlight = Color::Red)
        : rw{ rw }
        , data{ s }
        , base{ base }
        , highlight{ highlight } {};

    void updateDisplay() const;

private:
    RenderWindow &rw;
    Sortable &data;
    Color base;
    Color highlight;
};
