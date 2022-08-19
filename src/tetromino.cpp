#include <iostream>
#include <vector>
#include <string>

#include "tetromino.hpp"
#include "tools.hpp"

void Tetromino::removeCellsAtRow(int i) {
	auto j = cells.begin();
	while (j != cells.end()) {
		if ((*j)[0] == i) {
			j = cells.erase(j);
		} else {
			j++;
		}
	}
}

void Tetromino::deleteCell(int i) {
	cells.erase(cells.begin()+i-1);
}

bool Tetromino::makeRotation(int board[][10], std::vector<std::vector<int>> newCoords) {
	if(tools::isRotateLegal(board, *this, newCoords)) {
		this->clearCells();
		this->addCell(newCoords[0][0], newCoords[0][1]);
		this->addCell(newCoords[1][0], newCoords[1][1]);
		this->addCell(newCoords[2][0], newCoords[2][1]);
		this->addCell(newCoords[3][0], newCoords[3][1]);
		return true;
	}
	return false;
}

bool Tetromino::shiftCells(int board[][10], std::string direction) {
	if (tools::isMoveLegal(board, *this, direction)) {
		for (std::vector<int> &cell : cells) {
			if (direction == "right") {
				cell[1]++;
			} else if (direction == "left") {
				cell[1]--;
			} else if (direction == "down") {
				cell[0]++;
			}
		}
		return true;
	} else {
		return false;
	}
}

void Tetromino::move(int board[][10], std::string direction) {
	this->shiftCells(board, direction);
}

void Tetromino::gravity(int board[][10], std::vector<Tetromino*>& tetrominos) {
	if (!(this->shiftCells(board, "down"))) {
		this->deactivate();
		
		tools::clearCompletedLines(board, tetrominos);
		
		
		tools::findActiveTetromino(tetrominos);
	}
}

void Tetromino::updateCell(int i, int row, int col) {
	cells[i][0] = row;
	cells[i][1] = col;
}

void Tetromino::addCell(int x, int y) {
	std::vector<int> newCell = {x, y};
	cells.push_back(newCell);
}