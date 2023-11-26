#include "QuarterNote.h"

QuarterNote::QuarterNote()
{
	//this->ntCircle.setFillColor(sf::Color::Blue);
	this->scoreValue = 5;
	this->texture.loadFromFile("../MCO2-Symphonic-Journey/Notes/notes.png");
	this->notes.setTexture(this->texture);
	this->notes.setScale(0.5, 0.5);
	this->notes.setColor(sf::Color::Blue);
}