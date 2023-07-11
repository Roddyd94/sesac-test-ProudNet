#include "PlayerInfo.h"

PlayerInfo::PlayerInfo() {
	pos_x = g_CenterX;
	pos_y = g_CenterY;
	points = 0;
}

void PlayerInfo::SetPosition(int x, int y) {
	pos_x = x;
	pos_y = y;
}

bool PlayerInfo::SetPosition(int8_t key) {
	switch (key) {
	case 'U':
		if (pos_y + 1 == g_TileRow)
			return false;

		pos_y++;
		return true;
		break;
	case 'D':
		if (pos_y == 0)
			return false;

		pos_y--;
		return true;
		break;
	case 'L':
		if (pos_x == 0)
			return false;

		pos_x--;
		return true;
		break;
	case 'R':
		if (pos_x + 1 == g_TileCol)
			return false;

		pos_x++;
		return true;
		break;
	}
}

void PlayerInfo::AddPoint() {
	points++;
}

namespace Proud
{
	inline CMessage &operator>>(CMessage &m, PlayerInfo &info) {
		m >> info.points >> info.pos_x >> info.pos_y;
		return m;
	}

	inline CMessage &operator<<(CMessage &m, const PlayerInfo &info) {
		m << info.points << info.pos_x << info.pos_y;
		return m;
	}

	inline void AppendTextOut(String &s, const PlayerInfo &info) {
		String f;
		f.Format(L"Player{points: %d, x: %d, y: %d}", info.points, info.pos_x, info.pos_y);
		s += f;
	}
}

