#include <SFML/Graphics.hpp>

#include "tools.hpp"
#include "tetromino.hpp"
#include "block.hpp"
#include "line.hpp"
#include "t.hpp"
#include "l.hpp"
#include "j.hpp"
#include "s.hpp"
#include "z.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>

void tools::shiftCellsDown(int linesCleared, int lowestLine, std::vector<Tetromino*>& tetrominos) {
	for (Tetromino* t : tetrominos) {
		for (int i = 0; i < t->cellCount(); i++) {
			if (t->cellAt(i)[0] < lowestLine) {
				t->updateCell(i, t->cellAt(i)[0]+linesCleared, t->cellAt(i)[1]);
			}
		}
	}
}

void tools::clearCompletedLines(int board[][10], std::vector<Tetromino*>& tetrominos) {
	int linesCleared = 0;
	int lowestLine = 0;
	for (int i = 0; i < 20; i++) {
		int count = 0;
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == 1) count++;
		}
		
		if (count == 10) {
			linesCleared++;
			for (Tetromino* t : tetrominos) {
				t->removeCellsAtRow(i);
			}
			if (i > lowestLine) {
				lowestLine = i;
			}
		}
	}
	tools::shiftCellsDown(linesCleared, lowestLine, tetrominos);
}

bool tools::isRotateLegal(int board[][10], Tetromino t, std::vector<std::vector<int>> coords) {
	bool legal = true;;
	
	for (std::vector<int> pair : coords) {
		if ((board[pair[0]][pair[1]] != 0) && (tools::existsIn(t.getCells(), pair) == false)) {
			legal = false;
		}
	}
	
	return legal;
}

Tetromino* tools::chooseNewTetromino() {
	//std::srand(time(0));
	int num = rand() % 7;
	if (num == 0) {
		return new Block();
	} else if (num == 1) {
		return new Line();
	} else if (num == 2) {
		return new T();
	} else if (num == 3) {
		return new L();
	} else if (num == 4) {
		return new J();
	} else if (num == 5) {
		return new S();
	} else if (num == 6) {
		return new Z();
	}
	return new Line();
}

Tetromino* tools::findActiveTetromino(std::vector<Tetromino*>& tetrominos) {
	for (Tetromino* t : tetrominos) {
		if (t->isActive()) {
			return t;
		}
	}
	
	Tetromino* t = tools::chooseNewTetromino();
	t->activate();
	tetrominos.push_back(t);
	return t;
}

bool tools::isMoveLegal(int board[][10], Tetromino t, std::string direction) {
	bool legal = true;
	
	for (int i = 0; i < t.cellCount(); i++) {
		std::vector<int> newCell = t.cellAt(i);
		
		if (direction == "right") {
			newCell[1]++;
		} else if (direction == "left")  {
			newCell[1]--;
		} else if (direction == "down") {
			newCell[0]++;
		}

		if (newCell[1] > 9 || newCell[1] < 0) {
			legal = false;
		}
		if ((board[newCell[0]][newCell[1]] == 1) && (tools::existsIn(t.getCells(), newCell) == false)) {
			legal = false;
		}
	}
	return legal;
}

void tools::clearBoard(int board[][10]) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			board[i][j] = 0;
		}
	}
}

void tools::fillBoard(int board[][10], std::vector<Tetromino*> tetrominos) {
	for (Tetromino* t : tetrominos) {
		for (int i = 0; i < t->cellCount(); i++) {
			std::vector<int> coords = t->cellAt(i);
			board[coords[0]][coords[1]] = 1;
		}
	}
}

void tools::drawBoard(int board[][10], sf::RenderWindow &window, std::vector<Tetromino*> tetrominos) {
	const int xIndent = 500;
	const int yIndent = 100;
	
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			sf::RectangleShape r(sf::Vector2f(50, 50));
			r.setPosition(xIndent+(j*50), yIndent+(i*50));
			r.setOutlineColor(sf::Color::Black);
			r.setOutlineThickness(5);
			if (board[i][j] == 1) {
				for (Tetromino* t : tetrominos) {
					for (int p = 0; p < t->cellCount(); p++) {
						if (t->cellAt(p)[0] == i && t->cellAt(p)[1] == j) {
							if (t->getType() == "Block") {
								r.setFillColor(sf::Color::Yellow);
							} else if (t->getType() == "Line") {
								r.setFillColor(sf::Color::Cyan);
							} else if (t->getType() == "L") {
								r.setFillColor(sf::Color(255, 136, 0));
							} else if (t->getType() == "J") {
								r.setFillColor(sf::Color::Blue);
							} else if (t->getType() == "T") {
								r.setFillColor(sf::Color::Magenta);
							} else if (t->getType() == "S") {
								r.setFillColor(sf::Color::Green);
							} else if (t->getType() == "Z") {
								r.setFillColor(sf::Color::Red);
							}
						}
					}
				}
			}
				
				
			window.draw(r);
		}
	}
}