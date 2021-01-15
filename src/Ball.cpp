#include "Ball.h"

Ball::Ball(sf::Vector2f const & position) : PongEntity{position} {
    m_rectangle = sf::RectangleShape{sf::Vector2f{m_size, m_size}};
    m_rectangle.setPosition(m_position);
}

void Ball::update() {
}

void Ball::render(sf::RenderWindow & renderWindow) {
    renderWindow.draw(m_rectangle);
}
