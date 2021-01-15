#ifndef __PLAYER__H__
#define __PLAYER__H__

#include <SFML/Graphics.hpp>
#include "PongEntity.h"

class Player : public PongEntity {
    private:
        sf::RectangleShape m_rectangle;

    public:
        Player(sf::Vector2f const & position);
        void update() override;
        void render(sf::RenderWindow & renderWindow) override;
};

#endif
