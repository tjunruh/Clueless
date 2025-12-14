#include "cards.h"

bool cards::is_suspect(const std::string& card)
{
	bool is = false;
	for (unsigned int i = 0; i < suspects.size(); i++)
	{
		if (suspects[i] == card)
		{
			is = true;
			break;
		}
	}

	return is;
}

bool cards::is_weapon(const std::string& card)
{
	bool is = false;
	for (unsigned int i = 0; i < weapons.size(); i++)
	{
		if (weapons[i] == card)
		{
			is = true;
			break;
		}
	}

	return is;
}

bool cards::is_room(const std::string& card)
{
	bool is = false;
	for (unsigned int i = 0; i < rooms.size(); i++)
	{
		if (rooms[i] == card)
		{
			is = true;
			break;
		}
	}

	return is;
}