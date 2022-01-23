#include "pendulum_drawing.hpp"

void PendulumDot::update(float deltaTime)
{
    timeLeft -= deltaTime;
    auto x = 128.0 * (timeLeft / fadingTime);

    // Update alpha channel (transparency) of the color
    c.a = (int)x;
}

void PendulumDot::draw(RenderWindow &rw) const
{
    CircleShape cs{ radius };
    cs.setPosition(pixCoord - Vector2f{ radius, radius });
    cs.setFillColor(c);
    rw.draw(cs);
}

void PendulumDrawing::update(float deltaTime)
{
    for (size_t i{ 0 }; i < dots.size();)
    {
        dots[i].update(deltaTime);
        if (dots[i].isOutdated())
        {
            dots.erase(dots.begin() + i);
        }
        else
        {
            ++i;
        }
    }
}

void PendulumDrawing::draw(RenderWindow &rw) const
{
    for (auto dot : dots)
    {
        dot.draw(rw);
    }
}

void PendulumDrawing::addDot(const Vector2f &coord, const Color &c, float rad,
                             float fadingTime)
{
    dots.push_back(PendulumDot{ coord, rad, fadingTime, c });
}
