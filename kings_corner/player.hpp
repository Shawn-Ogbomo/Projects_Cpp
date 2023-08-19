#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "card.hpp"

class Player {
	static constexpr int max_age = 120;
	static constexpr char male = 'M';
	static constexpr char female = 'F';
public:
	Player();
	explicit Player(const std::string& name, char gender, int age);
	friend std::istream& operator >> (std::istream& is, Player& p);
	std::vector<Card>& hand();
private:
	std::string n;
	char g{};
	int a{};
	std::vector<Card> h;
};
#endif // PLAYER_HPP