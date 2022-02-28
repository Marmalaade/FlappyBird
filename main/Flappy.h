#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace sf;
class Flappy
{
	float angle = 0;
	double v = 0;
	int frame = 0;
public:
	Sprite sprite;
	float getAngle();
	double getVerticalSpeed();
	int getFrame();
	void setAngle(float angle);
	void setVerticalSpeed(double v);
	void setFrame(int frame);
	

};

