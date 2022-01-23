#include "utils.hpp"

void drawLine(RenderWindow &win, const Vector2f &a, const Vector2f &b,
              const Color &color)
{
    sf::Vertex lines[2]{ sf::Vertex{ a, color }, sf::Vertex{ b, color } };
    win.draw(lines, 2, sf::Lines);
}

float pendulumLength(float period)
{
    return period * period * 4 * M_PI * M_PI / GRAVITY;
}

void matchWindowView(RenderWindow &rw)
{
    Vector2f size{ rw.getSize() };
    Vector2f center{ size.x / 2, size.y / 2 };
    rw.setView(sf::View(center, size));
}
