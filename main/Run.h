#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>
#include "Flappy.h"
#include "Sounds.h"
#include"Textures.h"
#include"Game.h"
#include"GameStates.h"
#include "BirdUpdate.h"

using namespace sf;
using namespace std;
class Run
{
private:
	bool collides(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);
public:
	void run();
};

