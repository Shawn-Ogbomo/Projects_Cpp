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

const char quit = 'q';
const char reset = 'o';
const char start = 'x';
const std::string_view ex_key = "exit";

void main_screen() {
	while (true) try {
		std::cout << "\nKings Corner Press x to start o to reset: ";
		char ch{};
		std::cin >> ch;
		Util::check_stream(std::cin, "Exiting...");

		switch (ch) {
		case start:
		{
			std::cout << "Game starting...\n";
			return;
		}
		case reset:
		{
			throw std::runtime_error{ "Reseting...\n" };
		}

		default:
			std::cout << "\nInvalid input\n";
			Util::clean_up_mess(';');
			break;
		}
	}

	catch (const std::exception& e) {
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