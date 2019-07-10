#pragma once
class EMPTYORFULL
{
public:
	void show(std::string str)
	{
		sf::RenderWindow window(sf::VideoMode(250, 200), str);
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			
			window.clear();
			drawimage(&window, sf::Vector2f(50, 20));
			window.display();
		}
	}
	void drawimage(sf::RenderWindow *window, sf::Vector2f pos)
	{
		sf::Texture texture;
		if (!texture.loadFromFile("error.png"))
		{
			std::cout << "PNG image is not loaded." << std::endl;
		}
		sf::Sprite sprite;
		sprite.setTexture(texture);
		sprite.setPosition(pos);
		sprite.setScale(sf::Vector2f(0.3f, 0.3f));
		window->draw(sprite);
	}
};