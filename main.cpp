// Author: Ben Goodman
//Email: BCG2@email.sc.edu
//Section: 002
//Copyright 2021 Ben Goodman

#include <iostream>
#include "./Sim.h"

int main (int argc, char **argv) { 
	Sim w;
	string userInput;
	w.initGrid();
	
	std::cout << "Welcome to the snail garden" << "\n";
	std::cout << "Here is the Garden on day " << w.DayCycle();
	w.PrintGrid();
	
	std::cout << "Would you like to see the garden tomorrow? (y/n)" << "\n";
	std::cin >> userInput;

	
	while(userInput != "n")
	{
		w.UpdateGrid();
		w.PrintGrid();
		w.SnailsTerminate();
		w.MushroomsTerminate();
		//Snails Win
		if(w.SnailsTerminate() == true)
		{
			std::cout << "The Snails have taken over the garden" << "\n";
			break;
		}
		//Mushrooms Win
		if(w.MushroomsTerminate() == true)
		{
			std::cout << "The Mushrooms have taken over the garden" << "\n";
			break;
		}
		//Winter Comes
		if(w.day == 300)
		{
			std::cout << "Winter has arrived and all life in the garden died" << "\n";
			w.Death();
			break;
		}
		//Continue
		else
		{
		std::cout << "Here is the Garden on day " << w.DayCycle() << "\n";
		std::cout << "Would you like to see the garden tomorrow? (y/n)";
		std::cin >> userInput;
		}
	}
	std::cout << "The Simulation has terminated" << "\n";
	return 0;
}
