#include "LevelFour.h"



LevelFour::LevelFour()
{
    this->noteAmount = 35;
    this->borderAmount = 15;

    this->spLeftWall.setSize(sf::Vector2f(720, 10));
    this->spLeftWall.setPosition(5.0f, 0.0f);
    this->spLeftWall.setRotation(90);
    this->spLeftWall.setFillColor(sf::Color::Magenta);

    this->spRightWall.setSize(sf::Vector2f(720, 5));
    this->spRightWall.setPosition(1280.0f, 0.0f);
    this->spRightWall.setRotation(90);
    this->spRightWall.setFillColor(sf::Color::Magenta);

    this->spTopWall.setSize(sf::Vector2f(1280, 5));
    this->spTopWall.setPosition(5.0f, 0.0f);
    this->spTopWall.setFillColor(sf::Color::Magenta);

    this->spBotWall.setSize(sf::Vector2f(1280, 5));
    this->spBotWall.setPosition(0.0f, 715.0f);
    this->spBotWall.setFillColor(sf::Color::Magenta);

    this->vecDrawables.push_back(&this->spLeftWall);
    this->vecDrawables.push_back(&this->spRightWall);
    this->vecDrawables.push_back(&this->spTopWall);
    this->vecDrawables.push_back(&this->spBotWall);

    this->vecDrawables.push_back(&this->playerShape);

    this->spawnNotes(this->noteAmount);
    this->spawnBorders(this->borderAmount);

}

void LevelFour::updatePlayerDrawable(Player& player)
{
    this->playerShape = player.getShape();
    this->playerShape.setPosition(player.getPlayerPos());
}
std::vector<sf::Drawable*>& LevelFour::getDrawables()
{
    return this->vecDrawables;
}

void LevelFour::spawnNotes(int amount)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    int borderWidth = 30;
    std::uniform_int_distribution<> disX(borderWidth, 1280 - 2 * borderWidth);
    std::uniform_int_distribution<> disY(borderWidth, 720 - 2 * borderWidth);
    std::uniform_int_distribution<> disType(0, 3); 

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
                    this->vecDrawables.push_back(&note->getNoteSprite());
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

void LevelFour::spawnBorders(int amount)
{
    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Assuming a border of 10 pixels
    int borderWidth = 30;
    // Adjusted to account for border
    std::uniform_int_distribution<> disX(borderWidth, 1280 - 2 * borderWidth);
    // Adjusted to account for border
    std::uniform_int_distribution<> disY(borderWidth, 720 - 2 * borderWidth);

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

std::vector<Collidable*>& LevelFour::getCollidables()
{
    return this->vecCollidables;
}

void LevelFour::playMusicLevel() {
    bool play = PlaySound(TEXT("../MCO2-Symphonic-Journey/Level/LevelFour/TheFlowerofDuet.wav"), NULL, SND_ASYNC);
}
