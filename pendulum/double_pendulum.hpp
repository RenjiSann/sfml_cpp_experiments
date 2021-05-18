#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

#include "utils.hpp"

using namespace sf;


// Double pendulum solved using Runge-Kutta's method
class DoublePendulum : public IPendulum
{
	public:
		DoublePendulum(Vector2f& origin, Pendulum& p1, Pendulum& p2):
			fixPoint{origin}, p1{p1}, p2{p2} {};

		~DoublePendulum() = default;

		void update(float deltaTime) override;
		void draw(sf::RenderWindow& rw) const override;

		Vector2f getOrigin() const { return fixPoint; };

	private:
		Vector2f fixPoint;
		Pendulum p1;
		Pendulum p2;
};

