#ifndef __PONG__ENTITY__H__
#define __PONG__ENTITY__H__

#include <SFML/Graphics.hpp>

class PongEntity {
    protected:
        sf::Vector2f m_position;
        sf::Clock m_clock;
    
    public:
        PongEntity(sf::Vector2f const & position);
        void update();
        virtual void render(sf::RenderWindow & renderWindow) = 0;
};

#endif
