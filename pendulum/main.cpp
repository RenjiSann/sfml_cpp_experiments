#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "simple_pendulum.hpp"
#include "double_pendulum.hpp"


int main(int argc, char** argv)
{
	sf::RenderWindow window(
			sf::VideoMode(640, 480), 
			"Hello World !"
			);

	Vector2f origin{(float) window.getSize().x / 2, (float) window.getSize().y / 10};

	Pendulum a{2, M_PI / 2, 1, 0, {0,0}, Color::Red};
	Pendulum b{2, 2 * M_PI / 3, 1, 0, {0,0}, Color::Blue};
	Pendulum c{2, 2 * M_PI / 3 * 1.000001, 1, 0, {0,0}, Color::Blue};
	DoublePendulum dp{origin, a, b};
	DoublePendulum dp2{origin, a, c};

	std::vector<std::shared_ptr<IPendulum>> sp;
	for(size_t i = 0; i < 30; ++i)
	{
		sp.push_back(
				std::make_shared<SimplePendulum>(
					SimplePendulum{
					origin, 
					{pendulumLength(60.0/(50+i)), M_PI / 6, 1, 0, {0,0}, 
					Color::Red}}));
	}

	sp.push_back(std::make_shared<DoublePendulum>(dp));
	sp.push_back(std::make_shared<DoublePendulum>(dp2));

	// Main loop
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
			//dp.update(dTime);
			//dp.draw(window);
			   for(size_t i = 0; i < sp.size(); ++i)
			   {
			   sp[i]->update(dTime);
			   sp[i]->draw(window);
			   }

			window.display();
		}
	}
	return EXIT_SUCCESS;
}

