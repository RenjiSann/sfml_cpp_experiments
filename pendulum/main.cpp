#include <SFML/Graphics.hpp>
#include <vector>
#include "simple_pendulum.hpp"
#include "double_pendulum.hpp"


int main()
{
	sf::RenderWindow window(
			sf::VideoMode(640, 480), 
			"Hello World !"
			);


	Vector2f origin{(float) window.getSize().x / 2, (float) window.getSize().y / 3};
	Pendulum a{2, 2 * M_PI / 3, 1, 0, {0,0}, Color::Red};
	Pendulum b{2, 2 * M_PI / 3, 1, 0, {0,0}, Color::Blue};
	/*
	   std::vector<SimplePendulum> sp;
	   for(size_t i = 0; i < 30; ++i)
	   sp.push_back(SimplePendulum{(float) window.getSize().x / 2, 50, pendulumLength(60.0/(50+i)), M_PI / 6});
	   */
	DoublePendulum dp{origin, a, b};

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
			dp.update(dTime);
			dp.draw(window);
			/*
			   for(size_t i = 0; i < sp.size(); ++i)
			   {
			   sp[i].update(dTime);
			   sp[i].draw(window, sf::Color::Red);
			   }*/

			window.display();
		}
	}
	return EXIT_SUCCESS;
}

