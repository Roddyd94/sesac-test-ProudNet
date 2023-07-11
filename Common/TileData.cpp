#include "TileData.h"

void TileData::Setup(int num_rows, int num_cols) {
	this->num_cols = num_cols;
	for (int i = 0; i < num_rows * num_cols; ++i) {
		this->tiles.push_back(Item());
	}
}

void TileData::SetTile(int tile_x, int tile_y, Item tile) {
	tiles[tile_x + tile_y * num_cols] = tile;
}

void TileData::Move(uint8_t key) {

}

namespace Proud
{
    CMessage &operator>>(CMessage &m, TileData &t)
    {
        int size;
        m >> size;

        // 크기가 받아들일 수 없는 경우에는 예외를 발생시킨다.
        // 해킹된 경우 등을 의심할 수 있다.
        if (size < 0 || size >= CNetConfig::MessageMaxLength)
            ThrowExceptionOnReadArray(size);

        // 메모리 frag를 줄이기 위해
        t.tiles.reserve(size);
        t.tiles.resize(0);

        // 배열 항목 하나 하나를 읽는다.
        Item tile;
        for (int i = 0; i < size; i++)
        {
            m >> tile;
            t.tiles.push_back(tile);
        }

        return m;
    }

    CMessage &operator<<(CMessage &m, const TileData &t)
    {
        // 배열 크기를 기록한다.
        int size = (int)t.tiles.size();
        m << size;

        // 각 배열 인자를 기록한다.
        for (vector<Item>::const_iterator i = t.tiles.begin(); i != t.tiles.end(); i++)
        {
            m << (*i);
        }
        return m;
    }

    inline void AppendTextOut(String &s, const TileData &t)
    {
        s += L"<vector>";
    }
}