#include "pendulum.hpp"

void SimplePendulum::update(double deltaTime)
{
	// Compute the angular acceleration
	double angleA = - GRAVITY * sin(_angle)	/ _len;

	// Modify the angular velocity and angle
	_angleVel += angleA * deltaTime;
	_angle += _angleVel * deltaTime;

	// Apply to the bob's position
	_bob.x = _len * sin(_angle) * SimplePendulum::pixels_per_m;
	_bob.y = _len * cos(_angle) * SimplePendulum::pixels_per_m;

	// reduce speed by 1% factor if friction taken in account
	if(_friction)
		_angleVel *= (1 - deltaTime * 0.01);
}


void SimplePendulum::draw(sf::RenderWindow& rw, sf::Color c = sf::Color::Red)
{
	drawLine(rw, sf::Vector2f{_fixPoint}, sf::Vector2f{getPos()});
	sf::CircleShape bob{20};
	bob.setPosition((unsigned int) getPos().x-20, (unsigned int) getPos().y-20);
	bob.setFillColor(c);
	rw.draw(bob);

}


void drawLine(sf::RenderWindow& win, const sf::Vector2f& a, const sf::Vector2f& b) 
{
	sf::Vertex lines[2]
	{
		sf::Vertex{a},
		sf::Vertex{b}
	};
	win.draw(lines, 2, sf::Lines);
}


double getLength(double period)
{
	return period*period*4*M_PI*M_PI / GRAVITY;
}
