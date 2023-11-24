#ifndef LEVEL_THREE_H
#define LEVEL_THREE_H

#include "iostream" 
#include "string"
#include "vector"
#include "../Level.h"
#include "../../Player/Player.h"
#include "../../Notes/Notes.h"
#include "../../Notes/FullNote/FullNote.h"
#include "../../Notes/HalfNote/HalfNote.h"
#include "../../Notes/QuarterNote/QuarterNote.h"
#include "../../Border/Border.h"
#include <random>


class LevelThree : public Level
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
    LevelThree();

    void updatePlayerDrawable(Player& player) override;
    std::vector<sf::Drawable*>& getDrawables() override;
    void spawnNotes(int amount) override;
    void spawnBorders(int amount) override;
    std::vector<Collidable*>& getCollidables() override;


};

#endif