#ifndef LEVEL_TWO_H
#define LEVEL_TWO_H

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


class LevelTwo : public Level
{

public:
    LevelTwo();

    void updatePlayerDrawable(Player& player) override;
    std::vector<sf::Drawable*>& getDrawables() override;
    void spawnNotes(int amount) override;
    void spawnBorders(int amount) override;
    std::vector<Collidable*>& getCollidables() override;
    void playMusicLevel() override;
};

#endif