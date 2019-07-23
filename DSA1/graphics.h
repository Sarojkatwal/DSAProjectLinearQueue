template<class T>
class INSERTDELETE
{
public:
	void show(T arr[],int fr,int re,int max,int i)
	{
		sf::Vector2f initarrpos1,initarrpos2;
		int j = 0;
		float x = 10.0f, y = 110.0f, length = 950.0f / (max + 1), height = 90.0f;
		int textsize = static_cast<int>(length/3);
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		sf::RenderWindow window(sf::VideoMode(1000, 400), "Queues",sf::Style::Default,settings);
		std::ostringstream ddata, hints;
		hints << "Initially";
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type = sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						//std::cout << event.mouseButton.x << " " << event.mouseButton.y << std::endl;
					}
				}
			}
			drawtext(&window, sf::Color::Red, sf::Vector2f(300,10), "LINEAR QUEUE", 50, sf::Text::Bold);
			drawtext(&window, sf::Color::White, sf::Vector2f(30, 70),hints.str(), 30, sf::Text::Bold);
			drawrectangle(&window, sf::Color::Blue, sf::Vector2f(x+length/2 , y), 90, sf::Vector2f( height,10));
		    float m = x+length/2;
			for (int i =0; i <re; i++)
			{
				ddata.str("");
				if(i>=fr)
					ddata << arr[i];
				drawtext(&window, sf::Color::Green, sf::Vector2f(m+length/3.5f, y+ (height-textsize)/2), ddata.str(), textsize, sf::Text::Bold);
				drawrectangle(&window, sf::Color::Blue, sf::Vector2f(m + length, y), 90, sf::Vector2f(height, 10.0f));
				m = m + length;
			}
			drawrectangle(&window, sf::Color::Blue, sf::Vector2f(m+length, y), 90, sf::Vector2f(height, 10.0f));

			drawrectangle(&window,sf::Color::Blue, sf::Vector2f(x, y), 0, sf::Vector2f((max+1) * length, 10.0f));
			drawrectangle(&window,sf::Color::Blue, sf::Vector2f(x, y+height), 0, sf::Vector2f((max+1) * length, 10.0f));
			if (j == 2)
			{
				window.display();
				++j;
				sf::sleep(sf::seconds(3.0f));
				window.clear();
				continue;
			}
			ddata.str("");
			ddata << "front=" << fr;
			drawtext(&window, sf::Color::Cyan, sf::Vector2f((fr)*length+x+length/1.5f, y+1.25f*height), ddata.str(), 20, sf::Text::Italic);
			ddata.str("");
			ddata << "rear=" << re;
			if (fr != re)
			{
				drawtext(&window, sf::Color::Cyan, sf::Vector2f((re)* length + x + length / 1.5f, y + 1.25f*height), ddata.str(), 20, sf::Text::Italic);
			}
			else
			{
				drawtext(&window, sf::Color::Cyan, sf::Vector2f((re)* length + x + length / 1.5f, y + 1.5f*height), ddata.str(), 20, sf::Text::Italic);
			}
			drawimage(&window, sf::Vector2f((fr)*length + x + length/1.5f, y + height/1.4f));
			drawimage(&window, sf::Vector2f((re)* length + x + length / 1.5f, y + height / 1.4f));
			window.display();
			window.clear();
			if (j == 0||j==1)
			{
				sf::sleep(sf::seconds(2+2*j));
				j++;
				hints.str("");
				hints << (i == 1? "Insert new element at rear end and Increase rear by one." : "Remove the element of front end and Increase front by one..");
			}
			if (j ==2)
			{
		
				if (fr != re)
				{
					drawtext(&window, sf::Color::Cyan, sf::Vector2f((re)* length + x + length / 1.5f, y + 1.25f*height), ddata.str(), 20, sf::Text::Italic);
				}
				else
				{
					drawtext(&window, sf::Color::Cyan, sf::Vector2f((re)* length + x + length / 1.5f, y + 1.5f*height), ddata.str(), 20, sf::Text::Italic);
				}
				ddata.str("");
				ddata << "Front=" << fr;
				drawtext(&window, sf::Color::Cyan, sf::Vector2f((fr)*length + x + length / 1.5f, y + 1.25f*height), ddata.str(), 20, sf::Text::Italic);
				drawimage(&window, sf::Vector2f((fr)*length + x + length / 1.5f, y + height / 1.4f));
				drawimage(&window, sf::Vector2f((re)* length + x + length / 1.5f, y + height / 1.4f));
				i == 0 ? ++fr : ++re;
			}
			if (j >= 3)
			{
				hints.str("");
			}
		}
	}
	void drawrectangle(sf::RenderWindow* window,sf::Color color,sf::Vector2f pos,float ang,sf::Vector2f size)
	{
		sf::RectangleShape shape;
		shape.setFillColor(color);
		shape.setPosition(pos);
		shape.setRotation(ang);
		shape.setSize(size);
		window->draw(shape);
	}
	void drawtext(sf::RenderWindow *window,sf::Color color,sf::Vector2f pos,std::string ddata,int size,sf::Text::Style style)
	{
		sf::Font font4text;
		sf::Text nodedata;
		font4text.loadFromFile("roman.ttf");
		nodedata.setFont(font4text);
		nodedata.setCharacterSize(size);
		nodedata.setFillColor(color);
		nodedata.setStyle(style);
		nodedata.setString(ddata);
		nodedata.setPosition(pos);
		window->draw(nodedata);
	}
	void drawimage(sf::RenderWindow *window,sf::Vector2f pos)
	{
		sf::Texture texture;
		if (!texture.loadFromFile("arrow.png"))
		{
			std::cout << "PNG image is not loaded."<<std::endl;
		}
		sf::Sprite sprite;
		sprite.setTexture(texture);
		sprite.setPosition(pos);
		sprite.setScale(sf::Vector2f(0.03f,0.03f));
		window->draw(sprite);
	}
};