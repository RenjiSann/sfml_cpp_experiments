#include "double_pendulum.hpp"

void drawLine(sf::RenderWindow& win, const sf::Vector2f& a, const sf::Vector2f& b) 
{
	sf::Vertex lines[2]
	{
		sf::Vertex{a},
		sf::Vertex{b}
	};
	win.draw(lines, 2, sf::Lines);
}


void DoublePendulum::update(float deltaT)
{
}
