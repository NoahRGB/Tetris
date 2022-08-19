#pragma once

#include <SFML/Graphics.hpp>

#include "tetromino.hpp"

#include <vector>
#include <string>

namespace tools {
	
	template <typename T, typename A>
	bool existsIn(std::vector<T> list, A element) {
		for (T el : list) {
			if (el == element) return true;
		}
		return false;
	}
	
	bool isMoveLegal(int board[][10], Tetromino t, std::string direction);
	bool isRotateLegal(int board[][10], Tetromino t, std::vector<std::vector<int>> coords);
	Tetromino* findActiveTetromino(std::vector<Tetromino*>& tetrominos);
	Tetromino* chooseNewTetromino();
	
	void shiftCellsDown(int linesCleared, int lowestLine, std::vector<Tetromino*>& tetrominos);
	void clearCompletedLines(int board[][10], std::vector<Tetromino*>& tetrominos);
	void clearBoard(int board[][10]);
	void fillBoard(int board[][10], std::vector<Tetromino*> tetrominos);
	void drawBoard(int board[][10], sf::RenderWindow &window, std::vector<Tetromino*> tetrominos);
};