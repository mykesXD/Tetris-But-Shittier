#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#define HEIGHT 768
#define WIDTH 1024

int main()
{
	int tetromino[7][4][4]{
		{
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0},
		{0,0,0,0},
		},
		{
		{0,0,1,0},
		{1,1,1,0},
		{0,0,0,0},
		{0,0,0,0},
		},
		{
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0},
		{0,0,0,0},
		},
		{
		{0,1,1,0},
		{1,1,0,0},
		{0,0,0,0},
		{0,0,0,0},
		},
		{
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0},
		{0,0,0,0},
		},
		{
		{1,0,0,0},
		{1,1,1,0},
		{0,0,0,0},
		{0,0,0,0},
		},
		{
		{0,1,0,0},
		{1,1,1,0},
		{0,0,0,0},
		{0,0,0,0},
		},
	};
	ShowWindow(GetConsoleWindow(), SW_SHOW);
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Mykes", sf::Style::Close | sf::Style::Titlebar);
	sf::Event e;
	sf::Texture tileTexture;
	tileTexture.loadFromFile("images/tiles.png");
	sf::Texture gridTexture;
	gridTexture.loadFromFile("images/grid.png");
	sf::Image icon;
	sf::RectangleShape grid(sf::Vector2f(30 * 10, 30 * 20));
	grid.setTexture(&gridTexture);
	sf::Sprite tile(tileTexture);
	tile.setTextureRect(sf::IntRect(0,0,30,30));
	icon.loadFromFile("images/xie.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	int tilePos_x = 15;
	int tilePos_y = 0;
	int type = 4;
	int gg = 0;
	int grid_x = WIDTH / 2 - (30 * 10) / 2-1.5;
	int grid_y = HEIGHT / 2 - (30 * 20) / 2 +6;
	int lastPixel;
	/* auto collision = [&]()
	{
		for (int y = 0; y < 4; y++)for (int x = 0; x < 4; x++)
		{
			if (tetromino[type][x][y] == 0) continue;
			if (x + tilePos_x < 0 || x + tilePos_x >= grid_x-10 || y + tilePos_y >= grid_y-10) return false; // hit wall
		}
		return true;
	};
	*/
	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
			if (e.type == sf::Event::KeyPressed) 
			{
				switch (e.key.code) 
				{
					case sf::Keyboard::Left :
						tilePos_x -=1;
						// if (collision() == false) {
						//	tilePos_x += 1;
						break;
						
					case sf::Keyboard::Right:
						tilePos_x +=1;
						// if (collision() == false) {
						//	tilePos_x -= 1;
						break;
						
					case sf::Keyboard::Down:
						tilePos_y +=1;
						// if (collision() == false) {
						//	tilePos_y -= 1;
						break;
						
				}
			}
		}
		window.clear();
		window.draw(grid);
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				if (tetromino[type][y][x]) {

					tile.setPosition(sf::Vector2f((tilePos_x + x) * 30, (tilePos_y + y) * 30));
					tile.setTextureRect(sf::IntRect(type*30, 0, 30, 30));
					gg = (tilePos_x + x) * 30;
					window.draw(tile);
					
				}
			}
		}
		grid.setPosition(sf::Vector2f(grid_x, grid_y));
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		window.display();
	}

	return 0;
}