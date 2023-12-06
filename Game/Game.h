#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "../Utilities/Collision/Collidable.h"
#include "../Level/Level.h"
#include "../Level/MainMenu/MainMenu.h"
#include "../Level/LevelOne/LevelOne.h"
#include "../Level/LevelOneTransition/LevelOneTransition.h"
#include "../Level/LevelTwo/LevelTwo.h"
#include "../Level/LevelTwoTransition/LevelTwoTransition.h"
#include "../Level/LevelThree/LevelThree.h"
#include "../Level/LevelThreeTransition/LevelThreeTransition.h"
#include "../Level/LevelFour/LevelFour.h"
#include "../Level/EndGame/EndGame.h"
#include "../Player/Player.h"
#include "iostream"
#include "vector"
#include <memory>

class Game 
{
    private:
        std::vector<std::unique_ptr<Level>> levels;
        Player player;
        int currentLevelIndex;
        sf::Clock clock;


    public:
        Game();

        void startGame();
        void initialize();
        void display(sf::RenderWindow& window);
        void update();
        bool checkCollision(Collidable& objectA, Collidable& objectB);
        void changeLevel(int levelIndex);
               
};

#endif
