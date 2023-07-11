#pragma once
#include "ProudNetCommon.h"
#include "Item.h"
#include "PlayerInfo.h"

namespace TestGame {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_SendItems = (::Proud::RmiID)(1000+1);
               
    static const ::Proud::RmiID Rmi_SendPlayerInfo = (::Proud::RmiID)(1000+2);
               
    static const ::Proud::RmiID Rmi_Move = (::Proud::RmiID)(1000+3);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 

// Forward declarations


// Declarations



