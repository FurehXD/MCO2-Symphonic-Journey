#include "Wall.h"

Wall::Wall(float x, float y, float width, float height, float rotation) 
{
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    shape.setOrigin(width / 2, height / 2); // Set origin to center for rotation
    shape.setRotation(rotation);
}

void Wall::setPosition(float x, float y) 
{
    shape.setPosition(x, y);
}

void Wall::setSize(float width, float height) 
{
    shape.setSize(sf::Vector2f(width, height));
    shape.setOrigin(width / 2, height / 2); // Update origin after size change
}

void Wall::setRotation(float angle) 
{
    shape.setRotation(angle);
}

sf::RectangleShape& Wall::getShape() 
{
    return shape;
}

void Wall::draw(sf::RenderWindow& window) 
{
    window.draw(shape);
}
