#include <SFML/Graphics.hpp>
#include "Player.h"

int main(void) {
	sf::RenderWindow window{sf::VideoMode{800, 600}, "Pong"};

	auto player = Player{sf::Vector2f{0, 300.f}};
	auto player2 = Player{sf::Vector2f{800.f - 20.f, 300.f}};

	while (window.isOpen()) {
		sf::Event event;

		while(window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyReleased:
					if (event.key.code == sf::Keyboard::Escape) {
						window.close();
					}
					break;
				
				default:
					break;
			}
		}

		window.clear();

		player.update(sf::Keyboard::Z, sf::Keyboard::S);
		player.render(window);
		player2.update(sf::Keyboard::Up, sf::Keyboard::Down);
		player2.render(window);

		window.display();
	}

	return 0;
}
