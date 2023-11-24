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
		std::vector<Notes> vecNotes;
		std::vector<Border> vecBorders;

		sf::RectangleShape spTopWall;
		sf::RectangleShape spBotWall;
		sf::RectangleShape spLeftWall;
		sf::RectangleShape spRightWall;

		sf::CircleShape playerShape;

		int noteAmount;
		int borderAmount;

	public:
		Level();
		virtual std::vector<sf::Drawable*>& getDrawables() = 0;
		virtual void updatePlayerDrawable(Player& player) = 0;
		virtual std::vector<Collidable*>& getCollidables() = 0;
		virtual void spawnNotes(int amount) = 0;
		virtual void spawnBorders(int amount) = 0;
		virtual int getNoteAmount();
		virtual int getBorderAmount();
		virtual bool isSpaceFree(sf::FloatRect& bounds);

};



#endif // !LEVEL_H

