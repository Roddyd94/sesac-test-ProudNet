﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
using System.Net;

namespace TestGame
{
	internal class Proxy:Nettention.Proud.RmiProxy
	{
public bool SendItemSet(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int player_nth, HashSet<Item> item_set)
{
	using (Nettention.Proud.FreeListPopper<Nettention.Proud.Message> freeList = new Nettention.Proud.FreeListPopper<Nettention.Proud.Message>())
		{
		Nettention.Proud.Message __msg=freeList.GetObject();
		__msg.Clear();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.SendItemSet;
		__msg.Write(__msgid);
		Nettention.Proud.Marshaler.Write(__msg, player_nth);
		Nettention.Proud.Marshaler.Write(__msg, item_set);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_SendItemSet, Common.SendItemSet);
        }
}

public bool SendItemSet(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, int player_nth, HashSet<Item> item_set)
{
	using (Nettention.Proud.FreeListPopper<Nettention.Proud.Message> freeList = new Nettention.Proud.FreeListPopper<Nettention.Proud.Message>())
{
Nettention.Proud.Message __msg=freeList.GetObject();
__msg.Clear();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.SendItemSet;
__msg.Write(__msgid);
Nettention.Proud.Marshaler.Write(__msg, player_nth);
Nettention.Proud.Marshaler.Write(__msg, item_set);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_SendItemSet, Common.SendItemSet);
        }
}
public bool SendPlayer(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int player_nth, Player player)
{
	using (Nettention.Proud.FreeListPopper<Nettention.Proud.Message> freeList = new Nettention.Proud.FreeListPopper<Nettention.Proud.Message>())
		{
		Nettention.Proud.Message __msg=freeList.GetObject();
		__msg.Clear();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.SendPlayer;
		__msg.Write(__msgid);
		Nettention.Proud.Marshaler.Write(__msg, player_nth);
		Nettention.Proud.Marshaler.Write(__msg, player);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_SendPlayer, Common.SendPlayer);
        }
}

public bool SendPlayer(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, int player_nth, Player player)
{
	using (Nettention.Proud.FreeListPopper<Nettention.Proud.Message> freeList = new Nettention.Proud.FreeListPopper<Nettention.Proud.Message>())
{
Nettention.Proud.Message __msg=freeList.GetObject();
__msg.Clear();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.SendPlayer;
__msg.Write(__msgid);
Nettention.Proud.Marshaler.Write(__msg, player_nth);
Nettention.Proud.Marshaler.Write(__msg, player);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_SendPlayer, Common.SendPlayer);
        }
}
public bool Move(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, byte key)
{
	using (Nettention.Proud.FreeListPopper<Nettention.Proud.Message> freeList = new Nettention.Proud.FreeListPopper<Nettention.Proud.Message>())
		{
		Nettention.Proud.Message __msg=freeList.GetObject();
		__msg.Clear();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.Move;
		__msg.Write(__msgid);
		Nettention.Proud.Marshaler.Write(__msg, key);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_Move, Common.Move);
        }
}

public bool Move(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, byte key)
{
	using (Nettention.Proud.FreeListPopper<Nettention.Proud.Message> freeList = new Nettention.Proud.FreeListPopper<Nettention.Proud.Message>())
{
Nettention.Proud.Message __msg=freeList.GetObject();
__msg.Clear();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.Move;
__msg.Write(__msgid);
Nettention.Proud.Marshaler.Write(__msg, key);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_Move, Common.Move);
        }
}
public bool WhoAmI(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext)
{
	using (Nettention.Proud.FreeListPopper<Nettention.Proud.Message> freeList = new Nettention.Proud.FreeListPopper<Nettention.Proud.Message>())
		{
		Nettention.Proud.Message __msg=freeList.GetObject();
		__msg.Clear();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.WhoAmI;
		__msg.Write(__msgid);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_WhoAmI, Common.WhoAmI);
        }
}

public bool WhoAmI(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext)
{
	using (Nettention.Proud.FreeListPopper<Nettention.Proud.Message> freeList = new Nettention.Proud.FreeListPopper<Nettention.Proud.Message>())
{
Nettention.Proud.Message __msg=freeList.GetObject();
__msg.Clear();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.WhoAmI;
__msg.Write(__msgid);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_WhoAmI, Common.WhoAmI);
        }
}
public bool WhoYouAre(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int player_nth)
{
	using (Nettention.Proud.FreeListPopper<Nettention.Proud.Message> freeList = new Nettention.Proud.FreeListPopper<Nettention.Proud.Message>())
		{
		Nettention.Proud.Message __msg=freeList.GetObject();
		__msg.Clear();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.WhoYouAre;
		__msg.Write(__msgid);
		Nettention.Proud.Marshaler.Write(__msg, player_nth);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_WhoYouAre, Common.WhoYouAre);
        }
}

public bool WhoYouAre(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, int player_nth)
{
	using (Nettention.Proud.FreeListPopper<Nettention.Proud.Message> freeList = new Nettention.Proud.FreeListPopper<Nettention.Proud.Message>())
{
Nettention.Proud.Message __msg=freeList.GetObject();
__msg.Clear();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.WhoYouAre;
__msg.Write(__msgid);
Nettention.Proud.Marshaler.Write(__msg, player_nth);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_WhoYouAre, Common.WhoYouAre);
        }
}
	
		#if USE_RMI_NAME_STRING
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
public const string RmiName_SendItemSet="SendItemSet";
public const string RmiName_SendPlayer="SendPlayer";
public const string RmiName_Move="Move";
public const string RmiName_WhoAmI="WhoAmI";
public const string RmiName_WhoYouAre="WhoYouAre";
       
public const string RmiName_First = RmiName_SendItemSet;
		#else
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
public const string RmiName_SendItemSet="";
public const string RmiName_SendPlayer="";
public const string RmiName_Move="";
public const string RmiName_WhoAmI="";
public const string RmiName_WhoYouAre="";
       
public const string RmiName_First = "";
		#endif

		public override Nettention.Proud.RmiID[] GetRmiIDList() { return Common.RmiIDList; } 
	}
}
