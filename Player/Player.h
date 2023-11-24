#ifndef PLAYER_H
#define PLAYER_H

#include "iostream"
#include "string"
#include "vector"
#include "SFML/Graphics.hpp"
#include "../Utilities/Collision/Collidable.h"
#include "../Notes/Notes.h"
#include "../Border/Border.h"


class Player : public Collidable
{
    private:
        sf::CircleShape playerShape;
        sf::Vector2f playerPos;
        sf::Vector2f velocity;
        sf::Vector2f acceleration;
        int score;
        int notesTaken;


    public:
        Player();

        void handleInput(sf::Time& deltaTime);
     
        sf::CircleShape getShape();
        sf::Vector2f& getPlayerPos();
        void setPlayerPos(sf::Vector2f& newPos);
        void onCollision(Collidable& object) override;
        sf::FloatRect getBounds() override;
        int getNotesTaken();
        void setNotesTaken(int amount);
       

};

#endif
