#include "Player.h"

Player::Player() 
{
    this->playerPos = sf::Vector2f(100.0f, 100.0f);

    this->playerShape.setRadius(10.0f);
    this->playerShape.setPosition(playerPos);
    this->playerShape.setFillColor(sf::Color::Green);
    
}

void Player::handleInput(sf::Time& deltaTime)
{
    float maxSpeed = 200.0f;

    velocity.x = 0;
    velocity.y = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        velocity.y = -maxSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        velocity.y = maxSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        velocity.x = -maxSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        velocity.x = maxSpeed;

    playerPos += velocity * deltaTime.asSeconds();
    playerShape.setPosition(playerPos);
}

sf::Vector2f& Player::getPlayerPos()
{
    return this->playerPos;
}

sf::CircleShape Player::getShape()
{
    return this->playerShape;
}

void Player::setPlayerPos(sf::Vector2f& newPos)
{
    this->playerPos = newPos;
    this->playerShape.setPosition(this->playerPos);
}

void Player::onCollision(Collidable& object)
{
    Notes* note = dynamic_cast<Notes*>(&object);
    Border* border = dynamic_cast<Border*>(&object);
    if (note)
    {
        note->setNotePos(0, 0); //Temp need to create delete functionality
        this->score += note->getScoreValue();
        std::cout << "Score: " << this->score << std::endl;
    }
    if (border)
    {

        // Obtain the bounds of the border and the player
        sf::FloatRect borderBounds = border->getBounds();
        sf::FloatRect playerBounds = this->getBounds();
        float radius = this->playerShape.getRadius();

        // Calculate the center point of the player
        sf::Vector2f playerCenter(playerBounds.left + radius, playerBounds.top + radius);

        // Determine the depth of the collision
        float deltaX = (borderBounds.left + (borderBounds.width / 2)) - playerCenter.x;
        float deltaY = (borderBounds.top + (borderBounds.height / 2)) - playerCenter.y;

        // Correct player's position based on the shallowest penetration
        if (std::abs(deltaX) < std::abs(deltaY))
        {
            // Collision is horizontal
            if (deltaX > 0)
            {
                // Collision on the left
                playerPos.x = borderBounds.left - playerBounds.width;
            }
            else
            {
                // Collision on the right
                playerPos.x = borderBounds.left + borderBounds.width;
            }
            velocity.x = 0; // Stop horizontal movement
        }
        else
        {
            // Collision is vertical
            if (deltaY > 0)
            {
                // Collision on the top
                playerPos.y = borderBounds.top - playerBounds.height;
            }
            else
            {
                // Collision on the bottom
                playerPos.y = borderBounds.top + borderBounds.height;
            }
            velocity.y = 0; // Stop vertical movement
        }

        // Update the player's position
        setPlayerPos(playerPos);
    }
}

sf::FloatRect Player::getBounds()
{
    return this->playerShape.getGlobalBounds();
}

                