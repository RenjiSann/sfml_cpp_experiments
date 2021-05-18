#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;

struct Pendulum
{
	float len;
	float angle;
	float mass;
	Vector2f pos;
};

class DoublePendulum
{
public:
	DoublePendulum(Vector2f& origin, Pendulum& p1, Pendulum& p2):
		fixPoint{origin}, p1{p1}, p2{p2} {};
	
	void update(float deltaTime);
	void draw(sf::RenderWindow& rw) const;

	Vector2f getOrigin() const { return fixPoint; };

private:
	Vector2f fixPoint;
	Pendulum p1;
	Pendulum p2;
};

void drawLine(RenderWindow& win, const Vector2f& a, const Vector2f& b);
