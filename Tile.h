#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>
#include <cmath>


/*
TO DO:
	make precompiled headers for the sfml-files
	make Hitbox and collision
*/
class Tile
{
private:
	
	float offsetX; // tilemap with vector
	float offsetY;
	sf::Vector2f windowSize;
	sf::Texture texture;

public:

	sf::RectangleShape tilehitbox;
	sf::Sprite tileSprite;

	Tile(float x, float y, sf::Texture& texture_sheet, float offset_x, float offset_y, float width, float height);
	~Tile();

	void initVariables();


	//funktions
	void setPosition(float i_x, float i_y);
	void setSize(const float x, const float y);
	const sf::Vector2f& getPosition() const;
	
	void setTexture(sf::Texture& texture); // setTexture

	void update();
	void render(sf::RenderTarget* target);
};

