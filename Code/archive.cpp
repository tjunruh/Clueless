#include "archive.h"
#include <filesystem>
#include <ascii_engine/file_manager.h>
#include <ascii_engine/error_codes.h>

int archive::save_game(const std::string& game_name, data& database)
{
	if (!std::filesystem::exists(save_directory))
	{
		std::filesystem::create_directory(save_directory);
	}

	int status = database.save(save_directory + game_name);

	return status;
}

int archive::load_game(const std::string& game_name, data& database)
{
	if (!std::filesystem::exists(save_directory))
	{
		std::filesystem::create_directory(save_directory);
	}

	int status = database.load(save_directory + game_name);

	return status;
}

int archive::delete_game(const std::string& game_name)
{
	if (!std::filesystem::exists(save_directory))
	{
		std::filesystem::create_directory(save_directory);
	}

	return file_manager::delete_file(save_directory + game_name);
}

std::vector<std::string> archive::get_saved_game_names()
{
	std::vector<std::string> game_names;

	if (!std::filesystem::exists(save_directory))
	{
		std::filesystem::create_directory(save_directory);
	}

	for (const auto& entry : std::filesystem::directory_iterator(save_directory))
	{
		game_names.push_back(file_manager::extract_file(entry.path().string()));
	}

	for (int i = (game_names.size() - 1); i >= 0; i--)
	{
		if ((game_names[i] == ".") || (game_names[i] == ".."))
		{
			game_names.erase(game_names.begin() + i);
		}
	}

	return game_names;
}

bool archive::duplicate_name(const std::string& game_name)
{
	bool duplicate = false;
	std::vector<std::string> saved_game_names = get_saved_game_names();
	for (unsigned int i = 0; i < saved_game_names.size(); i++)
	{
		if (saved_game_names[i] == game_name)
		{
			duplicate = true;
			break;
		}
	}

	return duplicate;
}