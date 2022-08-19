#include <SFML/Graphics.hpp>

#include "tetromino.hpp"
#include "block.hpp"
#include "line.hpp"
#include "tools.hpp"

#include <iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(1500, 1500), "Tetris");
	window.setKeyRepeatEnabled(false);
	// window.setFramerateLimit(20);
	sf::Clock clock;

	std::vector<Tetromino*> tetrominos;
	int score = 0;
	
	Tetromino* t = tools::chooseNewTetromino();
	t->activate();
	tetrominos.push_back(t);
	
	int board[21][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					 	 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
						

	while(window.isOpen()) {
		sf::sleep(sf::milliseconds(1));
		sf::Time time = clock.getElapsedTime();
		sf::Event event;
		while(window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			} else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Right) {
					tools::findActiveTetromino(tetrominos)->move(board, "right");
				} else if (event.key.code == sf::Keyboard::Left) {
					tools::findActiveTetromino(tetrominos)->move(board, "left");
				} else if (event.key.code == sf::Keyboard::Down) {
					tools::findActiveTetromino(tetrominos)->move(board, "down");
				} else if (event.key.code == sf::Keyboard::Up) {
					tools::findActiveTetromino(tetrominos)->rotate(board);
				}
			}
		}

		window.clear(sf::Color::White);

		tools::clearBoard(board);
		
		tools::fillBoard(board, tetrominos);
		
		if (time.asSeconds() >= 0.5) {
			tools::findActiveTetromino(tetrominos)->gravity(board, tetrominos);
			clock.restart();
		}
		
		tools::drawBoard(board, window, tetrominos);
		
		
		
		
		window.display();
	}
	
	for (Tetromino* t : tetrominos) {
		delete t;
	}

    return 0;
}