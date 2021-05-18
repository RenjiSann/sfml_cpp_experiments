#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "utils.hpp"

using namespace sf;

class SimplePendulum
{
	public:
		SimplePendulum(float x, float y, float len, float angle, bool friction = false):
			/*
			 * x, y -> in pixels
			 * len -> in meters
			 * angle -> in radians
			 */
			_fixPoint{x,y},
			_bob{len * sinf(angle), len * cosf(angle)},
			_angle{angle},
			_angleVel{0},
			_len{len},
			_friction{friction} {};

		void update(float deltaTime);
		void draw(RenderWindow& rw, Color c);

		Vector2f getOrigin() const { return _fixPoint; };
		Vector2f getPos() const { return _bob + _fixPoint; };

	private:
		static constexpr float pixels_per_m{150};

		Vector2f _fixPoint;
		Vector2f _bob; // Location of the bob IN METERS
		float _angle;
		float _angleVel;
		float _len;
		bool _friction;
};

