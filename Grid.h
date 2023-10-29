#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>

class Grid
{
private:
	sf::RectangleShape pixelX;
	sf::RectangleShape pixelY;

	//Grid
	float gridSize;
	float gridAmountX;
	float gridAmountY;
	sf::Vector2f RectSizeX;
	sf::Vector2f RectSizeY;
	sf::Color FillColorX;
	sf::Color FillColorY;

	
public:

	Grid(float gridSize, float gridAmountX, float gridAmountY, sf::Vector2f RectsizeX, sf::Vector2f RectsizeY, sf::Color fillColorX, sf::Color fillColorY);
	~Grid();
	void getGridPosition();

	void update();
	void render(sf::RenderTarget* target);
};