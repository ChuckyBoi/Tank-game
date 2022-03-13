#include "icon.h"

Icon::Icon()
{
	
		IconT.loadFromFile("images/speed1.png");
		IconS.setTexture(&IconT);
		IconS.setSize(Vector2f(50, 50));
		IconT2.loadFromFile("images/bullet.png");
		IconS2.setTexture(&IconT2);
		IconS2.setSize(Vector2f(50, 50));
	


	
	
}

void Icon::setup(RenderWindow &window)
{
	
	elapsed1 = clock.getElapsedTime();
	elapsed2 = clock.getElapsedTime();
	elapsed3 = clock.getElapsedTime();
	elapsed4 = clock.getElapsedTime();
	elapsed2 = elapsed2 + seconds(15);
	elapsed4 = elapsed3 + seconds(20);
	
		
	//RandomLoc = Vector2f(rand() % int(window.getSize().x), rand() % int(window.getSize().y-200));
	//IconS.setPosition(RandomLoc);
	TakenBoost = false;
	TakenBulletSpeed = false;
	

}


void Icon::check(RenderWindow &window)
{

	if (elapsed1 <= elapsed2) {
		elapsed1 = clock.getElapsedTime();
	}
	if (elapsed1 >= elapsed2)
	{
		RandomLoc = Vector2f(rand() % int(window.getSize().x), rand() % int(window.getSize().y - 200));
		IconS.setPosition(RandomLoc);
		
		TakenBoost = false;
		elapsed2 = elapsed2 + seconds(15);
	}

	if (elapsed3 <= elapsed4) {
		elapsed3 = clock.getElapsedTime();
	}
	if (elapsed3 >= elapsed4)
	{
		RandomLoc = Vector2f(rand() % int(window.getSize().x), rand() % int(window.getSize().y - 200));
		IconS2.setPosition(RandomLoc);
		TakenBulletSpeed = false;
		elapsed4 = elapsed3 + seconds(15);
	}


}

void Icon::draw(RenderWindow &window)
{
	if (!TakenBoost)
	{


		window.draw(IconS);
	}
	if (!TakenBulletSpeed)
	{


		window.draw(IconS2);
	}
}

