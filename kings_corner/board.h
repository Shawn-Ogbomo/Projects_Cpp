#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "card.h"

struct Board {
	Deck middle_pile;
	std::vector<Card> north_pile;
	std::vector<Card> south_pile;
	std::vector<Card> east_pile;
	std::vector<Card> west_pile;
	std::vector<Card> north_west_pile;
	std::vector<Card> north_east_pile;
	std::vector<Card> south_west_pile;
	std::vector<Card> south_east_pile;
};

#endif // BOARD_H