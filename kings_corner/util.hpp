#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>
#include <string_view>

namespace Util {
	void format_string(std::string& target_string);

	//CHECKS STREAM STATE
	void check_stream(std::istream& is, const std::string& message, const std::string& message2 = "");

	bool found_duplicates(std::string_view target_string, char c);

	//GENERATES AN ARBITARY INTEGER IN THE RANGE X-Y INCLUSISIVE
	int generate_random_number(int x, int y);
}
#endif // UTIL_HPP