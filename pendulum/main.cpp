#include <SFML/Graphics.hpp>
#include <vector>
#include "pendulum.hpp"


int main()
{
	sf::RenderWindow window(
			sf::VideoMode(640, 480), 
			"Hello World !"
			);

	std::vector<SimplePendulum> sp;
	for(size_t i = 0; i < 30; ++i)
		sp.push_back(SimplePendulum{(double) window.getSize().x / 2, 50, getLength(60.0/(50+i)), M_PI / 6});


	while(window.isOpen())
	{
		sf::Event event;
		sf::Clock clock;
		while(true)
		{
			if(window.pollEvent(event) && event.type == sf::Event::Closed)
			{
				window.close();
				break;
			}

			window.clear();

			double dTime = clock.restart().asSeconds();
			for(size_t i = 0; i < sp.size(); ++i)
			{
				sp[i].update(dTime);
				sp[i].draw(window, sf::Color::Red);
			}

			window.display();
		}
	}
	return EXIT_SUCCESS;
}

