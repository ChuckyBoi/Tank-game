#include "SFML/Audio.hpp"
#include "Wall.h"
#include "Icon.h"



constexpr auto WIDTH = 1920	;
constexpr auto HEIGHT = 1080;
constexpr auto NAME = "OH YEAH";


using namespace std;
using namespace sf;

class Tank
{
private:
	
	Texture Tank1T;
	Texture Tank2T;
	Texture RotatedTank1T;
	Texture RotatedTank2T;

	RectangleShape Tank1S;
	RectangleShape Tank2S;


	int SpeedT1 = 10;
	int SpeedT2 = 10;

	Clock clock;
	Time BoostLast1;
	Time Timer1;
	Time BoostLast2;
	Time Timer2;
	Time BoostLast3;
	Time Timer3;
	Time BoostLast4;
	Time Timer4;

	int BulletSpeed1 = 24;
	int BulletSpeed2 = 24;




	RectangleShape Wall;
	RectangleShape Wall2;

	Texture BulletT;
	RectangleShape BulletS;

	Texture BulletT2;
	RectangleShape BulletS2;

	vector<RectangleShape>  Bullets;
	vector<RectangleShape>  Bullets2;

	Texture GreenWonT;
	RectangleShape GreenWonS;

	Texture BlueWonT;
	RectangleShape BlueWonS;

	bool BlueTankWon = false;
	bool GreenTankWon = false;
	bool rotated = false;
	bool finished = false;
	

	int down = 0;
	int up = 0;
	
	int NumofBulletsGoingPositive;
	int NumofBulletsGoingNegative;
	int NumofBulletsGoingPositive2;
	int NumofBulletsGoingNegative2;

	
	

	SoundBuffer buffer;
	Sound sound;

	Music music1;
	Music music2;
	Music music3;
	Music music4;





	///////////////////////////////////////
	/*RectangleShape IconShape;
	Texture IconTexture;
	Clock clock;
	Time elapsed1;
	Time elapsed2;
	*/
	

	

	//Vector2f CurrentPositionForTank1;
	//Vector2f CurrentPositionForTank2;

public:
	///////Az ablak neve es meretei////////

	Classwall Classwallobj;
	Icon icon;

	//Clock clock;
	//Time elapsed1;
	//Time elapsed2;
	
	

	int LivesForTank1 = 5;
	int LivesForTank2 = 5;

	int GamesWonTank1 = 0;
	int GamesWonTank2 = 0;
	
	Text lblScore = { "Lives: " + to_string(LivesForTank1),arial,30 };
	Text lblLives = { "Lives: " + to_string(LivesForTank2),arial,30 };

	Text lblGames1= { "Games won:"+ to_string(GamesWonTank1),arial,30 };
	Text lblGames2= { "Games won:"+ to_string(GamesWonTank2),arial,30 };

	Texture Wallpaper;
	Sprite sprite;

	bool Key = false;

	

	

	int ShootTimerForTank1 = 0;
	int ShootTimerForTank2 = 0;

	Font arial;

    //Texture WelcomeT;
	//RectangleShape WelcomeS;

	

	



	/////////////////////////////////////
	    
public:

	Tank()
	{

		Tank1T.loadFromFile("images/greentank(100x58).png");//beolvassa a filet
		//Tank2T.loadFromFile("images/pink2tank(100x58).png");//beolvassa a filet
		Tank2T.loadFromFile("images/bluetank(100x58).png");//beolvassa a filet
		RotatedTank2T.loadFromFile("images/bluetankrotated(100x58).png");
		RotatedTank1T.loadFromFile("images/greentankrotated(100x58).png");


		/*IconTexture.loadFromFile("images/bulletIcon.png");//beolvassa a filet
		IconShape.setSize(Vector2f(51, 51));
		IconShape.setTexture(&IconTexture);

		elapsed1 = clock.getElapsedTime();
		elapsed2 = clock.getElapsedTime();
		elapsed2 = elapsed2 + seconds(3);
		*/


		arial.loadFromFile("arial.ttf");
		lblGames2.setPosition(WIDTH / 2 - 200, 10.f);
		lblGames1.setPosition(WIDTH / 2 + 45, 10.f);
		lblScore.setPosition({ 10.f,10.f });
		lblLives.setPosition(WIDTH - 130, 10.f);
		
		
		

		BulletT.loadFromFile("images/bullet(49x16).png");
		BulletT2.loadFromFile("images/bullet(49x16).png");

		GreenWonT.loadFromFile("images/greenwon(800x600).bmp");
		BlueWonT.loadFromFile("images/bluewon(800x600).bmp");

	    music1.openFromFile("Audio/music.ogg");
	    music2.openFromFile("Audio/lol.ogg");
		music3.openFromFile("Audio/scatman.ogg");
		music4.openFromFile("Audio/Esperanza.ogg");

		buffer.loadFromFile("Audio/boom.ogg");

		//WelcomeT.loadFromFile("images/welcomescreen(800x600).bmp");


	}
	void setup(RenderWindow &window);
	
	void update(Event &event, RenderWindow &window);
	void draw(RenderWindow &window);
	

};

