#include <SFML/Graphics.hpp>
#include <iostream>
#include<time.h>
#include <stdlib.h> 
#include <Windows.h>
#define HEIGHT 768
#define WIDTH 1024
int tetromino[7][4][4][4]{
	{	// Z
		{
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0},
		{0,0,0,0}
		},
		{
		{0,0,1,0},
		{0,1,1,0},
		{0,1,0,0},
		{0,0,0,0}
		},
		{
		{0,0,0,0},
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0}
		},
		{
		{0,1,0,0},
		{1,1,0,0},
		{1,0,0,0},
		{0,0,0,0}
		},
	},

	{	// L
		{
		{0,0,1,0},
		{1,1,1,0},
		{0,0,0,0},
		{0,0,0,0}
		},
		{
		{0,1,0,0},
		{0,1,0,0},
		{0,1,1,0},
		{0,0,0,0}
		},
		{
		{0,0,0,0},
		{1,1,1,0},
		{1,0,0,0},
		{0,0,0,0}
		},
		{
		{1,1,0,0},
		{0,1,0,0},
		{0,1,0,0},
		{0,0,0,0}
		},
	},
	{ // O
		{
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0},
		{0,0,0,0}
		},
		{
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0},
		{0,0,0,0}
		},
		{
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0},
		{0,0,0,0}
		},
		{
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0},
		{0,0,0,0}
		},
	},
	{ // S
		{
		{0,1,1,0},
		{1,1,0,0},
		{0,0,0,0},
		{0,0,0,0},
		},
		{
		{0,1,0,0},
		{0,1,1,0},
		{0,0,1,0},
		{0,0,0,0},
		},
		{
		{0,0,0,0},
		{0,1,1,0},
		{1,1,0,0},
		{0,0,0,0},
		},
		{
		{1,0,0,0},
		{1,1,0,0},
		{0,1,0,0},
		{0,0,0,0},
		},
	},
	{ // I
		{
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0},
		{0,0,0,0},
		},
		{
		{0,0,1,0},
		{0,0,1,0},
		{0,0,1,0},
		{0,0,1,0},
		},
		{
		{0,0,0,0},
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0},
		},
		{
		{0,1,0,0},
		{0,1,0,0},
		{0,1,0,0},
		{0,1,0,0},
		},
	},
	{ // J
		{
		{1,0,0,0},
		{1,1,1,0},
		{0,0,0,0},
		{0,0,0,0},
		},
		{
		{0,1,1,0},
		{0,1,0,0},
		{0,1,0,0},
		{0,0,0,0},
		},
		{
		{0,0,0,0},
		{1,1,1,0},
		{0,0,1,0},
		{0,0,0,0},
		},
		{
		{0,1,0,0},
		{0,1,0,0},
		{1,1,0,0},
		{0,0,0,0},
		},
	},
	{ // T
		{
		{0,1,0,0},
		{1,1,1,0},
		{0,0,0,0},
		{0,0,0,0},
		},
		{
		{0,1,0,0},
		{0,1,1,0},
		{0,1,0,0},
		{0,0,0,0},
		},
		{
		{0,0,0,0},
		{1,1,1,0},
		{0,1,0,0},
		{0,0,0,0},
		},
		{
		{0,1,0,0},
		{1,1,0,0},
		{0,1,0,0},
		{0,0,0,0},
		},
	},
};
int grid[20][10] = {
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7},
	{7,7,7,7,7,7,7,7,7,7}

};
int screen_x = 150;
int screen_y = 150;
int tilePos_x = 9;
int tilePos_y = 0;
int coordX = 4;
int coordY = -1;
int type = 0;
int gg = 0;
int rotation = 0;
int positionX;
int positionY;
int check = 1;
int collision(int type, int tilePos_xx,int tilePos_yy,char Direction,int newRotation) {
	int newPositionX;
	int newPositionY;
	newRotation += rotation;
	if (newRotation > 4) {
		newRotation = 0;
	}
	else if (newRotation < 0) {
		newRotation = 3;
	}
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (tetromino[type][newRotation][y][x]) {
				newPositionX = (tilePos_xx + x) * 30;
				newPositionY = screen_y + ((tilePos_yy + y) * 30 - 30);
				if (Direction == 'l') {
					if ((newPositionX < screen_x || grid[coordY + y][coordX + x - 1] != 7)) {
						return TRUE;
					}
				}
				if (Direction == 'x') {
					if ((grid[coordY + y][coordX + x + 1] != 7) || newPositionX >= screen_x + (10 * 30)) {
					return TRUE;
					}
				}
				else if(Direction == 'y') {
					if (newPositionY >= screen_y + (20 * 30) || (grid[coordY + y + check][coordX + x] != 7)){
						return TRUE;
					}
				}
				else {
					// (newPositionY >= screen_y + (19 * 30)
					if (newPositionX < screen_x) {
						tilePos_x += 1;
						coordX += 1;
					}
					else if (newPositionX >= screen_x + (10 * 30)) {
						tilePos_x -= 1;
						coordX -= 1;
					}
					else if (newPositionY >= screen_y + (19 * 30)) {
						tilePos_y -= 1;
						coordY -= 1;

					}
				}
			}
		}
	}
	return FALSE;
}
int main(){
	ShowWindow(GetConsoleWindow(), SW_SHOW);
	sf::RenderWindow window(sf::VideoMode(600, 900), "Mykes", sf::Style::Close | sf::Style::Titlebar);
	
	//Frame Rate and Game Speed
	window.setFramerateLimit(60);
	sf::Clock clock;

	sf::Event e;
	sf::Texture tileTexture;
	tileTexture.loadFromFile("images/tiles.png");
	//sf::Texture gridTexture;
	//gridTexture.loadFromFile("images/gridTile.png");
	sf::Image icon;

	//sf::RectangleShape grid(sf::Vector2f(30, 30));

	//grid.setTexture(&gridTexture);
	sf::Sprite tile(tileTexture);
	tile.setTextureRect(sf::IntRect(0, 0, 30, 30));
	icon.loadFromFile("images/xie.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	while (window.isOpen())
	{
		static float prev = clock.getElapsedTime().asSeconds();
		if (clock.getElapsedTime().asSeconds() - prev >= 0.8)
		{
			if (collision(type, tilePos_x, tilePos_y + 1, 'y', 0)) {
				for (int x = 0; x < 4; x++) {
					for (int y = 0; y < 4; y++) {
						if (tetromino[type][rotation][y][x]) {
							grid[coordY + y][coordX + x] = type;
						}
					}
				}
				for (int x = 0; x < 20; x++) {
					int count = 0;
					for (int y = 0; y < 10; y++) {
						if (grid[x][y] != 7) {
							count += 1;
						}
					if (count == 10) {
						for (int r = x; r > 1; r--) {
							for (int y = 0; y < 10; y++) {
								grid[r][y] = grid[r - 1][y];
							}
							grid[8][10] = grid[7][10];
						}
						for (int x = 0; x < 10; x++) {
							grid[0][x] = 7;
						}
					}
						tile.setPosition(sf::Vector2f(screen_x + (x * 30), screen_y + (y * 30)));
						tile.setTextureRect(sf::IntRect(grid[y][x] * 30, 0, 30, 30));
						window.draw(tile);
					}
				}

				tilePos_x = 9;
				tilePos_y = 0;
				coordX = 4;
				coordY = -1;
				srand(time(NULL));

				type = rand() % 7 + 0;
				rotation = 0;
			}
			else {
				prev = clock.getElapsedTime().asSeconds();
				tilePos_y += 1;
				coordY += 1;
				printf("%d\n", tilePos_y);
			}
		}
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		if (e.key.code == sf::Keyboard::Space) {

		}
		window.clear();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
			static float prev = clock.getElapsedTime().asSeconds();
			if (clock.getElapsedTime().asSeconds() - prev >= 0.8)
			{
				prev = clock.getElapsedTime().asSeconds();
				type += 1;
				if (type >= 7) {
					type = 0;
				}
				rotation = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (collision(type, tilePos_x - 1, tilePos_y, 'l', 0)) {
				printf("SHIT");
			}
			else {
				static float prev = clock.getElapsedTime().asSeconds();
				if (clock.getElapsedTime().asSeconds() - prev >= 0.06)
				{
					prev = clock.getElapsedTime().asSeconds();
					tilePos_x -= 1;
					coordX -= 1;
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (collision(type, tilePos_x + 1, tilePos_y, 'x', 0)) {
				printf("SHIT");
			}
			else {
				static float prev = clock.getElapsedTime().asSeconds();
				if (clock.getElapsedTime().asSeconds() - prev >= 0.06)
				{
					prev = clock.getElapsedTime().asSeconds();
					tilePos_x += 1;
					coordX += 1;
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			check = 1;
			if (collision(type, tilePos_x, tilePos_y + 1, 'y', 0)) {
				printf("SHIT");
			}
			else {
				static float prev = clock.getElapsedTime().asSeconds();
				if (clock.getElapsedTime().asSeconds() - prev >= 0.06)
				{
					prev = clock.getElapsedTime().asSeconds();
					tilePos_y += 1;
					coordY += 1;
				}
			}
			check = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
			if (collision(type, tilePos_x, tilePos_y, 'r', -1)) {
				printf("SHIT");
			}
			else {
				static float prev = clock.getElapsedTime().asSeconds();
				if (clock.getElapsedTime().asSeconds() - prev >= 0.2)
				{
					prev = clock.getElapsedTime().asSeconds();
					rotation -= 1;
					if (rotation < 0) {
						rotation = 3;
					}
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (collision(type, tilePos_x, tilePos_y, 'r', 1)) {
				printf("SHIT");
			}
			else {
				static float prev = clock.getElapsedTime().asSeconds();
				if (clock.getElapsedTime().asSeconds() - prev >= 0.2)
				{
					prev = clock.getElapsedTime().asSeconds();
					rotation = int((rotation + 1) % 4);
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			bool blockInWay = FALSE;
			static float prev = clock.getElapsedTime().asSeconds();
			if (clock.getElapsedTime().asSeconds() - prev >= 1)
			{
				prev = clock.getElapsedTime().asSeconds();
				while (check <= 20 && blockInWay == FALSE) {
					if (collision(type, tilePos_x, tilePos_y + check, 'y', 0)) {
						tilePos_y = tilePos_y + check - 1;
						coordY = coordY + check - 1;
						check = 1;
						blockInWay = TRUE;
					}
					check += 1;
				if (blockInWay == FALSE){
					tilePos_y += 1;
					coordY +=1;
					check = 1;
					}
				}
			}
		}
		// Draw Board
		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 20; y++) {
				tile.setPosition(sf::Vector2f(screen_x + (x * 30), screen_y + (y * 30)));
				tile.setTextureRect(sf::IntRect(grid[y][x] * 30, 0, 30, 30));
				window.draw(tile);
			}
		}

		// Draw Tetrominos
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				if (tetromino[type][rotation][y][x]) {
					positionX = (tilePos_x + x) * 30;
					positionY = screen_y + ((tilePos_y + y) * 30 - 30);
					tile.setPosition(sf::Vector2f(positionX, positionY));
					tile.setTextureRect(sf::IntRect(type * 30, 0, 30, 30));
					window.draw(tile);

				}
			}
		}
		window.display();
	}
	return 0;
}
