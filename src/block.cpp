#include "tetromino.hpp"
#include "block.hpp"

#include <vector>

Block::Block() : Tetromino("Block") {
	this->addCell(0, 0);
	this->addCell(0, 1);
	this->addCell(1, 0);
	this->addCell(1, 1);
}

void Block::rotate(int board[][10]) {
	
}
