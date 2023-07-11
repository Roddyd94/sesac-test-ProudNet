﻿



  
// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

#pragma once


#include "TestGame_common.h"

namespace TestGame {


	class Proxy : public ::Proud::IRmiProxy
	{
	public:
	virtual bool SendItems ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_no, const std::vector<Item> & items) PN_SEALED; 
	virtual bool SendItems ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const int & player_no, const std::vector<Item> & items)   PN_SEALED;  
	virtual bool SendPlayerInfo ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & player_no, const PlayerInfo & info) PN_SEALED; 
	virtual bool SendPlayerInfo ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const int & player_no, const PlayerInfo & info)   PN_SEALED;  
	virtual bool Move ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int8_t & key) PN_SEALED; 
	virtual bool Move ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const int8_t & key)   PN_SEALED;  
static const PNTCHAR* RmiName_SendItems;
static const PNTCHAR* RmiName_SendPlayerInfo;
static const PNTCHAR* RmiName_Move;
static const PNTCHAR* RmiName_First;
		Proxy()
		{
			if(m_signature != 1)
				::Proud::ShowUserMisuseError(::Proud::ProxyBadSignatureErrorText);
		}

		virtual ::Proud::RmiID* GetRmiIDList() PN_OVERRIDE { return g_RmiIDList; } 
		virtual int GetRmiIDListCount() PN_OVERRIDE { return g_RmiIDListCount; }
	};

}


