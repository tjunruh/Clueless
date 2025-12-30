#pragma once

#include <ascii_engine/frame.h>
#include <ascii_engine/label.h>
#include <ascii_engine/text_box.h>
#include <ascii_engine/menu.h>
#include <ascii_engine/ascii_board.h>
#include "data.h"
#include "cards.h"

class display
{
public:
	display(frame* initialization_display, frame* turn_entry_display, frame* report_display, frame* control_display, frame* save_display, frame* load_display, frame* own_cards_entry_display);

	enum turn_entry_feedback
	{
		none,
		forward,
		backward,
		overview,
		save,
		settings,
		entry,
		exit
	};

	bool display_setup(data& database);
	turn_entry_feedback display_turn_entry(data& database, int round, int asking_player_turn_order);
	void display_overview(const std::vector<data::player_cards>& known_cards, data& databse);
	bool display_save(data& database);
	bool display_load(data& database);
	void display_own_cards_entry(data& database);
private:

	struct row_column
	{
		int row = -2;
		int column = -2;
	};

	struct report_board_coordinate_container
	{
		int player_turn_order = -1;
		std::string card_name = "";
		row_column coordinate;
	};

	const std::vector<report_board_coordinate_container> report_board_coordinate_map =
	{
		{0, cards::colonel_mustard, {1, 0}},
		{0, cards::professor_plum,  {2, 0}},
		{0, cards::mr_green,        {3, 0}},
		{0, cards::mrs_peacock,     {4, 0}},
		{0, cards::miss_scarlett,   {5, 0}},
		{0, cards::mrs_white,       {6, 0}},

		{0, cards::knife,           {7, 0}},
		{0, cards::candlestick,     {8, 0}},
		{0, cards::revolver,        {9, 0}},
		{0, cards::rope,            {10, 0}},
		{0, cards::lead_pipe,       {11, 0}},
		{0, cards::wrench,          {12, 0}},

		{0, cards::hall,            {13, 0}},
		{0, cards::lounge,          {14, 0}},
		{0, cards::dining_room,     {15, 0}},
		{0, cards::kitchen,         {16, 0}},
		{0, cards::ballroom,        {17, 0}},
		{0, cards::conservatory,    {18, 0}},
		{0, cards::billiard_room,   {19, 0}},
		{0, cards::library,         {20, 0}},
		{0, cards::study,           {21, 0}},


		{1, cards::colonel_mustard, {1, 1}},
		{1, cards::professor_plum,  {2, 1}},
		{1, cards::mr_green,        {3, 1}},
		{1, cards::mrs_peacock,     {4, 1}},
		{1, cards::miss_scarlett,   {5, 1}},
		{1, cards::mrs_white,       {6, 1}},

		{1, cards::knife,           {7, 1}},
		{1, cards::candlestick,     {8, 1}},
		{1, cards::revolver,        {9, 1}},
		{1, cards::rope,            {10, 1}},
		{1, cards::lead_pipe,       {11, 1}},
		{1, cards::wrench,          {12, 1}},

		{1, cards::hall,            {13, 1}},
		{1, cards::lounge,          {14, 1}},
		{1, cards::dining_room,     {15, 1}},
		{1, cards::kitchen,         {16, 1}},
		{1, cards::ballroom,        {17, 1}},
		{1, cards::conservatory,    {18, 1}},
		{1, cards::billiard_room,   {19, 1}},
		{1, cards::library,         {20, 1}},
		{1, cards::study,           {21, 1}},

		{2, cards::colonel_mustard, {1, 2}},
		{2, cards::professor_plum,  {2, 2}},
		{2, cards::mr_green,        {3, 2}},
		{2, cards::mrs_peacock,     {4, 2}},
		{2, cards::miss_scarlett,   {5, 2}},
		{2, cards::mrs_white,       {6, 2}},

		{2, cards::knife,           {7, 2}},
		{2, cards::candlestick,     {8, 2}},
		{2, cards::revolver,        {9, 2}},
		{2, cards::rope,            {10, 2}},
		{2, cards::lead_pipe,       {11, 2}},
		{2, cards::wrench,          {12, 2}},

		{2, cards::hall,            {13, 2}},
		{2, cards::lounge,          {14, 2}},
		{2, cards::dining_room,     {15, 2}},
		{2, cards::kitchen,         {16, 2}},
		{2, cards::ballroom,        {17, 2}},
		{2, cards::conservatory,    {18, 2}},
		{2, cards::billiard_room,   {19, 2}},
		{2, cards::library,         {20, 2}},
		{2, cards::study,           {21, 2}},

		{3, cards::colonel_mustard, {1, 3}},
		{3, cards::professor_plum,  {2, 3}},
		{3, cards::mr_green,        {3, 3}},
		{3, cards::mrs_peacock,     {4, 3}},
		{3, cards::miss_scarlett,   {5, 3}},
		{3, cards::mrs_white,       {6, 3}},

		{3, cards::knife,           {7, 3}},
		{3, cards::candlestick,     {8, 3}},
		{3, cards::revolver,        {9, 3}},
		{3, cards::rope,            {10, 3}},
		{3, cards::lead_pipe,       {11, 3}},
		{3, cards::wrench,          {12, 3}},

		{3, cards::hall,            {13, 3}},
		{3, cards::lounge,          {14, 3}},
		{3, cards::dining_room,     {15, 3}},
		{3, cards::kitchen,         {16, 3}},
		{3, cards::ballroom,        {17, 3}},
		{3, cards::conservatory,    {18, 3}},
		{3, cards::billiard_room,   {19, 3}},
		{3, cards::library,         {20, 3}},
		{3, cards::study,           {21, 3}},

		{4, cards::colonel_mustard, {1, 4}},
		{4, cards::professor_plum,  {2, 4}},
		{4, cards::mr_green,        {3, 4}},
		{4, cards::mrs_peacock,     {4, 4}},
		{4, cards::miss_scarlett,   {5, 4}},
		{4, cards::mrs_white,       {6, 4}},

		{4, cards::knife,           {7, 4}},
		{4, cards::candlestick,     {8, 4}},
		{4, cards::revolver,        {9, 4}},
		{4, cards::rope,            {10, 4}},
		{4, cards::lead_pipe,       {11, 4}},
		{4, cards::wrench,          {12, 4}},

		{4, cards::hall,            {13, 4}},
		{4, cards::lounge,          {14, 4}},
		{4, cards::dining_room,     {15, 4}},
		{4, cards::kitchen,         {16, 4}},
		{4, cards::ballroom,        {17, 4}},
		{4, cards::conservatory,    {18, 4}},
		{4, cards::billiard_room,   {19, 4}},
		{4, cards::library,         {20, 4}},
		{4, cards::study,           {21, 4}},

		{5, cards::colonel_mustard, {1, 5}},
		{5, cards::professor_plum,  {2, 5}},
		{5, cards::mr_green,        {3, 5}},
		{5, cards::mrs_peacock,     {4, 5}},
		{5, cards::miss_scarlett,   {5, 5}},
		{5, cards::mrs_white,       {6, 5}},

		{5, cards::knife,           {7, 5}},
		{5, cards::candlestick,     {8, 5}},
		{5, cards::revolver,        {9, 5}},
		{5, cards::rope,            {10, 5}},
		{5, cards::lead_pipe,       {11, 5}},
		{5, cards::wrench,          {12, 5}},

		{5, cards::hall,            {13, 5}},
		{5, cards::lounge,          {14, 5}},
		{5, cards::dining_room,     {15, 5}},
		{5, cards::kitchen,         {16, 5}},
		{5, cards::ballroom,        {17, 5}},
		{5, cards::conservatory,    {18, 5}},
		{5, cards::billiard_room,   {19, 5}},
		{5, cards::library,         {20, 5}},
		{5, cards::study,           {21, 5}}
	};

	void render_name_text_boxes(int number_of_players);
	bool is_number(const std::string& number_string);
	void set_suspect_menu_selection(const std::string& suspect);
	void set_room_menu_selection(const std::string& room);
	void set_weapon_menu_selection(const std::string& weapon);
	void set_known_card_menu_selection(const std::string& card_name);
	void set_answering_player_menu_selection(const std::string& name);
	bool name_present(const std::string& name, const std::vector<std::string>& names);
	row_column get_board_report_coordinate(int player_turn_order, const std::string& card);
	void reset_known_card_menu(data& database, int round, int player_turn_order, std::string& known_card);

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
	menu answering_player_menu;
	menu known_card_menu;
	label back_label;
	label lock_unlock_label;
	label forward_label;
	frame* turn_entry_frame;

	ascii_board report_board;
	label investigation_suggestions_label;
	label accusation_suggestions_label;
	frame* report_frame;

	label control_label;
	menu control_menu;
	frame* control_frame;

	text_box save_text_box;
	frame* save_frame;

	menu load_menu;
	frame* load_frame;

	menu own_cards_entry_menu;
	menu own_cards_entered_menu;
	frame* own_cards_entry_frame;
};