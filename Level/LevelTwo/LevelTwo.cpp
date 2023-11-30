#include "LevelTwo.h"



LevelTwo::LevelTwo()
{
    this->noteAmount = 30;
    this->borderAmount = 15;

    this->spLeftWall.setSize(sf::Vector2f(720, 10));
    this->spLeftWall.setPosition(5.0f, 0.0f);
    this->spLeftWall.setRotation(90);
    this->spLeftWall.setFillColor(sf::Color::Red);

    this->spRightWall.setSize(sf::Vector2f(720, 5));
    this->spRightWall.setPosition(1280.0f, 0.0f);
    this->spRightWall.setRotation(90);
    this->spRightWall.setFillColor(sf::Color::Red);

    this->spTopWall.setSize(sf::Vector2f(1280, 5));
    this->spTopWall.setPosition(5.0f, 0.0f);
    this->spTopWall.setFillColor(sf::Color::Red);

    this->spBotWall.setSize(sf::Vector2f(1280, 5));
    this->spBotWall.setPosition(0.0f, 715.0f);
    this->spBotWall.setFillColor(sf::Color::Red);

    this->vecDrawables.push_back(&this->spLeftWall);
    this->vecDrawables.push_back(&this->spRightWall);
    this->vecDrawables.push_back(&this->spTopWall);
    this->vecDrawables.push_back(&this->spBotWall);

    this->vecDrawables.push_back(&this->playerShape);

    this->spawnNotes(this->noteAmount);
    this->spawnBorders(this->borderAmount);

}

void LevelTwo::updatePlayerDrawable(Player& player)
{
    this->playerShape = player.getShape();
    this->playerShape.setPosition(player.getPlayerPos());
}
std::vector<sf::Drawable*>& LevelTwo::getDrawables()
{
    return this->vecDrawables;
}

void LevelTwo::spawnNotes(int amount)
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
    std::uniform_int_distribution<> disType(0, 1); // Adjust for the type of notes if needed

    for (int i = 0; i < amount; i++) {
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
            
            }

            if (note) {
                note->setNotePos(x, y);
                bounds = note->getBounds();

                spaceFree = isSpaceFree(bounds);
                if (spaceFree) {
                    //this->vecDrawables.push_back(&note->getShape());    //changed
                    this->vecDrawables.push_back(&note->getNoteSprite());
                    this->vecCollidables.push_back(note);
                }
                else {
                    delete note; // Clean up if space is not free
                }
            }
        }
    }
}

void LevelTwo::spawnBorders(int amount)
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

std::vector<Collidable*>& LevelTwo::getCollidables()
{
    return this->vecCollidables;
}

void LevelTwo::playMusicLevel() {
    PlaySound(TEXT("../MCO2-Symphonic-Journey/Level/LevelTwo/moonlightSonata.wav"), NULL, SND_ASYNC);
}