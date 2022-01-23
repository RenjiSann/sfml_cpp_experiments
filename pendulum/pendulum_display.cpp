#include "pendulum_display.hpp"

PendulumDisplay::PendulumDisplay(const Vector2f &size, bool trace)
    : keepTrace{ trace }
{
    periodlayer.create(size.x, size.y);

    if (trace)
    {
        fixLayer.create(size.x, size.y);
    }
}

void PendulumDisplay::clearTrace()
{
    if (keepTrace)
    {
        fixLayer.clear();
    }
}

void PendulumDisplay::drawTo(RenderWindow &rw)
{
    Sprite fix{ fixLayer.getTexture() };
    Sprite per{ periodlayer.getTexture() };

    rw.draw(fix);
    rw.draw(per);

    // After drawing, clear the periodic buffer
    periodlayer.clear();
}

void PendulumDisplay::addDot(const Vector2f &pos, const Color &c, bool trace)
{
    CircleShape cs{ PendulumDisplay::dotRadius };
    cs.setPosition(pos - (Vector2f{ 1, 1 } * PendulumDisplay::dotRadius));
    cs.setFillColor(c);
    periodlayer.draw(cs);

    // Add a trace for the point
    if (trace && keepTrace)
    {
        Color fadedColor{ c.r, c.g, c.b, PendulumDisplay::traceOpacity };
        cs.setPosition(pos - (Vector2f{ 1, 1 } * PendulumDisplay::traceRadius));
        fixLayer.draw(cs);
    }
}

void PendulumDisplay::setSize(const Vector2f &size)
{
    // TODO
}
