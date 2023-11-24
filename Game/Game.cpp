#include "Game.h"

Game::Game()
{
    this->levels.push_back(std::make_unique<LevelOne>());
    this->levels.push_back(std::make_unique<LevelTwo>());
    this->currentLevelndex = 0;
}

void Game::startGame() 
{
    std::cout << "Welcome to the Symphonic Journey!" << std::endl;
    std::cout <<  std::endl;

    this->initialize();
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    while(window.isOpen())
    {      
        this->display(window);
        this->update();         
    }
}

void Game::initialize()
{
     
}

void Game::display(sf::RenderWindow& window)
{
    
    window.clear();
    auto& drawables = this->levels[currentLevelndex]->getDrawables();
    for (auto& drawable : drawables) 
    {
        window.draw(*drawable);
    }
    window.display();
}


void Game::update()
{   
    sf::Time deltaTime = clock.restart();
    this->player.handleInput(deltaTime);
    this->levels[this->currentLevelndex]->updatePlayerDrawable(this->player);

    auto& collidables = this->levels[currentLevelndex]->getCollidables();

    for (size_t i = 0; i < collidables.size(); ++i) 
    {
        for (size_t j = i + 1; j < collidables.size(); ++j) 
        {
            if (checkCollision(*collidables[i], player)) 
            {
                
                this->player.onCollision(*collidables[i]);
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        changeLevel(0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        changeLevel(1);


    if (this->player.getNotesTaken() == this->levels[this->currentLevelndex]->getNoteAmount() - 1)
    {
        if (this->currentLevelndex < 4)
        {
            this->player.setNotesTaken(0);
            changeLevel(1);
        }
        else
            std::cout << "PLAYER WINS!" << std::endl;
    }
}

bool Game::checkCollision(Collidable& objectA, Collidable& objectB)
{
    return objectA.getBounds().intersects(objectB.getBounds());
}

void Game::changeLevel(int levelIndex)
{
    this->currentLevelndex = levelIndex;
}



