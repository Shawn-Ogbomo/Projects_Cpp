#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include<vector>
#include "card.h"

class Player {
public:
	Player() = default;
	explicit Player(const std::string& name, char gender, int age)
		:n{ name },
		g{ gender },
		a{ age } {
		//CHECK IF NAME GENDER AND AGE ARE VALID
	}

private:
	std::string n;
	char g{};
	int a{};
	std::vector<Card> hand; //INITIALIZED WITH 7 CARDS WHEN DECK IS SHUFFLED AND GAME STARTS
};

#endif // PLAYER_H