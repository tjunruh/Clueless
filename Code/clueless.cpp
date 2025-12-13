#include <string>
#include <ascii_engine/frame.h>
#include <ascii_engine/menu.h>
#include <ascii_engine/label.h>
#include <ascii_engine/ascii_io.h>
#include <ascii_engine/file_manager.h>

int main()
{
	ascii_io::ascii_engine_init(true);
	frame* home_frame = new frame();

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

	ascii_io::hide_cursor();
	do
	{
		home_frame->display();
		std::string selection = "";
		int key_stroke = ascii_io::undefined;
		initialization_menu.get_selection(selection, key_stroke);
		if (selection == "Exit")
		{
			break;
		}
	} while (1);

	delete(home_frame);
	ascii_io::show_cursor();
	ascii_io::ascii_engine_end();
}