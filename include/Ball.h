#ifndef __BALL__H__
#define __BALL__H__

#include <SFML/Graphics.hpp>
#include <math.h>
#include "PongEntity.h"
#include "Player.h"

class Ball : public PongEntity {
    private:
        sf::RectangleShape m_rectangle;

        Player * m_player1;
        Player * m_player2;

        float m_angle{0.f};
        float m_speedMoveX{400.f};
        float m_speedMoveY{400.f};

        static constexpr float m_size{15.f};

    public:
        Ball(sf::Vector2f const & position, Player * player1, Player * player2);
        void update();
        void render(sf::RenderWindow & renderWindow);
        void move(sf::Time dt);
        bool checkCollision(Player * player);
};

#endif
