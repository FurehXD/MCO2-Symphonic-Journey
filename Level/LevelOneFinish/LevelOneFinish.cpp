#include "LevelOneFinish.h"

LevelOneFinish::LevelOneFinish()
{
    this->noteAmount = 1;
    this->borderAmount = 0;

    this->text.setString("F�r Elise was composed by Ludwig van Beethoven.\nHe was a German composer and pianist from the eighteenth century.\nHe was widely regarded as one of the greatest composers\ncreating powerful and emotional compositions\nand leaving an enduring impact on classical music.");
    this->text.setPosition(50, 100);
    this->text.setCharacterSize(45);
    this->text.setFillColor(sf::Color::White);

    Border* leftBorder = new Border();
    leftBorder->setBorderPos(0.0f, 0.0f);
    leftBorder->getShape().setSize(sf::Vector2f(10, 720));
    leftBorder->getShape().setFillColor(sf::Color::White);

    Border* rightBorder = new Border();
    rightBorder->setBorderPos(1270.0f, 0.0f); // Adjust for the thickness of the border
    rightBorder->getShape().setSize(sf::Vector2f(10, 720));
    rightBorder->getShape().setFillColor(sf::Color::White);

    Border* topBorder = new Border();
    topBorder->setBorderPos(0.0f, 0.0f);
    topBorder->getShape().setSize(sf::Vector2f(1280, 10));
    topBorder->getShape().setFillColor(sf::Color::White);

    Border* bottomBorder = new Border();
    bottomBorder->setBorderPos(0.0f, 710.0f); // Adjust for the thickness of the border
    bottomBorder->getShape().setSize(sf::Vector2f(1280, 10));
    bottomBorder->getShape().setFillColor(sf::Color::White);

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
    this->vecDrawables.push_back(&this->text);

    this->spawnNotes(this->noteAmount);
    this->spawnBorders(this->borderAmount);


}

void LevelOneFinish::updatePlayerDrawable(Player& player)
{
    this->playerShape = player.getShape();
    this->playerShape.setPosition(player.getPlayerPos());
}
std::vector<sf::Drawable*>& LevelOneFinish::getDrawables()
{
    return this->vecDrawables;
}

void LevelOneFinish::spawnNotes(int amount)
{

    Notes* note = new Notes();
    note->setNotePos(1200, 645);
    this->vecDrawables.push_back(&note->getNoteSprite());
    this->vecCollidables.push_back(note);
}

void LevelOneFinish::spawnBorders(int amount)
{
    //No borders for this level
}

std::vector<Collidable*>& LevelOneFinish::getCollidables()
{
    return this->vecCollidables;
}

void LevelOneFinish::playMusicLevel() {
    PlaySound(TEXT("Assets/Note Sounds/Level.wav"), NULL, SND_ASYNC);
}
