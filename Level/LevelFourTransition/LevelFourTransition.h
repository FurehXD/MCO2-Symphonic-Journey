#ifndef LEVEL_FOUR_TRANSITION_H
#define LEVEL_FOUR_TRANSITION_H

#include "iostream" 
#include "string"
#include "vector"
#include "../Level.h"
#include "../../Player/Player.h"
#include "../../Notes/FullNote/FullNote.h"
#include "../../Notes/HalfNote/HalfNote.h"
#include "../../Border/Border.h"
#include <random>


class LevelFourTransition : public Level
{

    public:
        LevelFourTransition();

        void updatePlayerDrawable(Player& player) override;
        std::vector<sf::Drawable*>& getDrawables() override;
        void spawnNotes(int amount) override;
        void spawnBorders(int amount) override;
        std::vector<Collidable*>& getCollidables() override;
        void playMusicLevel() override;
};

#endif