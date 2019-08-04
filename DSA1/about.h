using namespace std;
class ABOUT
{
public:
	void SHOW()
	{
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		sf::RenderWindow window(sf::VideoMode(800, 440), "About", sf::Style::Default, settings);
		std::ostringstream stri;
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}

			}
			stri.str("");
			stri << "This is a made as a project work \nby Saroj and Sandesh.SFML gr-\naphics library on C++ language\nis used in making this.Enqueue\nand dequeue operations are an-\nimated graphically here.";
			window.clear();
			drawText(&window, 60, sf::Color::Blue, sf::Vector2f(10, 10), stri.str());
			window.display();
		}
	}
	void drawText(sf::RenderWindow *window, int size, sf::Color color, sf::Vector2f position, string str)
	{
		sf::Font font4text;
		sf::Text nodedata, torder;
		font4text.loadFromFile("roman.ttf");
		nodedata.setFont(font4text);
		nodedata.setFillColor(color);
		nodedata.setPosition(position);
		nodedata.setCharacterSize(size);
		nodedata.setString(str);
		window->draw(nodedata);
	}
};