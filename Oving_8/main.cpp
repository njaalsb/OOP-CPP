#include "Person.h"
#include "Meeting.h"
#include "MeetingWindow.h"
#include <iostream>

int main()
{
	int verdi;
	std::cout << "Velg oppgave du ønsker å teste:\n"; 
	std::cin >> verdi;
	//Car bil1(5);
	//Car bil2(3);

	std::unique_ptr<Car> bil1 = std::make_unique<Car>(5);
	std::unique_ptr<Car> bil2 = std::make_unique<Car>(2);

	Person Jotaro("Jotaro Joestar", "Star Platinum", std::move(bil1));
	Person Dio("Dio Brando", "Za Warudo", std::move(bil2));

	std::cout << Jotaro.getName() << std::endl;
	std::cout << Jotaro << std::endl;
	Jotaro.setEmail("Joestar");

	while (1)
	{
		switch (verdi)
		{
		case 1:
			std::cout << Jotaro.getName() << std::endl;
			std::cout << Jotaro.getEmail() << std::endl;
			std::cout << Jotaro << std::endl;
			break;
		
		default:
			break;
		}
	}
	return 0;
	
}
