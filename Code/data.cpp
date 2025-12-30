#include "data.h"
#include <ascii_engine/file_manager.h>
#include <ascii_engine/error_codes.h>

void data::set_number_of_players(int number)
{
	players.clear();
	number_of_players = number;

	for (int i = 0; i < number_of_players; i++)
	{
		player_name_turn_order_container new_player;
		new_player.turn_order = i;
		players.push_back(new_player);
	}
}

int data::get_number_of_players()
{
	return number_of_players;
}

void data::set_player_name(const std::string& name, int turn_order)
{
	for (unsigned int i = 0; i < players.size(); i++)
	{
		if (players[i].turn_order == turn_order)
		{
			players[i].name = name;
			break;
		}
	}
}

std::string data::get_player_name(int turn_order)
{
	std::string name = "";
	for (unsigned int i = 0; i < players.size(); i++)
	{
		if (players[i].turn_order == turn_order)
		{
			name = players[i].name;
			break;
		}
	}

	return name;
}

void data::set_player_out(bool out, int turn_order)
{
	for (unsigned int i = 0; i < players.size(); i++)
	{
		if (players[i].turn_order == turn_order)
		{
			players[i].out = out;
			break;
		}
	}
}

bool data::get_player_out(int turn_order)
{
	bool out = true;
	for (unsigned int i = 0; i < players.size(); i++)
	{
		if (players[i].turn_order == turn_order)
		{
			out = players[i].out;
			break;
		}
	}

	return out;
}

int data::get_player_turn_order(const std::string& name)
{
	int turn_order = -1;
	for (unsigned int i = 0; i < players.size(); i++)
	{
		if (players[i].name == name)
		{
			turn_order = players[i].turn_order;
			break;
		}
	}

	return turn_order;
}

void data::record_turn(turn turn_data)
{
	turn_history.push_back(turn_data);
}

void data::reset_suspect(int round, int asking_player_turn_order, const std::string& suspect)
{
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].round == round && turn_history[i].asking_player_turn_order == asking_player_turn_order)
		{
			turn_history[i].suspect = suspect;
			break;
		}
	}
}

void data::reset_room(int round, int asking_player_turn_order, const std::string& room)
{
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].round == round && turn_history[i].asking_player_turn_order == asking_player_turn_order)
		{
			turn_history[i].room = room;
			break;
		}
	}
}

void data::reset_weapon(int round, int asking_player_turn_order, const std::string& weapon)
{
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].round == round && turn_history[i].asking_player_turn_order == asking_player_turn_order)
		{
			turn_history[i].weapon = weapon;
			break;
		}
	}
}

void data::reset_known_card(int round, int asking_player_turn_order, const std::string& known_card)
{
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].round == round && turn_history[i].asking_player_turn_order == asking_player_turn_order)
		{
			turn_history[i].known_card = known_card;
			break;
		}
	}
}

void data::reset_answering_player_turn_order(int round, int asking_player_turn_order, int answering_player_turn_order)
{
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].round == round && turn_history[i].asking_player_turn_order == asking_player_turn_order)
		{
			turn_history[i].answering_player_turn_order = answering_player_turn_order;
			break;
		}
	}
}

bool data::turn_recorded(int round, int asking_player_turn_order)
{
	bool recorded = false;
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].round == round && turn_history[i].asking_player_turn_order == asking_player_turn_order)
		{
			recorded = true;
			break;
		}
	}

	return recorded;
}

data::turn data::get_turn(int round, int asking_player_turn_order)
{
	turn player_turn;
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].round == round && turn_history[i].asking_player_turn_order == asking_player_turn_order)
		{
			player_turn = turn_history[i];
			break;
		}
	}

	return player_turn;
}

std::string data::get_suspect(int round, int asking_player_turn_order)
{
	std::string suspect = "";
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].round == round && turn_history[i].asking_player_turn_order == asking_player_turn_order)
		{
			suspect = turn_history[i].suspect;
			break;
		}
	}

	return suspect;
}

std::string data::get_room(int round, int asking_player_turn_order)
{
	std::string room = "";
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].round == round && turn_history[i].asking_player_turn_order == asking_player_turn_order)
		{
			room = turn_history[i].room;
			break;
		}
	}

	return room;
}

std::string data::get_weapon(int round, int asking_player_turn_order)
{
	std::string weapon = "";
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].round == round && turn_history[i].asking_player_turn_order == asking_player_turn_order)
		{
			weapon = turn_history[i].weapon;
			break;
		}
	}

	return weapon;
}

std::string data::get_known_card(int round, int asking_player_turn_order)
{
	std::string known_card = "";
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].round == round && turn_history[i].asking_player_turn_order == asking_player_turn_order)
		{
			known_card = turn_history[i].known_card;
			break;
		}
	}

	return known_card;
}

int data::get_answering_player_turn_order(int round, int asking_player_turn_order)
{
	int answering_player_turn_order = -1;
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].round == round && turn_history[i].asking_player_turn_order == asking_player_turn_order)
		{
			answering_player_turn_order = turn_history[i].answering_player_turn_order;
			break;
		}
	}

	return answering_player_turn_order;
}

void data::set_one_of_each_murder_element(bool one_of_each)
{
	one_of_each_murder_element = one_of_each;
}

bool data::get_one_of_each_murder_element()
{
	return one_of_each_murder_element;
}

void data::set_game_name(const std::string& name)
{
	game_name = name;
}

std::string data::get_game_name()
{
	return game_name;
}

std::vector<data::player_cards> data::investigate()
{
	std::vector<player_cards> investigation_information;

	for (unsigned int i = 0; i < players.size(); i++)
	{
		player_cards cards_data;
		cards_data.name = players[i].name;
		cards_data.turn_order = players[i].turn_order;
		investigation_information.push_back(cards_data);
	}

	eliminate_cards_based_on_turn_history(investigation_information);
	add_cards_based_on_turn_history(investigation_information);

	bool investigation_information_modified = false;

	do
	{
		investigation_information_modified = false;
		investigation_information_modified = investigation_information_modified || add_cards_based_on_cards(investigation_information);
		investigation_information_modified = investigation_information_modified || add_cards_based_on_eliminated_cards(investigation_information);
		investigation_information_modified = investigation_information_modified || eliminate_cards_based_on_cards(investigation_information);
	} while (investigation_information_modified);

	return investigation_information;
}

bool data::append_card(std::vector<player_cards>& cards_data, const std::string& card, int turn_order)
{
	bool card_appended = false;
	for (unsigned int i = 0; i < cards_data.size(); i++)
	{
		if (cards_data[i].turn_order == turn_order && !card_present(cards_data[i].cards, card))
		{
			cards_data[i].cards.push_back(card);
			card_appended = true;
			break;
		}
	}

	return card_appended;
}

bool data::append_eliminated_card(std::vector<player_cards>& cards_data, const std::string& card, int turn_order)
{
	bool card_appended = false;
	for (unsigned int i = 0; i < cards_data.size(); i++)
	{
		if (cards_data[i].turn_order == turn_order && !card_present(cards_data[i].eliminated_cards, card))
		{
			cards_data[i].eliminated_cards.push_back(card);
			card_appended = true;
			break;
		}
	}

	return card_appended;
}

std::vector<int> data::get_players_between(int asking_player_turn_order, int answering_player_turn_order)
{
	int turn = asking_player_turn_order;
	std::vector<int> players_between;
	while (true)
	{
		if ((turn + 1) < (int)number_of_players)
		{
			turn = turn + 1;
		}
		else
		{
			turn = 0;
		}

		if (turn == answering_player_turn_order)
		{
			break;
		}

		players_between.push_back(turn);
	}

	return players_between;
}

bool data::card_present(const std::vector<std::string>& cards, const std::string& card)
{
	bool present = false;
	for (unsigned int i = 0; i < cards.size(); i++)
	{
		if (cards[i] == card)
		{
			present = true;
			break;
		}
	}

	return present;
}

bool data::card_present(const std::vector<player_cards>& card_data, const std::string& card, int turn_order, bool eliminated)
{
	bool present = false;
	for (unsigned int i = 0; i < card_data.size(); i++)
	{
		if (card_data[i].turn_order == turn_order)
		{
			if (eliminated)
			{
				present = card_present(card_data[i].cards, card);
			}
			else
			{
				present = card_present(card_data[i].eliminated_cards, card);
			}

			break;
		}
	}

	return present;
}

void data::eliminate_cards_based_on_turn_history(std::vector<player_cards>& card_data)
{
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		std::vector<int> players_between = get_players_between(turn_history[i].asking_player_turn_order, turn_history[i].answering_player_turn_order);
		for (unsigned int j = 0; j < players_between.size(); j++)
		{
			append_eliminated_card(card_data, turn_history[i].suspect, players_between[j]);
			append_eliminated_card(card_data, turn_history[i].room, players_between[j]);
			append_eliminated_card(card_data, turn_history[i].weapon, players_between[j]);
		}
	}
}

void data::add_cards_based_on_turn_history(std::vector<player_cards>& card_data)
{
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].known_card != "")
		{
			append_card(card_data, turn_history[i].known_card, turn_history[i].answering_player_turn_order);
		}
	}
}

bool data::eliminate_cards_based_on_cards(std::vector<player_cards>& card_data)
{
	bool card_data_modified = false;
	for (unsigned int i = 0; i < card_data.size(); i++)
	{
		for (unsigned int j = 0; j < card_data[i].cards.size(); j++)
		{
			for (unsigned int k = 0; k < card_data.size(); k++)
			{
				if (k != i)
				{
					bool card_appended = append_eliminated_card(card_data, card_data[i].cards[j],card_data[k].turn_order);
					card_data_modified = card_data_modified || card_appended;
				}
			}
		}
	}

	return card_data_modified;
}

bool data::add_cards_based_on_cards(std::vector<player_cards>& card_data)
{
	bool card_data_modified = false;
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		bool suspect_state_determined = false;
		bool room_state_determined = false;
		bool weapon_state_determined = false;

		if (one_of_each_murder_element && guilty_suspect != "")
		{
			suspect_state_determined = true;
		}

		if (one_of_each_murder_element && murder_room != "")
		{
			room_state_determined = true;
		}

		if (one_of_each_murder_element && murder_weapon != "")
		{
			weapon_state_determined = true;
		}

		for (unsigned int j = 0; j < card_data.size(); j++)
		{
			if (turn_history[i].answering_player_turn_order != card_data[j].turn_order)
			{
				if (!suspect_state_determined)
				{
					suspect_state_determined = card_present(card_data[j].cards, turn_history[i].suspect);
				}

				if (!room_state_determined)
				{
					room_state_determined = card_present(card_data[j].cards, turn_history[i].room);
				}

				if (!weapon_state_determined)
				{
					weapon_state_determined = card_present(card_data[j].cards, turn_history[i].weapon);
				}
			}
		}

		if (suspect_state_determined && room_state_determined && !weapon_state_determined)
		{
			bool weapon_appended = append_card(card_data, turn_history[i].weapon, turn_history[i].answering_player_turn_order);
			card_data_modified = card_data_modified || weapon_appended;
		}
		else if (suspect_state_determined && !room_state_determined && weapon_state_determined)
		{
			bool room_appended = append_card(card_data, turn_history[i].room, turn_history[i].answering_player_turn_order);
			card_data_modified = card_data_modified || room_appended;
		}
		else if (!suspect_state_determined && room_state_determined && weapon_state_determined)
		{
			bool weapon_appended = append_card(card_data, turn_history[i].suspect, turn_history[i].answering_player_turn_order);
			card_data_modified = card_data_modified || weapon_appended;
		}
	}

	return card_data_modified;
}

bool data::add_cards_based_on_eliminated_cards(std::vector<player_cards>& card_data)
{
	bool card_data_modified = false;
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		int possible_cards_provided = 3;
		std::string remaining_card = "";
		if (card_present(card_data, turn_history[i].suspect, turn_history[i].answering_player_turn_order, true))
		{
			possible_cards_provided--;
		}
		else
		{
			remaining_card = turn_history[i].suspect;
		}

		if (card_present(card_data, turn_history[i].room, turn_history[i].answering_player_turn_order, true))
		{
			possible_cards_provided--;
		}
		else
		{
			remaining_card = turn_history[i].room;
		}

		if (card_present(card_data, turn_history[i].weapon, turn_history[i].answering_player_turn_order, true))
		{
			possible_cards_provided--;
		}
		else
		{
			remaining_card = turn_history[i].weapon;
		}

		bool card_appended = false;
		if (possible_cards_provided == 1)
		{
			card_appended = append_card(card_data, remaining_card, turn_history[i].answering_player_turn_order);
		}

		card_data_modified = card_data_modified || card_appended;
	}

	return card_data_modified;
}

int data::save(const std::string& path)
{
	nlohmann::json game_data;

	game_data["game_name"] = game_name;
	game_data["number_of_players"] = number_of_players;
	game_data["one_of_each_murder_element"] = one_of_each_murder_element;

	nlohmann::json total_turn_data;
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		nlohmann::json turn_data;
		turn_data["round"] = turn_history[i].round;
		turn_data["asking_player_turn_order"] = turn_history[i].asking_player_turn_order;
		turn_data["suspect"] = turn_history[i].suspect;
		turn_data["room"] = turn_history[i].room;
		turn_data["weapon"] = turn_history[i].weapon;
		turn_data["answering_player_turn_order"] = turn_history[i].answering_player_turn_order;
		turn_data["known_card"] = turn_history[i].known_card;
		total_turn_data.push_back(turn_data);
	}

	game_data["turn_history"] = total_turn_data;
	game_data["guilty_suspect"] = guilty_suspect;
	game_data["murder_room"] = murder_room;
	game_data["murder_weapon"] = murder_weapon;

	nlohmann::json total_player_data;
	for (unsigned int i = 0; i < players.size(); i++)
	{
		nlohmann::json player_data;
		player_data["name"] = players[i].name;
		player_data["turn_order"] = players[i].turn_order;
		player_data["out"] = players[i].out;
		total_player_data.push_back(player_data);
	}

	game_data["players"] = total_player_data;

	int status = file_manager::write_file(path, game_data.dump(3));
	return status;
}

int data::load(const std::string& path)
{
	std::string content = "";
	int load_status = file_manager::read_file(path, content);
	int status = UNDEFINED;

	if (load_status == 0)
	{
		nlohmann::json game_data = nlohmann::json::parse(content, nullptr, false);

		if (loaded_data_valid(game_data))
		{
			game_name = game_data["game_name"];
			number_of_players = game_data["number_of_players"];
			one_of_each_murder_element = game_data["one_of_each_murder_element"];

			turn_history.clear();
			nlohmann::json turn_history_data = game_data["turn_history"];
			for (auto itr = turn_history_data.begin(); itr != turn_history_data.end(); ++itr)
			{
				turn turn_data;
				turn_data.round = (*itr)["round"];
				turn_data.asking_player_turn_order = (*itr)["asking_player_turn_order"];
				turn_data.suspect = (*itr)["suspect"];
				turn_data.room = (*itr)["room"];
				turn_data.weapon = (*itr)["weapon"];
				turn_data.answering_player_turn_order = (*itr)["answering_player_turn_order"];
				turn_data.known_card = (*itr)["known_card"];
				turn_history.push_back(turn_data);
			}

			guilty_suspect = game_data["guilty_suspect"];
			murder_room = game_data["murder_room"];
			murder_weapon = game_data["murder_weapon"];

			players.clear();
			nlohmann::json player_data = game_data["players"];
			for (auto itr = player_data.begin(); itr != player_data.end(); ++itr)
			{
				player_name_turn_order_container player;
				player.name = (*itr)["name"];
				player.turn_order = (*itr)["turn_order"];
				player.out = (*itr)["out"];
				players.push_back(player);
			}

			status = SUCCESS;
		}
		else
		{
			status = INVALID_CONFIG;
		}
	}
	else
	{
		status = INVALID_PATH;
	}

	return status;
}

bool data::loaded_data_valid(const nlohmann::json& game_data)
{
	if (game_data.is_discarded())
	{
		return false;
	}

	if (!game_data.contains("game_name") || !game_data["game_name"].is_string())
	{
		return false;
	}

	if (!game_data.contains("number_of_players") || !game_data["number_of_players"].is_number_integer())
	{
		return false;
	}

	if (!game_data.contains("one_of_each_murder_element") || !game_data["one_of_each_murder_element"].is_boolean())
	{
		return false;
	}

	if (!game_data.contains("turn_history") || !game_data["turn_history"].is_array())
	{
		return false;
	}

	if (!game_data.contains("guilty_suspect") || !game_data["guilty_suspect"].is_string())
	{
		return false;
	}

	if (!game_data.contains("murder_room") || !game_data["murder_room"].is_string())
	{
		return false;
	}

	if (!game_data.contains("murder_weapon") || !game_data["murder_weapon"].is_string())
	{
		return false;
	}

	if (!game_data.contains("players") || !game_data["players"].is_array())
	{
		return false;
	}

	nlohmann::json turn_history_data = game_data["turn_history"];

	for (auto itr = turn_history_data.begin(); itr != turn_history_data.end(); ++itr)
	{
		if (!(*itr).contains("round") || !(*itr)["round"].is_number_integer())
		{
			return false;
		}

		if (!(*itr).contains("asking_player_turn_order") || !(*itr)["asking_player_turn_order"].is_number_integer())
		{
			return false;
		}

		if (!(*itr).contains("suspect") || !(*itr)["suspect"].is_string())
		{
			return false;
		}

		if (!(*itr).contains("room") || !(*itr)["room"].is_string())
		{
			return false;
		}

		if (!(*itr).contains("weapon") || !(*itr)["weapon"].is_string())
		{
			return false;
		}

		if (!(*itr).contains("answering_player_turn_order") || !(*itr)["answering_player_turn_order"].is_number_integer())
		{
			return false;
		}

		if (!(*itr).contains("known_card") || !(*itr)["known_card"].is_string())
		{
			return false;
		}
	}

	nlohmann::json player_data = game_data["players"];

	for (auto itr = player_data.begin(); itr != player_data.end(); ++itr)
	{
		if (!(*itr).contains("name") || !(*itr)["name"].is_string())
		{
			return false;
		}

		if (!(*itr).contains("turn_order") || !(*itr)["turn_order"].is_number_integer())
		{
			return false;
		}

		if (!(*itr).contains("out") || !(*itr)["out"].is_boolean())
		{
			return false;
		}
	}

	return true;
}

int data::get_current_round()
{
	int round = 0;
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].round > round)
		{
			round = turn_history[i].round;
		}
	}

	int number_of_turns_in_round = 0;
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].round == round)
		{
			number_of_turns_in_round++;
		}
	}

	if (number_of_turns_in_round == number_of_players)
	{
		round++;
	}

	return round;
}

int data::get_current_turn()
{
	int current_turn = 0;
	int round = get_current_round();

	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].round == round && turn_history[i].asking_player_turn_order > current_turn)
		{
			current_turn = turn_history[i].asking_player_turn_order;
		}
	}

	if (current_turn + 1 < number_of_players)
	{
		current_turn = current_turn + 1;
	}
	else
	{
		current_turn = 0;
	}

	return current_turn;
}