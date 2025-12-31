#pragma once

#include <string>
#include <vector>
#include "../external_libraries/json.hpp"

class data
{
public:
	struct turn
	{
		int round = -1;
		int asking_player_turn_order = -1;
		std::string suspect = "";
		std::string room = "";
		std::string weapon = "";
		int answering_player_turn_order = -1;
		std::string known_card = "";
	};

	struct player_cards
	{
		std::string name = "";
		int turn_order = -1;
		std::vector<std::string> cards;
		std::vector<std::string> eliminated_cards;
	};

	void set_number_of_players(int number);
	int get_number_of_players();
	void set_player_name(const std::string& name, int turn_order);
	std::string get_player_name(int turn_order);
	int get_player_turn_order(const std::string& name);
	void set_player_out(bool out, int turn_order);
	bool get_player_out(int turn_order);
	void record_turn(turn turn_data);
	void reset_suspect(int round, int asking_player_turn_order, const std::string& suspect);
	void reset_room(int round, int asking_player_turn_order, const std::string& room);
	void reset_weapon(int round, int asking_player_turn_order, const std::string& weapon);
	void reset_known_card(int round, int asking_player_turn_order, const std::string& known_card);
	void reset_answering_player_turn_order(int round, int asking_player_turn_order, int answering_player_turn_order);
	bool turn_recorded(int round, int asking_player_turn_order);
	turn get_turn(int round, int asking_player_turn_order);
	std::string get_suspect(int round, int asking_player_turn_order);
	std::string get_room(int round, int asking_player_turn_order);
	std::string get_weapon(int round, int asking_player_turn_order);
	std::string get_known_card(int round, int asking_player_turn_order);
	void set_own_cards(const std::vector<std::string>& cards);
	std::vector<std::string> get_own_cards();
	int get_answering_player_turn_order(int round, int asking_player_turn_order);
	void set_one_of_each_murder_element(bool one_of_each);
	bool get_one_of_each_murder_element();
	void set_game_name(const std::string& name);
	std::string get_game_name();
	std::vector<player_cards> investigate();
	int save(const std::string& path);
	int load(const std::string& path);
	int get_current_round();
	int get_current_turn();
	std::string generate_probability_report(const std::vector<player_cards>& investigation_information);

private:
	bool append_card(std::vector<player_cards>& cards_data, const std::string& card, int turn_order);
	bool append_eliminated_card(std::vector<player_cards>& cards_data, const std::string& card, int turn_order);
	std::vector<int> get_players_between(int asking_player_turn_order, int answering_player_turn_order);
	bool card_present(const std::vector<std::string>& cards, const std::string& card);
	bool card_present(const std::vector<player_cards>& card_data, const std::string& card, int turn_order, bool eliminated);
	void eliminate_cards_based_on_turn_history(std::vector<player_cards>& card_data);
	void add_cards_based_on_turn_history(std::vector<player_cards>& card_data);
	bool eliminate_cards_based_on_cards(std::vector<player_cards>& card_data);
	bool add_cards_based_on_cards(std::vector<player_cards>& card_data);
	bool add_cards_based_on_eliminated_cards(std::vector<player_cards>& card_data);
	bool loaded_data_valid(const nlohmann::json& game_data);

	struct player_name_turn_order_container
	{
		std::string name = "";
		int turn_order = -1;
		bool out = false;
	};

	int number_of_players = 0;
	bool one_of_each_murder_element = true;
	std::string game_name = "";

	std::vector<player_name_turn_order_container> players;
	std::vector<turn> turn_history;
	std::vector<std::string> own_cards;
};