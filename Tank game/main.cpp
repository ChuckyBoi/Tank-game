#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tank.h"
//#include "Icon.h"

using namespace sf;
using namespace std;



int main()
{

	RenderWindow window{ VideoMode(WIDTH, HEIGHT),NAME};

	window.setFramerateLimit(60);
	Tank tank;
	//Icon icon;
	
	tank.setup(window);
	//icon.setup(window);
	
	

	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();

			if(Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}


		}

		window.clear();
		tank.update(event, window);
		tank.draw(window);

		window.display();
	}

	return 0;
	




}