#include "data.h"
#include "cards.h"
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
	std::string name = "None";
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
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (turn_history[i].round == turn_data.round && turn_history[i].asking_player_turn_order == turn_data.asking_player_turn_order)
		{
			turn_history.erase(turn_history.begin() + i);
			break;
		}
	}
	turn_history.push_back(turn_data);
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

void data::set_own_cards(const std::vector<std::string>& cards)
{
	own_cards = cards;
}

std::vector<std::string> data::get_own_cards()
{
	return own_cards;
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

	for (unsigned int i = 0; i < own_cards.size(); i++)
	{
		append_card(investigation_information, own_cards[i], 0);
	}

	eliminate_cards_based_on_turn_history(investigation_information);
	add_cards_based_on_turn_history(investigation_information);

	bool investigation_information_modified = false;

	do
	{
		investigation_information_modified = false;
		investigation_information_modified = investigation_information_modified || add_cards_based_on_deductions(investigation_information);
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

void data::eliminate_cards_based_on_turn_history(std::vector<player_cards>& card_data)
{
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (!turn_skipped(turn_history[i]))
		{
			if (turn_history[i].answering_player_turn_order != -1)
			{
				std::vector<int> players_between = get_players_between(turn_history[i].asking_player_turn_order, turn_history[i].answering_player_turn_order);
				for (unsigned int j = 0; j < players_between.size(); j++)
				{
					append_eliminated_card(card_data, turn_history[i].suspect, players_between[j]);
					append_eliminated_card(card_data, turn_history[i].room, players_between[j]);
					append_eliminated_card(card_data, turn_history[i].weapon, players_between[j]);
				}
			}
			else
			{
				for (int j = 0; j < number_of_players; j++)
				{
					if (j != turn_history[i].asking_player_turn_order)
					{
						append_eliminated_card(card_data, turn_history[i].suspect, j);
						append_eliminated_card(card_data, turn_history[i].room, j);
						append_eliminated_card(card_data, turn_history[i].weapon, j);
					}
				}
			}
		}
	}
}

void data::add_cards_based_on_turn_history(std::vector<player_cards>& card_data)
{
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (!turn_skipped(turn_history[i]) && turn_history[i].known_card != "None" && turn_history[i].answering_player_turn_order != -1)
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
					bool card_appended = append_eliminated_card(card_data, card_data[i].cards[j], card_data[k].turn_order);
					card_data_modified = card_data_modified || card_appended;
				}
			}
		}
	}

	return card_data_modified;
}

bool data::add_cards_based_on_deductions(std::vector<player_cards>& card_data)
{
	bool card_data_modified = false;
	for (unsigned int i = 0; i < turn_history.size(); i++)
	{
		if (!turn_skipped(turn_history[i]) && turn_history[i].answering_player_turn_order != -1)
		{
			bool suspect_state_determined = false;
			bool room_state_determined = false;
			bool weapon_state_determined = false;

			for (unsigned int j = 0; j < card_data.size(); j++)
			{
				if (!suspect_state_determined)
				{
					if (turn_history[i].answering_player_turn_order != card_data[j].turn_order)
					{
						suspect_state_determined = card_present(card_data[j].cards, turn_history[i].suspect);
					}
					else if (!suspect_state_determined && card_data[j].turn_order == turn_history[i].answering_player_turn_order)
					{
						suspect_state_determined = card_present(card_data[j].eliminated_cards, turn_history[i].suspect);
					}
				}

				if (!room_state_determined)
				{
					if (turn_history[i].answering_player_turn_order != card_data[j].turn_order)
					{
						room_state_determined = card_present(card_data[j].cards, turn_history[i].room);
					}
					else if (!room_state_determined && card_data[j].turn_order == turn_history[i].answering_player_turn_order)
					{
						room_state_determined = room_state_determined || card_present(card_data[j].eliminated_cards, turn_history[i].room);
					}
				}

				if (!weapon_state_determined)
				{
					if (turn_history[i].answering_player_turn_order != card_data[j].turn_order)
					{
						weapon_state_determined = card_present(card_data[j].cards, turn_history[i].weapon);
					}
					else if (!weapon_state_determined && card_data[j].turn_order == turn_history[i].answering_player_turn_order)
					{
						weapon_state_determined = weapon_state_determined || card_present(card_data[j].eliminated_cards, turn_history[i].weapon);
					}
				}
			}

			if (suspect_state_determined && room_state_determined && !weapon_state_determined)
			{
				bool weapon_appended = append_card(card_data, turn_history[i].weapon, turn_history[i].answering_player_turn_order);
				turn_history[i].known_card = turn_history[i].weapon;
				card_data_modified = card_data_modified || weapon_appended;
			}
			else if (suspect_state_determined && !room_state_determined && weapon_state_determined)
			{
				bool room_appended = append_card(card_data, turn_history[i].room, turn_history[i].answering_player_turn_order);
				turn_history[i].known_card = turn_history[i].room;
				card_data_modified = card_data_modified || room_appended;
			}
			else if (!suspect_state_determined && room_state_determined && weapon_state_determined)
			{
				bool suspect_appended = append_card(card_data, turn_history[i].suspect, turn_history[i].answering_player_turn_order);
				turn_history[i].known_card = turn_history[i].suspect;
				card_data_modified = card_data_modified || suspect_appended;
			}
		}
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

	nlohmann::json total_player_data;
	for (unsigned int i = 0; i < players.size(); i++)
	{
		nlohmann::json player_data;
		player_data["name"] = players[i].name;
		player_data["turn_order"] = players[i].turn_order;
		total_player_data.push_back(player_data);
	}

	game_data["own_cards"] = own_cards;

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

			players.clear();
			nlohmann::json player_data = game_data["players"];
			for (auto itr = player_data.begin(); itr != player_data.end(); ++itr)
			{
				player_name_turn_order_container player;
				player.name = (*itr)["name"];
				player.turn_order = (*itr)["turn_order"];
				players.push_back(player);
			}

			own_cards = game_data["own_cards"];

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

std::string data::generate_accusation_probability_report(const std::vector<player_cards>& investigation_information)
{
	std::string report = "";
	std::vector<std::string> known_suspects;
	std::vector<std::string> known_rooms;
	std::vector<std::string> known_weapons;

	for (unsigned int i = 0; i < investigation_information.size(); i++)
	{
		for (unsigned int j = 0; j < investigation_information[i].cards.size(); j++)
		{
			if (cards::is_suspect(investigation_information[i].cards[j]))
			{
				known_suspects.push_back(investigation_information[i].cards[j]);
			}
			else if (cards::is_room(investigation_information[i].cards[j]))
			{
				known_rooms.push_back(investigation_information[i].cards[j]);
			}
			else if (cards::is_weapon(investigation_information[i].cards[j]))
			{
				known_weapons.push_back(investigation_information[i].cards[j]);
			}
		}
	}

	unsigned int unknown_combinations = 0;

	if (one_of_each_murder_element)
	{
		unknown_combinations = (cards::suspects.size() - known_suspects.size()) * (cards::rooms.size() - known_rooms.size()) * (cards::weapons.size() - known_weapons.size());
	}
	else
	{
		unsigned int unknown_cards = (cards::suspects.size() - known_suspects.size()) + (cards::rooms.size() - known_rooms.size()) + (cards::weapons.size() - known_weapons.size());
		for (unsigned int i = 2; i < unknown_cards; i++)
		{
			unknown_combinations = unknown_combinations * i;
		}
	}

	float probability = 100.0f * (1.0f / (float)unknown_combinations);

	report = "Possible Combinations:\nProbability of Being Correct: " + std::to_string(probability) + "%\n";

	if (one_of_each_murder_element)
	{
		report = report + "Form (Suspect, Room, Weapon)\n";
		for (unsigned int i = 0; i < cards::suspects.size(); i++)
		{
			for (unsigned int j = 0; j < cards::rooms.size(); j++)
			{
				for (unsigned int k = 0; k < cards::weapons.size(); k++)
				{
					if (!card_present(known_suspects, cards::suspects[i]) && !card_present(known_rooms, cards::rooms[j]) && !card_present(known_weapons, cards::weapons[k]))
					{
						report = report + "(" + cards::suspects[i] + ", " + cards::rooms[j] + ", " + cards::weapons[k] + ")\n";
					}
				}
			}
		}
	}
	else
	{
		std::vector<std::string> all_cards;
		all_cards.insert(all_cards.end(), cards::suspects.begin(), cards::suspects.end());
		all_cards.insert(all_cards.end(), cards::rooms.begin(), cards::rooms.end());
		all_cards.insert(all_cards.end(), cards::weapons.begin(), cards::weapons.end());

		std::vector<std::string> all_known_cards;
		all_known_cards.insert(all_known_cards.end(), known_suspects.begin(), known_suspects.end());
		all_known_cards.insert(all_known_cards.end(), known_rooms.begin(), known_rooms.end());
		all_known_cards.insert(all_known_cards.end(), known_weapons.begin(), known_weapons.end());

		for (unsigned int i = 0; i < all_cards.size() - 2; i++)
		{
			for (unsigned int j = i + 1; j < all_cards.size() - 1; j++)
			{
				for (unsigned int k = j + 1; k < all_cards.size(); k++)
				{
					if (!card_present(all_known_cards, all_cards[i]) && !card_present(all_known_cards, all_cards[j]) && !card_present(all_known_cards, all_cards[k]))
					{
						report = report + "(" + all_cards[i] + ", " + all_cards[j] + ", " + all_cards[k] + ")\n";
					}
				}
			}
		}
	}

	return report;
}

std::string data::generate_investigation_report(const std::vector<player_cards>& investigation_information)
{
	std::vector<card_rating> suspect_ratings = rate_cards(cards::suspects, investigation_information);
	std::vector<card_rating> room_ratings = rate_cards(cards::rooms, investigation_information);
	std::vector<card_rating> weapon_ratings = rate_cards(cards::weapons, investigation_information);

	std::vector<std::string> known_cards;
	for (unsigned int i = 0; i < investigation_information.size(); i++)
	{
		known_cards.insert(known_cards.end(), investigation_information[i].cards.begin(), investigation_information[i].cards.end());
	}

	struct set_rating
	{
		std::string suspect = "";
		std::string room = "";
		std::string weapon = "";
		bool target_suspect = false;
		bool target_room = false;
		bool target_weapon = false;
		int rating = 0;
	};

	struct set_rating_sorting_functor
	{
		bool operator()(const set_rating& rating_1, const set_rating& rating_2)
		{
			return rating_1.rating > rating_2.rating;
		}
	};

	std::vector<set_rating> sets;

	player_cards own_cards;

	for (unsigned int i = 0; i < investigation_information.size(); i++)
	{
		if (investigation_information[i].turn_order == 0)
		{
			own_cards = investigation_information[i];
			break;
		}
	}

	bool suspect_known = card_of_type_known(investigation_information, (int)cards::suspects.size(), &cards::is_suspect);
	bool room_known = card_of_type_known(investigation_information, (int)cards::rooms.size(), &cards::is_room);
	bool weapon_known = card_of_type_known(investigation_information, (int)cards::weapons.size(), &cards::is_weapon);

	for (unsigned int i = 0; i < suspect_ratings.size(); i++)
	{
		for (unsigned int j = 0; j < room_ratings.size(); j++)
		{
			for (unsigned int k = 0; k < weapon_ratings.size(); k++)
			{
				int number_of_known_cards_in_set = 0;
				set_rating new_rating;
				if (suspect_known || card_present(known_cards, suspect_ratings[i].card))
				{
					number_of_known_cards_in_set++;
				}
				else
				{
					new_rating.target_suspect = true;
				}

				if (room_known || card_present(known_cards, room_ratings[j].card))
				{
					number_of_known_cards_in_set++;
				}
				else
				{
					new_rating.target_room = true;
				}

				if (weapon_known || card_present(known_cards, weapon_ratings[k].card))
				{
					number_of_known_cards_in_set++;
				}
				else
				{
					new_rating.target_weapon = true;
				}

				if (number_of_known_cards_in_set != 3)
				{
					new_rating.suspect = suspect_ratings[i].card;
					new_rating.room = room_ratings[j].card;
					new_rating.weapon = weapon_ratings[k].card;
					new_rating.rating = suspect_ratings[i].rating + room_ratings[j].rating + weapon_ratings[k].rating;
					sets.push_back(new_rating);
				}
			}
		}
	}

	std::sort(sets.begin(), sets.end(), set_rating_sorting_functor());

	std::string report = "Best Cards to Ask\nForm (Suspect, Room, Weapon) - Rating - Targeted Cards: ()\n";

	for (unsigned int i = 0; i < sets.size(); i++)
	{
		report = report + "(" + sets[i].suspect + ", " + sets[i].room + ", " + sets[i].weapon + ") - " + std::to_string(sets[i].rating) + " - Targeted Cards: (";
		bool first_card = true;
		if (sets[i].target_suspect)
		{
			report = report + sets[i].suspect;
			first_card = false;
		}

		if (sets[i].target_room)
		{
			if (!first_card)
			{
				report = report + ", ";
			}

			report = report + sets[i].room;
			first_card = false;
		}

		if (sets[i].target_weapon)
		{
			if (!first_card)
			{
				report = report + ", ";
			}

			report = report + sets[i].weapon;
		}

		report = report + ")\n";
	}

	return report;
}

bool data::turn_skipped(const turn& turn_data)
{
	bool skipped = false;
	if (turn_data.suspect == "None" || turn_data.room == "None" || turn_data.weapon == "None" || (turn_data.asking_player_turn_order == 0 && turn_data.known_card == "None" && turn_data.answering_player_turn_order != -1))
	{
		skipped = true;
	}

	return skipped;
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

	if (!game_data.contains("players") || !game_data["players"].is_array())
	{
		return false;
	}

	if (!game_data.contains("own_cards") || !game_data["own_cards"].is_array())
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
	}

	return true;
}

std::vector<data::card_rating> data::rate_cards(const std::vector<std::string>& cards_to_rate, const std::vector<player_cards>& investigation_information)
{
	std::vector<card_rating> rated_cards;
	for (unsigned int i = 0; i < cards_to_rate.size(); i++)
	{
		card_rating new_rating;
		new_rating.card = cards_to_rate[i];
		new_rating.rating = 0;
		for (unsigned int j = 0; j < investigation_information.size(); j++)
		{
			bool card_found = false;
			for (unsigned int k = 0; k < investigation_information[j].cards.size(); k++)
			{
				if (cards_to_rate[i] == investigation_information[j].cards[k])
				{
					if (investigation_information[j].turn_order != 0)
					{
						new_rating.rating = investigation_information[j].turn_order;
					}
					else
					{
						new_rating.rating = number_of_players;
					}

					card_found = true;
					break;
				}
			}

			if (card_found)
			{
				break;
			}
			else if (no_one_has_card(investigation_information, cards_to_rate[i]))
			{
				new_rating.rating = number_of_players;
			}
		}

		rated_cards.push_back(new_rating);
	}

	return rated_cards;
}

bool data::card_of_type_known(const std::vector<player_cards>& investigation_information, int number_of_cards_in_type, bool (*is_card_type)(const std::string& card))
{
	bool known = false;
	if (one_of_each_murder_element && investigation_information.size() > 0)
	{
		for (unsigned int i = 0; i < investigation_information[0].eliminated_cards.size(); i++)
		{
			if (is_card_type(investigation_information[0].eliminated_cards[i]))
			{
				known = no_one_has_card(investigation_information, investigation_information[0].eliminated_cards[i]);

				if (known)
				{
					break;
				}
			}
		}

		if (!known)
		{
			int known_cards_count = 0;

			for (unsigned int i = 0; i < investigation_information.size(); i++)
			{
				for (unsigned int j = 0; j < investigation_information[i].cards.size(); j++)
				{
					if (is_card_type(investigation_information[i].cards[j]))
					{
						known_cards_count++;
					}
				}
			}

			if (known_cards_count == number_of_cards_in_type - 1)
			{
				known = true;
			}
		}
	}

	return known;
}

bool data::no_one_has_card(const std::vector<player_cards>& investigation_information, const std::string& card)
{
	bool known = false;
	for (unsigned int i = 0; i < investigation_information.size(); i++)
	{
		known = false;
		for (unsigned int j = 0; j < investigation_information[i].eliminated_cards.size(); j++)
		{
			if (card == investigation_information[i].eliminated_cards[j])
			{
				known = true;
				break;
			}
		}

		if (!known)
		{
			break;
		}
	}

	return known;
}