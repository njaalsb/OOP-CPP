#include "Tile.h"
#include <map>

// For aa sette labelfarge i henhold til hvor mange miner som er rundt
const std::map<int, TDT4102::Color> minesToColor{{1, TDT4102::Color::blue},
												{2, TDT4102::Color::red},
												{3, TDT4102::Color::dark_green},
												{4, TDT4102::Color::dark_magenta},
												{5, TDT4102::Color::dark_blue},
												{6, TDT4102::Color::dark_cyan},
												{7, TDT4102::Color::dark_red},
												{8, TDT4102::Color::gold}};

// For aa sette Tilelabel i henhold til state
const std::map<Cell, std::string> cellToSymbol{{Cell::closed, ""},
									 			{Cell::open, ""},
									 	  		{Cell::flagged, "|>"}};

Tile::Tile(TDT4102::Point pos, int size) : 
	Button({pos.x, pos.y}, 1.5*size, size, "") {
		setButtonColor(TDT4102::Color::silver);
	}

void Tile::open()
{
	if (Tile::getState() == Cell::flagged || Tile::getState() == Cell::open)
	{
		return;
	} 
	else if(Tile::getState() == Cell::closed) {
		this->setButtonColor(TDT4102::Color::white);
		Tile::state = Cell::open;
		if (Tile::getIsMine())
		{
			Tile::set_label("X");
			Tile::set_label_color(TDT4102::Color::red);
		}
		
	}
	
}

void Tile::flag()
{
	if(Tile::getState() == Cell::flagged){
		Tile::state = Cell::closed;
		Tile::set_label(cellToSymbol.at(Cell::open));
	} else if(Tile::getState() != Cell::flagged){

		std::string lable = cellToSymbol.at(Cell::flagged);

		Tile::set_label(lable);

		Tile::set_label_color(TDT4102::Color::black);
	}
}


void Tile::setAdjMines(int n){
	static_cast<uint16_t>(n);
	if(1>n || n > 8){
		return;
	} else {
		Tile::set_label(std::to_string(n));
		Tile::set_label_color(minesToColor.at(n));
	}
	
}

