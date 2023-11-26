#include "Level.h"

Level::Level()
{
	
}

int Level::getNoteAmount()
{
	return this->noteAmount;
}

int Level::getBorderAmount()
{
	return this->borderAmount;
}

bool Level::isSpaceFree(sf::FloatRect& bounds)
{
    for (auto& collidable : this->vecCollidables)
    {
        if (collidable->getBounds().intersects(bounds))
        {
            return false;
        }
    }
    return true;
}

void Level::stopMusicLevel() {
    PlaySound(NULL, 0, 0);
}