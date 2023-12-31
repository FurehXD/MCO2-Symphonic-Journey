#ifndef NOTES_H
#define NOTES_H

#include "SFML/Graphics.hpp"
#include "../Utilities/Collision/Collidable.h"
#include "iostream"

class Notes : public Collidable
{
	protected:
		sf::CircleShape ntCircle;
		sf::Vector2f notePos;
		sf::Sprite notes;
		sf::Texture texture;
		int scoreValue;
		std::string filePath;
		
		

	public:
		Notes();
	
		sf::CircleShape& getShape();
		sf::Vector2f getNotePos();
		void setNotePos(float x, float y);
		void onCollision(Collidable& object) override;
		sf::FloatRect getBounds() override;
		virtual int getScoreValue();
		virtual sf::Sprite& getNoteSprite();
		



};


#endif


