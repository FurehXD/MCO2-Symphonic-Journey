#include "LevelThree.h"



LevelThree::LevelThree()
{
    this->noteAmount = 30;
    this->borderAmount = 15;

    this->spLeftWall.setSize(sf::Vector2f(720, 10));
    this->spLeftWall.setPosition(5.0f, 0.0f);
    this->spLeftWall.setRotation(90);
    this->spLeftWall.setFillColor(sf::Color::Yellow);

    this->spRightWall.setSize(sf::Vector2f(720, 5));
    this->spRightWall.setPosition(1280.0f, 0.0f);
    this->spRightWall.setRotation(90);
    this->spRightWall.setFillColor(sf::Color::Yellow);

    this->spTopWall.setSize(sf::Vector2f(1280, 5));
    this->spTopWall.setPosition(5.0f, 0.0f);
    this->spTopWall.setFillColor(sf::Color::Yellow);

    this->spBotWall.setSize(sf::Vector2f(1280, 5));
    this->spBotWall.setPosition(0.0f, 715.0f);
    this->spBotWall.setFillColor(sf::Color::Yellow);

    this->vecDrawables.push_back(&this->spLeftWall);
    this->vecDrawables.push_back(&this->spRightWall);
    this->vecDrawables.push_back(&this->spTopWall);
    this->vecDrawables.push_back(&this->spBotWall);

    this->vecDrawables.push_back(&this->playerShape);

    this->spawnNotes(this->noteAmount);
    this->spawnBorders(this->borderAmount);

}

void LevelThree::updatePlayerDrawable(Player& player)
{
    this->playerShape = player.getShape();
    this->playerShape.setPosition(player.getPlayerPos());
}
std::vector<sf::Drawable*>& LevelThree::getDrawables()
{
    return this->vecDrawables;
}

void LevelThree::spawnNotes(int amount)
{
    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> disX(0, 1280);
    std::uniform_int_distribution<> disY(0, 720);
    std::uniform_int_distribution<> disType(0, 3); // 0 for Notes, 1 for FullNotes, 2 for HalfNote, 3 for QuarterNote

    for (int i = 0; i < amount; i++) 
    {
        float x, y;
        sf::FloatRect bounds;
        bool spaceFree = false;

        while (!spaceFree) 
        {
            x = disX(gen);
            y = disY(gen);

            Notes* note = nullptr;
            switch (disType(gen))
            {
            case 0:
                note = new Notes();
                break;
            case 1:
                note = new FullNote();
                break;
            case 2:
                note = new HalfNote();
                break;
            case 3:
                note = new QuarterNote();
                break;
            }

            if (note) 
            {
                note->setNotePos(x, y);
                bounds = note->getBounds();

                spaceFree = isSpaceFree(bounds);
                if (spaceFree) 
                {
                    this->vecDrawables.push_back(&note->getShape());
                    this->vecCollidables.push_back(note);
                }
                else 
                {
                    delete note; // Clean up if space is not free
                }
            }
        }
    }
}

void LevelThree::spawnBorders(int amount)
{
    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> disX(0, 1280);
    std::uniform_int_distribution<> disY(0, 720);

    for (int i = 0; i < amount; ++i) 
    {
        float x, y;
        sf::FloatRect bounds;
        bool spaceFree = false;

        while (!spaceFree) 
        {
            x = disX(gen);
            y = disY(gen);

            Border* border = new Border();
            border->setBorderPos(x, y);
            bounds = border->getBounds();

            spaceFree = isSpaceFree(bounds);
            if (spaceFree) 
            {
                this->vecDrawables.push_back(&border->getShape());
                this->vecCollidables.push_back(border);
            }
            else 
            {
                delete border;
            }
        }
    }
}

std::vector<Collidable*>& LevelThree::getCollidables()
{
    return this->vecCollidables;
}

void LevelThree::playMusicLevel() {
    PlaySound(TEXT("../MCO2-Symphonic-Journey/Level/LevelThree/Winter.wav"), NULL, SND_ASYNC);
}