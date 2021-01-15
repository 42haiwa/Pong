#include "Ball.h"

#include <iostream>

Ball::Ball(sf::Vector2f const & position, Player * player1, Player * player2) : PongEntity{position} {
    m_rectangle = sf::RectangleShape{sf::Vector2f{m_size, m_size}};
    m_rectangle.setPosition(m_position);

    m_player1 = player1;
    m_player2 = player2;

    m_angle = 45.f;
}

void Ball::update() {
    sf::Time dt = m_clock.restart();
    move(dt);
}

void Ball::render(sf::RenderWindow & renderWindow) {
    renderWindow.draw(m_rectangle);
}

void Ball::move(sf::Time dt) {
    m_position.x += m_speedMoveX * dt.asSeconds() * (cos((m_angle) * M_PI / 180));
    m_position.y += m_speedMoveY * dt.asSeconds() * (sin((m_angle) * M_PI / 180));

    if (m_position.x < 0) m_speedMoveX *= -1;
    if (m_position.x > 800 - m_size) m_speedMoveX *= -1;
    if (m_position.y < 0) m_speedMoveY *= -1;
    if (m_position.y > 600 - m_size) m_speedMoveY *= -1;

    std::cout << "Player 1: X: " << m_player1->getX() << " Y: " << m_player1->getY() << std::endl;
    std::cout << "Player 2: X: " << m_player2->getX() << " Y: " << m_player2->getY() << std::endl;

    m_rectangle.setPosition(m_position);
}
