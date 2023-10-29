#include "Player.h"

void Player::initVariables()
{
	this->quit = false;
	
	this->playerSprite.setTexture(texture);

	this->playerSprite.setPosition(playerhitbox.getPosition().x, playerhitbox.getPosition().y);

	this->playerSprite.setScale(sf::Vector2f(0.5f, 0.5f));

	this->keytimeMax = 0.2f;

	this->movementSpeed = 400.f;

	this->JumpAndFallSpeed = 600.f;
}


void Player::setTexture(sf::Texture texture)
{/*
	this->playerhitbox.setTexture(texture);*/
}



void Player::setPosition(const float x, const float y)
{
	this->playerhitbox.setPosition(x, y);
}

const sf::Vector2f Player::getPosition()
{
	return this->playerhitbox.getPosition();
}

sf::Vector2f Player::getScale()
{
	return playerSprite.getScale();
}




void Player::setVelocity(const float dir_x, const float dir_y)
{
	this->velocity.x = dir_x;
	this->velocity.y = dir_y;
}

void Player::setVelocityX(const float dir_x)
{
	this->velocity.x = dir_x;
}

void Player::setVelocityY(const float dir_y)
{
	this->velocity.y = dir_y;
}





//constructurs
Player::Player(float x, float y, float& gridSize,sf::Texture texture)
{
	this->playerhitbox.setSize(sf::Vector2f(gridSize, gridSize));

	this->playerhitbox.setPosition(x, y);

	this->gridSize = gridSize;
	
	this->texture = texture;

	this->initVariables();



	//this->createAnimationComponent(texture_sheet);

}

Player::~Player()
{
}

//funktions





sf::Vector2f Player::getVelocity()
{
	return this->velocity;
}


void Player::updateMove(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		keytime += dt;
	}
	else
	{
		keytime = 0.f;
	}

	if (keytime <= keytimeMax && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		velocity.y += -JumpAndFallSpeed * dt;
	else
		velocity.y += JumpAndFallSpeed * dt;

	velocity.x = 0.f;

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//{
	//	velocity.y += -movementSpeed * dt;
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//{
	//	velocity.y += movementSpeed * dt;
	//}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x += -movementSpeed * dt;
		this->playerSprite.setScale(sf::Vector2f(-0.5f, 0.5f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += movementSpeed * dt;
		this->playerSprite.setScale(sf::Vector2f(0.5f, 0.5f));
	}

	
	this->playerhitbox.move(velocity);
}

void Player::update(const float& dt)
{
	this->playerSprite.setTexture(texture);

	if(playerSprite.getScale().x < 0)
		this->playerSprite.setPosition(sf::Vector2f(playerhitbox.getPosition().x + 40.f, playerhitbox.getPosition().y));
	else
		this->playerSprite.setPosition(sf::Vector2f(playerhitbox.getPosition().x, playerhitbox.getPosition().y));

}


void Player::render(sf::RenderTarget* target)
{									
	target->draw(this->playerSprite);
}

