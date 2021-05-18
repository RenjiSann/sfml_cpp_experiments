#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

// Basic pendulum structure
struct Pendulum
{
	float l; // length
	float a; // angle
	float m; // mass
	float v; // angular velocity
	Vector2f pos;
	Color c = Color::White; // Bob color
};


// Base interface for Pendulums 
class IPendulum
{
	public:
		IPendulum() = default;
		~IPendulum() = default;
		virtual void update(float deltaT) = 0;
		virtual void draw(RenderWindow& rw) const = 0;
};

// Gravitational constant in m.s^(-2)
constexpr float GRAVITY{9.81};

// How many pixels should a meter be
constexpr float pixels_per_m{150};

// Draw a line on the window between points a and b, with given color
void drawLine(RenderWindow& win, 
		const Vector2f& a, 
		const Vector2f& b, 
		const Color& color = Color::White);

// Gives the lenth (in meters) of a pendulum such that its period
// matches the given one (in seconds)
float pendulumLength(float period);

