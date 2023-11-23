#ifndef BORDER_H
#define BORDER_H

#include "SFML/Graphics.hpp"
#include "../Utilities/Collision/Collidable.h"
class Border : public Collidable
{
	protected:
		sf::RectangleShape brRect;
		sf::Vector2f borderPos;

	public:
		Border();
		sf::RectangleShape& getShape();
		sf::Vector2f getBorderPos();
		void setBorderPos(float x, float y);
		void onCollision(Collidable& object);
		sf::FloatRect getBounds();


};


#endif


