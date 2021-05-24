#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class PendulumDot
{
	public:
		PendulumDot(const Vector2f& coord, float radius, float fadingTime, const Color& c):
			pixCoord{coord},
			radius{radius},
			fadingTime{fadingTime},
			timeLeft{fadingTime},
			c{c} {};

		void update(float deltaTime); 
		void draw(RenderWindow& rw) const;

		bool isOutdated() const {return timeLeft <= 0; };

	private:
		Vector2f pixCoord;
		float radius;
		float fadingTime;
		float timeLeft;
		Color c;
};

class PendulumDrawing
{
public:
	PendulumDrawing() = default;
	~PendulumDrawing() = default;

	void update(float deltaTime);
	void draw(RenderWindow& rw) const;
	void addDot(const Vector2f& coord, const Color& c, float rad, float fadingTime);

private:
	std::vector<PendulumDot> dots;
};
