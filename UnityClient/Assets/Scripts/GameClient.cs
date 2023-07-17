using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.Logging;
using Nettention.Proud;
using TestGame;

public class GameClient : MonoBehaviour
{
    NetClient netClient;
    NetConnectionParam param;
    Proxy proxy;
    Stub stub;
    bool connected = false;
    HostID groupHostID = HostID.HostID_None;
    public GameManager gameManager;

    // Start is called before the first frame update
    void Start()
    {
        netClient = new NetClient();
        proxy = new Proxy();
        stub = new Stub();

        netClient.JoinServerCompleteHandler = (ErrorInfo info, ByteArray replyFromServer) =>
        {
            if (info.errorType == ErrorType.Ok)
            {
                connected = true;
            }
            proxy.WhoAmI(HostID.HostID_Server, RmiContext.FastEncryptedReliableSend);
        };

        netClient.LeaveServerHandler = (ErrorInfo info) =>
        {
            connected = false;
        };

        netClient.P2PMemberJoinHandler = (HostID memberHostID, HostID groupHostID, int memberCount, ByteArray customField) =>
        {
            this.groupHostID = groupHostID;
            Log.Debug(string.Format("join P2P group {0}.", this.groupHostID));
        };

        netClient.P2PMemberLeaveHandler = (HostID memberHostID, HostID groupHostID, int memberCount) =>
        {

            Log.Debug(string.Format("leave P2P group {0}.", this.groupHostID));
            this.groupHostID = HostID.HostID_None;
        };

        stub.SendItemSet = (HostID remote, RmiContext rmiContext, int player_nth, HashSet<Item> item_set) =>
        {
            Log.Debug(string.Format("SendItemSet"));
            gameManager.SetPlayerItems(player_nth, item_set);
            return true;
        };

        stub.SendPlayer = (HostID remote, RmiContext rmiContext, int player_nth, Player player) =>
        {
            Log.Debug(string.Format("SendPlayer"));
            gameManager.SetPlayerNth(player_nth, player);
            return true;
        };

        stub.WhoYouAre = (HostID remote, RmiContext rmiContext, int player_nth) =>
        {
            Log.Debug(string.Format("WhoYouAre"));
            gameManager.SetPlayerNth(player_nth);
            return true;
        };

        netClient.AttachProxy(proxy);
        netClient.AttachStub(stub);

        param = new NetConnectionParam();
        param.protocolVersion.Set(new System.Guid("{0x489fa1cc,0x5df3,0x4581,{0x96,0x56,0x4d,0x71,0xae,0xc8,0x34,0xf1}}"));
        param.serverPort = 33334;
        param.serverIP = "127.0.0.1";

        if (netClient.Connect(param) == false) Log.Error(string.Format("Failed to connect to server."));
    }

    

    // Update is called once per frame
    void Update()
    {
        // FrameMove를 호출하지 않으면 Stub을 처리하지 못한답니다.
        netClient.FrameMove();
    }

    public void CallClientMove(byte key)
    {
        proxy.Move(HostID.HostID_Server, RmiContext.SecureReliableSend, key);
    }

    public NetClient GetClient()
    {
        return netClient;
    }
}
