#include "Notes.h"

Notes::Notes()
{
	//this->ntCircle.setRadius(5);
	//this->ntCircle.setFillColor(sf::Color::Red);
	this->scoreValue = 5;
	this->texture.loadFromFile("../MCO2-Symphonic-Journey/Notes/quarternote.png");
	this->notes.setTexture(this->texture);
	this->notes.setScale(0.5, 0.5);
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

	//this->ntCircle.setPosition(this->notePos);   //changed
	this->notes.setPosition(this->notePos);
}

void Notes::onCollision(Collidable& object)
{
	
}

sf::Sprite& Notes::getNoteSprite() {
	return this->notes;
}

sf::FloatRect Notes::getBounds()
{
	//return this->ntCircle.getGlobalBounds();     //changed
	return this->notes.getGlobalBounds();
}

int Notes::getScoreValue()
{
	return this->scoreValue;
}
