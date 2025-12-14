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

	void set_number_of_players(unsigned int number);
	unsigned int get_number_of_players();
	void set_player_name(const std::string& name, int turn_order);
	std::string get_player_name(int turn_order);
	void record_turn(int round, int asking_player_turn_order, const std::string& suspect, const std::string& room, const std::string& weapon, int answering_player_turn_order);
	turn get_turn(int round, int asking_player_turn_order);
	void set_one_of_each_murder_element(bool one_of_each);
	std::vector<player_cards> investigate();
	int save(const std::string& path);
	int load(const std::string& path);

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


	struct player_name_turn_order_container
	{
		std::string name = "";
		int turn_order = -1;
	};

	unsigned int number_of_players = 0;
	bool one_of_each_murder_element = true;

	std::vector<player_name_turn_order_container> players;
	std::vector<turn> turn_history;

	std::string guilty_suspect = "";
	std::string murder_room = "";
	std::string murder_weapon = "";
};