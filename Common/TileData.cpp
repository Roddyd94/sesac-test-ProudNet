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

        // ũ�Ⱑ �޾Ƶ��� �� ���� ��쿡�� ���ܸ� �߻���Ų��.
        // ��ŷ�� ��� ���� �ǽ��� �� �ִ�.
        if (size < 0 || size >= CNetConfig::MessageMaxLength)
            ThrowExceptionOnReadArray(size);

        // �޸� frag�� ���̱� ����
        t.tiles.reserve(size);
        t.tiles.resize(0);

        // �迭 �׸� �ϳ� �ϳ��� �д´�.
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
        // �迭 ũ�⸦ ����Ѵ�.
        int size = (int)t.tiles.size();
        m << size;

        // �� �迭 ���ڸ� ����Ѵ�.
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