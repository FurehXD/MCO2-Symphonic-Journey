#include "Level.h"

Level::Level()
{
	
}


void Level::addDrawable(sf::Drawable* drawable)
{
	this->vecDrawables.push_back(drawable);
}



