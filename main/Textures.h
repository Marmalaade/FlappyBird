#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace sf;
class Textures
{
public:
	Texture flappy[3];
	Texture pipe;
	Texture background;
	Texture background2;
	Texture gameover;

	Textures();

};

