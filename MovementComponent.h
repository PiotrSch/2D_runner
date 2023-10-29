#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>

enum movment_states { IDLE = 0, MOVING, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN }; // change back to sprite if this doesnt work
class MovementComponent
{
private:

	sf::RectangleShape& sprite;

	float maxVelocity;
	float acceleration;
	float deceleration;

	sf::Vector2f velocity;



	//Init Funktions

public:
	MovementComponent(sf::RectangleShape& sprite, float maxVelocity, float accelaration, float deceleration);
	virtual ~MovementComponent();

	//Accessors
	const float& getMaxVelocity() const;
	const sf::Vector2f& getVelocity() const;

	//Funktions
	const bool getStates(const short unsigned state) const;
	void stopVelocity();
	void stopVelocityX();
	void stopVelocityY();

	void setVelocity(const float dir_x, const float dir_y, const float& dt);
	void setVelocityX(const float dir_x, const float& dt);
	void setVelocityY(const float dir_y, const float& dt);
	void update(const float& dt);
};