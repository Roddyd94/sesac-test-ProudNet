#pragma once
#include "../../ProudNet/include/ProudNetCommon.h"
#include <vector>

class Item {
public:
  static enum ItemType : int8_t { COIN = '$' };
  ItemType type;
  uint32_t scale;
  int pos_x;
  int pos_y;
  Item(ItemType type, uint32_t scale, int x, int y);
  Item(int x, int y);
  Item();
};

namespace Proud {
inline CMessage &operator>>(CMessage &m, Item &item);
inline CMessage &operator<<(CMessage &m, const Item &item);
inline CMessage &operator>>(CMessage &m, std::vector<Item> &items);
inline CMessage &operator<<(CMessage &m, const std::vector<Item> &items);
inline void AppendTextOut(String &s, const Item &item);
inline void AppendTextOut(String &s, const std::vector<Item> &items);
} // namespace Proud