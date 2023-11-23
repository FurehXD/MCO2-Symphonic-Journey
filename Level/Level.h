#ifndef LEVEL_H
#define LEVEL_H


#include "SFML/Graphics.hpp"
#include "../Player/Player.h"
#include "../Utilities/Collision/Collidable.h"
#include "vector"
#include "iostream"

class Level
{
	protected:
		std::vector<sf::Drawable*> vecDrawables;
		std::vector<Collidable*> vecCollidables;

	public:
		Level();
		virtual std::vector<sf::Drawable*>& getDrawables() = 0;
		virtual void updatePlayerDrawable(Player& player) = 0;
		virtual void addDrawable(sf::Drawable* drawable);
		virtual std::vector<Collidable*>& getCollidables() = 0;
};



#endif // !LEVEL_H

