#include <map>
#include <string>
#include "card.h"

Card::Card(std::string_view name, Suit su, int val, Color co)
	:n{ name },
	s{ su },
	v{ val },
	c{ co } {
}

Deck::Deck() {
	static std::map<std::string, int> m{
		{"ACE",1}, {"TW0",2},{"THREE",3},{"FOUR",4}
		,{"FIVE",5},{"SIX",6},{"SEVEN",7},{"EIGHT",8}
		,{"NINE",9},{"TEN",10}
		,{"JACK",11} , {"QUEEN",12} ,{"KING",13}
	};

	for (const auto& [key, value] : m) {
		cards.emplace_back(key, Suit::Hearts, value, Color::Red);
		cards.emplace_back(key, Suit::Diamonds, value, Color::Red);
		cards.emplace_back(key, Suit::Clubs, value, Color::Black);
		cards.emplace_back(key, Suit::Spades, value, Color::Black);
	}
}

void Deck::shuffle() {
}