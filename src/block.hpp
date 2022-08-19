#pragma once

class Block : public Tetromino {
	public:
		Block();
		void rotate(int board[][10]);
};