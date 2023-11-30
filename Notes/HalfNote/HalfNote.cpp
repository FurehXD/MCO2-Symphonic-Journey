#include "HalfNote.h"

HalfNote::HalfNote()
{
	//this->ntCircle.setFillColor(sf::Color::Yellow);
	this->scoreValue = 10;
	this->texture.loadFromFile("Assets/halfnote-min.png");
	this->notes.setTexture(this->texture);
	this->notes.setScale(0.5, 0.5);
	this->notes.setColor(sf::Color::Yellow);
}