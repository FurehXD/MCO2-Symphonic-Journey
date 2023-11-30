#include "Notes.h"

Notes::Notes()
{
	this->scoreValue = 5;
	this->texture.loadFromFile("../MCO2-Symphonic-Journey/Notes/notes.png");
	this->notes.setTexture(this->texture);
	this->notes.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
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
