#ifndef UTILITIES_COLLISION_COLLIDABLE_H
#define UTILITIES_COLLISION_COLLIDABLE_H

#include "SFML/Graphics.hpp"

class Collidable
{
	

	public:
		Collidable();
		virtual void onCollision(Collidable& object) = 0;
		virtual sf::FloatRect getBounds() = 0;
		

};

#endif

