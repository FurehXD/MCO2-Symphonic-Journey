#include "Border.h"

Border::Border()
{
	this->brRect.setFillColor(sf::Color::Cyan);
	this->brRect.setSize(sf::Vector2f(50, 50));
}

sf::RectangleShape& Border::getShape()
{
	return this->brRect;
}

sf::Vector2f Border::getBorderPos()
{
	return this->borderPos;
}

void Border::setBorderPos(float x, float y)
{
	this->borderPos.x = x;
	this->borderPos.y = y;

	this->brRect.setPosition(this->borderPos);
}

void Border::onCollision(Collidable& object)
{

}

sf::FloatRect Border::getBounds()
{
	return this->brRect.getGlobalBounds();
}