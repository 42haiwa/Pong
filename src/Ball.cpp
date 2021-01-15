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
    if (checkCollision(m_player1)) m_speedMoveX *= -1;
    if (checkCollision(m_player2)) m_speedMoveX *= -1;

    m_position.x += m_speedMoveX * dt.asSeconds() * (cos((m_angle) * M_PI / 180));
    m_position.y += m_speedMoveY * dt.asSeconds() * (sin((m_angle) * M_PI / 180));

    //if (m_position.x < 0) m_speedMoveX *= -1;
    //if (m_position.x > 800 - m_size) m_speedMoveX *= -1;
    if (m_position.y < 0) m_speedMoveY *= -1;
    if (m_position.y > 600 - m_size) m_speedMoveY *= -1;

    m_rectangle.setPosition(m_position);
}

bool Ball::checkCollision(Player * player) {
    sf::Vector2f rect1 = m_rectangle.getPosition();
    sf::Vector2f rect2 = player->getRect().getPosition();

    if (rect1.x < rect2.x + 20.f && rect1.x + 15.f > rect2.x && rect1.y < rect2.y + 120.f && 15.f + rect1.y > rect2.y) {
        std::cout << "Collision !" << std::endl;
        return true;    
    }

    return false;
}
