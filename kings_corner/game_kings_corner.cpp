//Shawn Ogbomo
// Sun Aug 3 2023
//Kings corner game v1
//revision history
//
//This program implements the card game kings in the corner
//Input from cin; output to cout.

#include <iostream>
#include "player.h"
#include "exceptions.h"

struct Board {
	Deck middle_pile;
	std::vector<Card> north_pile;
	std::vector<Card> south_pile;
	std::vector<Card> east_pile;
	std::vector<Card> west_pile;
	std::vector<Card> top_left_pile;
	std::vector<Card> top_right_pile;
	std::vector<Card> bottom_left_pile;
	std::vector<Card> bottom_right_pile;
};

const char quit = 'q';
const char reset = 'r';
const std::string_view ex_key = "exit";

int main() {
	try {
		Board game_board;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	catch (const Terminate&) {
		std::cerr << "exiting...";
	}
}