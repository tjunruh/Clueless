#include "display.h"
#include "archive.h"
#include <ascii_engine/ascii_io.h>

display::display(frame* initialization_display, frame* turn_entry_display, frame* report_display, frame* control_display, frame* save_display, frame* load_display) :
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
	known_card_menu(turn_entry_display, "new line"),
	back_label(turn_entry_display, "new line"),
	lock_unlock_label(turn_entry_display),
	forward_label(turn_entry_display),

	report_board(report_display, "board_configs/clue_deduction_sheet_config.txt", "default"),
	investigation_suggestions_label(report_display),
	accusation_suggestions_label(report_display, "merge"),

	control_label(control_display),
	control_menu(control_display, "new line"),

	save_text_box(save_display),

	load_menu(load_display)
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

	turn_entry_frame->set_selection_exit_keys({ascii_io::o, ascii_io::s});

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
	suspect_menu.append_item(cards::colonel_mustard);
	suspect_menu.append_item(cards::professor_plum);
	suspect_menu.append_item(cards::mr_green);
	suspect_menu.append_item(cards::mrs_peacock);
	suspect_menu.append_item(cards::miss_scarlett);
	suspect_menu.append_item(cards::mrs_white);
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
	room_menu.append_item(cards::hall);
	room_menu.append_item(cards::lounge);
	room_menu.append_item(cards::dining_room);
	room_menu.append_item(cards::kitchen);
	room_menu.append_item(cards::ballroom);
	room_menu.append_item(cards::conservatory);
	room_menu.append_item(cards::billiard_room);
	room_menu.append_item(cards::library);
	room_menu.append_item(cards::study);
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
	weapon_menu.append_item(cards::knife);
	weapon_menu.append_item(cards::candlestick);
	weapon_menu.append_item(cards::revolver);
	weapon_menu.append_item(cards::rope);
	weapon_menu.append_item(cards::lead_pipe);
	weapon_menu.append_item(cards::wrench);
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

	known_card_menu.append_item("None");
	known_card_menu.add_border(true);
	known_card_menu.use_spacing_width_multipliers(true);
	known_card_menu.set_width_multiplier(3.0f);
	known_card_menu.set_spacing_width_multipliers(3.0f, 3.0f);
	known_card_menu.enable_quit(true);
	known_card_menu.set_spacing(0, 2, 0, 0);
	known_card_menu.build();

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
	report_board.set_lines_count(-1);

	report_board.add_configuration("has", -1, -1, "   V   ", '*');
	report_board.add_configuration("hasn't", -1, -1, "   X   ", '*');
	report_board.build();

	investigation_suggestions_label.add_border(true);
	investigation_suggestions_label.use_spacing_width_multipliers(true);
	investigation_suggestions_label.set_width_multiplier(3.0f);
	investigation_suggestions_label.set_spacing_width_multipliers(0.5f, 1.0f);
	investigation_suggestions_label.set_spacing(0, 3, 0, 0);
	investigation_suggestions_label.set_lines_count(-25);

	accusation_suggestions_label.add_border(true);
	accusation_suggestions_label.use_spacing_width_multipliers(true);
	accusation_suggestions_label.set_width_multiplier(3.0f);
	accusation_suggestions_label.set_spacing_width_multipliers(0.5f, 1.0f);
	accusation_suggestions_label.set_spacing(0, 0, 0, 0);
	accusation_suggestions_label.set_lines_count(10);

	control_frame = control_display;

	control_label.set_output("Controls");
	control_label.set_alignment("center");
	
	control_menu.add_border(true);
	control_menu.set_alignment("center block");

	save_frame = save_display;

	save_text_box.set_spacing(20, 0, 0, 0);
	save_text_box.add_border(true);
	save_text_box.use_spacing_width_multipliers(true);
	save_text_box.set_width_multiplier(3.0f);
	save_text_box.set_spacing_width_multipliers(3.0f, 3.0f);
	save_text_box.set_title("Enter Game Name");

	load_frame = load_display;

	load_menu.set_spacing(5, 0, 0, 0);
	load_menu.add_border(true);
	load_menu.use_spacing_width_multipliers(true);
	load_menu.set_width_multiplier(3.0f);
	load_menu.set_spacing_width_multipliers(3.0f, 3.0f);
	load_menu.set_title("Select Game to Load");
	load_menu.enable_quit(true);
	load_menu.set_controls({ascii_io::enter, ascii_io::DEL}, ascii_io::up, ascii_io::down, ascii_io::left, ascii_io::right, ascii_io::q);
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
						initialization_frame->set_selection(your_name_text_box);
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
				else
				{
					initialization_frame->set_selection(player_2_name_text_box);
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
				else
				{
					if (number_of_players > 2)
					{
						initialization_frame->set_selection(player_3_name_text_box);
					}
					else
					{
						initialization_frame->set_selection(ok_label);
					}
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
				else
				{
					if (number_of_players > 3)
					{
						initialization_frame->set_selection(player_4_name_text_box);
					}
					else
					{
						initialization_frame->set_selection(ok_label);
					}
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
				else
				{
					if (number_of_players > 4)
					{
						initialization_frame->set_selection(player_5_name_text_box);
					}
					else
					{
						initialization_frame->set_selection(ok_label);
					}
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
				else
				{
					if (number_of_players > 5)
					{
						initialization_frame->set_selection(player_6_name_text_box);
					}
					else
					{
						initialization_frame->set_selection(ok_label);
					}
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
				else
				{
					initialization_frame->set_selection(ok_label);
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
	std::string known_card = "None";

	answering_player_menu.remove_all_items();
	answering_player_menu.append_item("None");
	for (int i = 0; i < database.get_number_of_players(); i++)
	{
		std::string player_name = database.get_player_name(i);
		answering_player_menu.append_item(player_name);
		report_board.set_tile(0, i, player_name);
	}
	answering_player_menu.build();

	if (database.turn_recorded(round, asking_player_turn_order))
	{
		data::turn turn_data = database.get_turn(round, asking_player_turn_order);
		set_suspect_menu_selection(turn_data.suspect);
		set_room_menu_selection(turn_data.room);
		set_weapon_menu_selection(turn_data.weapon);
		set_answering_player_menu_selection(database.get_player_name(turn_data.answering_player_turn_order));

		known_card_menu.remove_all_items();
		known_card_menu.append_item("None");
		if (turn_data.known_card != "")
		{
			known_card_menu.append_item(turn_data.suspect);
			known_card_menu.append_item(turn_data.room);
			known_card_menu.append_item(turn_data.weapon);
		}

		known_card_menu.build();
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
			else if (selection == forward_label && (asking_player_turn_order != 0 || known_card != "None"))
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
			else if (turn_entry_frame->selection_exit_key_used() && selection == ascii_io::o)
			{
				display_overview(database.investigate());
				ascii_io::zoom_to_level(0, 300);
				turn_entry_frame->display();
			}
			else if (turn_entry_frame->selection_exit_key_used() && selection == ascii_io::s)
			{
				feedback = save;
				break;
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
						reset_known_card_menu(database, round, asking_player_turn_order, known_card);
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
						reset_known_card_menu(database, round, asking_player_turn_order, known_card);
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
						reset_known_card_menu(database, round, asking_player_turn_order, known_card);
					}
				}
				else if (selection == known_card_menu && asking_player_turn_order == 0)
				{
					int key_stroke = ascii_io::undefined;
					known_card_menu.get_selection(known_card, key_stroke);
					if (key_stroke != ascii_io::enter)
					{
						known_card = "None";
						set_known_card_menu_selection(database.get_known_card(round, asking_player_turn_order));
					}
					else if (known_card != "None")
					{
						database.reset_known_card(round, asking_player_turn_order, known_card);
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
		turn_entry_frame->set_selection(suspect_menu);
		known_card_menu.remove_all_items();
		known_card_menu.append_item("None");

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
				if (suspect != "None" && room != "None" && weapon != "None" && answering_player_name != "None" && (asking_player_turn_order != 0 || known_card != "None"))
				{
					feedback = forward;
					data::turn turn_data;
					turn_data.round = round;
					turn_data.asking_player_turn_order = asking_player_turn_order;
					turn_data.suspect = suspect;
					turn_data.room = room;
					turn_data.weapon = weapon;
					turn_data.answering_player_turn_order = database.get_player_turn_order(answering_player_name);

					if (asking_player_turn_order == 0)
					{
						turn_data.known_card = known_card;
					}

					database.record_turn(turn_data);
					break;
				}
			}
			else if (turn_entry_frame->selection_exit_key_used() && selection == ascii_io::o)
			{
				display_overview(database.investigate());
				ascii_io::zoom_to_level(0, 300);
				turn_entry_frame->display();
			}
			else if (turn_entry_frame->selection_exit_key_used() && selection == ascii_io::s)
			{
				feedback = save;
				break;
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
					else
					{
						turn_entry_frame->set_selection(room_menu);
					}

					if (asking_player_turn_order == 0 && suspect != "None" && room != "None" && weapon != "None")
					{
						known_card_menu.append_item(suspect);
						known_card_menu.append_item(room);
						known_card_menu.append_item(weapon);
						known_card_menu.build();
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
					else
					{
						turn_entry_frame->set_selection(weapon_menu);
					}

					if (asking_player_turn_order == 0 && suspect != "None" && room != "None" && weapon != "None")
					{
						known_card_menu.append_item(suspect);
						known_card_menu.append_item(room);
						known_card_menu.append_item(weapon);
						known_card_menu.build();
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
					else
					{
						turn_entry_frame->set_selection(answering_player_menu);
					}

					if (asking_player_turn_order == 0 && suspect != "None" && room != "None" && weapon != "None")
					{
						known_card_menu.append_item(suspect);
						known_card_menu.append_item(room);
						known_card_menu.append_item(weapon);
						known_card_menu.build();
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
					else
					{
						if (asking_player_turn_order != 0)
						{
							turn_entry_frame->set_selection(forward_label);
						}
						else
						{
							turn_entry_frame->set_selection(known_card_menu);
						}
					}
				}
				else if (selection == known_card_menu && asking_player_turn_order == 0)
				{
					int key_stroke = ascii_io::undefined;
					known_card_menu.get_selection(known_card, key_stroke);
					if (key_stroke != ascii_io::enter)
					{
						known_card = "None";
						known_card_menu.set_cursor_index(0);
					}
					else
					{
						turn_entry_frame->set_selection(forward_label);
					}
				}
			}

		} while(true);
	}

	return feedback;
}

void display::display_overview(const std::vector<data::player_cards>& known_cards)
{
	ascii_io::zoom_to_level(-2, 500);
	report_board.clear_all();
	for (unsigned int i = 0; i < known_cards.size(); i++)
	{
		for (unsigned int j = 0; j < known_cards[i].cards.size(); j++)
		{
			row_column coordinate = get_board_report_coordinate(known_cards[i].turn_order, known_cards[i].cards[j]);
			report_board.activate_configuration("has", coordinate.row, coordinate.column);
		}

		for (unsigned int j = 0; j < known_cards[i].eliminated_cards.size(); j++)
		{
			row_column coordinate = get_board_report_coordinate(known_cards[i].turn_order, known_cards[i].eliminated_cards[j]);
			report_board.activate_configuration("hasn't", coordinate.row, coordinate.column);
		}
	}

	report_board.build();
	report_frame->display();

	ascii_io::wait_for_keystroke({ascii_io::enter});
}

bool display::display_save(data& database)
{
	bool saved = false;
	save_frame->display();
	do
	{
		unsigned int exit_keystroke = save_text_box.write();
		ascii_io::hide_cursor();
		if (exit_keystroke == ascii_io::enter)
		{
			std::string game_name = save_text_box.get_text();
			if (game_name != "" && !archive::duplicate_name(game_name))
			{
				int status = archive::save_game(game_name, database);
				if (status == SUCCESS)
				{
					saved = true;
					break;
				}
			}
		}
		else
		{
			saved = false;
			break;
		}

	} while(true);

	return saved;
}

bool display::display_load(data& database)
{
	bool loaded = false;
	load_menu.remove_all_items();

	std::vector<std::string> saved_games = archive::get_saved_game_names();
	for (unsigned int i = 0; i < saved_games.size(); i++)
	{
		load_menu.append_item(saved_games[i]);
	}

	load_menu.build();

	do
	{
		std::string selection = "";
		int key_stroke = ascii_io::undefined;
		load_menu.get_selection(selection, key_stroke);
		if (key_stroke == ascii_io::enter)
		{
			int status = archive::load_game(selection, database);
			if (status == SUCCESS)
			{
				loaded = true;
				break;
			}
			else
			{
				loaded = false;
			}
		}
		else if (key_stroke == ascii_io::q)
		{
			loaded = false;
			break;
		}
		else
		{
			archive::delete_game(selection);
			std::vector<std::string> saved_games = archive::get_saved_game_names();
			load_menu.remove_all_items();
			for (unsigned int i = 0; i < saved_games.size(); i++)
			{
				load_menu.append_item(saved_games[i]);
			}

			load_menu.build();
		}

	} while (true);

	return loaded;
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

void display::set_known_card_menu_selection(const std::string& card_name)
{
	std::vector<menu::item_structure> card_names = known_card_menu.get_menu_item_data();
	for (unsigned int i = 0; i < card_names.size(); i++)
	{
		if (card_names[i].item == card_name)
		{
			known_card_menu.set_cursor_index(i);
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

display::row_column display::get_board_report_coordinate(int player_turn_order, const std::string& card)
{
	row_column coordinate;
	for (unsigned int i = 0; i < report_board_coordinate_map.size(); i++)
	{
		if (report_board_coordinate_map[i].player_turn_order == player_turn_order && report_board_coordinate_map[i].card_name == card)
		{
			coordinate = report_board_coordinate_map[i].coordinate;
			break;
		}
	}

	return coordinate;
}

void display::reset_known_card_menu(data& database, int round, int player_turn_order, std::string& known_card)
{
	known_card_menu.remove_all_items();
	known_card_menu.append_item("None");
	known_card_menu.append_item(database.get_suspect(round, player_turn_order));
	known_card_menu.append_item(database.get_room(round, player_turn_order));
	known_card_menu.append_item(database.get_weapon(round, player_turn_order));
	known_card_menu.set_cursor_index(0);
	known_card = database.get_known_card(round, player_turn_order);
	set_known_card_menu_selection(known_card);
	if (known_card_menu.get_cursor_index() == 0)
	{
		known_card = "None";
	}
	known_card_menu.build();
}