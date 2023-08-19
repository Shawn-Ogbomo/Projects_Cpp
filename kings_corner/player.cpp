#include <iostream>
#include "player.hpp"
#include "util.hpp"

Player::Player() = default;

Player::Player(const std::string& name, char gender, int age)
	:n{ name },
	g{ static_cast<char>(toupper(gender)) },
	a{ age } {
	Util::format_string(n);

	if (const auto first_character = name.front(); name.empty() || first_character == '_'
		|| isdigit(first_character)
		|| isspace(first_character)
		|| Util::found_duplicates(n, ' ')
		|| g != male && g != female
		|| !a
		|| a < 0
		|| a > max_age) {
		throw std::runtime_error{ "Invalid Player credentials..." };
	}
}

std::vector<Card>& Player::hand() {
	return h;
}

std::istream& operator>>(std::istream& is, Player& p) {
	std::string name;
	int age;
	char gender{};

	is >> name >> gender >> age;

	if (!is) {
		is.clear(std::ios::failbit);
		return is;
	}

	Player temp{ name,gender,age };

	p = temp;

	return is;
}