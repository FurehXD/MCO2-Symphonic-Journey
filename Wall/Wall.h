#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>

class Wall 
{
    public:
        Wall(float x, float y, float width, float height, float rotation);

        void setPosition(float x, float y);
        void setSize(float width, float height);
        void setRotation(float angle);
        sf::RectangleShape& getShape();

        void draw(sf::RenderWindow& window);

    private:
        sf::RectangleShape shape;
};

#endif
