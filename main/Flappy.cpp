#include "Flappy.h"
#include "Flappy.h"

float Flappy::getAngle()
{
    return angle;
}

double Flappy::getVerticalSpeed()
{
    return v;
}

int Flappy::getFrame()
{
    return frame;
}

void Flappy::setAngle(float angle)
{
    this->angle = angle;
}

void Flappy::setVerticalSpeed(double v)
{
    this->v = v;
}

void Flappy::setFrame(int frame)
{
    this->frame = frame;
}
