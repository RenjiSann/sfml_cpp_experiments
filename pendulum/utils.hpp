#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

// Gravitational constant in m.s^(-2)
constexpr float GRAVITY{9.81};

// Draw a line on the window between points a and b, with given color
void drawLine(RenderWindow& win, 
		const Vector2f& a, 
		const Vector2f& b, 
		const Color& color = Color::White);

// Gives the lenth (in meters) of a pendulum such that its period
// matches the given one (in seconds)
float pendulumLength(float period);

