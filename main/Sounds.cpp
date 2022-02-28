#include "Sounds.h"

Sounds::Sounds()
{
chingBuffer.loadFromFile("./audio/score.wav");
hopBuffer.loadFromFile("./audio/flap.wav");
dishkBuffer.loadFromFile("./audio/crash.wav");
ching.setBuffer(chingBuffer);
hop.setBuffer(hopBuffer);
dishk.setBuffer(dishkBuffer);

}
