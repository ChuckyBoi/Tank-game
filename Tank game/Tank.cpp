#include "Tank.h"
#include <iostream>
#include <string.h>

void Tank::setup(RenderWindow &window)
{
	///////// SET TANKS //////
    Tank1S.setSize(Vector2f(100, 58));
	Tank1S.setTexture(&Tank1T);
	
	Tank2S.setSize(Vector2f(100, 58));
	Tank2S.setTexture(&Tank2T);




	/*Wall.setSize(Vector2f(40.f, 300));
	Wall.setFillColor(Color::Red);
	Wall2.setSize(Vector2f(40.f, 300));
	Wall2.setFillColor(Color::Red);
	Wall.setPosition(WIDTH / 2, HEIGHT - 300);
	Wall2.setPosition(WIDTH / 2, 0);
	*/

	BulletS.setSize(Vector2f(49, 16));
	BulletS.setTexture(&BulletT);
	
	BulletS2.setSize(Vector2f(49, 16));
	BulletS2.setTexture(&BulletT2);
	

	

	GreenWonS.setSize(Vector2f(1900, 1080));
	GreenWonS.setTexture(&GreenWonT);

	BlueWonS.setSize(Vector2f(1900, 1080));
	BlueWonS.setTexture(&BlueWonT);


	Wallpaper.loadFromFile("images/Wallpaper.jpg");
	Vector2u size = Wallpaper.getSize();
	sprite.setTexture(Wallpaper);

	
	
	

	sound.setBuffer(buffer);

	/*
	ExplosionT.loadFromFile("images/explosion(10x16).png");
	ExplosionS.setSize(Vector2f(10, 16));
	ExplosionS.setTexture(&ExplosionT);

	
	WelcomeS.setSize(Vector2f(800, 600));
	WelcomeS.setTexture(&WelcomeT);
	*/

	

	

	/////SET POSITION//////

	Tank1S.setPosition(0 , HEIGHT / 2);
	Tank2S.setPosition(WIDTH - Tank2S.getSize().x, HEIGHT / 2);
	       
	Classwallobj.setup(window);
	
	
	

}
void Tank::update(Event &event, RenderWindow &window)
{




	//Tank1S.setOrigin(100 / 2, 58 / 2);
	Vector2f  PlayerCenter = Vector2f((Tank1S.getPosition().x + (Tank1S.getSize().x)), (Tank1S.getPosition().y));
	Vector2f  PlayerCenter2 = Vector2f(Tank2S.getPosition().x - 50.f, Tank2S.getPosition().y);

	if (Keyboard::isKeyPressed(Keyboard::Num1))
	{
		music1.setVolume(50);
		music1.play();

		music2.stop();
		music3.stop();
		music4.stop();
	}
	if (Keyboard::isKeyPressed(Keyboard::Num2))
	{
		music2.setVolume(50);
		music2.play();

		music1.stop();
		music3.stop();
		music4.stop();
	}
	if (Keyboard::isKeyPressed(Keyboard::Num3))
	{
		music3.setVolume(50);
		music3.play();


		music1.stop();
		music2.stop();
		music4.stop();
	}
	if (Keyboard::isKeyPressed(Keyboard::Num4))
	{
		music4.setVolume(100);
		music4.play();

		music4.setPlayingOffset(seconds(45.f));
		music1.stop();
		music2.stop();
		music3.stop();
	}
	if (Keyboard::isKeyPressed(Keyboard::Num5))
	{

		music1.stop();
		music2.stop();
		music3.stop();
		music4.stop();
	}


	///////////BORDER 1////////////////////

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		//Tank1S.setRotation(180.f);
		Tank1S.move(Vector2f(-SpeedT1,0));

	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		Tank1S.move(Vector2f(SpeedT1, 0));
		//Tank1S.setRotation(0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		Tank1S.move(Vector2f(0, -SpeedT1));
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		Tank1S.move(Vector2f(0, SpeedT1));
	}


	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		Tank2S.move(Vector2f(-SpeedT2, 0));
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		Tank2S.move(Vector2f(SpeedT2, 0));
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		Tank2S.move(Vector2f(0, -SpeedT2));
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		Tank2S.move(Vector2f(0, SpeedT2));
	}

	/////////////////border 2////////////
	if (Tank1S.getPosition().x > WIDTH - Tank1S.getSize().x)
	{
		Tank1S.setPosition(WIDTH - Tank1S.getSize().x, Tank1S.getPosition().y);
	}
	if (Tank1S.getPosition().x < 0)
	{
		Tank1S.setPosition(0, Tank1S.getPosition().y);
	}
	if (Tank1S.getPosition().y < 0)
	{
		Tank1S.setPosition(Tank1S.getPosition().x, 0);
	}
	if (Tank1S.getPosition().y > HEIGHT - Tank1S.getSize().y)
	{
		Tank1S.setPosition(Tank1S.getPosition().x, HEIGHT - Tank1S.getSize().y);
	}

	/////////////////border 2////////////

	if (Tank2S.getPosition().x > WIDTH - Tank2S.getSize().x)
	{
		Tank2S.setPosition(WIDTH - Tank2S.getSize().x, Tank2S.getPosition().y);
	}
	if (Tank2S.getPosition().x < 0)
	{
		Tank2S.setPosition(0, Tank2S.getPosition().y);
	}
	if (Tank2S.getPosition().y < 0)
	{
		Tank2S.setPosition(Tank2S.getPosition().x, 0);
	}
	if (Tank2S.getPosition().y > HEIGHT - Tank2S.getSize().y)
	{
		Tank2S.setPosition(Tank2S.getPosition().x, HEIGHT - Tank2S.getSize().y);
	}


	/////////////////border 2////////////

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*if (Tank1S.getPosition().x < window.getSize().x / 2) {
		if ((Tank1S.getGlobalBounds().intersects(Wall.getGlobalBounds()) || (Tank1S.getGlobalBounds().intersects(Wall2.getGlobalBounds()))))
		{

			Tank1S.setPosition(window.getSize().x / 2 - Tank1S.getSize().x, Tank1S.getPosition().y);
		}
	}
	if (Tank1S.getPosition().x > window.getSize().x / 2) {
		if ((Tank1S.getGlobalBounds().intersects(Wall.getGlobalBounds()) || (Tank1S.getGlobalBounds().intersects(Wall2.getGlobalBounds()))))
		{

			Tank1S.setPosition(window.getSize().x / 2 + Wall.getSize().x, Tank1S.getPosition().y);
		}
	}

	if (Tank2S.getPosition().x < window.getSize().x / 2) {
		if ((Tank2S.getGlobalBounds().intersects(Wall.getGlobalBounds()) || (Tank2S.getGlobalBounds().intersects(Wall2.getGlobalBounds()))))
		{

			Tank2S.setPosition(window.getSize().x / 2 - Tank2S.getSize().x, Tank2S.getPosition().y);
		}
	}
	if (Tank2S.getPosition().x > window.getSize().x / 2) {
		if ((Tank2S.getGlobalBounds().intersects(Wall.getGlobalBounds()) || (Tank2S.getGlobalBounds().intersects(Wall2.getGlobalBounds()))))
		{

			Tank2S.setPosition(window.getSize().x / 2 + Wall.getSize().x, Tank2S.getPosition().y);
		}
	}




	if (Tank2S.getGlobalBounds().intersects(Wall2.getGlobalBounds()) && Tank2S.getPosition().y > Wall2.getPosition().y)
	{

		Tank2S.setPosition(Tank2S.getPosition().x, Tank2S.getPosition().y + 10.f);

	}
	if (Tank2S.getGlobalBounds().intersects(Wall.getGlobalBounds()) && Tank2S.getPosition().y < Wall.getPosition().y)
	{

		Tank2S.setPosition(Tank2S.getPosition().x, Tank2S.getPosition().y - 10.f);
	}


	if (Tank1S.getGlobalBounds().intersects(Wall2.getGlobalBounds()) && Tank1S.getPosition().y > Wall2.getPosition().y)
	{

		Tank1S.setPosition(Tank1S.getPosition().x, Tank1S.getPosition().y + 10.f);

	}
	if (Tank1S.getGlobalBounds().intersects(Wall.getGlobalBounds()) && Tank2S.getPosition().y < Wall.getPosition().y)
	{

		Tank1S.setPosition(Tank1S.getPosition().x, Tank1S.getPosition().y - 10.f);
	}
	*/




	if (!rotated) {
		if (Tank1S.getGlobalBounds().intersects(Tank2S.getGlobalBounds()))

		{

			Tank1S.setPosition(Tank1S.getPosition().x - SpeedT1, Tank1S.getPosition().y);

		}
		if (Tank2S.getGlobalBounds().intersects(Tank1S.getGlobalBounds()))

		{

			Tank2S.setPosition(Tank2S.getPosition().x + SpeedT2, Tank2S.getPosition().y);

		}
	}
	else
	{

		if (Tank1S.getGlobalBounds().intersects(Tank2S.getGlobalBounds()))

		{

			Tank1S.setPosition(Tank1S.getPosition().x + SpeedT1, Tank1S.getPosition().y);

		}
		if (Tank2S.getGlobalBounds().intersects(Tank1S.getGlobalBounds()))

		{

			Tank2S.setPosition(Tank2S.getPosition().x - SpeedT2, Tank2S.getPosition().y);

		}

	}




	//Classwallobj.walls[1].setFillColor(Color::White);







	for (int i = 0; i <= Classwallobj.numOfWalls; i++)
	{


		////////////
		if (Tank1S.getGlobalBounds().intersects(Classwallobj.walls[i].getGlobalBounds()) && (Tank1S.getPosition().x < Classwallobj.walls[i].getPosition().x))

		{

			Tank1S.setPosition(Tank1S.getPosition().x - SpeedT1, Tank1S.getPosition().y);

		}
		if (Tank1S.getGlobalBounds().intersects(Classwallobj.walls[i].getGlobalBounds()) && Tank1S.getPosition().x > Classwallobj.walls[i].getPosition().x)
		{

			Tank1S.setPosition(Tank1S.getPosition().x + SpeedT1, Tank1S.getPosition().y);

		}
		if (Tank1S.getGlobalBounds().intersects(Classwallobj.walls[i].getGlobalBounds()) && Tank1S.getPosition().y > Classwallobj.walls[i].getPosition().y)
		{

			Tank1S.setPosition(Tank1S.getPosition().x, Tank1S.getPosition().y + SpeedT1);

		}
		if (Tank1S.getGlobalBounds().intersects(Classwallobj.walls[i].getGlobalBounds()) && Tank1S.getPosition().y < Classwallobj.walls[i].getPosition().y)
		{

			Tank1S.setPosition(Tank1S.getPosition().x, Tank1S.getPosition().y - SpeedT1);

		}



		////////////

		if (Tank2S.getGlobalBounds().intersects(Classwallobj.walls[i].getGlobalBounds()) && Tank2S.getPosition().x < Classwallobj.walls[i].getPosition().x)
		{

			Tank2S.setPosition(Tank2S.getPosition().x - SpeedT2, Tank2S.getPosition().y);

		}
		if (Tank2S.getGlobalBounds().intersects(Classwallobj.walls[i].getGlobalBounds()) && Tank2S.getPosition().x > Classwallobj.walls[i].getPosition().x)
		{

			Tank2S.setPosition(Tank2S.getPosition().x + SpeedT2, Tank2S.getPosition().y);

		}
		if (Tank2S.getGlobalBounds().intersects(Classwallobj.walls[i].getGlobalBounds()) && Tank2S.getPosition().y > Classwallobj.walls[i].getPosition().y)
		{

			Tank2S.setPosition(Tank2S.getPosition().x, Tank2S.getPosition().y + SpeedT2);

		}
		if (Tank2S.getGlobalBounds().intersects(Classwallobj.walls[i].getGlobalBounds()) && Tank2S.getPosition().y < Classwallobj.walls[i].getPosition().y)
		{

			Tank2S.setPosition(Tank2S.getPosition().x, Tank2S.getPosition().y - SpeedT2);
		}

		//////////// 


	}

	
	
	icon.check(window);

	if (Tank1S.getGlobalBounds().intersects(icon.IconS.getGlobalBounds()))
	{
		Timer1 = clock.getElapsedTime();
		BoostLast1 = Timer1 + seconds(10);
		icon.TakenBoost = true;
		SpeedT1 = 20;

	}
	if (Timer1 < BoostLast1) {
		Timer1 = clock.getElapsedTime();
		SpeedT1 = 20;
	}
	else
	{
		SpeedT1 = 10;
	}
	if (Tank2S.getGlobalBounds().intersects(icon.IconS.getGlobalBounds()))
	{
		Timer2= clock.getElapsedTime();
		BoostLast2 = Timer2 + seconds(10);
		icon.TakenBoost = true;

	}
	if (Timer2 < BoostLast2) {
		Timer2 = clock.getElapsedTime();
		SpeedT2 = 20;
	}
	else
	{
		SpeedT2 = 10;
	}

	if (Tank1S.getGlobalBounds().intersects(icon.IconS2.getGlobalBounds()))
	{
		Timer3 = clock.getElapsedTime();
		BoostLast3 = Timer3 + seconds(20);
		icon.TakenBulletSpeed = true;
		BulletSpeed1 = 24;

	}
	if (Timer3 < BoostLast3) {
		Timer3 = clock.getElapsedTime();
		BulletSpeed1 = 24;
	}
	else
	{
		BulletSpeed1 = 12;
	}

	if (Tank2S.getGlobalBounds().intersects(icon.IconS2.getGlobalBounds()))
	{
		Timer4 = clock.getElapsedTime();
		BoostLast4 = Timer4 + seconds(10);
		icon.TakenBulletSpeed = true;
		
	}
	if (Timer4 < BoostLast4) {
		Timer4 = clock.getElapsedTime();
		BulletSpeed2 = 24;
	}
	else
	{
		BulletSpeed2 = 12;
	}

	

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (Tank1S.getPosition().x > Tank2S.getPosition().x || (Tank2S.getPosition().x < Tank1S.getPosition().x)) {

		PlayerCenter = Vector2f((Tank1S.getPosition().x) - 50, (Tank1S.getPosition().y));
		PlayerCenter2 = Vector2f(Tank2S.getPosition().x + Tank2S.getSize().x, Tank2S.getPosition().y);
		Tank2S.setTexture(&RotatedTank2T);
		Tank1S.setTexture(&RotatedTank1T);
		rotated = true;
	}
	if (Tank1S.getPosition().x < Tank2S.getPosition().x || (Tank2S.getPosition().x > Tank1S.getPosition().x)) {

		PlayerCenter = Vector2f((Tank1S.getPosition().x) + Tank1S.getSize().x, (Tank1S.getPosition().y));
		PlayerCenter2 = Vector2f(Tank2S.getPosition().x - 50.f, Tank2S.getPosition().y);
		Tank1S.setTexture(&Tank1T);
		Tank2S.setTexture(&Tank2T);


		rotated = false;

	}


	if (ShootTimerForTank1 < 20)
	{
		ShootTimerForTank1++;
	}
	if (Keyboard::isKeyPressed(Keyboard::Space) && ShootTimerForTank1 >= 20)
	{


		BulletS.setPosition(PlayerCenter);
		Bullets.push_back(RectangleShape(BulletS));

		ShootTimerForTank1 = 0;
	}


	for (size_t i = 0; i < Bullets.size(); i++)
	{

		if (rotated)
		{
			NumofBulletsGoingNegative = i;
			Bullets[i].move(-BulletSpeed1, 0.f);
		}
		else

		{
			NumofBulletsGoingPositive = i;
			Bullets[i].move(BulletSpeed1, 0.f);

		}
	}
	if (rotated)
	{
		for (int i = 0; i < NumofBulletsGoingPositive; i++)
		{


			//Bullets.erase(Bullets.begin() +i );
			Bullets.clear();

			NumofBulletsGoingPositive--;


		}
	}

	if (!rotated)
	{

		for (int i = 0; i < NumofBulletsGoingNegative;i++)
		{

			//Bullets.erase(Bullets.begin() + i);
			Bullets.clear();

			NumofBulletsGoingNegative--;

		}


	}


	for (size_t i = 0; i < Bullets.size(); i++)
	{
		if ((Bullets[i].getPosition().x) > WIDTH - 10)
		{
			Bullets.erase(Bullets.begin() + i);
		}

	}
	for (size_t i = 0; i < Bullets.size(); i++)
	{
		if ((Bullets[i].getPosition().x) <= 0)
		{
			Bullets.erase(Bullets.begin() + i);
		}
	}



	for (size_t i = 0; i < Bullets.size(); i++)
	{
		if (Bullets[i].getGlobalBounds().intersects(Wall.getGlobalBounds()) || Bullets[i].getGlobalBounds().intersects(Wall2.getGlobalBounds())) {
			Bullets.erase(Bullets.begin() + i);
			break;
		}





		for (int j = 0;j <= Classwallobj.numOfWalls;j++)
		{
			if (Bullets[i].getGlobalBounds().intersects(Classwallobj.walls[j].getGlobalBounds()))

			{

				Bullets.erase(Bullets.begin() + i);
				break;
			}

		}
	}



	for (size_t i = 0; i < Bullets.size(); i++)
	{


		if (Bullets[i].getGlobalBounds().intersects(Tank2S.getGlobalBounds()))
		{
			Bullets.erase(Bullets.begin() + i);


			sound.play();

			LivesForTank1 = LivesForTank1 - 1;
			lblLives.setString("Lives: " + to_string(LivesForTank1));

			break;
		}
	}



	if (ShootTimerForTank2 < 20)
	{
		ShootTimerForTank2++;
	}
	if (Keyboard::isKeyPressed(Keyboard::P) && ShootTimerForTank2 >= 20)
	{
		BulletS2.setPosition(PlayerCenter2);
		Bullets2.push_back(RectangleShape(BulletS2));

		ShootTimerForTank2 = 0;
	}
	for (size_t j = 0; j < Bullets2.size(); j++)
	{

		if (rotated)
		{
			NumofBulletsGoingPositive2 = j;
			Bullets2[j].move(BulletSpeed2, 0.f);
		}
		else

		{
			NumofBulletsGoingNegative2 = j;
			Bullets2[j].move(-BulletSpeed2, 0.f);

		}
	}
	if (rotated)
	{
		for (int j = 0; j < NumofBulletsGoingNegative2; j++)
		{
			//Bullets2.erase(Bullets2.begin() + NumofBulletsGoingNegative2);
			Bullets2.clear();
			NumofBulletsGoingNegative2--;

		}
	}
	if (!rotated)
	{
		for (int j = 0; j < NumofBulletsGoingPositive2; j++)
		{
			Bullets2.clear();
			NumofBulletsGoingPositive2--;
		}

	}




	for (size_t j = 0; j < Bullets2.size(); j++)
	{
		if (Bullets2[j].getPosition().x > WIDTH) {

			Bullets2.erase(Bullets2.begin() + j);
		}

	}
	for (size_t j = 0; j < Bullets2.size(); j++)
	{
		if ((Bullets2[j].getPosition().x) < 0)
		{
			Bullets2.erase(Bullets2.begin() + j);
		}
	}

	for (size_t j = 0; j < Bullets2.size(); j++)
	{
		if (Bullets2[j].getGlobalBounds().intersects(Wall.getGlobalBounds()) || Bullets2[j].getGlobalBounds().intersects(Wall2.getGlobalBounds())) {
			Bullets2.erase(Bullets2.begin() + j);
			break;
		}




		for (int i = 0;i <= Classwallobj.numOfWalls;i++)
		{
			if (Bullets2[j].getGlobalBounds().intersects(Classwallobj.walls[i].getGlobalBounds()))
			{

				Bullets2.erase(Bullets2.begin() + j);
				break;
			}

		}



		for (size_t j = 0; j < Bullets2.size(); j++) {

			if (Bullets2[j].getGlobalBounds().intersects(Tank1S.getGlobalBounds())) {


				sound.play();

				LivesForTank2 = LivesForTank2 - 1;

				lblScore.setString("Lives: " + to_string(LivesForTank2));


				Bullets2.erase(Bullets2.begin() + j);

				break;
			}
		}


	}

	
	if (Keyboard::isKeyPressed(Keyboard::T))
	{
		//Key = true;
		Classwallobj.setup(window);
		
	}

		




	//window.draw(sprite);

	
	

		
	//window.draw(Tank1S);
	//window.draw(Tank2S);

		if (LivesForTank2 <= 0)
		{
			window.clear();
			window.draw(BlueWonS);
			BlueTankWon = true;

			if (Keyboard::isKeyPressed(Keyboard::R))
			{
				LivesForTank1 = 5;
				LivesForTank2 = 5;
				GreenTankWon = false;
				BlueTankWon = false;
				lblLives.setString("Lives: " + to_string(LivesForTank1));
				lblScore.setString("Lives: " + to_string(LivesForTank2));
				GamesWonTank1++;
				lblGames1.setString("Games won: "+ to_string(GamesWonTank1));

				Bullets.clear();
				Bullets2.clear();
				Tank1S.setPosition(0, HEIGHT / 2);
				Tank2S.setPosition(WIDTH - Tank1S.getSize().x, HEIGHT / 2);

			}

		}
		if (LivesForTank1 <= 0)
		{
			window.clear();
			window.draw(GreenWonS);
			GreenTankWon = true;

			if (Keyboard::isKeyPressed(Keyboard::R))
			{
				LivesForTank1 = 5;
				LivesForTank2 = 5;
				GreenTankWon = false;
				BlueTankWon = false;
				
				lblLives.setString("Lives: " + to_string(LivesForTank1));
				lblScore.setString("Lives: " + to_string(LivesForTank2));

				GamesWonTank2++;
				lblGames2.setString("Games won: " + to_string(GamesWonTank2));

				Bullets.clear();
				Bullets2.clear();

				Tank1S.setPosition(0, HEIGHT / 2);
				Tank2S.setPosition(WIDTH - Tank1S.getSize().x, HEIGHT / 2);

			}
		}
	
	
	
	
}

void Tank::draw(RenderWindow &window)
{
	window.draw(Tank1S);
	window.draw(Tank2S);
	
	//window.draw(Wall);
	//window.draw(Wall2);

	///window.draw(IconShape);

	window.draw(lblLives);
	window.draw(lblScore);
	window.draw(lblGames1);
	window.draw(lblGames2);

	Classwallobj.draw(window);
	icon.draw(window);

	for (size_t i = 0;i < Bullets.size();i++) {


		window.draw(Bullets[i]);
	}

	for (size_t j = 0;j < Bullets2.size();j++) {

		window.draw(Bullets2[j]);
	}

	if(GreenTankWon)
	{
		window.clear();
		window.draw(GreenWonS);

	}
	if (BlueTankWon)
	{
		window.clear();
		window.draw(BlueWonS);

	}


}
