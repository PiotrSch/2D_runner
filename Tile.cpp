#include "Tile.h"


void Tile::initVariables()
{


}






void Tile::setPosition(float i_x, float i_y)
{
	this->tilehitbox.setPosition(i_x, i_y);
}

void Tile::setSize(const float x, const float y)
{
	this->tilehitbox.setSize(sf::Vector2f(x, y));
}

const sf::Vector2f& Tile::getPosition() const
{
	return this->tilehitbox.getPosition();
}

void Tile::setTexture(sf::Texture& texture)
{
	this->tilehitbox.setTexture(&texture);
}


Tile::Tile(float x, float y,/* bool isTransparent,*/ sf::Texture& texture_sheet, float offset_x, float offset_y, float width, float height)
	:offsetX(offset_x), offsetY(offset_y)
{
	this->tilehitbox.setPosition(x, y);
	this->tilehitbox.setSize(sf::Vector2f(width, height));

	texture = texture_sheet;

	this->tileSprite.setTexture(texture);
	this->tileSprite.setScale(0.25f, 0.25f);
	this->tileSprite.setPosition(sf::Vector2f(tilehitbox.getPosition()));
	this->initVariables();




	//this->setTransparency()
	//this->platform.setPosition(this->tilehitbox.getPosition().x + offset_x, this->tilehitbox.getPosition().y + offset_y);
	//this->platform.setScale(2.f, 2.f);
	//this->platform.setTexture(texture_sheet);

}

Tile::~Tile()
{
}

//
//const sf::Vector2f& Tile::getTilePosition() const
//{
//	return this->hitbox.getPosition();
//}
//
//const sf::FloatRect Tile::getGlobalBounds() const
//{
//	return this->hitbox.getGlobalBounds();
//}
//
//void Tile::setTilePosition(const float x, const float y)
//{
//	this->hitbox.setPosition(x, y);
//}



void Tile::update()
{

}

void Tile::render(sf::RenderTarget* target)
{
	target->draw(this->tileSprite);
}

















