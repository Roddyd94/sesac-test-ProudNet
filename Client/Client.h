#pragma once
#include "stdafx.h"

#include "../../ProudNet/include/ProudNetClient.h"

using namespace std;
using namespace Proud;

#include "../Common/TestGame_common.cpp"
#include "../Common/TestGame_proxy.cpp"
#include "../Common/TestGame_stub.cpp"
#include "../Common/Vars.h"

#ifdef _WIN32
#include "Windows.h"
#elif __unix__

#elif __linux__

#elif __APPLE__

#endif