#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
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
int tilePos_x = 8;
int tilePos_y = 0;
int coordX = 3;
int coordY = -1;
int type = 0;
int gg = 0;
int rotation = 0;
int positionX;
int positionY;
int check = 1;
int holdPiece = 7;
int holdCount = 0;
int score = 0;
float speed = 0.3;
bool pieceDropped = FALSE;
int collision(int type, int tilePos_xx, int tilePos_yy, char Direction, int newRotation) {
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
					if (tilePos_y < 2) {
						if (newPositionX < screen_x) {
							return TRUE;
						}
					}
					else if (tilePos_y >= 2) {
						if ((newPositionX < screen_x || grid[coordY + y][coordX + x - 1] != 7)) {
							return TRUE;
						}
					}
				}
				if (Direction == 'x') {
					if (tilePos_y < 2) {
						if (newPositionX >= screen_x + (10 * 30)) {
							return TRUE;
						}
					}
					else if (tilePos_y >= 2) {
						if ((grid[coordY + y][coordX + x + 1] != 7) || newPositionX >= screen_x + (10 * 30)) {
							return TRUE;
						}
					}
				}
				else if (Direction == 'y') {
					if (newPositionY >= screen_y + (20 * 30) || (grid[coordY + y + check][coordX + x] != 7)) {
						return TRUE;
					}
				}
				else {
					// (newPositionY >= screen_y + (19 * 30)
					if ((grid[coordY + y][coordX + x] != 7)) {
						return TRUE;
					}
					if (newPositionX < screen_x) {
						tilePos_x += 1;
						coordX += 1;
					}
					else if (newPositionX >= screen_x + (10 * 30)) {
						tilePos_x -= 1;
						coordX -= 1;

					}
				}
			}
		}
	}
	return FALSE;
}
int main() {

	ShowWindow(GetConsoleWindow(), SW_SHOW);
	sf::RenderWindow window(sf::VideoMode(600, 900), "Tetris Metris", sf::Style::Close | sf::Style::Titlebar);

	//Frame Rate and Game Speed
	window.setFramerateLimit(60);
	sf::Clock clock;
	sf::SoundBuffer clearBuffer;
	clearBuffer.loadFromFile("sounds/clear.wav");
	sf::Sound clear;
	clear.setBuffer(clearBuffer);
	sf::SoundBuffer placeBuffer;
	placeBuffer.loadFromFile("sounds/place.wav");
	sf::Sound place;
	place.setBuffer(placeBuffer);

	sf::Font font;
	font.loadFromFile("fonts/MnPixel.ttf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(45);
	text.setFillColor(sf::Color::White);
	text.setString("0");
	text.setPosition(345, 818);
	sf::Event e;
	sf::Texture tileTexture;
	tileTexture.loadFromFile("images/tiles.png");
	sf::Image icon;
	sf::Texture layoutTexture;
	layoutTexture.loadFromFile("images/layout.png");
	sf::Sprite layout(layoutTexture);
	layout.setTextureRect(sf::IntRect(0, 0, 600, 900));
	sf::Texture bgTexture;
	bgTexture.loadFromFile("images/bg2.png");
	sf::Sprite bg(bgTexture);
	bg.setTextureRect(sf::IntRect(0, 0, 600, 900));
	sf::Sprite tile(tileTexture);
	tile.setTextureRect(sf::IntRect(0, 0, 30, 30));
	icon.loadFromFile("images/xie.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	srand(time(NULL));
	int rand1 = rand() % 7 + 0;
	srand(time(NULL));
	int rand2 = rand() % 7 + 0;
	type = rand1;
	if (rand1 == rand2) {
		if (rand2 <= 0) {
			rand2++;
		}
		else {
			rand2--;
		}
	}
	while (window.isOpen())
	{
		for (int x = 0; x < 10; x++) {
			if (grid[0][x] != 7) {
				exit(0);
			}
		}
		static float prev = clock.getElapsedTime().asSeconds();
		if (clock.getElapsedTime().asSeconds() - prev >= speed)
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
							score += 1;
							clear.play();
							text.setString(std::to_string(score));
							for (int r = x; r > 1; r--) {
								for (int y = 0; y < 10; y++) {
									grid[r][y] = grid[r - 1][y];
								}
								//grid[8][10] = grid[7][10];
							}
							for (int x = 0; x < 10; x++) {
								grid[0][x] = 7;
							}
						}

					}
				}
				place.play();
				tilePos_x = 8;
				tilePos_y = 0;
				coordX = 3;
				coordY = -1;
				rand1 = rand2;
				type = rand1;
				srand(time(NULL));
				rand2 = rand() % 7 + 0;
				rotation = 0;
				holdCount = 0;
				pieceDropped = FALSE;
			}
			else {
				prev = clock.getElapsedTime().asSeconds();
				tilePos_y += 1;
				coordY += 1;
				pieceDropped = FALSE;
			}
		}
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
				exit(0);
			}
		}

		window.clear();
		window.draw(bg);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			bool blockInWay = FALSE;
			pieceDropped = TRUE;
			static float prev = clock.getElapsedTime().asSeconds();
			if (clock.getElapsedTime().asSeconds() - prev >= 0.75)
			{
				prev = clock.getElapsedTime().asSeconds();
				while (check <= 22 && blockInWay == FALSE) {
					if (blockInWay == FALSE) {
						tilePos_y += 1;
						coordY += 1;
						check = 1;
					}
					if (collision(type, tilePos_x, tilePos_y + check, 'y', 0)) {
						tilePos_y = tilePos_y + check - 1;
						coordY = coordY + check - 1;
						check = 1;
						blockInWay = TRUE;
					}
					check += 1;
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
			static float prev = clock.getElapsedTime().asSeconds();
			if (clock.getElapsedTime().asSeconds() - prev >= 0.2 && pieceDropped == FALSE)
			{
				if (holdPiece >= 7 && holdCount < 1) {
					prev = clock.getElapsedTime().asSeconds();
					rand1 = rand2;
					holdPiece = type;
					type = rand1;
					srand(time(NULL));
					rand2 = rand() % 7 + 0;
					tilePos_x = 8;
					tilePos_y = 0;
					coordX = 3;
					coordY = -1;
					rotation = 0;
					holdCount += 1;
				}
				else if (holdPiece < 7 && holdCount < 1) {
					int placeHolder;
					placeHolder = type;
					type = holdPiece;
					holdPiece = placeHolder;
					tilePos_x = 8;
					tilePos_y = 0;
					coordX = 3;
					coordY = -1;
					rotation = 0;
					holdCount += 1;
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (collision(type, tilePos_x - 1, tilePos_y, 'l', 0)) {
				std:: cout << "Collision\n";
			}
			else if (pieceDropped == FALSE) {
				static float prev = clock.getElapsedTime().asSeconds();
				if (clock.getElapsedTime().asSeconds() - prev >= 0.04)
				{
					prev = clock.getElapsedTime().asSeconds();
					tilePos_x -= 1;
					coordX -= 1;
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (collision(type, tilePos_x + 1, tilePos_y, 'x', 0)) {
				std::cout << "Collision\n";
			}
			else if (pieceDropped == FALSE) {
				static float prev = clock.getElapsedTime().asSeconds();
				if (clock.getElapsedTime().asSeconds() - prev >= 0.04)
				{
					prev = clock.getElapsedTime().asSeconds();
					tilePos_x += 1;
					coordX += 1;
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			check = 1;
			if (collision(type, tilePos_x, tilePos_y + 1, 'y', 2)) {
				std::cout << "Collision\n";
			}
			else if (pieceDropped == FALSE) {
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
				std::cout << "Collision\n";
			}
			else if (pieceDropped == FALSE) {
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
				std::cout << "Collision\n";
			}
			else if (pieceDropped == FALSE) {
				static float prev = clock.getElapsedTime().asSeconds();
				if (clock.getElapsedTime().asSeconds() - prev >= 0.2)
				{
					prev = clock.getElapsedTime().asSeconds();
					rotation = int((rotation + 1) % 4);
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

		layout.setPosition(0, 0);
		window.draw(layout);
		window.draw(text);


		// Draw Next Piece
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				if (tetromino[rand2][0][y][x]) {
					positionX = 490 + x * 20;
					positionY = 190 + y * 20;
					tile.setPosition(sf::Vector2f(positionX, positionY));
					tile.setTextureRect(sf::IntRect(rand2 * 30, 0, 20, 20));
					window.draw(tile);

				}
			}
		}
		// Draw Holded Piece
		if (holdPiece < 7) {
			for (int x = 0; x < 4; x++) {
				for (int y = 0; y < 4; y++) {
					if (tetromino[holdPiece][0][y][x]) {
						positionX = 40 + x * 20;
						positionY = 190 + y * 20;
						tile.setPosition(sf::Vector2f(positionX, positionY));
						tile.setTextureRect(sf::IntRect(holdPiece * 30, 0, 20, 20));
						window.draw(tile);

					}

				}
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

