using Nettention.Proud;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using static Item;

namespace TestGame
{
    public class ItemMarshaler : Marshaler
    {
        public static bool Read(Message msg, out HashSet<Item> items)
        {
            int size = 0;
            items = null;

            if (!msg.ReadScalar(ref size))
            {
                return false;
            }
            for (int i = 0; i < size; ++i)
            {
                Item item = Resources.Load<Item>("Prefabs/Item");
                byte type = 0;
                if (!msg.Read(out type))
                {
                    return false;
                }
                item.type = (ItemType)type;
                if (!msg.Read(out item.scale))
                {
                    return false;
                }
                if (!msg.Read(out item.posX))
                {
                    return false;
                }
                if (!msg.Read(out item.posY))
                {
                    return false;
                }
                items.Add(item);
            }
            return true;
        }

        public static void Write(Message msg, HashSet<Item> items)
        {
            msg.WriteScalar(items.Count);
            Item[] itemArray = new Item[items.Count];
            for (int i = 0; i < items.Count; ++i)
            {
                msg.Write((byte)itemArray[i].type);
                msg.Write(itemArray[i].scale);
                msg.Write(itemArray[i].posX);
                msg.Write(itemArray[i].posY);
            }
        }
    }
}
