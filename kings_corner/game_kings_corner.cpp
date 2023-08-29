//Shawn Ogbomo
// Sun Aug 3 2023
//Kings corner game v1
//revision history
//This program implements the card game kings in the corner
//Input from cin; output to cout.

#include <iostream>
#include "player.h"
#include "exceptions.h"
#include "card.h"
#include "board.h"
#include "util.h"

std::string_view  quit = "q";
std::string_view  reset = "o";
std::string_view start = "x";
std::string_view  help = "h";
std::string_view ex_key = "exit";

[[noreturn]] void main_screen() {
	while (true) try {
		std::cout << "\nKings Corner Press x to start o to reset : ";

		std::string s;
		std::getline(std::cin, s);

		if (s == start) {
			//START GAME IN HERE
			std::cout << "Game starting...\n";
			throw std::runtime_error{ "Reseting...\n" };
		}

		if (s == reset) {
			throw std::runtime_error{ "Reseting...\n" };
		}

		if (s == quit) {
			std::cout << "Quit...\n";
			throw Terminate{ "Exiting..." };
		}

		if (s == help) {
			std::cout << "Help screen...";
			throw std::runtime_error{ "Reseting...\n" };
		}

		throw std::runtime_error{ "Invalid input. Try again...\n" };
	}

	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
}

int main() {
	try {
		main_screen();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	catch (const Terminate& e) {
		std::cerr << e.what() << "\n";
	}
}