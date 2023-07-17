#include "Item.h"

Item::Item() : Item(0, 0) {}

Item::Item(int x, int y) : Item((int)'@', 1, x, y) {}

Item::Item(int type, int scale, int x, int y)
    : type(type), scale(scale), pos_x(x), pos_y(y) {}

bool operator<(const Item &l, const Item &r) {
  if (l.pos_x == r.pos_x)
    return l.pos_y < r.pos_y;
  return l.pos_x < r.pos_x;
}
namespace Proud {
inline CMessage &operator>>(CMessage &m, Item &item) {
  m >> item.type >> item.scale >> item.pos_x >> item.pos_y;
  return m;
}

inline CMessage &operator<<(CMessage &m, const Item &item) {
  m << item.type << item.scale << item.pos_x << item.pos_y;

  return m;
}

inline CMessage &operator>>(CMessage &m, std::set<Item> &item_set) {
  int size;
  m >> size;

  if (size < 0 || size >= CNetConfig::MessageMaxLength)
    ThrowExceptionOnReadArray(size);

  Item item;
  for (int i = 0; i < size; i++) {
    m >> item;
    item_set.insert(item);
  }
  return m;
}

inline CMessage &operator<<(CMessage &m, const std::set<Item> &item_set) {
  int size = (int)item_set.size();
  m << size;

  for (std::set<Item>::iterator i = item_set.begin(); i != item_set.end(); i++) {
    m << (*i);
  }
  return m;
}

inline void AppendTextOut(String &s, const Item &item) {
  String f;
  f.Format(L"Tile{%c[%d,%d] scale: %d}", item.type, item.pos_x, item.pos_y,
           item.scale);
  s += f;
}

inline void AppendTextOut(String &s, const std::set<Item> &items) {
  s += L"<set>";
}
} // namespace Proud