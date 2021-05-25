#include "double_pendulum.hpp"


void DoublePendulum::update(float deltaT)
{
	// Find angular accelerations thanks to
	// https://www.myphysicslab.com/pendulum/double-pendulum-en.html
	float DENUM = 2 * p1.m + p2.m - p2.m * cosf(2 * (p1.a - p2.a));
	
	float n1 = - GRAVITY * (2 * p1.m + p2.m) * sinf(p1.a);
	float n2 = - GRAVITY * p2.m * sinf(p1.a - 2 * p2.a);
	float n3 = - 2 * sinf(p1.a - p2.a) * p2.m;
	float n4 = p2.v * p2.v * p2.l + p1.v * p1.v * p1.l * cosf(p1.a - p2.a);
	float acc1 = (n1 + n2 + n3 * n4) / (p1.l * DENUM);


	float n5 = 2 * sinf(p1.a - p2.a);
	float n6 = p1.v * p1.v * p1.l * (p1.m + p2.m);
	float n7 = GRAVITY * (p1.m + p2.m) * cosf(p1.a);
	//float n7 = - GRAVITY * (p1.m + p2.m) * cosf(p1.a);
	float n8 = p2.v * p2.v * p2.l * p2.m * cosf(p1.a - p2.a);
	// acc2 = (n5 * (n6 + n7 + n8)) / (p2.l * DENUM)
	float acc2 = (n5 * (n6 + n7 + n8)) / (p2.l * DENUM);

	p1.v += acc1 * deltaT;
	p2.v += acc2 * deltaT;
	
	p1.a += p1.v * deltaT;
	p2.a += p2.v * deltaT;

	// Move the position of the pendulums
	p1.pos.x = p1.l * sinf(p1.a);
	p1.pos.y = p1.l * cosf(p1.a);

	p2.pos.x = p2.l * sinf(p2.a);
	p2.pos.y = p2.l * cosf(p2.a);

	pdRef.update(deltaT);
}

void DoublePendulum::draw(RenderWindow& rw) const
{
	float fadingTime = 1.0;
	float radius = 10.0;
	Vector2f v1 = pixels_per_m * p1.pos + fixPoint;
	Vector2f v2 = v1 + pixels_per_m * p2.pos;
	
	drawLine(rw, fixPoint, v1, Color(100,100,100));
	drawLine(rw, v1, v2, Color(100,100,100));

	pdRef.addDot(v1, p1.c, radius, 0);
	pdRef.addDot(v2, p2.c, radius, fadingTime);
	pdRef.draw(rw);
	/*
	CircleShape c1{10};
	c1.setFillColor(p1.c);
	c1.setPosition(v1.x - 10, v1.y - 10);
	rw.draw(c1);

	CircleShape c2{10};
	c2.setFillColor(p2.c);
	c2.setPosition(v2.x - 10, v2.y - 10);
	rw.draw(c2);
	*/
}
