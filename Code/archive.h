#pragma once

#include <string>
#include "data.h"

namespace archive
{
	const std::string save_directory = "saved_games/";
	int save_game(const std::string& game_name, data& database);
	int load_game(const std::string& game_name, data& database);
	int delete_game(const std::string& game_name);
	std::vector<std::string> get_saved_game_names();
	bool duplicate_name(const std::string& name);
};