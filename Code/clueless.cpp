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
	display display_manager(initialization_frame, turn_entry_frame, report_frame, control_frame);
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

	ascii_io::hide_cursor();
	do
	{
		home_frame->display();
		std::string selection = "";
		int key_stroke = ascii_io::undefined;
		initialization_menu.get_selection(selection, key_stroke);
		if (selection == "New Game")
		{
			bool setup_complete = display_manager.display_setup(database);
			if (setup_complete)
			{
				display::turn_entry_feedback feedback = display::turn_entry_feedback::none;
				do
				{
					feedback = display_manager.display_turn_entry(database, round, turn);
					if (feedback == display::turn_entry_feedback::forward)
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
					else if (feedback == display::turn_entry_feedback::backward)
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
					}
				} while(feedback != display::turn_entry_feedback::save);
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
	ascii_io::show_cursor();
	ascii_io::ascii_engine_end();
}