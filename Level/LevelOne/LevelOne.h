#ifndef LEVEL_ONE_H
#define LEVEL_ONE_H

#include "iostream" 
#include "string"
#include "vector"
#include "../Level.h"
#include "../../Player/Player.h"
#include "../../Notes/Notes.h"
#include "../../Notes/FullNote/FullNote.h"
#include "../../Border/Border.h"
#include <random>


class LevelOne : public Level
{
    private:
        //Player shape
        sf::CircleShape playerShape;

        //Walls
        sf::RectangleShape spTopWall;
        sf::RectangleShape spBotWall;
        sf::RectangleShape spLeftWall;
        sf::RectangleShape spRightWall;
        std::vector<Notes> vecNotes;
        std::vector<Border> vecBorders;
        
        

    public:
        LevelOne();

        void updatePlayerDrawable(Player& player) override;
        std::vector<sf::Drawable*>& getDrawables() override;
        void spawnNotes(int amount);
        void spawnBorders(int amount);
        std::vector<Collidable*>& getCollidables() override;

};

#endif