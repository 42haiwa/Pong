#include "Player.h"

Player::Player(sf::Vector2f const & position) : PongEntity{position} {
    m_rectangle = sf::RectangleShape{sf::Vector2f{20.f, 120.f}};
    m_rectangle.setFillColor(sf::Color::White);
}

void Player::update() {

}

void Player::render(sf::RenderWindow & renderWindow) {
    renderWindow.draw(m_rectangle);
}
