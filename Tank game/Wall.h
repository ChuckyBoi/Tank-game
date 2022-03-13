#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstdlib>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>


using namespace std;
using namespace sf;


class Classwall
{

private:
	//VertexArray lines;

	

public:
	int Height = 1080;
	int Width = 1920;
	bool intersects = false;
	Classwall()
		
	{
		wall.setFillColor(Color::Red);
		wall.setSize(Vector2f(30, 200));
		
	
	
	
	}
	void setup(RenderWindow &window);
	void draw(RenderWindow &window);
	void update(Event &event, RenderWindow &window);

	RectangleShape wall;
	vector <RectangleShape> walls;
	Vector2f RandomLoc;
	int numOfWalls = 5;
	//int x = 300;
	//int y = 300;
	//Vector2f VizszintesFal =  Vector2f(200.f,20.f);
	//Vector2f FuggolegesFal = Vector2f(20.f, 200.f);

	
		 
	

};