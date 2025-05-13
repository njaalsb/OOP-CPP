#include "MinesweeperWindow.h"
#include <iostream>
#include <random>

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize, title},
	width{width}, height{height}, mines{mines}
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
			auto temp = tiles.back().get();
			add(*temp); 
		}
	}
	// Legg til miner paa tilfeldige posisjoner
	int i = 0;
	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<int> distribution(0, tiles.size()-1);
	while (i < mines) {
		int pos = distribution(generator);
		if (!tiles[pos]->getIsMine()) {
			tiles[pos]->setIsMine(true);
			++i;
		}
	}
	int mineCount = 0;
	for (auto& tile : tiles) {
		if (tile->getIsMine()) ++mineCount;
	}
	std::cout << "Plasserte miner: " << mineCount << "\n";
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	// Oppgave 3c
	std::shared_ptr<Tile> t = at(xy);
	if (t->getState() != Cell::closed)
	{
		return;
	}
	
	if(t->getState() == Cell::closed) {
		t->open();
		if(t->getIsMine()){
			loser(xy);
			return;
		} 
		else
		{
			vector<Point> n = adjacentPoints(xy);
			int count = countMines(n);
			if(count>0){
				t->setLabel(std::to_string(count));
			}
			else {
				for (Point p : n)
				{
					openTile(p);
				}
			}
		}
	}
}

void MinesweeperWindow::flagTile(Point xy) {
	// Oppgave 3B
	std::shared_ptr<Tile> t = at(xy);
	if(t->getState() == Cell::closed || t->getState() == Cell::flagged){
		t->flag();
	}
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click() {
	
	Point xy{this->get_mouse_coordinates()};

	if (!inRange(xy)) {
		return;
	}
	if (this->is_left_mouse_button_down()) {
		openTile(xy);
	}
	else if(this->is_right_mouse_button_down()){
		flagTile(xy);
	}
}

int MinesweeperWindow::countMines(std::vector<Point> coords) const{
	int adjMines = 0;
	for(Point p : coords){
		if (at(p)->getIsMine())
		{
			++adjMines;
		}	
	}
	return adjMines;
}

void MinesweeperWindow::loser(Point xy){
	shared_ptr<Tile> p = at(xy);
	p->Tile::setLabelColor(TDT4102::Color::red);
	this->setBackgroundColor(TDT4102::Color::red);
	p->setButtonColor(TDT4102::Color::black);
	std::cout << "Du tapte" << std::endl;
	
}

void MinesweeperWindow::winner(){
	won = true;

	for(auto tile : tiles){
		if(tile->getState() == Cell::closed){
			tile->flag();
		}
	}
}