#include <map>
#include <string>
#include <iomanip>
#include "card.h"

Card::Card(std::string_view name, Suit su, int val, Color co)
	:n{ name },
	s{ su },
	v{ val },
	c{ co } {
}

std::string_view Card::suit() const {
	switch (s)
	{
	case Suit::Hearts:
		return "Hearts";
	case Suit::Diamonds:
		return "Diamonds";
	case Suit::Clubs:
		return "Clubs";
	case Suit::Spades:
		return "Spades";
		break;
	}
	throw std::runtime_error{ "oops, something went wrong..." };
}

std::string_view Card::color() const {
	switch (c)
	{
	case Color::Red:
		return "Red";
	case Color::Black:
		return "Black";
	default:
		break;
	}
	throw std::runtime_error{ "oops, something went wrong..." };
}

Deck::Deck() {
	static std::map<std::string, int> m{
		{"ACE",1}, {"TWO",2},{"THREE",3},{"FOUR",4}
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

std::ostream& operator<<(std::ostream& os, const Card& c) {
	return os << "|" << std::setw(5) << c.n << "| " << std::setw(8) << c.suit()
		<< "|" << std::setw(2) << c.v << "|" << std::setw(5) << c.color()
		<< "|\n";
}