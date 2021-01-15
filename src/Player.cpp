#include "Player.h"

Player::Player(sf::Vector2f const & position) : PongEntity{position} {
    m_rectangle = sf::RectangleShape{sf::Vector2f{m_sizeX, m_sizeY}};
    m_rectangle.setFillColor(sf::Color::White);
    m_rectangle.setPosition(m_position);
}

void Player::update() {
}

void Player::update(sf::Keyboard::Key upKey, sf::Keyboard::Key downKey) {
    update();
    sf::Time dt = m_clock.restart();
    checkKeyboard(dt, upKey, downKey);
}

void Player::render(sf::RenderWindow & renderWindow) {
    renderWindow.draw(m_rectangle);
}

void Player::checkKeyboard(sf::Time dt, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey) {
    if (sf::Keyboard::isKeyPressed(upKey)) {
        m_position.y -= m_speedMove * dt.asSeconds();
    }

    if (sf::Keyboard::isKeyPressed(downKey)) {
        m_position.y += m_speedMove * dt.asSeconds();
    }

    if (m_position.y < 0) m_position.y = 0;
    if (m_position.y > 600 - m_sizeY) m_position.y = 600 - m_sizeY;

    m_rectangle.setPosition(m_position);
}

float Player::getX() const {
    return m_position.x;
}

float Player::getY() const {
    return m_position.y;
}

sf::RectangleShape Player::getRect() const {
    return m_rectangle;
}
