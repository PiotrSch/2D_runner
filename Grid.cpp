#include "Grid.h"


Grid::Grid(float gridSize, float gridAmountX, float gridAmountY, sf::Vector2f RectsizeX, sf::Vector2f RectsizeY, sf::Color fillColorX, sf::Color fillColorY)
{
	this->gridSize = gridSize;
	this->gridAmountX = gridAmountX; 
	this->gridAmountY = gridAmountY;
	this->RectSizeX = RectsizeX;
	this->RectSizeY = RectsizeY;
	this->FillColorX = fillColorX;
	this->FillColorY = fillColorY;
}

Grid::~Grid()
{

}

void Grid::getGridPosition()
{
}



void Grid::update()
{

}

void Grid::render(sf::RenderTarget* target)
{
	for (int i = 0; i < gridAmountX; i++)
	{
		pixelX.setPosition(gridSize * i, 0.f);
		pixelX.setSize(RectSizeX);
		pixelX.setFillColor(FillColorX);

		
		target->draw(pixelX);
		for (int j = 0; j < gridAmountY; j++)
		{
			pixelY.setPosition(0.f, gridSize * j);
			pixelY.setSize(RectSizeY);
			pixelY.setFillColor(FillColorY);
			//this->gridPosY = j;
			target->draw(pixelY);
		}
		
	}
}
