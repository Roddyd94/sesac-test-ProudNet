#pragma once
#include "../../ProudNet/include/ProudNetCommon.h"
#include "../Marshal/Item.cpp"
#include "../Marshal/Item.h"
#include "../Marshal/Player.cpp"
#include "../Marshal/Player.h"

namespace TestGame {

// Message ID that replies to each RMI method.

static const ::Proud::RmiID Rmi_SendItemSet = (::Proud::RmiID)(1000 + 1);

static const ::Proud::RmiID Rmi_SendPlayer = (::Proud::RmiID)(1000 + 2);

static const ::Proud::RmiID Rmi_Move = (::Proud::RmiID)(1000 + 3);

static const ::Proud::RmiID Rmi_WhoAmI = (::Proud::RmiID)(1000 + 4);

static const ::Proud::RmiID Rmi_WhoYouAre = (::Proud::RmiID)(1000 + 5);

// List that has RMI ID.
extern ::Proud::RmiID g_RmiIDList[];
// RmiID List Count
extern int g_RmiIDListCount;

} // namespace TestGame

// Forward declarations

// Declarations
