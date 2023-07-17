using Nettention.Proud;
using System.Collections;
using System.Collections.Generic;
using static Player;

namespace TestGame
{
    public class PlayerMarshaler : Marshaler
    {
        public static bool Read(Message msg, out Player player)
        {
            player = null;
            if (!msg.Read(out player.nth))
            {
                return false;
            }
            if (!msg.Read(out player.points))
            {
                return false;
            }
            if (!msg.Read(out player.posX))
            {
                return false;
            }
            if (!msg.Read(out player.posY))
            {
                return false;
            }
            return true;
        }

        public static void Write(Message msg, Player player)
        {
            msg.Write(player.nth);
            msg.Write(player.points);
            msg.Write(player.posX);
            msg.Write(player.posY);
        }
    }
}
