﻿

// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

#include "TestGame_stub.h"

const unsigned char sz_TestGame_stub_hRmi[] = {
    0x00, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xff, 0x00, 0x99, 0xaa,
    0xbb, 0xcc, 0xdd, 0xff, 0xaa, 0xbb, 0xcc, 0xdd, 0xff, 0x99,
    0xaa, 0xbb, 0xcc, 0x99, 0xaa, 0xdd, 0xff, 0x00};

namespace TestGame {

bool Stub::ProcessReceivedMessage(::Proud::CReceivedMessage &pa,
                                  void *hostTag) {
#ifndef __FreeBSD__
  {
    // unusable but required. you may ignore it, because it does not occur any
    // worthless load.
    unsigned char x = sz_TestGame_stub_hRmi[0];
    x++;
  }
#endif
  ::Proud::HostID remote = pa.GetRemoteHostID();
  if (remote == ::Proud::HostID_None) {
    ShowUnknownHostIDWarning(remote);
  }

  ::Proud::CMessage &__msg = pa.GetReadOnlyMessage();
  int orgReadOffset = __msg.GetReadOffset();

  ::Proud::RmiID __rmiID;
  if (!__msg.Read(__rmiID))
    goto __fail;

  switch ((int)__rmiID) // case is to prevent from clang compile error
  {
  case Rmi_SendItems: {
    ::Proud::RmiContext ctx;
    ctx.m_rmiID = __rmiID;
    ctx.m_sentFrom = pa.GetRemoteHostID();
    ctx.m_relayed = pa.IsRelayed();
    ctx.m_hostTag = hostTag;
    ctx.m_encryptMode = pa.GetEncryptMode();
    ctx.m_compressMode = pa.GetCompressMode();

    if (BeforeDeserialize(remote, ctx, __msg) == false) {
      // The user don't want to call the RMI function.
      // So, We fake that it has been already called.
      __msg.SetReadOffset(__msg.GetLength());
      return true;
    }

    int player_nth;
    __msg >> player_nth;
    std::vector<Item> items;
    __msg >> items;
    m_core->PostCheckReadMessage(__msg, RmiName_SendItems);

    if (m_enableNotifyCallFromStub && !m_internalUse) {
      ::Proud::String parameterString;

      ::Proud::AppendTextOut(parameterString, player_nth);

      parameterString += _PNT(", ");
      ::Proud::AppendTextOut(parameterString, items);

      NotifyCallFromStub(remote, (::Proud::RmiID)Rmi_SendItems,
                         RmiName_SendItems, parameterString);

#ifdef VIZAGENT
      m_core->Viz_NotifyRecvToStub(remote, (::Proud::RmiID)Rmi_SendItems,
                                   RmiName_SendItems, parameterString);
#endif
    } else if (!m_internalUse) {
#ifdef VIZAGENT
      m_core->Viz_NotifyRecvToStub(remote, (::Proud::RmiID)Rmi_SendItems,
                                   RmiName_SendItems, _PNT(""));
#endif
    }

    int64_t __t0 = 0;
    if (!m_internalUse && m_enableStubProfiling) {
      ::Proud::BeforeRmiSummary summary;
      summary.m_rmiID = (::Proud::RmiID)Rmi_SendItems;
      summary.m_rmiName = RmiName_SendItems;
      summary.m_hostID = remote;
      summary.m_hostTag = hostTag;
      BeforeRmiInvocation(summary);

      __t0 = ::Proud::GetPreciseCurrentTimeMs();
    }

    // Call this method.
    bool __ret = SendItems(remote, ctx, player_nth, items);

    if (__ret == false) {
      // Error: RMI function that a user did not create has been called.
      m_core->ShowNotImplementedRmiWarning(RmiName_SendItems);
    }

    if (!m_internalUse && m_enableStubProfiling) {
      ::Proud::AfterRmiSummary summary;
      summary.m_rmiID = (::Proud::RmiID)Rmi_SendItems;
      summary.m_rmiName = RmiName_SendItems;
      summary.m_hostID = remote;
      summary.m_hostTag = hostTag;
      int64_t __t1;

      __t1 = ::Proud::GetPreciseCurrentTimeMs();

      summary.m_elapsedTime = (uint32_t)(__t1 - __t0);
      AfterRmiInvocation(summary);
    }
  } break;
  case Rmi_SendPlayer: {
    ::Proud::RmiContext ctx;
    ctx.m_rmiID = __rmiID;
    ctx.m_sentFrom = pa.GetRemoteHostID();
    ctx.m_relayed = pa.IsRelayed();
    ctx.m_hostTag = hostTag;
    ctx.m_encryptMode = pa.GetEncryptMode();
    ctx.m_compressMode = pa.GetCompressMode();

    if (BeforeDeserialize(remote, ctx, __msg) == false) {
      // The user don't want to call the RMI function.
      // So, We fake that it has been already called.
      __msg.SetReadOffset(__msg.GetLength());
      return true;
    }

    int player_nth;
    __msg >> player_nth;
    Player player;
    __msg >> player;
    m_core->PostCheckReadMessage(__msg, RmiName_SendPlayer);

    if (m_enableNotifyCallFromStub && !m_internalUse) {
      ::Proud::String parameterString;

      ::Proud::AppendTextOut(parameterString, player_nth);

      parameterString += _PNT(", ");
      ::Proud::AppendTextOut(parameterString, player);

      NotifyCallFromStub(remote, (::Proud::RmiID)Rmi_SendPlayer,
                         RmiName_SendPlayer, parameterString);

#ifdef VIZAGENT
      m_core->Viz_NotifyRecvToStub(remote, (::Proud::RmiID)Rmi_SendPlayer,
                                   RmiName_SendPlayer, parameterString);
#endif
    } else if (!m_internalUse) {
#ifdef VIZAGENT
      m_core->Viz_NotifyRecvToStub(remote, (::Proud::RmiID)Rmi_SendPlayer,
                                   RmiName_SendPlayer, _PNT(""));
#endif
    }

    int64_t __t0 = 0;
    if (!m_internalUse && m_enableStubProfiling) {
      ::Proud::BeforeRmiSummary summary;
      summary.m_rmiID = (::Proud::RmiID)Rmi_SendPlayer;
      summary.m_rmiName = RmiName_SendPlayer;
      summary.m_hostID = remote;
      summary.m_hostTag = hostTag;
      BeforeRmiInvocation(summary);

      __t0 = ::Proud::GetPreciseCurrentTimeMs();
    }

    // Call this method.
    bool __ret = SendPlayer(remote, ctx, player_nth, player);

    if (__ret == false) {
      // Error: RMI function that a user did not create has been called.
      m_core->ShowNotImplementedRmiWarning(RmiName_SendPlayer);
    }

    if (!m_internalUse && m_enableStubProfiling) {
      ::Proud::AfterRmiSummary summary;
      summary.m_rmiID = (::Proud::RmiID)Rmi_SendPlayer;
      summary.m_rmiName = RmiName_SendPlayer;
      summary.m_hostID = remote;
      summary.m_hostTag = hostTag;
      int64_t __t1;

      __t1 = ::Proud::GetPreciseCurrentTimeMs();

      summary.m_elapsedTime = (uint32_t)(__t1 - __t0);
      AfterRmiInvocation(summary);
    }
  } break;
  case Rmi_Move: {
    ::Proud::RmiContext ctx;
    ctx.m_rmiID = __rmiID;
    ctx.m_sentFrom = pa.GetRemoteHostID();
    ctx.m_relayed = pa.IsRelayed();
    ctx.m_hostTag = hostTag;
    ctx.m_encryptMode = pa.GetEncryptMode();
    ctx.m_compressMode = pa.GetCompressMode();

    if (BeforeDeserialize(remote, ctx, __msg) == false) {
      // The user don't want to call the RMI function.
      // So, We fake that it has been already called.
      __msg.SetReadOffset(__msg.GetLength());
      return true;
    }

    int key;
    __msg >> key;
    m_core->PostCheckReadMessage(__msg, RmiName_Move);

    if (m_enableNotifyCallFromStub && !m_internalUse) {
      ::Proud::String parameterString;

      ::Proud::AppendTextOut(parameterString, key);

      NotifyCallFromStub(remote, (::Proud::RmiID)Rmi_Move, RmiName_Move,
                         parameterString);

#ifdef VIZAGENT
      m_core->Viz_NotifyRecvToStub(remote, (::Proud::RmiID)Rmi_Move,
                                   RmiName_Move, parameterString);
#endif
    } else if (!m_internalUse) {
#ifdef VIZAGENT
      m_core->Viz_NotifyRecvToStub(remote, (::Proud::RmiID)Rmi_Move,
                                   RmiName_Move, _PNT(""));
#endif
    }

    int64_t __t0 = 0;
    if (!m_internalUse && m_enableStubProfiling) {
      ::Proud::BeforeRmiSummary summary;
      summary.m_rmiID = (::Proud::RmiID)Rmi_Move;
      summary.m_rmiName = RmiName_Move;
      summary.m_hostID = remote;
      summary.m_hostTag = hostTag;
      BeforeRmiInvocation(summary);

      __t0 = ::Proud::GetPreciseCurrentTimeMs();
    }

    // Call this method.
    bool __ret = Move(remote, ctx, key);

    if (__ret == false) {
      // Error: RMI function that a user did not create has been called.
      m_core->ShowNotImplementedRmiWarning(RmiName_Move);
    }

    if (!m_internalUse && m_enableStubProfiling) {
      ::Proud::AfterRmiSummary summary;
      summary.m_rmiID = (::Proud::RmiID)Rmi_Move;
      summary.m_rmiName = RmiName_Move;
      summary.m_hostID = remote;
      summary.m_hostTag = hostTag;
      int64_t __t1;

      __t1 = ::Proud::GetPreciseCurrentTimeMs();

      summary.m_elapsedTime = (uint32_t)(__t1 - __t0);
      AfterRmiInvocation(summary);
    }
  } break;
  case Rmi_WhoAmI: {
    ::Proud::RmiContext ctx;
    ctx.m_rmiID = __rmiID;
    ctx.m_sentFrom = pa.GetRemoteHostID();
    ctx.m_relayed = pa.IsRelayed();
    ctx.m_hostTag = hostTag;
    ctx.m_encryptMode = pa.GetEncryptMode();
    ctx.m_compressMode = pa.GetCompressMode();

    if (BeforeDeserialize(remote, ctx, __msg) == false) {
      // The user don't want to call the RMI function.
      // So, We fake that it has been already called.
      __msg.SetReadOffset(__msg.GetLength());
      return true;
    }

    m_core->PostCheckReadMessage(__msg, RmiName_WhoAmI);

    if (m_enableNotifyCallFromStub && !m_internalUse) {
      ::Proud::String parameterString;

      NotifyCallFromStub(remote, (::Proud::RmiID)Rmi_WhoAmI, RmiName_WhoAmI,
                         parameterString);

#ifdef VIZAGENT
      m_core->Viz_NotifyRecvToStub(remote, (::Proud::RmiID)Rmi_WhoAmI,
                                   RmiName_WhoAmI, parameterString);
#endif
    } else if (!m_internalUse) {
#ifdef VIZAGENT
      m_core->Viz_NotifyRecvToStub(remote, (::Proud::RmiID)Rmi_WhoAmI,
                                   RmiName_WhoAmI, _PNT(""));
#endif
    }

    int64_t __t0 = 0;
    if (!m_internalUse && m_enableStubProfiling) {
      ::Proud::BeforeRmiSummary summary;
      summary.m_rmiID = (::Proud::RmiID)Rmi_WhoAmI;
      summary.m_rmiName = RmiName_WhoAmI;
      summary.m_hostID = remote;
      summary.m_hostTag = hostTag;
      BeforeRmiInvocation(summary);

      __t0 = ::Proud::GetPreciseCurrentTimeMs();
    }

    // Call this method.
    bool __ret = WhoAmI(remote, ctx);

    if (__ret == false) {
      // Error: RMI function that a user did not create has been called.
      m_core->ShowNotImplementedRmiWarning(RmiName_WhoAmI);
    }

    if (!m_internalUse && m_enableStubProfiling) {
      ::Proud::AfterRmiSummary summary;
      summary.m_rmiID = (::Proud::RmiID)Rmi_WhoAmI;
      summary.m_rmiName = RmiName_WhoAmI;
      summary.m_hostID = remote;
      summary.m_hostTag = hostTag;
      int64_t __t1;

      __t1 = ::Proud::GetPreciseCurrentTimeMs();

      summary.m_elapsedTime = (uint32_t)(__t1 - __t0);
      AfterRmiInvocation(summary);
    }
  } break;
  case Rmi_WhoYouAre: {
    ::Proud::RmiContext ctx;
    ctx.m_rmiID = __rmiID;
    ctx.m_sentFrom = pa.GetRemoteHostID();
    ctx.m_relayed = pa.IsRelayed();
    ctx.m_hostTag = hostTag;
    ctx.m_encryptMode = pa.GetEncryptMode();
    ctx.m_compressMode = pa.GetCompressMode();

    if (BeforeDeserialize(remote, ctx, __msg) == false) {
      // The user don't want to call the RMI function.
      // So, We fake that it has been already called.
      __msg.SetReadOffset(__msg.GetLength());
      return true;
    }

    int player_nth;
    __msg >> player_nth;
    m_core->PostCheckReadMessage(__msg, RmiName_WhoYouAre);

    if (m_enableNotifyCallFromStub && !m_internalUse) {
      ::Proud::String parameterString;

      ::Proud::AppendTextOut(parameterString, player_nth);

      NotifyCallFromStub(remote, (::Proud::RmiID)Rmi_WhoYouAre,
                         RmiName_WhoYouAre, parameterString);

#ifdef VIZAGENT
      m_core->Viz_NotifyRecvToStub(remote, (::Proud::RmiID)Rmi_WhoYouAre,
                                   RmiName_WhoYouAre, parameterString);
#endif
    } else if (!m_internalUse) {
#ifdef VIZAGENT
      m_core->Viz_NotifyRecvToStub(remote, (::Proud::RmiID)Rmi_WhoYouAre,
                                   RmiName_WhoYouAre, _PNT(""));
#endif
    }

    int64_t __t0 = 0;
    if (!m_internalUse && m_enableStubProfiling) {
      ::Proud::BeforeRmiSummary summary;
      summary.m_rmiID = (::Proud::RmiID)Rmi_WhoYouAre;
      summary.m_rmiName = RmiName_WhoYouAre;
      summary.m_hostID = remote;
      summary.m_hostTag = hostTag;
      BeforeRmiInvocation(summary);

      __t0 = ::Proud::GetPreciseCurrentTimeMs();
    }

    // Call this method.
    bool __ret = WhoYouAre(remote, ctx, player_nth);

    if (__ret == false) {
      // Error: RMI function that a user did not create has been called.
      m_core->ShowNotImplementedRmiWarning(RmiName_WhoYouAre);
    }

    if (!m_internalUse && m_enableStubProfiling) {
      ::Proud::AfterRmiSummary summary;
      summary.m_rmiID = (::Proud::RmiID)Rmi_WhoYouAre;
      summary.m_rmiName = RmiName_WhoYouAre;
      summary.m_hostID = remote;
      summary.m_hostTag = hostTag;
      int64_t __t1;

      __t1 = ::Proud::GetPreciseCurrentTimeMs();

      summary.m_elapsedTime = (uint32_t)(__t1 - __t0);
      AfterRmiInvocation(summary);
    }
  } break;
  default:
    goto __fail;
  }
  return true;
__fail : {
  __msg.SetReadOffset(orgReadOffset);
  return false;
}
}
#ifdef USE_RMI_NAME_STRING
const PNTCHAR *Stub::RmiName_SendItems = _PNT("SendItems");
#else
const PNTCHAR *Stub::RmiName_SendItems = _PNT("");
#endif
#ifdef USE_RMI_NAME_STRING
const PNTCHAR *Stub::RmiName_SendPlayer = _PNT("SendPlayer");
#else
const PNTCHAR *Stub::RmiName_SendPlayer = _PNT("");
#endif
#ifdef USE_RMI_NAME_STRING
const PNTCHAR *Stub::RmiName_Move = _PNT("Move");
#else
const PNTCHAR *Stub::RmiName_Move = _PNT("");
#endif
#ifdef USE_RMI_NAME_STRING
const PNTCHAR *Stub::RmiName_WhoAmI = _PNT("WhoAmI");
#else
const PNTCHAR *Stub::RmiName_WhoAmI = _PNT("");
#endif
#ifdef USE_RMI_NAME_STRING
const PNTCHAR *Stub::RmiName_WhoYouAre = _PNT("WhoYouAre");
#else
const PNTCHAR *Stub::RmiName_WhoYouAre = _PNT("");
#endif
const PNTCHAR *Stub::RmiName_First = RmiName_SendItems;

} // namespace TestGame
