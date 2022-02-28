#include "Textures.h"

Textures::Textures()
{
	background.loadFromFile("./images/background.png");
	background2.loadFromFile("./images/background2.png");
	pipe.loadFromFile("./images/pipe.png");
	gameover.loadFromFile("./images/gameover.png");
	flappy[0].loadFromFile("./images/flappy1.png");
	flappy[1].loadFromFile("./images/flappy2.png");
	flappy[2].loadFromFile("./images/flappy3.png");
}
