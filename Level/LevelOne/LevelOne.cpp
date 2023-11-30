#include "LevelOne.h"

LevelOne::LevelOne()
{
    this->noteAmount = 20;
    this->borderAmount = 15;

    Border* leftBorder = new Border();
    leftBorder->setBorderPos(0.0f, 0.0f);
    leftBorder->getShape().setSize(sf::Vector2f(10, 720));
    leftBorder->getShape().setFillColor(sf::Color::Blue);

    Border* rightBorder = new Border();
    rightBorder->setBorderPos(1270.0f, 0.0f); // Adjust for the thickness of the border
    rightBorder->getShape().setSize(sf::Vector2f(10, 720));
    rightBorder->getShape().setFillColor(sf::Color::Blue);

    Border* topBorder = new Border();
    topBorder->setBorderPos(0.0f, 0.0f);
    topBorder->getShape().setSize(sf::Vector2f(1280, 10));
    topBorder->getShape().setFillColor(sf::Color::Blue);

    Border* bottomBorder = new Border();
    bottomBorder->setBorderPos(0.0f, 710.0f); // Adjust for the thickness of the border
    bottomBorder->getShape().setSize(sf::Vector2f(1280, 10));
    bottomBorder->getShape().setFillColor(sf::Color::Blue);

    // Add borders to the collidables vector
    this->vecCollidables.push_back(leftBorder);
    this->vecCollidables.push_back(rightBorder);
    this->vecCollidables.push_back(topBorder);
    this->vecCollidables.push_back(bottomBorder);

    this->vecDrawables.push_back(&leftBorder->getShape());
    this->vecDrawables.push_back(&rightBorder->getShape());
    this->vecDrawables.push_back(&topBorder->getShape());
    this->vecDrawables.push_back(&bottomBorder->getShape());

    this->vecDrawables.push_back(&this->playerShape);


    this->spawnNotes(this->noteAmount);
    this->spawnBorders(this->borderAmount);

    
}

void LevelOne::updatePlayerDrawable(Player& player)
{
    this->playerShape = player.getShape();
    this->playerShape.setPosition(player.getPlayerPos());
}
std::vector<sf::Drawable*>& LevelOne::getDrawables()
{
    return this->vecDrawables;
}

void LevelOne::spawnNotes(int amount)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    int borderWidth = 30;
    std::uniform_int_distribution<> disX(borderWidth, 1280 - 2 * borderWidth);
    std::uniform_int_distribution<> disY(borderWidth, 720 - 2 * borderWidth);
    std::uniform_int_distribution<> disType(0, 0); 

    for (int i = 0; i < amount; i++) {
        float x, y;
        sf::FloatRect bounds;
        bool spaceFree = false;

        while (!spaceFree) {
            x = disX(gen);
            y = disY(gen);

            Notes* note = nullptr;
            switch (disType(gen)) 
            {
                case 0:
                    note = new Notes();
                    break;      
            }

            if (note) 
            {
                note->setNotePos(x, y);
                bounds = note->getBounds();

                spaceFree = isSpaceFree(bounds);
                if (spaceFree)
                {
                    this->vecDrawables.push_back(&note->getNoteSprite());
                    this->vecCollidables.push_back(note);
                }
                else
                {
                    delete note; // If space is not free
                }
            }
        }
    }
}

void LevelOne::spawnBorders(int amount)
{
    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    int borderWidth = 30;
    std::uniform_int_distribution<> disX(borderWidth, 1280 - 2 * borderWidth);
    std::uniform_int_distribution<> disY(borderWidth, 720 - 2 * borderWidth);

    for (int i = 0; i < amount; ++i) {
        float x, y;
        sf::FloatRect bounds;
        bool spaceFree = false;

        while (!spaceFree) {
            x = disX(gen);
            y = disY(gen);

            Border* border = new Border();
            border->setBorderPos(x, y);
            bounds = border->getBounds();

            spaceFree = isSpaceFree(bounds);
            if (spaceFree) {
                this->vecDrawables.push_back(&border->getShape());
                this->vecCollidables.push_back(border);
            }
            else {
                delete border; 
            }
        }
    }
}

std::vector<Collidable*>& LevelOne::getCollidables()
{
    return this->vecCollidables;
}

void LevelOne::playMusicLevel() {
    PlaySound(TEXT("Assets/Lilas.wav"), NULL, SND_ASYNC);
}
