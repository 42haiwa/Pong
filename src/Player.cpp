#include "Player.h"

Player::Player(sf::Vector2f const & position) : PongEntity{position} {
    m_rectangle = sf::RectangleShape{sf::Vector2f{m_sizeX, m_sizeY}};
    m_rectangle.setFillColor(sf::Color::White);
    m_rectangle.setPosition(position);
}

void Player::update() {
    sf::Time dt = m_clock.restart();
    checkKeyboard(dt);
}

void Player::render(sf::RenderWindow & renderWindow) {
    renderWindow.draw(m_rectangle);
}

void Player::checkKeyboard(sf::Time dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_position.y -= m_speedMove * dt.asSeconds();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_position.y += m_speedMove * dt.asSeconds();
    }

    if (m_position.y < 0) m_position.y = 0;
    if (m_position.y > 600 - m_sizeY) m_position.y = 600 - m_sizeY;

    m_rectangle.setPosition(m_position);
}
