#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>

class Bullet
{
public:
	sf::CircleShape CShape;


    float currentVelocityX;
    float maxVelocity;
    
    sf::Vector2f velocity;



    Bullet();
    //inits
    void initVariables();
    void move(float x, float y, const float& dt);

    ////Funktions
    //    //Componetnt funktions
    //void setTexture(sf::Texture& texture);
    //void setPosition(const float x, const float y); // from Hitbox
    //const sf::Vector2f getPosition();



    void update();
    void render(sf::RenderTarget* target);


};

