#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

typedef sf::Vector2<double> vec2;

// Gravitational constant in m.s^(-2)
constexpr double GRAVITY{9.81};

class SimplePendulum
{
	public:
		SimplePendulum(double x, double y, double len, double angle, bool friction = false):
			/*
			 * x, y -> in pixels
			 * len -> in meters
			 * angle -> in radians
			 */
			_fixPoint{x,y},
			_bob{len * sin(angle), len * cos(angle)},
			_angle{angle},
			_angleVel{0},
			_len{len},
			_friction{friction} {};

		void update(double deltaTime);
		void draw(sf::RenderWindow& rw, sf::Color c);

		vec2 getOrigin() const { return _fixPoint; };
		vec2 getPos() const { return _bob + _fixPoint; };

	private:
		static constexpr double pixels_per_m{150};

		vec2 _fixPoint;
		vec2 _bob; // Location of the bob IN METERS
		double _angle;
		double _angleVel;
		double _len;
		bool _friction;
};


// Draw a line from a to b on the given render window
void drawLine(sf::RenderWindow& win, const sf::Vector2f& a, const sf::Vector2f& b);

// Return the size (in m) needed for a pendulum to have set period;
double getLength(double period);
