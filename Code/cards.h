#include <string>
#include <vector>

namespace cards
{
	const std::string colonel_mustard = "Colonel Mustard";
	const std::string miss_scarlett = "Miss Scarlett";
	const std::string mrs_peacock = "Mrs. Peacock";
	const std::string mr_green = "Mr. Green";
	const std::string mrs_white = "Mrs. White";
	const std::string professor_plum = "Professor Plum";

	const std::string candlestick = "Candlestick";
	const std::string dagger = "Dagger";
	const std::string lead_pipe = "Lead Pipe";
	const std::string revolver = "Revolver";
	const std::string rope = "Rope";
	const std::string wrench = "Wrench";
	
	const std::string ballroom = "Ballroom";
	const std::string conservatory = "Conservatory";
	const std::string dining_room = "Dining Room";
	const std::string hall = "Hall";
	const std::string kitchen = "Kitchen";
	const std::string library = "Library";
	const std::string lounge = "Lounge";
	const std::string study = "Study";
	const std::string billiard_room = "Billiard Room";

	const std::vector<std::string> suspects =
	{
		colonel_mustard,
		miss_scarlett,
		mrs_peacock,
		mr_green,
		mrs_white,
		professor_plum
	};

	const std::vector<std::string> weapons =
	{
		candlestick,
		dagger,
		lead_pipe,
		revolver,
		rope,
		wrench
	};

	const std::vector<std::string> rooms =
	{
		ballroom,
		conservatory,
		dining_room,
		hall,
		kitchen,
		library,
		lounge,
		study,
		billiard_room
	};

	bool is_suspect(const std::string& card);
	bool is_weapon(const std::string& card);
	bool is_room(const std::string& card);
}