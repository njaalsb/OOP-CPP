#include "MeetingWindow.h"
#include <iostream>

MeetingWindow::MeetingWindow(TDT4102::Point position, int width, int height, const std::string& title):
	// BEGIN 4a
    AnimationWindow(position.x, position.y, width, height, title),
	// END 4a

	// BEGIN 4e
	quitBtn(position, width, height, title),
	// END 4e

	// BEGIN 5a
	#define FOUR_A
	// END 5a

	// BEGIN 5b
	#define FOUR_B
	// END 5b

	dummyArgument{0}
{
	// Felles
	// BEGIN 4f
	
	// END 4f
	
	// BEGIN 4g
	quitBtn.setCallback([]() {
		std::cout << "Quit button pressed!" << std::endl;
	});
	// END 4g

	// BEGIN 5d

	// END 5d

	// Ny person
	#ifndef FOUR_A
	attachPersonWidget(personName);
	attachPersonWidget(personEmail);
	#endif

	#ifndef FOUR_B
	attachPersonWidget(personSeats);
	attachPersonWidget(personNewBtn);
	#endif
}

// Callbackfunksjoner
// BEGIN 4d
void cb_quit(){
	;
}
// END 4d

// BEGIN 5c

// END 5c

void MeetingWindow::attachPersonWidget(TDT4102::Widget& pw)
{
	add(pw);
	personWidgets.emplace_back(std::ref(pw));
}