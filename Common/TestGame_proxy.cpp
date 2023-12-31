﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.


#include "TestGame_proxy.h"

namespace TestGame {


        
	bool Proxy::SendItemSet ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth, const std::set<Item> & item_set)	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_SendItemSet;
__msg.Write(__msgid); 
	
__msg << player_nth;
__msg << item_set;
		
		return RmiSend(&remote,1,rmiContext,__msg,
			RmiName_SendItemSet, (::Proud::RmiID)Rmi_SendItemSet);
	}

	bool Proxy::SendItemSet ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const int & player_nth, const std::set<Item> & item_set)  	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_SendItemSet;
__msg.Write(__msgid); 
	
__msg << player_nth;
__msg << item_set;
		
		return RmiSend(remotes,remoteCount,rmiContext,__msg,
			RmiName_SendItemSet, (::Proud::RmiID)Rmi_SendItemSet);
	}
        
	bool Proxy::SendPlayer ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth, const Player & player)	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_SendPlayer;
__msg.Write(__msgid); 
	
__msg << player_nth;
__msg << player;
		
		return RmiSend(&remote,1,rmiContext,__msg,
			RmiName_SendPlayer, (::Proud::RmiID)Rmi_SendPlayer);
	}

	bool Proxy::SendPlayer ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const int & player_nth, const Player & player)  	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_SendPlayer;
__msg.Write(__msgid); 
	
__msg << player_nth;
__msg << player;
		
		return RmiSend(remotes,remoteCount,rmiContext,__msg,
			RmiName_SendPlayer, (::Proud::RmiID)Rmi_SendPlayer);
	}
        
	bool Proxy::Move ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int8_t & key)	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_Move;
__msg.Write(__msgid); 
	
__msg << key;
		
		return RmiSend(&remote,1,rmiContext,__msg,
			RmiName_Move, (::Proud::RmiID)Rmi_Move);
	}

	bool Proxy::Move ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const int8_t & key)  	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_Move;
__msg.Write(__msgid); 
	
__msg << key;
		
		return RmiSend(remotes,remoteCount,rmiContext,__msg,
			RmiName_Move, (::Proud::RmiID)Rmi_Move);
	}
        
	bool Proxy::WhoAmI ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext )	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_WhoAmI;
__msg.Write(__msgid); 
	
		
		return RmiSend(&remote,1,rmiContext,__msg,
			RmiName_WhoAmI, (::Proud::RmiID)Rmi_WhoAmI);
	}

	bool Proxy::WhoAmI ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext)  	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_WhoAmI;
__msg.Write(__msgid); 
	
		
		return RmiSend(remotes,remoteCount,rmiContext,__msg,
			RmiName_WhoAmI, (::Proud::RmiID)Rmi_WhoAmI);
	}
        
	bool Proxy::WhoYouAre ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth)	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_WhoYouAre;
__msg.Write(__msgid); 
	
__msg << player_nth;
		
		return RmiSend(&remote,1,rmiContext,__msg,
			RmiName_WhoYouAre, (::Proud::RmiID)Rmi_WhoYouAre);
	}

	bool Proxy::WhoYouAre ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const int & player_nth)  	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_WhoYouAre;
__msg.Write(__msgid); 
	
__msg << player_nth;
		
		return RmiSend(remotes,remoteCount,rmiContext,__msg,
			RmiName_WhoYouAre, (::Proud::RmiID)Rmi_WhoYouAre);
	}
#ifdef USE_RMI_NAME_STRING
const PNTCHAR* Proxy::RmiName_SendItemSet =_PNT("SendItemSet");
#else
const PNTCHAR* Proxy::RmiName_SendItemSet =_PNT("");
#endif
#ifdef USE_RMI_NAME_STRING
const PNTCHAR* Proxy::RmiName_SendPlayer =_PNT("SendPlayer");
#else
const PNTCHAR* Proxy::RmiName_SendPlayer =_PNT("");
#endif
#ifdef USE_RMI_NAME_STRING
const PNTCHAR* Proxy::RmiName_Move =_PNT("Move");
#else
const PNTCHAR* Proxy::RmiName_Move =_PNT("");
#endif
#ifdef USE_RMI_NAME_STRING
const PNTCHAR* Proxy::RmiName_WhoAmI =_PNT("WhoAmI");
#else
const PNTCHAR* Proxy::RmiName_WhoAmI =_PNT("");
#endif
#ifdef USE_RMI_NAME_STRING
const PNTCHAR* Proxy::RmiName_WhoYouAre =_PNT("WhoYouAre");
#else
const PNTCHAR* Proxy::RmiName_WhoYouAre =_PNT("");
#endif
const PNTCHAR* Proxy::RmiName_First = RmiName_SendItemSet;

}



