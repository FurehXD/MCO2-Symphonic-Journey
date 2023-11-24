#include "LevelOne.h"

LevelOne::LevelOne()
{
    this->noteAmount = 10;
    this->borderAmount = 5;

    this->spLeftWall.setSize(sf::Vector2f(720, 10));
    this->spLeftWall.setPosition(5.0f, 0.0f);
    this->spLeftWall.setRotation(90);
    this->spLeftWall.setFillColor(sf::Color::Blue);

    this->spRightWall.setSize(sf::Vector2f(720, 5));
    this->spRightWall.setPosition(1280.0f, 0.0f);
    this->spRightWall.setRotation(90);
    this->spRightWall.setFillColor(sf::Color::Blue);

    this->spTopWall.setSize(sf::Vector2f(1280, 5));
    this->spTopWall.setPosition(5.0f, 0.0f);
    this->spTopWall.setFillColor(sf::Color::Blue);

    this->spBotWall.setSize(sf::Vector2f(1280, 5));
    this->spBotWall.setPosition(0.0f, 715.0f);
    this->spBotWall.setFillColor(sf::Color::Blue);
    

    this->vecDrawables.push_back(&this->spLeftWall);
    this->vecDrawables.push_back(&this->spRightWall);
    this->vecDrawables.push_back(&this->spTopWall);
    this->vecDrawables.push_back(&this->spBotWall);

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
    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> disX(0, 1280);
    std::uniform_int_distribution<> disY(0, 720);
    std::uniform_int_distribution<> disType(0, 1);

    for (int i = 0; i < amount; ++i)
    {
        float x = disX(gen);
        float y = disY(gen);

        if (disType(gen) == 0)
        {
            // Spawn a Notes
            Notes* note = new Notes();
            note->setNotePos(x, y);
            this->vecDrawables.push_back(&note->getShape());
            this->vecCollidables.push_back(note);
        }
        else
        {
            // Spawn a FullNote
            FullNote* fullNote = new FullNote();
            fullNote->setNotePos(x, y);
            this->vecDrawables.push_back(&fullNote->getShape());
            this->vecCollidables.push_back(fullNote);
        }
    }
}

void LevelOne::spawnBorders(int amount)
{
    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> disX(0, 1280);
    std::uniform_int_distribution<> disY(0, 720);

    for (int i = 0; i < amount; ++i)
    {
        Border* borders = new Border();

        float x = disX(gen);
        float y = disY(gen);

        borders->setBorderPos(x, y);
        this->vecDrawables.push_back(&borders->getShape());
        this->vecCollidables.push_back(borders);

    }
}

std::vector<Collidable*>& LevelOne::getCollidables()
{
    return this->vecCollidables;
}