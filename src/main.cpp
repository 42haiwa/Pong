#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"

// TASK: Fix clock and pause

int main(void) {
	sf::RenderWindow window{sf::VideoMode{800, 600}, "Pong"};

	auto player = Player{sf::Vector2f{0, 300.f}};
	auto player2 = Player{sf::Vector2f{800.f - 20.f, 300.f}};
	auto ball = Ball{sf::Vector2f{400.f, 300.f}, &player, &player2};

	auto pause{false};

	while (window.isOpen()) {
		sf::Event event;

		while(window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyReleased:
					if (event.key.code == sf::Keyboard::Escape) {
						if (pause) {
							pause = false;
							break;
						}
						pause = true;
					}
					break;
				
				default:
					break;
			}
		}

		if (pause) continue;

		window.clear();

		ball.update();
		ball.render(window);

		player.update(sf::Keyboard::Z, sf::Keyboard::S);
		player.render(window);
		player2.update(sf::Keyboard::Up, sf::Keyboard::Down);
		player2.render(window);

		window.display();
	}

	return 0;
}
