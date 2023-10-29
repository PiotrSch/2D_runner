#include "SecondaryPlayer.h"

void SecondaryPlayer::initVariables()
{
	this->quit = false;

	this->SecondaryPlayerSprite.setTexture(texture);

	this->SecondaryPlayerSprite.setPosition(SecondaryPlayerhitbox.getPosition().x, SecondaryPlayerhitbox.getPosition().y);

	this->SecondaryPlayerSprite.setScale(sf::Vector2f(0.5f, 0.5f));

	this->keytimeMax = 0.2f;
	
	this->movementSpeed = 400.f;

	this->JumpAndFallSpeed = 600.f;
}


void SecondaryPlayer::setTexture(sf::Texture& texture)
{
	//this->playerhitbox.setTexture(texture);
}



void SecondaryPlayer::setPosition(const float x, const float y)
{
	this->SecondaryPlayerhitbox.setPosition(x, y);
}

const sf::Vector2f SecondaryPlayer::getPosition()
{
	return this->SecondaryPlayerhitbox.getPosition();
}

sf::Vector2f SecondaryPlayer::getScale()
{
	return SecondaryPlayerSprite.getScale();
}


void SecondaryPlayer::setVelocity(const float dir_x, const float dir_y)
{
	this->velocity.x = dir_x;
	this->velocity.y = dir_y;
}

void SecondaryPlayer::setVelocityX(const float dir_x)
{
	this->velocity.x = dir_x;
}

void SecondaryPlayer::setVelocityY(const float dir_y)
{
	this->velocity.y = dir_y;
}






//constructurs
SecondaryPlayer::SecondaryPlayer(float x, float y, float& gridSize, sf::Texture texture)
{
	this->SecondaryPlayerhitbox.setSize(sf::Vector2f(gridSize, gridSize));

	this->SecondaryPlayerhitbox.setPosition(x, y);

	this->gridSize = gridSize;

	this->texture = texture;



	this->initVariables();

}

SecondaryPlayer::~SecondaryPlayer()
{
}


sf::Vector2f SecondaryPlayer::getVelocity()
{
	return this->velocity;
}


void SecondaryPlayer::updateMove(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		keytime += dt;
	}
	else
	{
		keytime = 0.f;
	}

	if (keytime <= keytimeMax && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		velocity.y += -JumpAndFallSpeed * dt;
	else
		velocity.y += JumpAndFallSpeed * dt;

	velocity.x = 0.f;

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//{
	//	velocity.y += -movementSpeed * dt;
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	//{
	//	velocity.y += movementSpeed * dt;
	//}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		velocity.x += -movementSpeed * dt;
		this->SecondaryPlayerSprite.setScale(sf::Vector2f(-0.5f, 0.5f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		velocity.x += movementSpeed * dt;
		this->SecondaryPlayerSprite.setScale(sf::Vector2f(0.5f, 0.5f));
	}


	this->SecondaryPlayerhitbox.move(velocity);
}


void SecondaryPlayer::update(const float& dt)
{
	this->SecondaryPlayerSprite.setTexture(texture);

	if (SecondaryPlayerSprite.getScale().x < 0)
		this->SecondaryPlayerSprite.setPosition(sf::Vector2f(SecondaryPlayerhitbox.getPosition().x + 40.f, SecondaryPlayerhitbox.getPosition().y));
	else
		this->SecondaryPlayerSprite.setPosition(sf::Vector2f(SecondaryPlayerhitbox.getPosition().x, SecondaryPlayerhitbox.getPosition().y));

}


void SecondaryPlayer::render(sf::RenderTarget* target)
{
	target->draw(this->SecondaryPlayerSprite);
}