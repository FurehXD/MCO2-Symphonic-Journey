#include "Notes.h"

Notes::Notes()
{
	this->ntCircle.setRadius(5);
	this->ntCircle.setFillColor(sf::Color::Red);
	this->scoreValue = 5;
}

sf::CircleShape& Notes::getShape()
{
	return this->ntCircle;
}

sf::Vector2f Notes::getNotePos()
{
	return this->notePos;
}

void Notes::setNotePos(float x, float y)
{
	this->notePos.x = x;
	this->notePos.y = y;

	this->ntCircle.setPosition(this->notePos);
}

void Notes::onCollision(Collidable& object)
{
	
}

sf::FloatRect Notes::getBounds()
{
	return this->ntCircle.getGlobalBounds();
}

void Notes::startFollow(Collidable& object)
{
	
}

int Notes::getScoreValue()
{
	return this->scoreValue;
}
