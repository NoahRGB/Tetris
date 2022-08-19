#include "tetromino.hpp"
#include "line.hpp"
#include "tools.hpp"

#include <vector>
#include <iostream>

Line::Line() : Tetromino("Line") {
	this->addCell(0, 0);
	this->addCell(1, 0);
	this->addCell(2, 0);
	this->addCell(3, 0);
}

void Line::rotate(int board[][10]) {
	int config = this->getConfig();
	std::vector<std::vector<int>> newCoords;
	if (config == 0) {
		newCoords = {{this->cellAt(1)[0], this->cellAt(1)[1]}, 
					 {this->cellAt(1)[0], this->cellAt(1)[1]-1}, 
					 {this->cellAt(1)[0], this->cellAt(1)[1]+1}, 
					 {this->cellAt(1)[0], this->cellAt(1)[1]+2}};				   
	} else if (config == 1) {
		newCoords = {{this->cellAt(0)[0], this->cellAt(0)[1]}, 
					 {this->cellAt(0)[0]-1, this->cellAt(0)[1]}, 
					 {this->cellAt(0)[0]-2, this->cellAt(0)[1]}, 
					 {this->cellAt(0)[0]+1, this->cellAt(0)[1]}};					   
	} else if (config == 2) {
		newCoords = {{this->cellAt(1)[0], this->cellAt(1)[1]}, 
					 {this->cellAt(1)[0], this->cellAt(1)[1]-1}, 
					 {this->cellAt(1)[0], this->cellAt(1)[1]+1}, 
					 {this->cellAt(1)[0], this->cellAt(1)[1]+2}};					   
	} else if (config == 3) {
		newCoords = {{this->cellAt(0)[0], this->cellAt(0)[1]}, 
					 {this->cellAt(0)[0]-1, this->cellAt(0)[1]}, 
					 {this->cellAt(0)[0]-2, this->cellAt(0)[1]}, 
					 {this->cellAt(0)[0]+1, this->cellAt(0)[1]}};					   
	}
	
	if(this->makeRotation(board, newCoords)) {
		if (config != 3) {
			this->nextConfig();
		} else {
			this->resetConfig();
		}
	}
	
}