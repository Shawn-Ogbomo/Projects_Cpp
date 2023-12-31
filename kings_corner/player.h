#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player {
	static constexpr int max_age = 120;
	static constexpr char male = 'M';
	static constexpr char female = 'F';
public:
	Player();
	explicit Player(const std::string& name, char gender, int age);
	friend std::istream& operator >> (std::istream& is, Player& p);
	friend std::ostream& operator <<(std::ostream& os, const Player& p);
private:
	std::string n;
	char g{};
	int a{};
};
#endif // PLAYER_H