#include "FullNote.h"

FullNote::FullNote()
{
	this->scoreValue = 20;
	this->texture.loadFromFile("../MCO2-Symphonic-Journey/Notes/wholenote.png");
	this->notes.setTexture(this->texture);
	this->notes.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));

	this->notes.setScale(0.1, 0.1);
}

