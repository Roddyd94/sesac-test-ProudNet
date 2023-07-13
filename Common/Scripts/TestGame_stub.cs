﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
using System.Net;	     

namespace TestGame
{
	internal class Stub:Nettention.Proud.RmiStub
	{
public AfterRmiInvocationDelegate AfterRmiInvocation = delegate(Nettention.Proud.AfterRmiSummary summary) {};
public BeforeRmiInvocationDelegate BeforeRmiInvocation = delegate(Nettention.Proud.BeforeRmiSummary summary) {};

		public delegate bool SendItemSetDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int player_nth, std.set<Item> item_set);  
		public SendItemSetDelegate SendItemSet = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int player_nth, std.set<Item> item_set)
		{ 
			return false;
		};
		public delegate bool SendPlayerDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int player_nth, Player player);  
		public SendPlayerDelegate SendPlayer = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int player_nth, Player player)
		{ 
			return false;
		};
		public delegate bool MoveDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int8_t key);  
		public MoveDelegate Move = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int8_t key)
		{ 
			return false;
		};
		public delegate bool WhoAmIDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext);  
		public WhoAmIDelegate WhoAmI = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext)
		{ 
			return false;
		};
		public delegate bool WhoYouAreDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int player_nth);  
		public WhoYouAreDelegate WhoYouAre = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int player_nth)
		{ 
			return false;
		};
	public override bool ProcessReceivedMessage(Nettention.Proud.ReceivedMessage pa, Object hostTag) 
	{
		Nettention.Proud.HostID remote=pa.RemoteHostID;
		if(remote==Nettention.Proud.HostID.HostID_None)
		{
			ShowUnknownHostIDWarning(remote);
		}

		Nettention.Proud.Message __msg=pa.ReadOnlyMessage;
		int orgReadOffset = __msg.ReadOffset;
        Nettention.Proud.RmiID __rmiID = Nettention.Proud.RmiID.RmiID_None;
        if (!__msg.Read( out __rmiID))
            goto __fail;
					
		switch(__rmiID)
		{
        case Common.SendItemSet:
            ProcessReceivedMessage_SendItemSet(__msg, pa, hostTag, remote);
            break;
        case Common.SendPlayer:
            ProcessReceivedMessage_SendPlayer(__msg, pa, hostTag, remote);
            break;
        case Common.Move:
            ProcessReceivedMessage_Move(__msg, pa, hostTag, remote);
            break;
        case Common.WhoAmI:
            ProcessReceivedMessage_WhoAmI(__msg, pa, hostTag, remote);
            break;
        case Common.WhoYouAre:
            ProcessReceivedMessage_WhoYouAre(__msg, pa, hostTag, remote);
            break;
		default:
			 goto __fail;
		}
		return true;
__fail:
	  {
			__msg.ReadOffset = orgReadOffset;
			return false;
	  }
	}
    void ProcessReceivedMessage_SendItemSet(Nettention.Proud.Message __msg, Nettention.Proud.ReceivedMessage pa, Object hostTag, Nettention.Proud.HostID remote)
    {
        Nettention.Proud.RmiContext ctx = new Nettention.Proud.RmiContext();
        ctx.sentFrom=pa.RemoteHostID;
        ctx.relayed=pa.IsRelayed;
        ctx.hostTag=hostTag;
        ctx.encryptMode = pa.EncryptMode;
        ctx.compressMode = pa.CompressMode;

        int player_nth; Nettention.Proud.Marshaler.Read(__msg,out player_nth);	
std.set<Item> item_set; Nettention.Proud.Marshaler.Read(__msg,out item_set);	
core.PostCheckReadMessage(__msg, RmiName_SendItemSet);
        if(enableNotifyCallFromStub==true)
        {
        string parameterString = "";
        parameterString+=player_nth.ToString()+",";
parameterString+=item_set.ToString()+",";
        NotifyCallFromStub(Common.SendItemSet, RmiName_SendItemSet,parameterString);
        }

        if(enableStubProfiling)
        {
        Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
        summary.rmiID = Common.SendItemSet;
        summary.rmiName = RmiName_SendItemSet;
        summary.hostID = remote;
        summary.hostTag = hostTag;
        BeforeRmiInvocation(summary);
        }

        long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();

        // Call this method.
        bool __ret =SendItemSet (remote,ctx , player_nth, item_set );

        if(__ret==false)
        {
        // Error: RMI function that a user did not create has been called. 
        core.ShowNotImplementedRmiWarning(RmiName_SendItemSet);
        }

        if(enableStubProfiling)
        {
        Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
        summary.rmiID = Common.SendItemSet;
        summary.rmiName = RmiName_SendItemSet;
        summary.hostID = remote;
        summary.hostTag = hostTag;
        summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
        AfterRmiInvocation(summary);
        }
    }
    void ProcessReceivedMessage_SendPlayer(Nettention.Proud.Message __msg, Nettention.Proud.ReceivedMessage pa, Object hostTag, Nettention.Proud.HostID remote)
    {
        Nettention.Proud.RmiContext ctx = new Nettention.Proud.RmiContext();
        ctx.sentFrom=pa.RemoteHostID;
        ctx.relayed=pa.IsRelayed;
        ctx.hostTag=hostTag;
        ctx.encryptMode = pa.EncryptMode;
        ctx.compressMode = pa.CompressMode;

        int player_nth; Nettention.Proud.Marshaler.Read(__msg,out player_nth);	
Player player; Nettention.Proud.Marshaler.Read(__msg,out player);	
core.PostCheckReadMessage(__msg, RmiName_SendPlayer);
        if(enableNotifyCallFromStub==true)
        {
        string parameterString = "";
        parameterString+=player_nth.ToString()+",";
parameterString+=player.ToString()+",";
        NotifyCallFromStub(Common.SendPlayer, RmiName_SendPlayer,parameterString);
        }

        if(enableStubProfiling)
        {
        Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
        summary.rmiID = Common.SendPlayer;
        summary.rmiName = RmiName_SendPlayer;
        summary.hostID = remote;
        summary.hostTag = hostTag;
        BeforeRmiInvocation(summary);
        }

        long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();

        // Call this method.
        bool __ret =SendPlayer (remote,ctx , player_nth, player );

        if(__ret==false)
        {
        // Error: RMI function that a user did not create has been called. 
        core.ShowNotImplementedRmiWarning(RmiName_SendPlayer);
        }

        if(enableStubProfiling)
        {
        Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
        summary.rmiID = Common.SendPlayer;
        summary.rmiName = RmiName_SendPlayer;
        summary.hostID = remote;
        summary.hostTag = hostTag;
        summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
        AfterRmiInvocation(summary);
        }
    }
    void ProcessReceivedMessage_Move(Nettention.Proud.Message __msg, Nettention.Proud.ReceivedMessage pa, Object hostTag, Nettention.Proud.HostID remote)
    {
        Nettention.Proud.RmiContext ctx = new Nettention.Proud.RmiContext();
        ctx.sentFrom=pa.RemoteHostID;
        ctx.relayed=pa.IsRelayed;
        ctx.hostTag=hostTag;
        ctx.encryptMode = pa.EncryptMode;
        ctx.compressMode = pa.CompressMode;

        int8_t key; Nettention.Proud.Marshaler.Read(__msg,out key);	
core.PostCheckReadMessage(__msg, RmiName_Move);
        if(enableNotifyCallFromStub==true)
        {
        string parameterString = "";
        parameterString+=key.ToString()+",";
        NotifyCallFromStub(Common.Move, RmiName_Move,parameterString);
        }

        if(enableStubProfiling)
        {
        Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
        summary.rmiID = Common.Move;
        summary.rmiName = RmiName_Move;
        summary.hostID = remote;
        summary.hostTag = hostTag;
        BeforeRmiInvocation(summary);
        }

        long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();

        // Call this method.
        bool __ret =Move (remote,ctx , key );

        if(__ret==false)
        {
        // Error: RMI function that a user did not create has been called. 
        core.ShowNotImplementedRmiWarning(RmiName_Move);
        }

        if(enableStubProfiling)
        {
        Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
        summary.rmiID = Common.Move;
        summary.rmiName = RmiName_Move;
        summary.hostID = remote;
        summary.hostTag = hostTag;
        summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
        AfterRmiInvocation(summary);
        }
    }
    void ProcessReceivedMessage_WhoAmI(Nettention.Proud.Message __msg, Nettention.Proud.ReceivedMessage pa, Object hostTag, Nettention.Proud.HostID remote)
    {
        Nettention.Proud.RmiContext ctx = new Nettention.Proud.RmiContext();
        ctx.sentFrom=pa.RemoteHostID;
        ctx.relayed=pa.IsRelayed;
        ctx.hostTag=hostTag;
        ctx.encryptMode = pa.EncryptMode;
        ctx.compressMode = pa.CompressMode;

        core.PostCheckReadMessage(__msg, RmiName_WhoAmI);
        if(enableNotifyCallFromStub==true)
        {
        string parameterString = "";
                NotifyCallFromStub(Common.WhoAmI, RmiName_WhoAmI,parameterString);
        }

        if(enableStubProfiling)
        {
        Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
        summary.rmiID = Common.WhoAmI;
        summary.rmiName = RmiName_WhoAmI;
        summary.hostID = remote;
        summary.hostTag = hostTag;
        BeforeRmiInvocation(summary);
        }

        long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();

        // Call this method.
        bool __ret =WhoAmI (remote,ctx  );

        if(__ret==false)
        {
        // Error: RMI function that a user did not create has been called. 
        core.ShowNotImplementedRmiWarning(RmiName_WhoAmI);
        }

        if(enableStubProfiling)
        {
        Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
        summary.rmiID = Common.WhoAmI;
        summary.rmiName = RmiName_WhoAmI;
        summary.hostID = remote;
        summary.hostTag = hostTag;
        summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
        AfterRmiInvocation(summary);
        }
    }
    void ProcessReceivedMessage_WhoYouAre(Nettention.Proud.Message __msg, Nettention.Proud.ReceivedMessage pa, Object hostTag, Nettention.Proud.HostID remote)
    {
        Nettention.Proud.RmiContext ctx = new Nettention.Proud.RmiContext();
        ctx.sentFrom=pa.RemoteHostID;
        ctx.relayed=pa.IsRelayed;
        ctx.hostTag=hostTag;
        ctx.encryptMode = pa.EncryptMode;
        ctx.compressMode = pa.CompressMode;

        int player_nth; Nettention.Proud.Marshaler.Read(__msg,out player_nth);	
core.PostCheckReadMessage(__msg, RmiName_WhoYouAre);
        if(enableNotifyCallFromStub==true)
        {
        string parameterString = "";
        parameterString+=player_nth.ToString()+",";
        NotifyCallFromStub(Common.WhoYouAre, RmiName_WhoYouAre,parameterString);
        }

        if(enableStubProfiling)
        {
        Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
        summary.rmiID = Common.WhoYouAre;
        summary.rmiName = RmiName_WhoYouAre;
        summary.hostID = remote;
        summary.hostTag = hostTag;
        BeforeRmiInvocation(summary);
        }

        long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();

        // Call this method.
        bool __ret =WhoYouAre (remote,ctx , player_nth );

        if(__ret==false)
        {
        // Error: RMI function that a user did not create has been called. 
        core.ShowNotImplementedRmiWarning(RmiName_WhoYouAre);
        }

        if(enableStubProfiling)
        {
        Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
        summary.rmiID = Common.WhoYouAre;
        summary.rmiName = RmiName_WhoYouAre;
        summary.hostID = remote;
        summary.hostTag = hostTag;
        summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
        AfterRmiInvocation(summary);
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

		public override Nettention.Proud.RmiID[] GetRmiIDList { get{return Common.RmiIDList;} }
		
	}
}

