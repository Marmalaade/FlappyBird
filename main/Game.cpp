#include "Game.h"

Game::Game(Textures& textures)
{
	font.loadFromFile("./fonts/flappy.ttf");
	background[0].setTexture(textures.background);
	background[1].setTexture(textures.background);
	background[2].setTexture(textures.background);
	background[0].setScale(1.15625, 1.171875);
	background[1].setScale(1.15625, 1.171875);
	background[2].setScale(1.15625, 1.171875);
	background[1].setPosition(333, 0);
	background[2].setPosition(666, 0);
	background2[0].setTexture(textures.background2);
	background2[1].setTexture(textures.background2);
	background2[2].setTexture(textures.background2);
	background2[0].setScale(1.15625, 1.171875);
	background2[1].setScale(1.15625, 1.171875);
	background2[2].setScale(1.15625, 1.171875);
	background2[1].setPosition(333, 0);
	background2[2].setPosition(666, 0);
	gameover.setTexture(textures.gameover);
	gameover.setOrigin(192 / 2, 42 / 2);
	gameover.setPosition(500, 125);
	gameover.setScale(2, 2);
	startGameText.setString("Press to start");
	startGameText.setFont(font);
	startGameText.setOutlineColor(Color::Black);
	startGameText.setOutlineThickness(5);
	startGameText.setFillColor(Color::White);
	startGameText.setCharacterSize(70);
	startGameText.setOrigin(startGameText.getLocalBounds().width / 2, 0);
	startGameText.setPosition(500, 200);
	pressC.setString("Press RightMouse to continue");
	pressC.setFont(font);
	pressC.setOutlineColor(Color::Black);
	pressC.setOutlineThickness(5);
	pressC.setFillColor(Color::White);
	pressC.setCharacterSize(50);
	pressC.setOrigin(pressC.getLocalBounds().width / 2, 0);
	pressC.setPosition(500, 250);
	scoreText.setFont(font);
	scoreText.setOutlineColor(Color::Black);
	scoreText.setOutlineThickness(3);
	scoreText.setFillColor(Color::White);
	scoreText.setCharacterSize(50);
	scoreText.move(30, 0);
	highscoreText.setFont(font);
	highscoreText.setOutlineColor(Color::Black);
	highscoreText.setOutlineThickness(3);
	highscoreText.setFillColor(Color::White);
	highscoreText.move(30, 80);
	score = 0;
	highscore = 0;
	frames = 0;
	gameState = waiting;
}
