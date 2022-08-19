#include "tetromino.hpp"
#include "t.hpp"

#include <vector>

T::T() : Tetromino("T") {
	this->addCell(0, 1);
	this->addCell(1, 0);
	this->addCell(1, 1);
	this->addCell(1, 2);
}


void T::rotate(int board[][10]) {
	int config = this->getConfig();
	std::vector<std::vector<int>> newCoords;
	if (config == 0) {
		newCoords = {{this->cellAt(2)[0], this->cellAt(2)[1]}, 
					 {this->cellAt(2)[0]-1, this->cellAt(2)[1]}, 
					 {this->cellAt(2)[0], this->cellAt(2)[1]+1}, 
					 {this->cellAt(2)[0]+1, this->cellAt(2)[1]}};				   
	} else if (config == 1) {
		newCoords = {{this->cellAt(0)[0], this->cellAt(0)[1]}, 
					 {this->cellAt(0)[0], this->cellAt(0)[1]+1}, 
					 {this->cellAt(0)[0], this->cellAt(0)[1]-1}, 
					 {this->cellAt(0)[0]+1, this->cellAt(0)[1]}};					   
	} else if (config == 2) {
		newCoords = {{this->cellAt(0)[0], this->cellAt(0)[1]}, 
					 {this->cellAt(0)[0]+1, this->cellAt(0)[1]}, 
					 {this->cellAt(0)[0]-1, this->cellAt(0)[1]}, 
					 {this->cellAt(0)[0], this->cellAt(0)[1]-1}};					   
	} else if (config == 3) {
		newCoords = {{this->cellAt(0)[0], this->cellAt(0)[1]+1}, 
					 {this->cellAt(0)[0], this->cellAt(0)[1]-1}, 
					 {this->cellAt(0)[0], this->cellAt(0)[1]}, 
					 {this->cellAt(0)[0]-1, this->cellAt(0)[1]}};					   
	}
	
	if(this->makeRotation(board, newCoords)) {
		if (config != 3) {
			this->nextConfig();
		} else {
			this->resetConfig();
		}
	}
	
}