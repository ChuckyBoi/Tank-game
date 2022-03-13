#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstdlib>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>


using namespace sf;
using namespace std;





class Icon
{
private:
		Clock clock;
	   Time elapsed1;
	   Time elapsed2;
	   Time elapsed3;
	  Time elapsed4;
	   
	
	   Vector2f RandomLoc;


public:
	RectangleShape IconS;
	Texture IconT;
	RectangleShape IconS2;
	Texture IconT2;
	bool TakenBoost = false;
	bool TakenBulletSpeed = false;

	Icon();
	void setup(RenderWindow &window);
	void check(RenderWindow &window);
	void draw(RenderWindow &window);

	
	
};

