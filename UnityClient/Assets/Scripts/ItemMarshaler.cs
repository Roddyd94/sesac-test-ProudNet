using Nettention.Proud;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.Logging;

using static Item;

namespace TestGame
{
    public class ItemMarshaler : Marshaler
    {
        public static bool Read(Message msg, out Item item)
        {
            item = new Item();

            if (msg.Read(out item.type)
                && msg.Read(out item.scale)
                && msg.Read(out item.posX)
                && msg.Read(out item.posY))
            {
                return true;
            }
            return false;
        }

        public static void Write(Message msg, Item item)
        {
            msg.Write(item.type);
            msg.Write(item.scale);
            msg.Write(item.posX);
            msg.Write(item.posY);
        }
        public static void Read(Message msg, out HashSet<Item> items)
        {
            items = new HashSet<Item>();

            int size = 0;
            msg.Read(out size);

            Log.Debug("set size: {0}", size);

            for (int i = 0; i < size; ++i)
            {
                Item item = new Item();
                Read(msg, out item);
                Log.Debug("{0}", item.ToString());
                items.Add(item);
            }
        }

        public static void Write(Message msg, HashSet<Item> items)
        {
            msg.Write((int)items.Count);

            foreach (var item in items)
            {
                Write(msg, item);
            }
        }
    }
}
