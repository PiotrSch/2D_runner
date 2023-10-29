#include "Game.h"
#include <iostream>

//to do: 
// everythink smaler
// website where u can download all games
// textures and map
// 



void Game::initCollisionRect()
{
	this->rTop_player.setSize(sf::Vector2f(gridSize - 2.f, gridSize - 2.f));
	this->rTop_player.setFillColor(sf::Color::Yellow);
	this->rTop_player.setOutlineColor(sf::Color::Black);

	this->rRight_player.setSize(sf::Vector2f(gridSize - 2.f, gridSize - 2.f));
	this->rRight_player.setFillColor(sf::Color::Yellow);
	this->rRight_player.setOutlineColor(sf::Color::Black);

	this->rLeft_player.setSize(sf::Vector2f(gridSize - 2.f, gridSize - 2.f));
	this->rLeft_player.setFillColor(sf::Color::Yellow);
	this->rLeft_player.setOutlineColor(sf::Color::Black);

	this->rBottom_player.setSize(sf::Vector2f(gridSize - 2.f, gridSize - 2.f));
	this->rBottom_player.setFillColor(sf::Color::Yellow);
	this->rBottom_player.setOutlineColor(sf::Color::Black);


	this->rTop_secplayer.setSize(sf::Vector2f(gridSize - 2.f, gridSize - 2.f));
	this->rTop_player.setFillColor(sf::Color::Yellow);
	this->rTop_player.setOutlineColor(sf::Color::Black);

	this->rRight_secplayer.setSize(sf::Vector2f(gridSize - 2.f, gridSize - 2.f));
	this->rRight_secplayer.setFillColor(sf::Color::Yellow);
	this->rRight_secplayer.setOutlineColor(sf::Color::Black);

	this->rLeft_secplayer.setSize(sf::Vector2f(gridSize - 2.f, gridSize - 2.f));
	this->rLeft_secplayer.setFillColor(sf::Color::Yellow);
	this->rLeft_secplayer.setOutlineColor(sf::Color::Black);

	this->rBottom_secplayer.setSize(sf::Vector2f(gridSize - 2.f, gridSize - 2.f));
	this->rBottom_secplayer.setFillColor(sf::Color::Yellow);
	this->rBottom_secplayer.setOutlineColor(sf::Color::Black);
}
void Game::initTiles()
{
	tile.setFillColor(sf::Color::Red);
	tile.setSize(sf::Vector2f(gridSize, gridSize));
	tile.setPosition(gridSize * 5, gridSize * 2);

	tiles.push_back(this->tile);
}

void Game::initFont()
{
	if (!font.loadFromFile("textures/Font/Dosis-Light.ttf"))
	{
		std::cout << "font could not load\n";
	}

	this->text_player.setFont(this->font);
	this->text_player.setCharacterSize(24);
	this->text_player.setFillColor(sf::Color::Green);
	this->text_secplayer.setPosition(0, 0);



}

void Game::initFontSec()
{
	this->text_secplayer.setFont(this->font);
	this->text_secplayer.setCharacterSize(24);
	this->text_secplayer.setFillColor(sf::Color::Green);
	this->text_secplayer.setPosition(gridSize * 10, 0);
}


void Game::initVariables()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "TestName");

	player = NULL;
	secondaryPlayer = NULL;


	this->initCollisionRect();
	this->initRandTilePos();
	this->initPlayerTexture();
	this->initSecondaryTexture();
	this->initBulletTexture();
	this->initTileTexture();
	this->initTiles();
	this->initFont();
	this->initFontSec();

	
	this->gridSize = 40.f;


	this->keytimePlayer = 0.f;
	this->keytimeMaxPlayer = 0.003f;


	this->keytimeSecPlayer = 0.f;
	this->keytimeMaxSecPlayer = 0.003f;


	HP_player = 100;
	HP_secplayer = 100;
	
	this->HitTimerPlayer = 0.f;
	this->HitTimerPlayerMax = 0.0007f;

	this->HitTimerSecPlayer = 0.f;
	this->HitTimerSecPlayerMax = 0.0007f;
}

void Game::initRandTilePos()
{
	srand((unsigned int)time(NULL));

	this->randTilePosX = rand() % (this->window->getSize().x);
	this->randTilePosY = rand() % (this->window->getSize().y);


}

void Game::initPlayerTexture()
{
	if (!PlayerTexture.loadFromFile("textures/PlayerTexture/PLAYER_GHOST_noBG.png")) // player texture
	{
		std::cout << "ERROR: PLAYER TEXTURE COULD NOT LOAD! \n";
	}
}

void Game::initBulletTexture()
{
	if (!BulletTexture.loadFromFile("textures/TileSheet/TileSheet1.png"))
	{
		std::cout << "ERROR: BULLETTEXTURE COULD NOT BE LOADED! \n";
	}
}

void Game::initSecondaryTexture()// finish secondary player and bullet
{
	if (!SecondaryPlayerTexture.loadFromFile("textures/PlayerTexture/SecondaryPlayer_noBG.png"))
	{
		std::cout << "ERROR: SECONDARYPLAYER TEXTURE COULD NOT LOAD! \n";
	}
}

void Game::initTileTexture()
{
	if (!TileTexture.loadFromFile("textures/TileSheet/tileTexture_pinkblue_noBG.png")) // player texture
	{
		std::cout << "ERROR: PLAYER TEXTURE COULD NOT LOAD! \n";
	}    
}


void Game::createPlayer(float x, float y, float& gridSize, sf::Texture texture)
{
	this->player = new Player(x, y, gridSize, texture);
}

void Game::createSecondaryPlayer(float x, float y, float& gridSize, sf::Texture texture)
{
	this->secondaryPlayer = new SecondaryPlayer(x, y, gridSize, texture); 
}


void Game::createGrid(float gridSize, float gridAmountX, float gridAmountY, sf::Vector2f RectsizeX, sf::Vector2f RectsizeY, sf::Color fillColorX, sf::Color fillColorY)
{
	this->grid = new Grid(gridSize, gridAmountX, gridAmountY, RectsizeX, RectsizeY, fillColorX, fillColorY);
}


Game::Game()
{
	this->initVariables();
	this->createPlayer(gridSize * 5,gridSize * 1, gridSize, PlayerTexture); 
	this->createSecondaryPlayer(gridSize * 14, gridSize * 1, gridSize, this->SecondaryPlayerTexture);
	this->createGrid(this->gridSize, this->window->getSize().x / this->gridSize, this->window->getSize().y / this->gridSize, sf::Vector2f(1.f, this->window->getSize().y), sf::Vector2f(this->window->getSize().x, 1.f), sf::Color::Green, sf::Color::Red);
}

Game::~Game()
{
	delete this->window;

	
}





//to do:
//make fps font
//make animations and background



const bool Game::getEndGame() const
{
	return this->Endgame;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

//float Game::getMousePositionX()
//{
//	return sf::Mouse::getPosition().x;
//}


void Game::stopVelocityWallPlayer()
{
	//check right wall 
	if (this->player->playerhitbox.getPosition().x < 0.f)
	{
		this->player->playerhitbox.setPosition(0.f, this->player->playerhitbox.getPosition().y);
		this->player->setPosition(0.f, this->player->playerhitbox.getPosition().y);
	}

	if (this->player->playerhitbox.getPosition().x + this->player->playerhitbox.getSize().x > this->window->getSize().x)
	{
		this->player->playerhitbox.setPosition(this->window->getSize().x - this->player->playerhitbox.getSize().x, this->player->playerhitbox.getPosition().y);
		this->player->setPosition(this->window->getSize().x - this->player->playerhitbox.getSize().x, this->player->playerhitbox.getPosition().y);
	}

	if (this->player->playerhitbox.getPosition().y < 0.f)
	{
		this->player->playerhitbox.setPosition(this->player->playerhitbox.getPosition().x, 0.f);
		this->player->setPosition(this->player->playerhitbox.getPosition().x, 0.f);
	}

	if (this->player->playerhitbox.getPosition().y + this->player->playerhitbox.getSize().y > this->window->getSize().y)
	{
		this->player->playerhitbox.setPosition(this->player->playerhitbox.getPosition().x, this->window->getSize().y - this->player->playerhitbox.getSize().y);
		this->player->setPosition(this->player->playerhitbox.getPosition().x, this->window->getSize().y - this->player->playerhitbox.getSize().y);
	}
}

void Game::stopVelocityWallSecondaryPlayer()
{
	//check right wall 
	if (this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().x < 0.f)
	{
		this->secondaryPlayer->SecondaryPlayerhitbox.setPosition(0.f, this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().y);
		this->secondaryPlayer->setPosition(0.f, this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().y);

	}

	if (this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().x + this->player->playerhitbox.getSize().x > this->window->getSize().x)
	{
		this->secondaryPlayer->SecondaryPlayerhitbox.setPosition(this->window->getSize().x - this->secondaryPlayer->SecondaryPlayerhitbox.getSize().x, this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().y);
		this->secondaryPlayer->setPosition(this->window->getSize().x - this->secondaryPlayer->SecondaryPlayerhitbox.getSize().x, this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().y);

	}

	if (this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().y < 0.f)
	{
		this->secondaryPlayer->SecondaryPlayerhitbox.setPosition(this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().x, 0.f);
		this->secondaryPlayer->setPosition(this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().x, 0.f);

	}

	if (this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().y + this->secondaryPlayer->SecondaryPlayerhitbox.getSize().y > this->window->getSize().y)
	{
		this->secondaryPlayer->SecondaryPlayerhitbox.setPosition(this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().x, this->window->getSize().y - this->secondaryPlayer->SecondaryPlayerhitbox.getSize().y);
		this->secondaryPlayer->setPosition(this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().x, this->window->getSize().y - this->secondaryPlayer->SecondaryPlayerhitbox.getSize().y);

	}
}

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateHP_Player()
{
	bool isHit = false;
	for (int i = 0; i < bullets_SecPlayer.size(); i++)
	{

		if (this->player->playerhitbox.getPosition().x + this->player->playerhitbox.getSize().x >= this->bullets_SecPlayer[i].CShape.getPosition().x &&
			this->player->playerhitbox.getPosition().x <= this->bullets_SecPlayer[i].CShape.getPosition().x + this->bullets_SecPlayer[i].CShape.getRadius() &&
			this->player->playerhitbox.getPosition().y + this->player->playerhitbox.getSize().y >= this->bullets_SecPlayer[i].CShape.getPosition().y &&
			this->player->playerhitbox.getPosition().y <= this->bullets_SecPlayer[i].CShape.getPosition().y + this->bullets_SecPlayer[i].CShape.getRadius())
		{
			isHit = true;
		}
	}
	if (isHit)
		this->HitTimerPlayer += dt;
	else
		this->HitTimerPlayer = 0;
		
	if (isHit && this->HitTimerPlayer <= HitTimerPlayerMax)
	{
		HP_player -= 1;
		std::cout << "P: " << HP_player << std::endl;
	}

}

void Game::updateHP_SecPlayer()
{
	bool isHit = false;
	for (int i = 0; i < bullets_Player.size(); i++)
	{

		if (this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().x + this->secondaryPlayer->SecondaryPlayerhitbox.getSize().x >= this->bullets_Player[i].CShape.getPosition().x &&
			this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().x <= this->bullets_Player[i].CShape.getPosition().x + this->bullets_Player[i].CShape.getRadius() &&
			this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().y + this->secondaryPlayer->SecondaryPlayerhitbox.getSize().y >= this->bullets_Player[i].CShape.getPosition().y &&
			this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().y <= this->bullets_Player[i].CShape.getPosition().y + this->bullets_Player[i].CShape.getRadius())
		{
			isHit = true;
		}
	}
	if (isHit)
		this->HitTimerSecPlayer += dt;
	else
		this->HitTimerSecPlayer = 0;

	if (isHit && this->HitTimerSecPlayer <= HitTimerSecPlayerMax)
	{
		HP_secplayer -= 1;
		std::cout << "S: " << HP_secplayer << std::endl;
	}
}


void Game::updateBulletPlayer() 
{
	// to do: Make Bullet speed independend of FPS



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		this->keytimePlayer += dt;
	else
		this->keytimePlayer = 0;
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && this->player->getScale().x >= 0 && this->keytimePlayer <= keytimeMaxPlayer)
	{
		b1_Player.CShape.setPosition(this->player->getPosition().x, this->player->getPosition().y);
		b1_Player.currentVelocityX = (this->b1_Player.maxVelocity);

		
		bullets_Player.push_back(Bullet(b1_Player));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)&& this->player->getScale().x < 0 && this->keytimePlayer <= keytimeMaxPlayer)
	{
		b1_Player.CShape.setPosition(this->player->getPosition().x, this->player->getPosition().y);
		b1_Player.currentVelocityX = -this->b1_Player.maxVelocity;

		
		bullets_Player.push_back(Bullet(b1_Player));
	}
	for (size_t i = 0; i < bullets_Player.size(); i++)
	{
		bullets_Player[i].move(bullets_Player[i].currentVelocityX,0, dt); // FINISH !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		if (bullets_Player[i].CShape.getPosition().x < 0 || bullets_Player[i].CShape.getPosition().x > this->window->getSize().x || bullets_Player[i].CShape.getPosition().y < 0 || bullets_Player[i].CShape.getPosition().y > window->getSize().y)
		{
			bullets_Player.erase(bullets_Player.begin() + i); // deletes all bullets outside the screen
		}
	}
}

void Game::updateBulletSecondaryPlayer()
{

	//std::cout << keytime << std::endl;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		this->keytimeSecPlayer += dt;
	else
		this->keytimeSecPlayer = 0;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && this->secondaryPlayer->getScale().x >= 0 && this->keytimeSecPlayer <= keytimeMaxSecPlayer)
	{
		b1_SecPlayer.CShape.setPosition(this->secondaryPlayer->getPosition().x, this->secondaryPlayer->getPosition().y);
		b1_SecPlayer.currentVelocityX = (this->b1_SecPlayer.maxVelocity);


		bullets_SecPlayer.push_back(Bullet(b1_SecPlayer));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && this->secondaryPlayer->getScale().x < 0 && this->keytimeSecPlayer <= keytimeMaxSecPlayer)
	{
		b1_SecPlayer.CShape.setPosition(this->secondaryPlayer->getPosition().x, this->secondaryPlayer->getPosition().y);
		b1_SecPlayer.currentVelocityX = -this->b1_SecPlayer.maxVelocity;


		bullets_SecPlayer.push_back(Bullet(b1_SecPlayer));
	}
	for (size_t i = 0; i < bullets_SecPlayer.size(); i++)
	{
		bullets_SecPlayer[i].CShape.move(bullets_SecPlayer[i].currentVelocityX, 0);

		if (bullets_SecPlayer[i].CShape.getPosition().x < 0 || bullets_SecPlayer[i].CShape.getPosition().x > this->window->getSize().x || bullets_SecPlayer[i].CShape.getPosition().y < 0 || bullets_SecPlayer[i].CShape.getPosition().y > window->getSize().y)
		{
			bullets_SecPlayer.erase(bullets_SecPlayer.begin() + i); // deletes all bullets outside the screen
		}
	}
}



void Game::updateTilesLvL1()
{
	bool exists = false;
	short maxSize = 40;

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 3, gridSize * 13);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 4, gridSize * 13);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}
	
	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 5, gridSize * 13);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 6, gridSize * 13);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	//1111111111111111111111


	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 13, gridSize * 13);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 14, gridSize * 13);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 15, gridSize * 13);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 16, gridSize * 13);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	//22222222222222222222222222222222

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 8, gridSize * 11);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 9, gridSize * 11);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 10, gridSize * 11);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 11, gridSize * 11);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}


	//333333333333333333333333333333333
	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 3, gridSize * 9);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 4, gridSize * 9);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 5, gridSize * 9);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 6, gridSize * 9);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	//44444444444444444444444444444444


	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 13, gridSize * 9);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 14, gridSize * 9);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 15, gridSize * 9);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 16, gridSize * 9);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	//5555555555555555555555555555555555555555

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 8, gridSize * 7);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 9, gridSize * 7);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 10, gridSize * 7);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 11, gridSize * 7);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	//66666666666666666666666666666666666666666

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 9, gridSize * 3);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 10, gridSize * 3);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}


	//777777777777777777777777777777777777777777


	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 6, gridSize * 5);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 5, gridSize * 5);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 13, gridSize * 5);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 14, gridSize * 5);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}


	//8888888888888888888888888888888888888888888888

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 1, gridSize * 7);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 2, gridSize * 7);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 17, gridSize * 7);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

	if (!exists && tiles.size() <= maxSize)
	{
		tile.setPosition(gridSize * 18, gridSize * 7);
		tile.setSize(sf::Vector2f(gridSize, gridSize));
		tileSprite.setPosition(sf::Vector2f(tile.getPosition()));
		tileSprite.setTexture(TileTexture);
		tileSprite.setScale(sf::Vector2f(0.5f, 0.5f));
		tile_Sprites.push_back(tileSprite);
		tiles.push_back(tile);
	}

}

void Game::updateGridPosition()
{
	this->grid->getGridPosition();


}

void Game::updateCRectPlayer() // fucking collision detection
{

	bool RightC = false;
	bool LeftC = false;
	bool TopC = false;
	bool BottomC = false;
	bool PlayerC = false;

	//Top
	this->rTop_player.setPosition(player->getPosition().x + 1.f, player->getPosition().y - gridSize);
	this->rTop_player.setFillColor(sf::Color::Yellow);
	this->rTop_player.setSize(sf::Vector2f(gridSize - 2.f, gridSize / 3.f));

	//Right
	this->rRight_player.setPosition(player->getPosition().x + gridSize, player->getPosition().y + 1.f);
	this->rRight_player.setFillColor(sf::Color::Yellow);
	this->rRight_player.setSize(sf::Vector2f(gridSize / 3.f, gridSize - 2.f));

	//Left
	this->rLeft_player.setPosition(player->getPosition().x - gridSize, player->getPosition().y + 1.f);
	this->rLeft_player.setFillColor(sf::Color::Yellow);
	this->rLeft_player.setSize(sf::Vector2f(gridSize / 3.f, gridSize - 2.f));

	//Bottom
	this->rBottom_player.setPosition(player->getPosition().x + 1.f, player->getPosition().y + gridSize);
	this->rBottom_player.setFillColor(sf::Color::Yellow);
	this->rBottom_player.setSize(sf::Vector2f(gridSize - 2.f, gridSize / 3.f));

	for (int i = 0; i < tiles.size(); i++) 
	{

		if (this->player->playerhitbox.getPosition().x + this->player->playerhitbox.getSize().x >= this->tiles[i].getPosition().x &&
			this->player->playerhitbox.getPosition().x <= this->tiles[i].getPosition().x + this->tiles[i].getSize().x &&
			this->player->playerhitbox.getPosition().y + this->player->playerhitbox.getSize().y >= this->tiles[i].getPosition().y &&
			this->player->playerhitbox.getPosition().y <= this->tiles[i].getPosition().y + this->tiles[i].getSize().y)
		{
			if (rTop_player.getPosition().x + rTop_player.getSize().x >= this->tiles[i].getPosition().x &&
				rTop_player.getPosition().x <= this->tiles[i].getPosition().x + this->tiles[i].getSize().x &&
				rTop_player.getPosition().y + rTop_player.getSize().y >= this->tiles[i].getPosition().y &&
				rTop_player.getPosition().y <= this->tiles[i].getPosition().y + this->tiles[i].getSize().y
				&& this->player->getVelocity().y < 0)
			{
				player->playerhitbox.setPosition(player->playerhitbox.getPosition().x, this->tiles[i].getPosition().y + this->tiles[i].getSize().y + 0.5f);
			}


			if (rBottom_player.getPosition().x + rBottom_player.getSize().x >= this->tiles[i].getPosition().x &&
				rBottom_player.getPosition().x <= this->tiles[i].getPosition().x + this->tiles[i].getSize().x &&
				rBottom_player.getPosition().y + rBottom_player.getSize().y >= this->tiles[i].getPosition().y &&
				rBottom_player.getPosition().y <= this->tiles[i].getPosition().y + this->tiles[i].getSize().y
				&& this->player->getVelocity().y > 0)
			{
				player->playerhitbox.setPosition(this->player->playerhitbox.getPosition().x, this->tiles[i].getPosition().y - this->player->playerhitbox.getSize().y - 0.5f);
			}


			if (rRight_player.getPosition().x + rRight_player.getSize().x >= this->tiles[i].getPosition().x &&
				rRight_player.getPosition().x <= this->tiles[i].getPosition().x + this->tiles[i].getSize().x &&
				rRight_player.getPosition().y + rRight_player.getSize().y >= this->tiles[i].getPosition().y &&
				rRight_player.getPosition().y <= this->tiles[i].getPosition().y + this->tiles[i].getSize().y
				&& this->player->getVelocity().x > 0)
			{
				player->playerhitbox.setPosition(this->tiles[i].getPosition().x - this->player->playerhitbox.getSize().x - 0.5f, this->player->playerhitbox.getPosition().y);
			}



			if (rLeft_player.getPosition().x + rLeft_player.getSize().x >= this->tiles[i].getPosition().x &&
				rLeft_player.getPosition().x <= this->tiles[i].getPosition().x + this->tiles[i].getSize().x &&
				rLeft_player.getPosition().y + rLeft_player.getSize().y >= this->tiles[i].getPosition().y &&
				rLeft_player.getPosition().y <= this->tiles[i].getPosition().y + this->tiles[i].getSize().y
				&& this->player->getVelocity().x < 0)
			{
				player->playerhitbox.setPosition(this->tiles[i].getPosition().x + this->tiles[i].getSize().x + 0.5f, this->player->playerhitbox.getPosition().y);
			}
		}
	}
}




void Game::updateCRectSecondaryPlayer()
{
	bool RightC = false;
	bool LeftC = false;
	bool TopC = false;
	bool BottomC = false;
	bool PlayerC = false;

	//Top
	this->rTop_secplayer.setPosition(secondaryPlayer->getPosition().x + 1.f, secondaryPlayer->getPosition().y - gridSize);
	this->rTop_secplayer.setSize(sf::Vector2f(gridSize - 2.f, gridSize / 3.f));

	//Right
	this->rRight_secplayer.setPosition(secondaryPlayer->getPosition().x + gridSize, secondaryPlayer->getPosition().y + 1.f);
	this->rRight_secplayer.setSize(sf::Vector2f(gridSize / 3.f, gridSize - 2.f));

	//Left
	this->rLeft_secplayer.setPosition(secondaryPlayer->getPosition().x - gridSize, secondaryPlayer->getPosition().y + 1.f);
	this->rLeft_secplayer.setSize(sf::Vector2f(gridSize / 3.f, gridSize - 2.f));

	//Bottom
	this->rBottom_secplayer.setPosition(secondaryPlayer->getPosition().x + 1.f, secondaryPlayer->getPosition().y + gridSize);
	this->rBottom_secplayer.setSize(sf::Vector2f(gridSize - 2.f, gridSize / 3.f));

	for (int i = 0; i < tiles.size(); i++)
	{

		if (this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().x + this->secondaryPlayer->SecondaryPlayerhitbox.getSize().x >= this->tiles[i].getPosition().x &&
			this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().x <= this->tiles[i].getPosition().x + this->tiles[i].getSize().x &&
			this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().y + this->secondaryPlayer->SecondaryPlayerhitbox.getSize().y >= this->tiles[i].getPosition().y &&
			this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().y <= this->tiles[i].getPosition().y + this->tiles[i].getSize().y)
		{
			if (rTop_secplayer.getPosition().x + rTop_secplayer.getSize().x >= this->tiles[i].getPosition().x &&
				rTop_secplayer.getPosition().x <= this->tiles[i].getPosition().x + this->tiles[i].getSize().x &&
				rTop_secplayer.getPosition().y + rTop_secplayer.getSize().y >= this->tiles[i].getPosition().y &&
				rTop_secplayer.getPosition().y <= this->tiles[i].getPosition().y + this->tiles[i].getSize().y
				&& this->secondaryPlayer->getVelocity().y < 0)
			{
				secondaryPlayer->SecondaryPlayerhitbox.setPosition(secondaryPlayer->SecondaryPlayerhitbox.getPosition().x, this->tiles[i].getPosition().y + this->tiles[i].getSize().y + 0.5f);
			}


			if (rBottom_secplayer.getPosition().x + rBottom_secplayer.getSize().x >= this->tiles[i].getPosition().x &&
				rBottom_secplayer.getPosition().x <= this->tiles[i].getPosition().x + this->tiles[i].getSize().x &&
				rBottom_secplayer.getPosition().y + rBottom_secplayer.getSize().y >= this->tiles[i].getPosition().y &&
				rBottom_secplayer.getPosition().y <= this->tiles[i].getPosition().y + this->tiles[i].getSize().y
				&& this->secondaryPlayer->getVelocity().y > 0)
			{
				secondaryPlayer->SecondaryPlayerhitbox.setPosition(this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().x, this->tiles[i].getPosition().y - this->secondaryPlayer->SecondaryPlayerhitbox.getSize().y - 0.5f);
			}


			if (rRight_secplayer.getPosition().x + rRight_secplayer.getSize().x >= this->tiles[i].getPosition().x &&
				rRight_secplayer.getPosition().x <= this->tiles[i].getPosition().x + this->tiles[i].getSize().x &&
				rRight_secplayer.getPosition().y + rRight_secplayer.getSize().y >= this->tiles[i].getPosition().y &&
				rRight_secplayer.getPosition().y <= this->tiles[i].getPosition().y + this->tiles[i].getSize().y
				&& this->secondaryPlayer->getVelocity().x > 0)
			{
				secondaryPlayer->SecondaryPlayerhitbox.setPosition(this->tiles[i].getPosition().x - this->secondaryPlayer->SecondaryPlayerhitbox.getSize().x - 0.5f, this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().y);
			}



			if (rLeft_secplayer.getPosition().x + rLeft_secplayer.getSize().x >= this->tiles[i].getPosition().x &&
				rLeft_secplayer.getPosition().x <= this->tiles[i].getPosition().x + this->tiles[i].getSize().x &&
				rLeft_secplayer.getPosition().y + rLeft_secplayer.getSize().y >= this->tiles[i].getPosition().y &&
				rLeft_secplayer.getPosition().y <= this->tiles[i].getPosition().y + this->tiles[i].getSize().y
				&& this->secondaryPlayer->getVelocity().x < 0)
			{
				secondaryPlayer->SecondaryPlayerhitbox.setPosition(this->tiles[i].getPosition().x + this->tiles[i].getSize().x + 0.5f, this->secondaryPlayer->SecondaryPlayerhitbox.getPosition().y);
			}
		}
	}
}



void Game::updateFontplayer()
{

	std::stringstream ss_player;
	this->text_secplayer.setPosition(gridSize * 10, 0);

	ss_player << "HP_player: " << this->HP_player << "\n";

	this->text_player.setString(ss_player.str());



}

void Game::updateFontsecplayer()
{
	std::stringstream ss_SecPlayer;
	this->text_secplayer.setPosition(gridSize * 15.9f, 0);

	ss_SecPlayer << "HP_SecPlayer: " << this->HP_secplayer << "\n";

	this->text_secplayer.setString(ss_SecPlayer.str());
}

void Game::update()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}
	//test
	this->player->update(dt);
	this->player->updateMove(dt);
	this->secondaryPlayer->update(dt);
	this->secondaryPlayer->updateMove(dt);
	this->updateCRectSecondaryPlayer();
	this->updateCRectPlayer();
	this->stopVelocityWallPlayer();
	this->stopVelocityWallSecondaryPlayer();
	this->updateBulletSecondaryPlayer();
	this->updateBulletPlayer();

	this->updateFontplayer();
	this->updateFontsecplayer();

	this->updateTilesLvL1();
	this->updateHP_Player();
	this->updateHP_SecPlayer();
}

void Game::render()
{

	//clear
	this->window->clear(sf::Color::White);


	//render

	//this->grid->render(this->window);

	for (size_t i = 0; i < bullets_Player.size(); i++)
	{
		window->draw(bullets_Player[i].CShape);
	}

	for (size_t i = 0; i < bullets_SecPlayer.size(); i++)
	{
		window->draw(bullets_SecPlayer[i].CShape);
	}


	this->player->render(this->window);
	this->secondaryPlayer->render(this->window);
	this->window->draw(this->text_player);
	this->window->draw(this->text_secplayer);



	for (size_t i = 0; i < tile_Sprites.size(); i++)
	{
		window->draw(tile_Sprites[i]);
	}



	//display
	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}