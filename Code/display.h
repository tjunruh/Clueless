#pragma once

#include <ascii_engine/frame.h>
#include <ascii_engine/label.h>
#include <ascii_engine/text_box.h>
#include <ascii_engine/menu.h>
#include <ascii_engine/ascii_board.h>
#include "data.h"

class display
{
public:
	display(frame* initialization_display, frame* turn_entry_display, frame* report_display, frame* control_display);

	bool display_setup(data& database);
private:
	void render_name_text_boxes(int number_of_players);
	bool is_number(const std::string& number_string);

	label number_of_players_label;
	text_box number_of_players_text_box;
	label your_name_label;
	text_box your_name_text_box;
	label players_names_label;
	text_box player_2_name_text_box;
	text_box player_3_name_text_box;
	text_box player_4_name_text_box;
	text_box player_5_name_text_box;
	text_box player_6_name_text_box;
	label cancel_label;
	label ok_label;
	frame* initialization_frame;

	label round_label;
	label asking_player_label;
	label suspect_label;
	menu suspect_menu;
	label room_label;
	menu room_menu;
	label weapon_label;
	menu weapon_menu;
	label answering_player_label;
	label known_card_label;
	label back_label;
	label forward_label;
	frame* turn_entry_frame;

	ascii_board report_board;
	label investigation_suggestions_label;
	label accusation_suggestions_label;
	frame* report_frame;

	label control_label;
	menu control_menu;
	frame* control_frame;
};