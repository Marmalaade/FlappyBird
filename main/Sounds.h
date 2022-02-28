#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace sf;

class Sounds
{
public:
	SoundBuffer chingBuffer;
	SoundBuffer hopBuffer;
	SoundBuffer dishkBuffer;
	Sound ching;
	Sound hop;
	Sound dishk;
	Sounds();
}; 

