#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace sf;
class GameStates
{
public:
	int score;
	int highscore;
	int frames;
	enum  GameState
	{
		waiting,
		started,
		gameover
	};
	GameState gameState;
	
};

