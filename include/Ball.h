#ifndef __BALL__H__
#define __BALL__H__

#include <SFML/Graphics.hpp>
#include <math.h>
#include "PongEntity.h"

class Ball : public PongEntity {
    private:
        sf::RectangleShape m_rectangle;

        float m_angle{0.f};
        float m_speedMoveX{500.f};
        float m_speedMoveY{500.f};

        static constexpr float m_size{15.f};

    public:
        Ball(sf::Vector2f const & position);
        void update();
        void render(sf::RenderWindow & renderWindow);
        void move(sf::Time dt);
};

#endif
