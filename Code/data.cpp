#include "data.h"
#include <ascii_engine/file_manager.h>

void data::set_number_of_players(unsigned int number)
{
	players.clear();
	number_of_players = number;

	for (unsigned int i = 0; i < number_of_players; i++)
	{
		player_name_turn_order_container new_player;
		new_player.turn_order = i;
		players.push_back(new_player);
	}
}

unsigned int data::get_number_of_players()
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

void data::record_turn(int round, int asking_player_turn_order, const std::string& suspect, const std::string& room, const std::string& weapon, int answering_player_turn_order)
{
	turn player_turn;
	player_turn.round = round;
	player_turn.asking_player_turn_order = asking_player_turn_order;
	player_turn.suspect = suspect;
	player_turn.room = room;
	player_turn.weapon = weapon;
	player_turn.answering_player_turn_order = answering_player_turn_order;
	turn_history.push_back(player_turn);
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
				bool card_appended = append_card(card_data, card_data[i].cards[j],card_data[k].turn_order);
				card_data_modified = card_data_modified || card_appended;
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