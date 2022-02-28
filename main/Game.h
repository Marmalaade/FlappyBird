#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "GameStates.h"
#include "Textures.h"

using namespace sf;
class Game:public GameStates
{
public:
	
	Sprite background[3];
	Sprite background2[3];
	Sprite gameover;
	Text startGameText;
	Text pressC;
	Text scoreText;
	Text highscoreText;
	Font font;
	Game(Textures &textures);
};

