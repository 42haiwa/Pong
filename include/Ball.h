#ifndef __BALL__H__
#define __BALL__H__

#include <SFML/Graphics.hpp>
#include "PongEntity.h"

class Ball : public PongEntity {
    private:
        sf::RectangleShape m_rectangle;

        static constexpr float m_size{15.f};

    public:
        Ball(sf::Vector2f const & position);
        void update();
        void render(sf::RenderWindow & renderWindow);
};

#endif
