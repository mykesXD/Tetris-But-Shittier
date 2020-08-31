#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
int main()
{	
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Mykes",sf::Style::Close | sf::Style::Titlebar);
	sf::Event e;
	sf::Texture texture;
	texture.loadFromFile("images/astolfo.png");
	sf::Image icon;
	icon.loadFromFile("images/xie.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	sf::Sprite sprite(texture);
	sprite.setScale(0.4f, 0.4f);
	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		window.draw(sprite);
		window.display();
	}
	return 0;
}