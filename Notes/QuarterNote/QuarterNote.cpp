#include "QuarterNote.h"

QuarterNote::QuarterNote()
{
	//this->ntCircle.setFillColor(sf::Color::Blue);
	this->scoreValue = 5;
	this->texture.loadFromFile("Assets/quarternote.png");
	this->notes.setTexture(this->texture);
	this->notes.setScale(0.2, 0.2);
}