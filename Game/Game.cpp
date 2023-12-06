#include "Game.h"

Game::Game()
{
    
}

void Game::startGame() 
{
    std::cout << "Welcome to the Symphonic Journey!" << std::endl;
    std::cout <<  std::endl;
    this->initialize();
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    this->levels[this->currentLevelIndex]->playMusicLevel();

    while(window.isOpen())
    {     
        this->update();
        this->display(window);
    }
}

void Game::initialize()
{
    this->levels.push_back(std::make_unique<MainMenu>());
    this->levels.push_back(std::make_unique<LevelOne>());
    this->levels.push_back(std::make_unique<LevelOneFinish>());
    this->levels.push_back(std::make_unique<LevelTwo>());
    this->levels.push_back(std::make_unique<LevelTwoFinish>());
    this->levels.push_back(std::make_unique<LevelThree>());
    this->levels.push_back(std::make_unique<LevelThreeFinish>());
    this->levels.push_back(std::make_unique<LevelFour>());
    this->levels.push_back(std::make_unique<EndGame>());

    this->currentLevelIndex = 0;
}

void Game::display(sf::RenderWindow& window)
{
    window.clear();
    if (this->currentLevelIndex < levels.size() && levels[this->currentLevelIndex])
    {
        auto& drawables = levels[this->currentLevelIndex]->getDrawables();
        for (auto& drawable : drawables)
        {
            if (drawable) 
            {
                window.draw(*drawable);
            }
        }
        
    }
    window.display();
}


void Game::update()
{
    sf::Time deltaTime = clock.restart();
    this->player.handleInput(deltaTime);

    // Check if the current level index is valid before updating the player drawable
    if (this->currentLevelIndex >= 0 && this->currentLevelIndex < levels.size() && levels[this->currentLevelIndex]) 
    {
        this->levels[currentLevelIndex]->updatePlayerDrawable(this->player);

        auto& collidables = this->levels[currentLevelIndex]->getCollidables();

        for (size_t i = 0; i < collidables.size(); ++i) 
        {
            if (checkCollision(*collidables[i], this->player)) 
            {
                this->player.onCollision(*collidables[i]);
            }
        }

        // Handling level completion and transition
        if (this->player.getNotesTaken() == this->levels[currentLevelIndex]->getNoteAmount())
        {
            std::cout << "LEVEL INDEX: " << this->currentLevelIndex << std::endl;
            if (this->currentLevelIndex < levels.size() - 1)
            {
                this->player.setNotesTaken(0);
                changeLevel(this->currentLevelIndex + 1); // Go to the next level
            }
            else
            {
                std::cout << "PLAYER WINS!" << std::endl;
                exit(1);
                // Handle the win condition
            }
        }
    }
    else 
    {
        //If not a valid level
        std::cout << "Loaded an invalid level" << std::endl;
    }
}


bool Game::checkCollision(Collidable& objectA, Collidable& objectB)
{
    return objectA.getBounds().intersects(objectB.getBounds());
}

void Game::changeLevel(int levelIndex)
{
    if (levelIndex >= 0 && levelIndex < levels.size() && levels[levelIndex])
    {
        levels[this->currentLevelIndex]->stopMusicLevel();
        this->currentLevelIndex = levelIndex;
        levels[this->currentLevelIndex]->playMusicLevel();
    }
    else
    {
        std::cout << "Could not change Level" << std::endl;
    }
}



