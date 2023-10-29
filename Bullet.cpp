#include "Bullet.h"



Bullet::Bullet()
{


    this->initVariables();
    
}



void Bullet::initVariables()
{
    this->CShape.setRadius(6.f);
    this->CShape.setFillColor(sf::Color::Red);

    this->maxVelocity = 0.3f;
    this->currentVelocityX = 0.f;
}

void Bullet::move(float x, float y, const float& dt)
{
    velocity.x += x * dt;
    velocity.y += y * dt;

    this->CShape.move(velocity);
}





void Bullet::update()
{
    
}

void Bullet::render(sf::RenderTarget* target)
{

}

