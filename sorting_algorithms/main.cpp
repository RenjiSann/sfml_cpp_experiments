#include <iostream>

#include "insertion_sort_strategy.hpp"
#include "sortable.hpp"
#include "sorting_view.hpp"

int main()
{
    Sortable x{ 100 };
    x.show();
    std::cout << '\n';
    sf::RenderWindow rw{ VideoMode(640, 480), "Sorting" };

    auto sv = SortingView(rw, x);
    auto strat = InsertionSortStrategy(sv, x);

    while (rw.isOpen())
    {
        sf::Event event;
        while (rw.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                rw.close();
        }
        strat.run();
        x.shuffle();
    }
}
