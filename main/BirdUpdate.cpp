#include "BirdUpdate.h"

float BirdUpdate::getFx()
{
	return fx;
}

float BirdUpdate::getFy()
{
	return fy;
}

float BirdUpdate::getFw()
{
	return fw;
}

float BirdUpdate::getFh()
{
	return fh;
}

void BirdUpdate::setFx(float fx)
{
	this->fx = fx;
}

void BirdUpdate::setFy(float fy)
{
	this->fy = fy;
}

void BirdUpdate::setFw(float fw)
{
	this->fw = fw;
}

void BirdUpdate::setFh(float fh)
{
	this->fh = fh;
}

BirdUpdate::BirdUpdate(Flappy& flappy)
{
	 fx = flappy.sprite.getPosition().x;
	 fy = flappy.sprite.getPosition().y;
	 fw = 34 * flappy.sprite.getScale().x;
	 fh = 24 * flappy.sprite.getScale().y;
}
