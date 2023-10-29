#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class SecondaryPlayer
{
private:
    bool quit;

    sf::Vector2f velocity;
    float movementSpeed;
    float JumpAndFallSpeed;

    float gridSize;
    float keytime;
    float keytimeMax;

    sf::Texture texture;
public:
    sf::RectangleShape SecondaryPlayerhitbox;
    sf::Sprite SecondaryPlayerSprite;

    SecondaryPlayer(float x, float y, float& gridSize, sf::Texture texture);
    virtual ~SecondaryPlayer();
    //inits
    void initVariables();


    //Funktions
    void setTexture(sf::Texture& texture);
    void setPosition(const float x, const float y); // from Hitbox
    const sf::Vector2f getPosition();
    sf::Vector2f getScale();


    virtual void setVelocity(const float dir_x, const float dir_y);
    virtual void setVelocityX(const float dir_x);
    virtual void setVelocityY(const float dir_y);


    sf::Vector2f getVelocity();

    void updateMove(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target);
};

