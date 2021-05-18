#include "simple_pendulum.hpp"

void SimplePendulum::update(float deltaTime)
{
	// Compute the angular acceleration
	float angleA = - GRAVITY * sinf(p.a) / p.l;

	// Modify the angular velocity and angle
	p.v += angleA * deltaTime;
	p.a += p.v * deltaTime;

	// Apply to the bob's position
	p.pos.x = p.l * sinf(p.a);
	p.pos.y = p.l * cosf(p.a);

	// reduce speed by 1% factor if friction taken in account
	if(friction)
		p.v *= (1 - deltaTime * 0.01);
}


void SimplePendulum::draw(RenderWindow& rw) const
{
	Vector2f pixPos = p.pos * pixels_per_m + fixPoint;
	drawLine(rw, fixPoint, pixPos, Color(100,100,100));
	CircleShape bob{20};
	bob.setPosition((unsigned int) pixPos.x-20, (unsigned int) pixPos.y-20);
	bob.setFillColor(p.c);
	rw.draw(bob);

}
