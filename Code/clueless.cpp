#include <string>
#include <ascii_engine/frame.h>
#include <ascii_engine/menu.h>
#include <ascii_engine/label.h>
#include <ascii_engine/ascii_io.h>
#include <ascii_engine/file_manager.h>
#include "data.h"
#include "display.h"

int main()
{
	ascii_io::ascii_engine_init(true);
	frame* home_frame = new frame();
	frame* initialization_frame = new frame();
	frame* turn_entry_frame = new frame();
	frame* report_frame = new frame();
	frame* control_frame = new frame();
	frame* save_frame = new frame();
	frame* load_frame = new frame();
	frame* own_cards_entry_frame = new frame();
	frame* eliminate_players_display = new frame();
	display display_manager(initialization_frame, turn_entry_frame, report_frame, control_frame, save_frame, load_frame, own_cards_entry_frame, eliminate_players_display);
	data database;

	std::string logo_content = "";
	file_manager::read_file("board_configs/logo.txt", logo_content);

	label logo(home_frame);
	logo.set_output(logo_content);
	logo.set_alignment("center block");
	logo.set_spacing(15, 3, 0, 0);

	menu initialization_menu(home_frame, "new line");
	initialization_menu.set_alignment("center block");
	initialization_menu.append_item("New Game");
	initialization_menu.append_item("Load Game");
	initialization_menu.append_item("Exit");
	initialization_menu.enable_quit(false);
	initialization_menu.build();

	int round = 1;
	int turn = 0;

	bool initialize_game = true;
	bool setup_game = true;

	ascii_io::hide_cursor();
	std::string selection = "";
	do
	{
		int key_stroke = ascii_io::undefined;
		if (initialize_game)
		{
			home_frame->display();
			initialization_menu.get_selection(selection, key_stroke);
			setup_game = true;
		}

		if (selection == "New Game")
		{
			bool setup_complete = true;
			if (setup_game)
			{
				setup_complete = display_manager.display_setup(database);
				if (setup_complete)
				{
					display_manager.display_own_cards_entry(database);
				}
			}

			if (setup_complete)
			{
				display::turn_entry_feedback feedback = display::turn_entry_feedback::none;
				do
				{
					feedback = display_manager.display_turn_entry(database, round, turn);
					if (feedback == display::turn_entry_feedback::forward)
					{
						do
						{
							if (turn + 1 < database.get_number_of_players())
							{
								turn++;
							}
							else
							{
								turn = 0;
								round++;
							}
						} while (database.get_player_out(turn) && !database.turn_recorded(round, turn));
					}
					else if (feedback == display::turn_entry_feedback::backward)
					{
						do
						{
							if (turn - 1 >= 0)
							{
								turn--;
							}
							else if (round - 1 >= 1)
							{
								turn = database.get_number_of_players() - 1;
								round--;
							}
						} while (database.get_player_out(turn) && !database.turn_recorded(round, turn));
					}
					else if (feedback == display::turn_entry_feedback::entry)
					{
						display_manager.display_own_cards_entry(database);
					}
					else if (feedback == display::turn_entry_feedback::remove)
					{
						display_manager.display_eliminated_players_entry(database);
						while (database.get_player_out(turn) && !database.turn_recorded(round, turn))
						{
							if (turn + 1 < database.get_number_of_players())
							{
								turn++;
							}
							else
							{
								turn = 0;
								round++;
							}
						}
					}
					else if (feedback == display::turn_entry_feedback::save)
					{
						bool game_saved = display_manager.display_save(database);
						if (game_saved)
						{
							initialize_game = true;
							break;
						}
					}
					else if (feedback == display::turn_entry_feedback::exit)
					{
						initialize_game = true;
						break;
					}

				} while(true);
			}
		}
		else if (selection == "Load Game")
		{
			bool game_loaded = display_manager.display_load(database);
			if (game_loaded)
			{
				round = database.get_current_round();
				turn = database.get_current_turn();
				initialize_game = false;
				setup_game = false;
				selection = "New Game";
			}
			else
			{
				initialize_game = true;
			}
		}
		else if (selection == "Exit")
		{
			break;
		}
	} while (1);

	delete(home_frame);
	delete(initialization_frame);
	delete(turn_entry_frame);
	delete(report_frame);
	delete(control_frame);
	delete(save_frame);
	delete(load_frame);
	delete(own_cards_entry_frame);
	delete(eliminate_players_display);
	ascii_io::show_cursor();
	ascii_io::ascii_engine_end();
}