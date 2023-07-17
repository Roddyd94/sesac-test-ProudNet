#pragma once
#include "../../ProudNet/include/ProudNetCommon.h"
#include <vector>

class Item {
public:
  int type;
  int scale;
  int pos_x;
  int pos_y;
  Item();
  Item(int x, int y);
  Item(int type, int scale, int x, int y);
  friend bool operator<(const Item &l, const Item &r);
};

namespace Proud {
inline CMessage &operator>>(CMessage &m, Item &item);
inline CMessage &operator<<(CMessage &m, const Item &item);
inline CMessage &operator>>(CMessage &m, std::set<Item> &item_set);
inline CMessage &operator<<(CMessage &m, const std::set<Item> &item_set);
inline void AppendTextOut(String &s, const Item &item);
inline void AppendTextOut(String &s, const std::set<Item> &item_set);
} // namespace Proud