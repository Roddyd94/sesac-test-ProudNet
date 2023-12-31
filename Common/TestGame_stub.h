﻿  






// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.
   
#pragma once


#include "TestGame_common.h"

     
namespace TestGame {


	class Stub : public ::Proud::IRmiStub
	{
	public:
               
		virtual bool SendItemSet ( ::Proud::HostID, ::Proud::RmiContext& , const int & , const std::set<Item> & )		{ 
			return false;
		} 

#define DECRMI_TestGame_SendItemSet bool SendItemSet ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth, const std::set<Item> & item_set) PN_OVERRIDE

#define DEFRMI_TestGame_SendItemSet(DerivedClass) bool DerivedClass::SendItemSet ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth, const std::set<Item> & item_set)
#define CALL_TestGame_SendItemSet SendItemSet ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth, const std::set<Item> & item_set)
#define PARAM_TestGame_SendItemSet ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth, const std::set<Item> & item_set)
               
		virtual bool SendPlayer ( ::Proud::HostID, ::Proud::RmiContext& , const int & , const Player & )		{ 
			return false;
		} 

#define DECRMI_TestGame_SendPlayer bool SendPlayer ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth, const Player & player) PN_OVERRIDE

#define DEFRMI_TestGame_SendPlayer(DerivedClass) bool DerivedClass::SendPlayer ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth, const Player & player)
#define CALL_TestGame_SendPlayer SendPlayer ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth, const Player & player)
#define PARAM_TestGame_SendPlayer ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth, const Player & player)
               
		virtual bool Move ( ::Proud::HostID, ::Proud::RmiContext& , const int8_t & )		{ 
			return false;
		} 

#define DECRMI_TestGame_Move bool Move ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int8_t & key) PN_OVERRIDE

#define DEFRMI_TestGame_Move(DerivedClass) bool DerivedClass::Move ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int8_t & key)
#define CALL_TestGame_Move Move ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int8_t & key)
#define PARAM_TestGame_Move ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int8_t & key)
               
		virtual bool WhoAmI ( ::Proud::HostID, ::Proud::RmiContext& )		{ 
			return false;
		} 

#define DECRMI_TestGame_WhoAmI bool WhoAmI ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ) PN_OVERRIDE

#define DEFRMI_TestGame_WhoAmI(DerivedClass) bool DerivedClass::WhoAmI ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext )
#define CALL_TestGame_WhoAmI WhoAmI ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext )
#define PARAM_TestGame_WhoAmI ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext )
               
		virtual bool WhoYouAre ( ::Proud::HostID, ::Proud::RmiContext& , const int & )		{ 
			return false;
		} 

#define DECRMI_TestGame_WhoYouAre bool WhoYouAre ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth) PN_OVERRIDE

#define DEFRMI_TestGame_WhoYouAre(DerivedClass) bool DerivedClass::WhoYouAre ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth)
#define CALL_TestGame_WhoYouAre WhoYouAre ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth)
#define PARAM_TestGame_WhoYouAre ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth)
 
		virtual bool ProcessReceivedMessage(::Proud::CReceivedMessage &pa, void* hostTag) PN_OVERRIDE;
		static const PNTCHAR* RmiName_SendItemSet;
		static const PNTCHAR* RmiName_SendPlayer;
		static const PNTCHAR* RmiName_Move;
		static const PNTCHAR* RmiName_WhoAmI;
		static const PNTCHAR* RmiName_WhoYouAre;
		static const PNTCHAR* RmiName_First;
		virtual ::Proud::RmiID* GetRmiIDList() PN_OVERRIDE { return g_RmiIDList; }
		virtual int GetRmiIDListCount() PN_OVERRIDE { return g_RmiIDListCount; }
	};

#ifdef SUPPORTS_CPP11 
	
	class StubFunctional : public Stub 
	{
	public:
               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const int & , const std::set<Item> & ) > SendItemSet_Function;
		virtual bool SendItemSet ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth, const std::set<Item> & item_set) 
		{ 
			if (SendItemSet_Function==nullptr) 
				return true; 
			return SendItemSet_Function(remote,rmiContext, player_nth, item_set); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const int & , const Player & ) > SendPlayer_Function;
		virtual bool SendPlayer ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth, const Player & player) 
		{ 
			if (SendPlayer_Function==nullptr) 
				return true; 
			return SendPlayer_Function(remote,rmiContext, player_nth, player); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const int8_t & ) > Move_Function;
		virtual bool Move ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int8_t & key) 
		{ 
			if (Move_Function==nullptr) 
				return true; 
			return Move_Function(remote,rmiContext, key); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& ) > WhoAmI_Function;
		virtual bool WhoAmI ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ) 
		{ 
			if (WhoAmI_Function==nullptr) 
				return true; 
			return WhoAmI_Function(remote,rmiContext); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const int & ) > WhoYouAre_Function;
		virtual bool WhoYouAre ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_nth) 
		{ 
			if (WhoYouAre_Function==nullptr) 
				return true; 
			return WhoYouAre_Function(remote,rmiContext, player_nth); 
		}

	};
#endif

}


