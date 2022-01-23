#include "sorting_view.hpp"

void SortingView::updateDisplay() const
{
    // Find width of rectangles
    int width = rw.getSize().x / data.getCount();

    rw.clear();

    for (size_t i{ 0 }; i < data.getCount(); ++i)
    {
        float height_ratio = data[i] / (float)data.max;
        RectangleShape r{ { (float)width, height_ratio * rw.getSize().y } };
        r.setPosition(
            { (float)i * width, rw.getSize().y * (1 - height_ratio) });
        rw.draw(r);
    }
    rw.display();
}
