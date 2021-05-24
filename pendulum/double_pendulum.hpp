#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

#include "utils.hpp"
#include "pendulum_drawing.hpp"

using namespace sf;


// Double pendulum solved using Runge-Kutta's method
class DoublePendulum : public IPendulum
{
	public:
		DoublePendulum(
				const Vector2f& origin, 
				PendulumDrawing& drawer,
				Pendulum& p1, 
				Pendulum& p2):
			IPendulum{origin}, 
			pdRef{drawer},
			p1{p1}, p2{p2} {};

		~DoublePendulum() = default;

		void update(float deltaTime) override;
		void draw(sf::RenderWindow& rw) const override;


	private:
		PendulumDrawing& pdRef;
		Pendulum p1;
		Pendulum p2;
};

