#ifndef CARD_HPP
#define CARD_HPP

#include <vector>
#include <iostream>

class Player;
enum class Suit {
	Hearts = 1, Diamonds, Clubs, Spades
};

enum class Color {
	Red = 1, Black
};

class Card {
public:
	explicit Card(std::string_view name, Suit su, int val, Color co);
	friend std::ostream& operator << (std::ostream& os, const Card& c);
	std::string_view suit()const;
	std::string_view color()const;
private:
	std::string n;
	Suit s{};
	int v{};
	Color c{};
};

class Deck {
public:
	Deck();
	friend std::ostream& operator<<(std::ostream& os, const Deck& d);
	void draw(Player& p);
private:
	void shuffle();
	std::vector<Card> cards;
};
#endif // CARD_HPP