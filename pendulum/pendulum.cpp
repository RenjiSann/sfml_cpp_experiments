#include "pendulum.hpp"

void SimplePendulum::update(float deltaTime)
{
	// Compute the angular acceleration
	float angleA = - GRAVITY * sinf(_angle)	/ _len;

	// Modify the angular velocity and angle
	_angleVel += angleA * deltaTime;
	_angle += _angleVel * deltaTime;

	// Apply to the bob's position
	_bob.x = _len * sinf(_angle) * SimplePendulum::pixels_per_m;
	_bob.y = _len * cosf(_angle) * SimplePendulum::pixels_per_m;

	// reduce speed by 1% factor if friction taken in account
	if(_friction)
		_angleVel *= (1 - deltaTime * 0.01);
}


void SimplePendulum::draw(RenderWindow& rw, Color c = Color::Red)
{
	drawLine(rw, Vector2f{_fixPoint}, Vector2f{getPos()}, Color(100,100,100));
	CircleShape bob{20};
	bob.setPosition((unsigned int) getPos().x-20, (unsigned int) getPos().y-20);
	bob.setFillColor(c);
	rw.draw(bob);

}
