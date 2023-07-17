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
            player = new Player();
            if (msg.Read(out player.nth)
                && msg.Read(out player.points)
                && msg.Read(out player.posX)
                && msg.Read(out player.posY))
            {
                return true;
            }
            return false;
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
