#include "Item.h"

Item::Item(Item::ItemType type, uint32_t scale, int x, int y)
	: type(type), scale(scale), pos_x(x), pos_y(y) {}

Item::Item(int x, int y)
    : Item(Item::ItemType::COIN, 0, x, y) {}

Item::Item()
    : Item(0, 0) {}

namespace Proud
{
    inline CMessage &operator>>(CMessage &m, Item &item)
    {
        int8_t temp_type;
        m >> temp_type >> item.scale >> item.pos_x >> item.pos_y;
        item.type = (Item::ItemType)temp_type;
        return m;
    }

    inline CMessage &operator<<(CMessage &m, const Item &item)
    {
        const int8_t temp_type = (int8_t)item.type;
        m << temp_type << item.scale << item.pos_x << item.pos_y;

        return m;
    }


    inline CMessage &operator>>(CMessage &m, std::vector<Item> &items) {
        // 크기를 얻는다.
        int size;
        m >> size;

        // 크기가 받아들일 수 없는 경우에는 예외를 발생시킨다.
        // 해킹된 경우 등을 의심할 수 있다.
        if (size < 0 || size >= CNetConfig::MessageMaxLength)
            ThrowExceptionOnReadArray(size);

        // 메모리 frag를 줄이기 위해
        items.reserve(size);
        items.resize(0);

        // 배열 항목 하나 하나를 읽는다.
        Item item;
        for (int i = 0; i < size; i++)
        {
            m >> item;
            items.push_back(item);
        }
        return m;
    }
    
    inline CMessage &operator<<(CMessage & m, const std::vector<Item> &items) {
        // 배열 크기를 기록한다.
        int size = (int)items.size();
        m << size;

        // 각 배열 인자를 기록한다.
        for (std::vector<Item>::const_iterator i = items.begin(); i != items.end(); i++)
        {
            m << (*i);
        }
        return m;
    }

    inline void AppendTextOut(String &s, const Item &item)
    {
        String f;
        f.Format(L"Tile{%c[%d,%d] scale: %d}", item.type, item.pos_x, item.pos_y, item.scale);
        s += f;
    }

    inline void AppendTextOut(String &s, const std::vector<Item> &items) {
        s += L"<vector>";
    }
}