#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::RectangleShape& sprite, float maxVelocity, float accelaration, float deceleration)
	:sprite(sprite), maxVelocity(maxVelocity), acceleration(accelaration), deceleration(deceleration)
{
}

MovementComponent::~MovementComponent()
{
}

const float& MovementComponent::getMaxVelocity() const
{
	return this->maxVelocity;
}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

//funktions
const bool MovementComponent::getStates(const short unsigned state) const
{
	switch (state)
	{
	case IDLE:
		if (this->velocity.x == 0.f && this->velocity.y == 0.f)
			return true;
		break;


	case MOVING:
		if (this->velocity.x != 0.f && this->velocity.y != 0.f)
			return true;
		break;


	case MOVING_LEFT:
		if (this->velocity.x < 0.f)
			return true;
		break;


	case MOVING_RIGHT:
		if (this->velocity.x > 0.f)
			return true;
		break;

	case MOVING_UP:
		if (this->velocity.y < 0.f)
			return true;
		break;


	case MOVING_DOWN:
		if (this->velocity.y > 0.f)
			return true;
		break;

	default:
		break;
	}
	return false;
}

void MovementComponent::stopVelocity()
{
	this->velocity.x = 0.f;
	this->velocity.y = 0.f;
}

void MovementComponent::stopVelocityX()
{
	this->velocity.x = 0.f;
}

void MovementComponent::stopVelocityY()
{
	this->velocity.y = 0.f;
}

void MovementComponent::setVelocity(const float dir_x, const float dir_y, const float& dt)
{
	this->velocity.x += this->acceleration * dir_x;

	this->velocity.y += this->acceleration * dir_y;
}

void MovementComponent::setVelocityX(const float dir_x, const float& dt)
{
	this->velocity.x += this->acceleration * dir_x;
}

void MovementComponent::setVelocityY(const float dir_y, const float& dt)
{
	this->velocity.y += this->acceleration * dir_y;
}

void MovementComponent::update(const float& dt)
{
	/*Decelarates the sprite and controls the max
	and moves the sprite*/

	//decelaration
	if (this->velocity.x > 0.f) // Check for negatve X
	{
		//Max Velocity check positiv
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;



		//Deceleration x-position
		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;

	}
	else if (this->velocity.x < 0.f) // Check for negative 
	{
		//MAx velocity check negative
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;

		//Deselaration x negative
		this->velocity.x += deceleration;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}


	if (this->velocity.y > 0.f) // Check for Negative Y
	{
		//Max Velocity check positiv
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;



		//Deceleration x-position
		this->velocity.y -= deceleration;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;

	}
	else if (this->velocity.y < 0.f) // Check for negative 
	{
		//MAx velocity check negative
		if (this->velocity.y < -this->maxVelocity)
			this->velocity.y = -this->maxVelocity;

		//Deselaration x negative
		this->velocity.y += deceleration;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}
	//Final move
	this->sprite.move(this->velocity * dt); // Uses velocity
}
