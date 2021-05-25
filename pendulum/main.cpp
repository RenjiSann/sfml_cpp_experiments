#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "simple_pendulum.hpp"
#include "double_pendulum.hpp"
#include "pendulum_drawing.hpp"


int main(int argc, char** argv)
{
	sf::RenderWindow window(
			sf::VideoMode(640, 480), 
			"Hello World !"
			);

	Vector2f origin{window.getSize()};
	PendulumDrawing pd{};

	Pendulum a{2, M_PI , 1, 0, {0,0}, Color::Red};
	Pendulum b{2, 2 * M_PI / 3, 1, 0, {0,0}, Color::Blue};
	Pendulum c{2, 2 * M_PI / 3, 1, 0, {0,0}, Color::Green};
	DoublePendulum dp{origin, pd, a, b};
	DoublePendulum dp2{origin, pd, a, c};

	std::vector<std::shared_ptr<IPendulum>> sp;
	//for(size_t i = 0; i < 30; ++i)
	for(size_t i = 0; i < 0; ++i)
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
			// Event handling
			if(window.pollEvent(event))
			{
				if(sf::Event::Closed == event.type)
				{
					window.close();
					break;
				}
				if(sf::Event::Resized == event.type)
				{		
					Vector2f s{window.getSize()};
					// Resize the view of the window
					matchWindowView(window);

					// Move the center of every pendulum to the new center
					for(size_t i = 0; i < sp.size(); ++i)
					{
						Vector2f origin{s};
						origin.x /= 2.0;
						origin.y /= 10.0;
						sp[i]->setOrigin(origin);
					}
				}
			}

			// Clear the current pendulums
			window.clear();

			// Find the time elapsed since last frame
			double dTime = clock.restart().asSeconds();
			std::cout << dTime << std::endl;

			// Update every pendulum
			for(size_t i = 0; i < sp.size(); ++i)
			{
				sp[i]->update(dTime);
				sp[i]->draw(window);
			}

			// Display the built img on the screen
			window.display();
		}
	}
	return EXIT_SUCCESS;
}

