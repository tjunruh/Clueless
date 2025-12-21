#include "display.h"
#include <ascii_engine/ascii_io.h>

display::display(frame* initialization_display, frame* turn_entry_display, frame* report_display, frame* control_display) :
	number_of_players_label(initialization_display),
	number_of_players_text_box(initialization_display, "merge"),
	your_name_label(initialization_display, "merge"),
	your_name_text_box(initialization_display, "merge"),
	players_names_label(initialization_display),
	player_2_name_text_box(initialization_display, "merge"),
	player_3_name_text_box(initialization_display, "merge"),
	player_4_name_text_box(initialization_display, "merge"),
	player_5_name_text_box(initialization_display, "merge"),
	player_6_name_text_box(initialization_display, "merge"),
	cancel_label(initialization_display, "new line"),
	ok_label(initialization_display),

	round_label(turn_entry_display),
	asking_player_label(turn_entry_display, "new line"),
	suspect_label(turn_entry_display, "new line"),
	suspect_menu(turn_entry_display, "merge"),
	room_label(turn_entry_display),
	room_menu(turn_entry_display, "merge"),
	weapon_label(turn_entry_display),
	weapon_menu(turn_entry_display, "merge"),
	answering_player_label(turn_entry_display, "new line"),
	known_card_label(turn_entry_display, "new line"),
	back_label(turn_entry_display, "new line"),
	forward_label(turn_entry_display),

	report_board(report_display, "board_configs/clue_deduction_sheet_config.txt", "default"),
	investigation_suggestions_label(report_display),
	accusation_suggestions_label(report_display, "merge"),

	control_label(control_display),
	control_menu(control_display, "new line")
{
	initialization_frame = initialization_display;
	number_of_players_label.set_output("Enter Number of Players (2-6)");
	number_of_players_label.set_alignment("center");
	number_of_players_label.use_spacing_width_multipliers(true);
	number_of_players_label.set_width_multiplier(3.0f);
	number_of_players_label.set_spacing_width_multipliers(1.0f, 0.5f);
	number_of_players_label.set_spacing(6, 0, 0, 0);

	number_of_players_text_box.add_border(true);
	number_of_players_text_box.use_spacing_width_multipliers(true);
	number_of_players_text_box.set_width_multiplier(3.0f);
	number_of_players_text_box.set_spacing_width_multipliers(1.0f, 0.5f);
	number_of_players_text_box.set_spacing(0, 3, 0, 0);
	number_of_players_text_box.set_max_characters(1);

	your_name_label.set_output("Enter Your Name");
	your_name_label.set_alignment("center");
	your_name_label.use_spacing_width_multipliers(true);
	your_name_label.set_width_multiplier(3.0f);
	your_name_label.set_spacing_width_multipliers(1.0f, 0.5f);
	your_name_label.set_spacing(0, 0, 0, 0);

	your_name_text_box.add_border(true);
	your_name_text_box.use_spacing_width_multipliers(true);
	your_name_text_box.set_width_multiplier(3.0f);
	your_name_text_box.set_spacing_width_multipliers(1.0f, 0.5f);

	players_names_label.set_output("Enter Your Opponents's Names in Turn Order After You");
	players_names_label.set_alignment("center");
	players_names_label.use_spacing_width_multipliers(true);
	players_names_label.set_width_multiplier(3.0f);
	players_names_label.set_spacing_width_multipliers(0.5f, 1.0f);
	players_names_label.set_spacing(6, 1, 0, 0);

	player_2_name_text_box.use_spacing_width_multipliers(true);
	player_2_name_text_box.set_width_multiplier(3.0f);
	player_2_name_text_box.set_spacing_width_multipliers(0.5f, 1.0f);
	player_2_name_text_box.set_spacing(0, 1, 0, 0);
	
	player_3_name_text_box.use_spacing_width_multipliers(true);
	player_3_name_text_box.set_width_multiplier(3.0f);
	player_3_name_text_box.set_spacing_width_multipliers(0.5f, 1.0f);
	player_3_name_text_box.set_spacing(0, 1, 0, 0);

	player_4_name_text_box.use_spacing_width_multipliers(true);
	player_4_name_text_box.set_width_multiplier(3.0f);
	player_4_name_text_box.set_spacing_width_multipliers(0.5f, 1.0f);
	player_4_name_text_box.set_spacing(0, 1, 0, 0);

	player_5_name_text_box.use_spacing_width_multipliers(true);
	player_5_name_text_box.set_width_multiplier(3.0f);
	player_5_name_text_box.set_spacing_width_multipliers(0.5f, 1.0f);
	player_5_name_text_box.set_spacing(0, 1, 0, 0);

	player_6_name_text_box.use_spacing_width_multipliers(true);
	player_6_name_text_box.set_width_multiplier(3.0f);
	player_6_name_text_box.set_spacing_width_multipliers(0.5f, 1.0f);
	player_6_name_text_box.set_spacing(0, 1, 0, 0);

	cancel_label.set_output("Cancel");
	cancel_label.add_border(true);
	cancel_label.use_spacing_width_multipliers(true);
	cancel_label.set_width_multiplier(2.0f);
	cancel_label.set_spacing_width_multipliers(0.5f, 2.0f);
	cancel_label.set_spacing(6, 0, 0, 0);
	cancel_label.set_selectable(true);

	ok_label.set_output("Ok");
	ok_label.add_border(true);
	ok_label.use_spacing_width_multipliers(true);
	ok_label.set_width_multiplier(2.0f);
	ok_label.set_spacing_width_multipliers(2.0f, 0.5f);
	ok_label.set_spacing(6, 0, 0, 0);
	ok_label.set_selectable(true);

	turn_entry_frame = turn_entry_display;

	round_label.set_output("Round: ");
	round_label.set_alignment("center");
	round_label.use_spacing_width_multipliers(true);
	round_label.set_width_multiplier(3.0f);
	round_label.set_spacing_width_multipliers(3.0f, 3.0f);
	round_label.set_spacing(6, 3, 0, 0);

	asking_player_label.set_output("Asking Player: ");
	asking_player_label.set_alignment("center");
	asking_player_label.use_spacing_width_multipliers(true);
	asking_player_label.set_width_multiplier(3.0f);
	asking_player_label.set_spacing_width_multipliers(3.0f, 3.0f);
	asking_player_label.set_spacing(0, 3, 0, 0);

	suspect_label.set_output("Suspect");
	suspect_label.set_alignment("center");
	suspect_label.use_spacing_width_multipliers(true);
	suspect_label.set_width_multiplier(2.33f);
	suspect_label.set_spacing_width_multipliers(0.5f, 0.25f);
	
	suspect_menu.append_item("Colonel Mustard");
	suspect_menu.append_item("Professor Plum");
	suspect_menu.append_item("Mr. Green");
	suspect_menu.append_item("Mrs. Peacock");
	suspect_menu.append_item("Miss Scarlet");
	suspect_menu.append_item("Mrs. White");
	suspect_menu.add_border(true);
	suspect_menu.use_spacing_width_multipliers(true);
	suspect_menu.set_width_multiplier(2.33f);
	suspect_menu.set_spacing_width_multipliers(0.5f, 0.25f);
	suspect_menu.set_spacing(0, 3, 0, 0);
	suspect_menu.build();

	room_label.set_output("Room");
	room_label.set_alignment("center");
	room_label.use_spacing_width_multipliers(true);
	room_label.set_width_multiplier(2.33f);
	room_label.set_spacing_width_multipliers(0.25f, 0.25f);

	room_menu.append_item("Hall");
	room_menu.append_item("Lounge");
	room_menu.append_item("Dining Room");
	room_menu.append_item("Kitchen");
	room_menu.append_item("Ballroom");
	room_menu.append_item("Conservatory");
	room_menu.append_item("Billiard Room");
	room_menu.append_item("Library");
	room_menu.append_item("Study");
	room_menu.add_border(true);
	room_menu.use_spacing_width_multipliers(true);
	room_menu.set_width_multiplier(2.33f);
	room_menu.set_spacing_width_multipliers(0.25f, 0.25f);
	room_menu.set_spacing(0, 3, 0, 0);
	room_menu.build();

	weapon_label.set_output("Weapon");
	weapon_label.set_alignment("center");
	weapon_label.use_spacing_width_multipliers(true);
	weapon_label.set_width_multiplier(2.33f);
	weapon_label.set_spacing_width_multipliers(0.25f, 0.5f);

	weapon_menu.append_item("Knife");
	weapon_menu.append_item("Candlestick");
	weapon_menu.append_item("Revolver");
	weapon_menu.append_item("Rope");
	weapon_menu.append_item("Lead Pipe");
	weapon_menu.append_item("Wrench");
	weapon_menu.add_border(true);
	weapon_menu.use_spacing_width_multipliers(true);
	weapon_menu.set_width_multiplier(2.33f);
	weapon_menu.set_spacing_width_multipliers(0.25f, 0.5f);
	weapon_menu.set_spacing(0, 3, 0, 0);
	weapon_menu.build();

	report_frame = report_display;

	report_board.use_spacing_width_multipliers(true);
	report_board.set_width_multiplier(3.0f);
	report_board.set_spacing_width_multipliers(1.0f, 0.5f);
	report_board.set_spacing(6, 6, 0, 0);
	report_board.set_lines_count(-12);

	investigation_suggestions_label.add_border(true);
	investigation_suggestions_label.use_spacing_width_multipliers(true);
	investigation_suggestions_label.set_width_multiplier(3.0f);
	investigation_suggestions_label.set_spacing_width_multipliers(0.5f, 1.0f);
	investigation_suggestions_label.set_spacing(6, 3, 0, 0);
	investigation_suggestions_label.set_lines_count(-25);

	accusation_suggestions_label.add_border(true);
	accusation_suggestions_label.use_spacing_width_multipliers(true);
	accusation_suggestions_label.set_width_multiplier(3.0f);
	accusation_suggestions_label.set_spacing_width_multipliers(0.5f, 1.0f);
	accusation_suggestions_label.set_spacing(0, 6, 0, 0);
	accusation_suggestions_label.set_lines_count(10);

	control_frame = control_display;

	control_label.set_output("Controls");
	control_label.set_alignment("center");
	
	control_menu.add_border(true);
	control_menu.set_alignment("center block");
}

bool display::display_setup(data& database)
{
	int selection = ascii_io::undefined;
	std::string number_of_players_text = "";
	int number_of_players = 0;
	std::string player_name = "";
	std::string player_2_name = "";
	std::string player_3_name = "";
	std::string player_4_name = "";
	std::string player_5_name = "";
	std::string player_6_name = "";
	bool setup_completed = false;
	initialization_frame->display();

	do
	{
		selection = initialization_frame->get_selection();

		if (selection == number_of_players_text_box)
		{
			int exit_code = number_of_players_text_box.write();
			if (exit_code == ascii_io::enter)
			{
				number_of_players_text = number_of_players_text_box.get_text();
				if (is_number(number_of_players_text))
				{
					number_of_players = stoi(number_of_players_text);
					if (number_of_players < 2 || number_of_players > 6)
					{
						number_of_players = 0;
						number_of_players_text_box.clear();
					}
					else
					{
						render_name_text_boxes(number_of_players);
					}
				}
				else
				{
					number_of_players_text_box.clear();
				}
			}

			ascii_io::hide_cursor();
		}
		else if (selection == your_name_text_box)
		{
			int exit_code = your_name_text_box.write();
			ascii_io::hide_cursor();
			if (exit_code == ascii_io::enter)
			{
				player_name = your_name_text_box.get_text();
			}
			else
			{
				your_name_text_box.clear();
			}
		}
		else if (selection == player_2_name_text_box)
		{
			int exit_code = player_2_name_text_box.write();
			ascii_io::hide_cursor();
			if (exit_code == ascii_io::enter)
			{
				player_2_name = player_2_name_text_box.get_text();
			}
			else
			{
				player_2_name_text_box.clear();
			}
		}
		else if (selection == player_3_name_text_box)
		{
			int exit_code = player_3_name_text_box.write();
			ascii_io::hide_cursor();
			if (exit_code == ascii_io::enter)
			{
				player_3_name = player_3_name_text_box.get_text();
			}
			else
			{
				player_3_name_text_box.clear();
			}
		}
		else if (selection == player_4_name_text_box)
		{
			int exit_code = player_4_name_text_box.write();
			ascii_io::hide_cursor();
			if (exit_code == ascii_io::enter)
			{
				player_4_name = player_4_name_text_box.get_text();
			}
			else
			{
				player_4_name_text_box.clear();
			}
		}
		else if (selection == player_5_name_text_box)
		{
			int exit_code = player_5_name_text_box.write();
			ascii_io::hide_cursor();
			if (exit_code == ascii_io::enter)
			{
				player_5_name = player_5_name_text_box.get_text();
			}
			else
			{
				player_5_name_text_box.clear();
			}
		}
		else if (selection == player_6_name_text_box)
		{
			int exit_code = player_6_name_text_box.write();
			ascii_io::hide_cursor();
			if (exit_code == ascii_io::enter)
			{
				player_6_name = player_6_name_text_box.get_text();
			}
			else
			{
				player_6_name = player_6_name_text_box.get_text();
			}
		}
		else if (selection == cancel_label)
		{
			setup_completed = false;
			break;
		}
		else if (selection == ok_label)
		{
			if (number_of_players != 0)
			{
				setup_completed = true;
				if (number_of_players >= 6 && player_6_name == "")
				{
					setup_completed = false;
				}

				if (number_of_players >= 5 && player_5_name == "")
				{
					setup_completed = false;
				}

				if (number_of_players >= 4 && player_4_name == "")
				{
					setup_completed = false;
				}

				if (number_of_players >= 3 && player_3_name == "")
				{
					setup_completed = false;
				}

				if (number_of_players >= 2 && player_2_name == "")
				{
					setup_completed = false;
				}

				if (player_name == "")
				{
					setup_completed = false;
				}
			}

			if (setup_completed)
			{
				break;
			}
		}

	} while (true);

	if (setup_completed)
	{
		database.set_number_of_players(number_of_players);
		database.set_player_name(player_name, 0);
		database.set_player_name(player_2_name, 1);
		database.set_player_name(player_3_name, 2);
		database.set_player_name(player_4_name, 3);
		database.set_player_name(player_5_name, 4);
		database.set_player_name(player_6_name, 5);
	}

	number_of_players_text_box.clear();
	your_name_text_box.clear();
	player_2_name_text_box.clear();
	player_3_name_text_box.clear();
	player_4_name_text_box.clear();
	player_5_name_text_box.clear();
	player_6_name_text_box.clear();

	return setup_completed;
}

void display::render_name_text_boxes(int number_of_players)
{
	if (number_of_players == 6)
	{
		player_2_name_text_box.set_selectable(true);
		player_2_name_text_box.add_border(true);
		player_3_name_text_box.set_selectable(true);
		player_3_name_text_box.add_border(true);
		player_4_name_text_box.set_selectable(true);
		player_4_name_text_box.add_border(true);
		player_5_name_text_box.set_selectable(true);
		player_5_name_text_box.add_border(true);
		player_6_name_text_box.set_selectable(true);
		player_6_name_text_box.add_border(true);
	}
	else if (number_of_players == 5)
	{
		player_2_name_text_box.set_selectable(true);
		player_2_name_text_box.add_border(true);
		player_3_name_text_box.set_selectable(true);
		player_3_name_text_box.add_border(true);
		player_4_name_text_box.set_selectable(true);
		player_4_name_text_box.add_border(true);
		player_5_name_text_box.set_selectable(true);
		player_5_name_text_box.add_border(true);
		player_6_name_text_box.set_selectable(false);
		player_6_name_text_box.add_border(false);
	}
	else if (number_of_players == 4)
	{
		player_2_name_text_box.set_selectable(true);
		player_2_name_text_box.add_border(true);
		player_3_name_text_box.set_selectable(true);
		player_3_name_text_box.add_border(true);
		player_4_name_text_box.set_selectable(true);
		player_4_name_text_box.add_border(true);
		player_5_name_text_box.set_selectable(false);
		player_5_name_text_box.add_border(false);
		player_6_name_text_box.set_selectable(false);
		player_6_name_text_box.add_border(false);
	}
	else if (number_of_players == 3)
	{
		player_2_name_text_box.set_selectable(true);
		player_2_name_text_box.add_border(true);
		player_3_name_text_box.set_selectable(true);
		player_3_name_text_box.add_border(true);
		player_4_name_text_box.set_selectable(false);
		player_4_name_text_box.add_border(false);
		player_5_name_text_box.set_selectable(false);
		player_5_name_text_box.add_border(false);
		player_6_name_text_box.set_selectable(false);
		player_6_name_text_box.add_border(false);
	}
	else if (number_of_players == 2)
	{
		player_2_name_text_box.set_selectable(false);
		player_2_name_text_box.add_border(false);
		player_3_name_text_box.set_selectable(false);
		player_3_name_text_box.add_border(false);
		player_4_name_text_box.set_selectable(false);
		player_4_name_text_box.add_border(false);
		player_5_name_text_box.set_selectable(false);
		player_5_name_text_box.add_border(false);
		player_6_name_text_box.set_selectable(false);
		player_6_name_text_box.add_border(false);
	}
}

bool display::is_number(const std::string& number_string)
{
	bool number = true;
	if (number_string.length() == 0)
	{
		number = false;
	}
	else
	{
		for (unsigned int i = 0; i < number_string.length(); i++)
		{
			if (!isdigit(number_string[i]))
			{
				number = false;
				break;
			}
		}
	}

	return number;
}