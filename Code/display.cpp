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
	answering_player_menu(turn_entry_display, "new line"),
	known_card_label(turn_entry_display, "new line"),
	back_label(turn_entry_display, "new line"),
	lock_unlock_label(turn_entry_display),
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
	player_2_name_text_box.set_selectable(false);
	
	player_3_name_text_box.use_spacing_width_multipliers(true);
	player_3_name_text_box.set_width_multiplier(3.0f);
	player_3_name_text_box.set_spacing_width_multipliers(0.5f, 1.0f);
	player_3_name_text_box.set_spacing(0, 1, 0, 0);
	player_3_name_text_box.set_selectable(false);

	player_4_name_text_box.use_spacing_width_multipliers(true);
	player_4_name_text_box.set_width_multiplier(3.0f);
	player_4_name_text_box.set_spacing_width_multipliers(0.5f, 1.0f);
	player_4_name_text_box.set_spacing(0, 1, 0, 0);
	player_4_name_text_box.set_selectable(false);

	player_5_name_text_box.use_spacing_width_multipliers(true);
	player_5_name_text_box.set_width_multiplier(3.0f);
	player_5_name_text_box.set_spacing_width_multipliers(0.5f, 1.0f);
	player_5_name_text_box.set_spacing(0, 1, 0, 0);
	player_5_name_text_box.set_selectable(false);

	player_6_name_text_box.use_spacing_width_multipliers(true);
	player_6_name_text_box.set_width_multiplier(3.0f);
	player_6_name_text_box.set_spacing_width_multipliers(0.5f, 1.0f);
	player_6_name_text_box.set_spacing(0, 1, 0, 0);
	player_6_name_text_box.set_selectable(false);

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
	round_label.add_border(true);
	round_label.use_spacing_width_multipliers(true);
	round_label.set_width_multiplier(3.0f);
	round_label.set_spacing_width_multipliers(3.0f, 3.0f);
	round_label.set_spacing(1, 2, 0, 0);

	asking_player_label.set_output("Asking Player: ");
	asking_player_label.set_alignment("center");
	asking_player_label.add_border(true);
	asking_player_label.use_spacing_width_multipliers(true);
	asking_player_label.set_width_multiplier(3.0f);
	asking_player_label.set_spacing_width_multipliers(3.0f, 3.0f);
	asking_player_label.set_spacing(0, 2, 0, 0);

	suspect_label.set_output("Suspect");
	suspect_label.set_alignment("center");
	suspect_label.use_spacing_width_multipliers(true);
	suspect_label.set_width_multiplier(2.33f);
	suspect_label.set_spacing_width_multipliers(0.5f, 0.25f);

	suspect_menu.append_item("None");
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
	suspect_menu.set_spacing(0, 2, 0, 0);
	suspect_menu.enable_quit(true);
	suspect_menu.build();

	room_label.set_output("Room");
	room_label.set_alignment("center");
	room_label.use_spacing_width_multipliers(true);
	room_label.set_width_multiplier(2.33f);
	room_label.set_spacing_width_multipliers(0.25f, 0.25f);

	room_menu.append_item("None");
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
	room_menu.set_spacing(0, 2, 0, 0);
	room_menu.enable_quit(true);
	room_menu.build();

	weapon_label.set_output("Weapon");
	weapon_label.set_alignment("center");
	weapon_label.use_spacing_width_multipliers(true);
	weapon_label.set_width_multiplier(2.33f);
	weapon_label.set_spacing_width_multipliers(0.25f, 0.5f);

	weapon_menu.append_item("None");
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
	weapon_menu.set_spacing(0, 2, 0, 0);
	weapon_menu.enable_quit(true);
	weapon_menu.build();

	answering_player_label.set_output("Answering Player");
	answering_player_label.set_alignment("center");
	answering_player_label.add_border(true);
	answering_player_label.use_spacing_width_multipliers(true);
	answering_player_label.set_width_multiplier(3.0f);
	answering_player_label.set_spacing_width_multipliers(3.0f, 3.0f);

	answering_player_menu.append_item("None");
	answering_player_menu.add_border(true);
	answering_player_menu.use_spacing_width_multipliers(true);
	answering_player_menu.set_width_multiplier(3.0f);
	answering_player_menu.set_spacing_width_multipliers(3.0f, 3.0f);
	answering_player_menu.set_spacing(0, 2, 0, 0);
	answering_player_menu.enable_quit(true);
	answering_player_menu.build();

	known_card_label.set_output("Known Card: ");
	known_card_label.set_alignment("center");
	known_card_label.add_border(true);
	known_card_label.use_spacing_width_multipliers(true);
	known_card_label.set_width_multiplier(3.0f);
	known_card_label.set_spacing_width_multipliers(3.0f, 3.0f);
	known_card_label.set_spacing(0, 2, 0, 0);

	back_label.set_output("<-- Back");
	back_label.set_alignment("center");
	back_label.add_border(true);
	back_label.use_spacing_width_multipliers(true);
	back_label.set_width_multiplier(2.0f);
	back_label.set_spacing_width_multipliers(0.5f, 0.5f);
	back_label.set_spacing(4, 0, 0, 0);
	back_label.set_selectable(true);

	lock_unlock_label.set_output("lock");
	lock_unlock_label.set_alignment("center");
	lock_unlock_label.add_border(true);
	lock_unlock_label.use_spacing_width_multipliers(true);
	lock_unlock_label.set_width_multiplier(2.0f);
	lock_unlock_label.set_spacing_width_multipliers(0.5f, 0.5f);
	lock_unlock_label.set_spacing(4, 0, 0, 0);
	lock_unlock_label.set_selectable(true);

	forward_label.set_output("Forward -->");
	forward_label.set_alignment("center");
	forward_label.add_border(true);
	forward_label.use_spacing_width_multipliers(true);
	forward_label.set_width_multiplier(2.0f);
	forward_label.set_spacing_width_multipliers(0.5f, 0.5f);
	forward_label.set_spacing(4, 0, 0, 0);
	forward_label.set_selectable(true);

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
				if (name_present(player_name, {player_2_name, player_3_name, player_4_name, player_5_name, player_6_name}))
				{
					player_name = "";
					your_name_text_box.clear();
				}
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
				if (name_present(player_2_name, {player_name, player_3_name, player_4_name, player_5_name, player_6_name}))
				{
					player_2_name = "";
					player_2_name_text_box.clear();
				}
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
				if (name_present(player_3_name, {player_2_name, player_name, player_4_name, player_5_name, player_6_name}))
				{
					player_3_name = "";
					player_3_name_text_box.clear();
				}
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
				if (name_present(player_4_name, {player_2_name, player_3_name, player_name, player_5_name, player_6_name}))
				{
					player_4_name = "";
					player_4_name_text_box.clear();
				}
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
				if (name_present(player_5_name, {player_2_name, player_3_name, player_4_name, player_name, player_6_name}))
				{
					player_5_name = "";
					player_5_name_text_box.clear();
				}
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
				if (name_present(player_6_name, {player_2_name, player_3_name, player_4_name, player_5_name, player_name}))
				{
					player_6_name = "";
					player_6_name_text_box.clear();
				}
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
		answering_player_menu.remove_all_items();
		answering_player_menu.append_item("None");
		for (int i = 0; i < number_of_players; i++)
		{
			answering_player_menu.append_item(database.get_player_name(i));
		}
		answering_player_menu.build();
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

display::turn_entry_feedback display::display_turn_entry(data& database, int round, int asking_player_turn_order)
{
	turn_entry_feedback feedback = forward;
	round_label.set_output("Round: " + std::to_string(round));
	asking_player_label.set_output("Asking Player: " + database.get_player_name(asking_player_turn_order));

	std::string suspect = "None";
	std::string room = "None";
	std::string weapon = "None";
	std::string answering_player_name = "None";

	if (database.turn_recorded(round, asking_player_turn_order))
	{
		data::turn turn_data = database.get_turn(round, asking_player_turn_order);
		suspect_menu.start_logging("menu.log");
		set_suspect_menu_selection(turn_data.suspect);
		set_room_menu_selection(turn_data.room);
		set_weapon_menu_selection(turn_data.weapon);
		set_answering_player_menu_selection(database.get_player_name(turn_data.answering_player_turn_order));
		known_card_label.set_output("Known Card: " + turn_data.known_card);
		lock_unlock_label.set_output("unlock");

		int selection = ascii_io::undefined;

		do
		{
			selection = turn_entry_frame->get_selection();
			if (selection == back_label)
			{
				feedback = backward;
				break;
			}
			else if (selection == forward_label)
			{
				feedback = forward;
				break;
			}
			else if (selection == lock_unlock_label)
			{
				if (lock_unlock_label.get_output() == "lock")
				{
					lock_unlock_label.set_output("unlock");
				}
				else if (lock_unlock_label.get_output() == "unlock")
				{
					lock_unlock_label.set_output("lock");
				}
			}
			else if (lock_unlock_label.get_output() == "lock")
			{
				if (selection == suspect_menu)
				{
					int key_stroke = ascii_io::undefined;
					suspect_menu.get_selection(suspect, key_stroke);
					if (key_stroke != ascii_io::enter)
					{
						suspect = "None";
						set_suspect_menu_selection(database.get_suspect(round, asking_player_turn_order));
					}
					else if (suspect != "None")
					{
						database.reset_suspect(round, asking_player_turn_order, suspect);
					}
				}
				else if (selection == room_menu)
				{
					int key_stroke = ascii_io::undefined;
					room_menu.get_selection(room, key_stroke);
					if (key_stroke != ascii_io::enter)
					{
						room = "None";
						set_room_menu_selection(database.get_room(round, asking_player_turn_order));
					}
					else if (room != "None")
					{
						database.reset_room(round, asking_player_turn_order, room);
					}
				}
				else if (selection == weapon_menu)
				{
					int key_stroke = ascii_io::undefined;
					weapon_menu.get_selection(weapon, key_stroke);
					if (key_stroke != ascii_io::enter)
					{
						weapon = "None";
						set_weapon_menu_selection(database.get_weapon(round, asking_player_turn_order));
					}
					else if (weapon != "None")
					{
						database.reset_weapon(round, asking_player_turn_order, weapon);
					}
				}
				else if (selection == answering_player_menu)
				{
					int key_stroke = ascii_io::undefined;
					answering_player_menu.get_selection(answering_player_name, key_stroke);
					if (key_stroke != ascii_io::enter)
					{
						answering_player_name = "None";
						set_answering_player_menu_selection(database.get_player_name(database.get_answering_player_turn_order(round, asking_player_turn_order)));
					}
					else if (answering_player_name != "None")
					{
						database.reset_answering_player_turn_order(round, asking_player_turn_order, database.get_player_turn_order(answering_player_name));
					}
				}
			}

		} while(true);
	}
	else
	{
		suspect_menu.set_cursor_index(0);
		room_menu.set_cursor_index(0);
		weapon_menu.set_cursor_index(0);
		answering_player_menu.set_cursor_index(0);
		lock_unlock_label.set_output("lock");

		int selection = ascii_io::undefined;

		do
		{
			selection = turn_entry_frame->get_selection();

			if (selection == back_label)
			{
				feedback = backward;
				break;
			}
			else if (selection == lock_unlock_label)
			{
				if (lock_unlock_label.get_output() == "lock")
				{
					lock_unlock_label.set_output("unlock");
				}
				else if (lock_unlock_label.get_output() == "unlock")
				{
					lock_unlock_label.set_output("lock");
				}
			}
			else if (selection == forward_label)
			{
				if (suspect != "None" && room != "None" && weapon != "None" && answering_player_name != "None")
				{
					feedback = forward;
					data::turn turn_data;
					turn_data.round = round;
					turn_data.asking_player_turn_order = asking_player_turn_order;
					turn_data.suspect = suspect;
					turn_data.room = room;
					turn_data.weapon = weapon;
					turn_data.answering_player_turn_order = database.get_player_turn_order(answering_player_name);
					database.record_turn(turn_data);
					break;
				}
			}
			else if (lock_unlock_label.get_output() == "lock")
			{
				if (selection == suspect_menu)
				{
					int key_stroke = ascii_io::undefined;
					suspect_menu.get_selection(suspect, key_stroke);
					if (key_stroke != ascii_io::enter)
					{
						suspect = "None";
						suspect_menu.set_cursor_index(0);
					}
				}
				else if (selection == room_menu)
				{
					int key_stroke = ascii_io::undefined;
					room_menu.get_selection(room, key_stroke);
					if (key_stroke != ascii_io::enter)
					{
						room = "None";
						room_menu.set_cursor_index(0);
					}
				}
				else if (selection == weapon_menu)
				{
					int key_stroke = ascii_io::undefined;
					weapon_menu.get_selection(weapon, key_stroke);
					if (key_stroke != ascii_io::enter)
					{
						weapon = "None";
						weapon_menu.set_cursor_index(0);
					}
				}
				else if (selection == answering_player_menu)
				{
					int key_stroke = ascii_io::undefined;
					answering_player_menu.get_selection(answering_player_name, key_stroke);
					if (key_stroke != ascii_io::enter)
					{
						answering_player_name = "None";
						answering_player_menu.set_cursor_index(0);
					}
				}
			}

		} while(true);
	}

	return feedback;
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
		player_2_name_text_box.set_selectable(true);
		player_2_name_text_box.add_border(true);
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

void display::set_suspect_menu_selection(const std::string& suspect)
{
	std::vector<menu::item_structure> suspects = suspect_menu.get_menu_item_data();
	for (unsigned int i = 0; i < suspects.size(); i++)
	{
		if (suspects[i].item == suspect)
		{
			suspect_menu.set_cursor_index(i);
			break;
		}
	}
}

void display::set_room_menu_selection(const std::string& room)
{
	std::vector<menu::item_structure> rooms = room_menu.get_menu_item_data();
	for (unsigned int i = 0; i < rooms.size(); i++)
	{
		if (rooms[i].item == room)
		{
			room_menu.set_cursor_index(i);
			break;
		}
	}
}

void display::set_weapon_menu_selection(const std::string& weapon)
{
	std::vector<menu::item_structure> weapons = weapon_menu.get_menu_item_data();
	for (unsigned int i = 0; i < weapons.size(); i++)
	{
		if (weapons[i].item == weapon)
		{
			weapon_menu.set_cursor_index(i);
			break;
		}
	}
}

void display::set_answering_player_menu_selection(const std::string& name)
{
	std::vector<menu::item_structure> names = answering_player_menu.get_menu_item_data();
	for (unsigned int i = 0; i < names.size(); i++)
	{
		if (names[i].item == name)
		{
			answering_player_menu.set_cursor_index(i);
			break;
		}
	}
}

bool display::name_present(const std::string& name, const std::vector<std::string>& names)
{
	bool present = false;
	for (unsigned int i = 0; i < names.size(); i++)
	{
		if (name == names[i])
		{
			present = true;
			break;
		}
	}

	return present;
}