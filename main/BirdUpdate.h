#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "GameStates.h"
#include "Textures.h"
#include"Flappy.h"

using namespace sf;
class BirdUpdate
{
	float fx;
	float fy;
	float fw;
	float fh;
public:
	float getFx();
	float getFy();
	float getFw();
	float getFh();

	void setFx(float fx);
	void setFy(float fy);
	void setFw(float fw);
	void setFh(float fh);
	BirdUpdate(Flappy &flappy);
};

