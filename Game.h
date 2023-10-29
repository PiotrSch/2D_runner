#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>
#include "Player.h"
#include "Tile.h"
#include "Grid.h"
#include "SecondaryPlayer.h"
#include "Bullet.h"
#include <vector>
#include <array>
#include <sstream>


class Game
{
private:
	sf::RenderWindow* window;
	Player* player;
	SecondaryPlayer* secondaryPlayer;
	Grid* grid;
	sf::Event event;





	float randTilePosX;
	float randTilePosY;

	sf::Texture PlayerTexture;
	sf::Texture SecondaryPlayerTexture;
	sf::Texture BulletTexture;

	bool Endgame;

	sf::Clock dtClock;
	float dt;


	float keytimePlayer;
	float keytimeMaxPlayer;

	float keytimeSecPlayer;
	float keytimeMaxSecPlayer;

	float HitTimerPlayer;
	float HitTimerPlayerMax;

	float HitTimerSecPlayer;
	float HitTimerSecPlayerMax;

	//Bullet
	Bullet b1_Player;
	std::vector<Bullet> bullets_Player;

	Bullet b1_SecPlayer;
	std::vector<Bullet> bullets_SecPlayer;

	sf::RectangleShape tile;
	std::vector<sf::RectangleShape> tiles;
	sf::Sprite tileSprite;	
	std::vector<sf::Sprite> tile_Sprites;	
	sf::Texture TileTexture;


	//gridTutorial---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	float gridSize;


	
	
	//Collision dectection tutorial--------------------------------------------------------

	sf::RectangleShape rTop_player;
	sf::RectangleShape rLeft_player;
	sf::RectangleShape rBottom_player;
	sf::RectangleShape rRight_player;


	sf::RectangleShape rTop_secplayer;
	sf::RectangleShape rLeft_secplayer;
	sf::RectangleShape rBottom_secplayer;
	sf::RectangleShape rRight_secplayer;


	int HP_player;
	int HP_secplayer;
	//Font------------------------------------------------------------------------------

	sf::Font font;
	sf::Text text_player;
	sf::Text text_secplayer;



public:
	Game();
	~Game();

	//inits
	
	void initCollisionRect();
	void initVariables();
	void initRandTilePos();
	void initPlayerTexture();
	void initBulletTexture();
	void initSecondaryTexture();
	void initTileTexture();
	void initTiles();
	void initFont();
	void initFontSec();


	void createPlayer(float x, float y, float& gridSize, sf::Texture texture);
	void createSecondaryPlayer(float x, float y, float& gridSize, sf::Texture texture);
	void createGrid(float gridSize, float gridAmountX, float gridAmountY, sf::Vector2f RectsizeX, sf::Vector2f RectsizeY, sf::Color fillColorX, sf::Color fillColorY);

	//funktions

	const bool getEndGame() const;
	const bool running() const;

	void stopVelocityWallPlayer();
	void stopVelocityWallSecondaryPlayer();

	void updateDt();
	void updateHP_Player();
	void updateHP_SecPlayer();
	void updateBulletPlayer();
	void updateBulletSecondaryPlayer();
	void updateTilesLvL1();
	void updateGridPosition();
	void updateCRectPlayer();
	void updateCRectSecondaryPlayer();
	void updateFontplayer();
	void updateFontsecplayer();


	void update();

	void render();
	void run();

};

