#include "Vars.h"

using namespace std;
using namespace Proud;

// Protocol version that you define.
// Your server app and client app must have the same value below.
PNGUID guid = {0xeb292954,
               0xac27,
               0x49cf,
               {0x88, 0x8d, 0x22, 0xa5, 0xb3, 0x42, 0x05, 0x1c}};

Guid g_Version = Guid(guid);

// TCP listening port number.
int g_ServerPort = 33334;
