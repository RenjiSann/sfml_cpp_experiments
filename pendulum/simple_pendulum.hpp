#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "utils.hpp"

using namespace sf;

class SimplePendulum : IPendulum
{
	public:
		SimplePendulum(const Vector2f& origin, const Pendulum& p, bool friction = false):
			/*
			 * origin -> fix point coordinates in pixels
			 * len -> in meters
			 * angle -> in radians
			 */
			fixPoint{origin},
			p{p},
			friction{friction} {};

		void update(float deltaTime) override;
		void draw(RenderWindow& rw) const override;

		//Vector2f getOrigin() const { return _fixPoint; };
		//Vector2f getPos() const { return fixPoint + ; };

	private:
		
		Vector2f fixPoint;
		Pendulum p;
		bool friction;
		/*
		Vector2f _bob; // Location of the bob IN METERS
		float _angle;
		float _angleVel;
		float _len;
		*/
};

