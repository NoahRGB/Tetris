#pragma once

#include "tetromino.hpp"

#include <vector>
#include <string>


class Tetromino {
	private:
		std::vector<std::vector<int>> cells;
		std::string type;
		
		int currentConfig = 0;
		bool active = false;


	public:
		Tetromino(std::string pType) : type(pType) {};
		std::string getType() { return type; }
		
		virtual void rotate(int board[][10]) {};
		bool shiftCells(int board[][10], std::string direction);
		void move(int board[][10], std::string direction);
		void gravity(int board[][10], std::vector<Tetromino*>& tetrominos);
		
		
		
		void activate() { active = true; }
		void deactivate() { active = false; }
		bool isActive() { return active; }
		
		void nextConfig() { currentConfig++; }
		void resetConfig() { currentConfig = 0; }
		int getConfig() { return currentConfig; }
		bool makeRotation(int board[][10], std::vector<std::vector<int>> newCoords);
		
		void addCell(int x, int y);
		void deleteCell(int i);
		void updateCell(int i, int row, int col);
		void removeCellsAtRow(int i);
		std::vector<std::vector<int>> getCells() { return cells; }
		int cellCount() { return cells.size(); }
		std::vector<int> cellAt(int i) { return cells[i]; }
		void clearCells() { cells.clear(); }
	
};