#include "wall.h"



void Classwall::setup(RenderWindow &window)
{

	srand(time(NULL));
	walls.clear();

 for (size_t i = 0; i <= numOfWalls;i++) 
 {
	      walls.push_back(RectangleShape(wall));
	      RandomLoc = Vector2f (rand() % int(Width), rand() % int(Height-200));
	      wall.setPosition(RandomLoc);
		
	      
	      
	
 }

 //COOL MAP
    /*
   walls[0].setPosition(Vector2f(0, 300));
	walls[0].setSize(Vector2f(2000, 20.f));
	walls[1].setPosition(Vector2f(0, 770));
	walls[1].setSize(Vector2f(2000, 20.f));
	*/

 //////////////THE LABIRINT MAP
 /*
    walls[0].setSize(VizszintesFal);
	walls[0].setPosition(Vector2f(x, y));
	walls[1].setSize(FuggolegesFal);
    walls[1].setPosition(Vector2f(x+200,y));
	walls[2].setSize(VizszintesFal);
	walls[2].setPosition(Vector2f(x+200, y+200));
	walls[3].setSize(Vector2f(FuggolegesFal.x,-FuggolegesFal.y + 100));
    walls[3].setPosition(Vector2f(x+380,y+200));
	walls[4].setSize(Vector2f(VizszintesFal.x-100,VizszintesFal.y)));
	
	*/

 /*
	//walls[5].setPosition(Vector2f(0, 770));
	walls[5].setSize(Vector2f(2000, 20.f));
    walls[6].setPosition(Vector2f(0, 300));
	walls[6].setSize(Vector2f(2000, 20.f));
	walls[7].setPosition(Vector2f(0, 770));
	walls[7].setSize(Vector2f(2000, 20.f));
	walls[8].setPosition(Vector2f(0, 300));
	walls[8].setSize(Vector2f(2000, 20.f));
	walls[9].setPosition(Vector2f(0, 770));
	walls[9].setSize(Vector2f(2000, 20.f));
	
	*/
	
	
	
 //ARRANGED MAP

 /*  walls[0].setPosition(Vector2f(300, 300));
	walls[1].setPosition(Vector2f(600, 600));
	walls[2].setPosition(Vector2f(900, 300));
	walls[3].setPosition(Vector2f(1200, 600));
	walls[4].setPosition(Vector2f(1500, 300));
	walls[5].setPosition(Vector2f(1800, 600));
	*/
	
	
	
	
 //lines.setPrimitiveType(Quads);

 //lines[0].position = Vector2f(500, 500);
 //lines[0].color = Color::Green;
		
		
		

	
	


}


void Classwall::update(Event &event, RenderWindow &window)
{





}
void Classwall::draw(RenderWindow &window)
{
	for (size_t i = 0;i < walls.size();i++)
	{
		window.draw(walls[i]);

	}




}