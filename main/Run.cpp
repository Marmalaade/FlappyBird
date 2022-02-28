#include "Run.h"




bool Run::collides(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
{
			return x1 + w1 >= x2 && x1 <= x2 + w2 && y1 + h1 >= y2 && y1 <= y2 + h2;
}

void Run::run()
{
	RenderWindow window(VideoMode(1000, 600), "Flappy Bird");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	srand(time(0));

	Sounds sounds;

	Textures textures;

	Flappy flappy;
	flappy.setAngle(0);
	flappy.setVerticalSpeed(0);
	flappy.setFrame(0);

	flappy.sprite.setPosition(250, 300);
	flappy.sprite.setScale(2, 2);

	vector<Sprite> pipes;
    
	Game game(textures);
	

	ifstream fin;
	fin.exceptions(ofstream::badbit | ofstream::failbit);
	try {
		fin.open("Highscore.txt");
		fin.read((char*)&game.highscore, sizeof(game.highscore));
	}
	catch (const ifstream::failure& ex) {
		cout << ex.what() << endl;
		cout << ex.code() << endl;
		cout << "Error with file open.." << endl;
	}
	fin.close();


	while (window.isOpen()) {
		
		flappy.sprite.setTexture(textures.flappy[1]);
		game.scoreText.setString("Score " + to_string(game.score));
		game.highscoreText.setString("High Score " + to_string(game.highscore));
	

		float fx = flappy.sprite.getPosition().x;
		float fy = flappy.sprite.getPosition().y;
		float fw = 34 * flappy.sprite.getScale().x;
		float fh = 24 * flappy.sprite.getScale().y;

		if (game.gameState == Game::GameState::waiting || game.gameState == Game::GameState::started) {

			if (game.frames % 6 == 0) {
				flappy.setFrame(flappy.getFrame() + 1);
			}
			if (flappy.getFrame() == 3) {
				flappy.setFrame(0);
			}
		}

		flappy.sprite.setTexture(textures.flappy[flappy.getFrame()]);

		if (game.gameState == Game::GameState::started) {

			if (flappy.getAngle() < 25)
				flappy.setAngle(flappy.getAngle()+2);

			else
				flappy.setAngle(25);
		}
		if (game.gameState != Game::GameState::waiting) {
			flappy.sprite.move(0, flappy.getVerticalSpeed());
			flappy.setVerticalSpeed(flappy.getVerticalSpeed()+0.5);
		}

		if (game.gameState == Game::GameState::started) {
			if (fy < 0) {
				flappy.sprite.setPosition(250, 0);
				flappy.setVerticalSpeed(0);
			}
			else if (fy > 600) {
				flappy.setVerticalSpeed(0);
				game.gameState = Game::GameState::gameover;
				sounds.dishk.play();
			}
		}

		for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++) {
			if (game.gameState == Game::GameState::started && (*itr).getPosition().x == 250) {
				game.score++;
				sounds.ching.play();

				if (game.score > game.highscore) {
					game.highscore = game.score;
				}

				break;
			}
		}

		if (game.gameState == Game::GameState::started && game.frames % 150 == 0) {
			int r = rand() % 275 + 75;
			int gap = 185;

			Sprite pipeL;
			pipeL.setTexture(textures.pipe);
			pipeL.setPosition(1000, r + gap);
			pipeL.setScale(2, 2);

			Sprite pipeU;
			pipeU.setTexture(textures.pipe);
			pipeU.setPosition(1000, r);
			pipeU.setScale(2, -2);

			pipes.push_back(pipeL);
			pipes.push_back(pipeU);
		}

		if (game.gameState == Game::GameState::started) {
			for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++) {
				(*itr).move(-3, 0);
			}
		}

		if (game.frames % 100 == 0) {
			vector<Sprite>::iterator startitr = pipes.begin();
			vector<Sprite>::iterator enditr = pipes.begin();

			for (; enditr != pipes.end(); enditr++) {
				if ((*enditr).getPosition().x > -104) {
					break;
				}
			}

			pipes.erase(startitr, enditr);
		}

		if (game.gameState == Game::GameState::started) {
			for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++) {

				float px, py, pw, ph;

				if ((*itr).getScale().y > 0) {
					px = (*itr).getPosition().x;
					py = (*itr).getPosition().y;
					pw = 52 * (*itr).getScale().x;
					ph = 320 * (*itr).getScale().y;
				}
				else {
					pw = 52 * (*itr).getScale().x;
					ph = -320 * (*itr).getScale().y;
					px = (*itr).getPosition().x;
					py = (*itr).getPosition().y - ph;
				}

				if (collides(fx, fy, fw, fh, px, py, pw, ph)) {
					game.gameState = Game::GameState::gameover;
					sounds.dishk.play();
				}
			}
		}

		Event event;
		while (window.pollEvent(event)) {
			

			if (event.type == Event::KeyPressed &&
				event.key.code == Keyboard::Escape) {
				Event::Closed;
				ofstream fout;
				fout.exceptions(ofstream::badbit | ofstream::failbit);
				try {
					fout.open("Highscore.txt");
					fout.write((char*)&game.highscore, sizeof(game.highscore));
				}
					catch(const exception& ex){
						cout << ex.what() << endl;
						cout << "Error with file open.." <<endl;
				}
					fout.close();
					window.close();

			}

			else if (event.type == Event::MouseButtonPressed &&
				event.key.code == Mouse::Left) {
				if (game.gameState == Game::GameState::waiting) {
					game.gameState = Game::GameState::started;
				}

				if (game.gameState == Game::GameState::started) {
					flappy.setVerticalSpeed(-8);
					Vector2f Rt = flappy.sprite.getPosition();
					flappy.setAngle(-45);

					sounds.hop.play();
				}

			}
			else if (event.type == Event::MouseButtonPressed &&
				event.key.code == Mouse::Right &&
				game.gameState == Game::GameState::gameover) {
				game.gameState = Game::GameState::waiting;
				flappy.sprite.setPosition(250, 300);
				flappy.setAngle(0);
				game.score = 0;
				pipes.clear();
			}
		}

		window.clear();
		if (game.score > 1) {
			window.draw(game.background2[0]);
			window.draw(game.background2[1]);
			window.draw(game.background2[2]);
		}
		else {
			window.draw(game.background[0]);
			window.draw(game.background[1]);
			window.draw(game.background[2]);
		}
		
		flappy.sprite.setRotation(flappy.getAngle());
		window.draw(flappy.sprite);

		for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++) {
			window.draw(*itr);
		}

		window.draw(game.scoreText);
		window.draw(game.highscoreText);
	
		if (game.gameState == Game::GameState::gameover) {
			window.draw(game.gameover);

			if (game.frames % 60 < 30) {
				window.draw(game.pressC);
			}
		}
		if (game.gameState == Game::GameState::waiting) {
			window.draw(game.startGameText);
		}
		window.display();
		
		game.frames++;
	}


}

