#include <iostream>
#include <algorithm>
#include "util.h"
#include "exceptions.h"

void Util::format_string(std::string& target_string) {
	if (!target_string.empty()) {
		target_string[0] = toupper(target_string[0]);
		std::transform(target_string.cbegin() + 1, target_string.cend(), target_string.begin() + 1
			, [](unsigned char letter) {return std::tolower(letter); });
	}
}

void Util::skip_input(std::istream& is, char terminator) {
	const std::string pattern = "+-*/=;()$%^#~"
		"IVXLCDM"
		"cex";

	for (char ch{}; is.get(ch);) {
		if (ch == terminator || ch == '\n' || pattern.find(ch) != std::string::npos) {
			is.unget();
			return;
		}
	}
}

void Util::check_stream(std::istream& is, const std::string& message, const std::string& message2) {
	if (is.eof() || std::cin.eof()) {
		throw Terminate{ message + message2 };
	}

	if (is.fail()) {
		is.clear();
		throw std::runtime_error{ message };
	}
}

bool Util::found_duplicates(std::string_view target_string, char c) {
	const int num_items = std::count(target_string.begin(), target_string.end(), c);
	return num_items > 1;
}