#ifndef NOTES_H
#define NOTES_H

#include "SFML/Graphics.hpp"
#include "../Utilities/Collision/Collidable.h"
#include "iostream"
#include "../Player/Player.h"

class Notes : public Collidable
{
	protected:
		sf::CircleShape ntCircle;
		sf::Vector2f notePos;
		int scoreValue;

	public:
		Notes();
	
		sf::CircleShape& getShape();
		sf::Vector2f getNotePos();
		void setNotePos(float x, float y);
		void onCollision(Collidable& object) override;
		sf::FloatRect getBounds() override;
		void startFollow(Collidable& object);
		virtual int getScoreValue();
		



};


#endif


