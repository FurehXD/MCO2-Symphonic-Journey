#include "HalfNote.h"

HalfNote::HalfNote()
{
	this->scoreValue = 10;
	this->texture.loadFromFile("Assets/halfnote.png");
	this->notes.setTexture(this->texture);
	this->notes.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
	this->notes.setScale(0.2, 0.2);
}