#include "FullNote.h"

FullNote::FullNote()
{
	//this->ntCircle.setFillColor(sf::Color::Magenta);
	this->scoreValue = 20;
	this->texture.loadFromFile("../MCO2-Symphonic-Journey/Notes/wholenote.png");
	this->notes.setTexture(this->texture);
	this->notes.setScale(0.2, 0.2);
	//this->notes.setColor(sf::Color::Magenta);
}


