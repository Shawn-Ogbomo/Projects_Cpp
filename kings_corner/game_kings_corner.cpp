//Shawn Ogbomo
// Sun Aug 3 2023
//Kings corner game v1
//revision history
//
//This program implements the card game kings in the corner
//Input from cin; output to cout.

#include <iostream>
#include "player.h"

int main() {
	try {
		for (Player p; std::cin >> p;) {
			p = {};
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
	}
}