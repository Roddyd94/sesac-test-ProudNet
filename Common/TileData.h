#pragma once
#include "ProudNetCommon.h"
#include <vector>
#include "Tile.h"

using std::vector;

class TileData
{
public:
    int num_cols;
	vector<Item> tiles;
    void Setup(int tile_x, int tile_y);
    void SetTile(int tile_x, int tile_y, Item tile);
    void Move(uint8_t key);
};

namespace Proud
{
    CMessage &operator>>(CMessage &m, TileData &t);
    CMessage &operator<<(CMessage &m, const TileData &t);
    inline void AppendTextOut(String &s, const TileData &t);
}