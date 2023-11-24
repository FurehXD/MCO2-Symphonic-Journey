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
		int noteAmount;
		int borderAmount;

	public:
		Level();
		virtual std::vector<sf::Drawable*>& getDrawables() = 0;
		virtual void updatePlayerDrawable(Player& player) = 0;
		virtual std::vector<Collidable*>& getCollidables() = 0;
		virtual int getNoteAmount();
		virtual int getBorderAmount();
};



#endif // !LEVEL_H

