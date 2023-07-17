using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.Logging;

public class GameManager : MonoBehaviour
{
    public Player playerPrefab;
    public Item itemPrefab;
    private int myPlayerNth;
    private Player[] players;
    private HashSet<Item>[] playerItemHashSetArray;
    // Start is called before the first frame update
    public void SetPlayer(int player_nth, Player player)
    {
        Log.Info(player);
        players[player_nth].SetPlayer(player);

        Log.Info(players[player_nth]);
    }
    public void SetPlayerItems(int player_nth, HashSet<Item> playerItemHashSet)
    {
        playerItemHashSetArray[player_nth].Clear();
        foreach (var item in playerItemHashSet)
        {
            playerItemHashSetArray[player_nth].Add(
                Instantiate<Item>(item, new Vector2(), Quaternion.identity)
            );
        }
    }
    public Player GetPlayer(int player_nth)
    {
        return players[player_nth];
    }
    public HashSet<Item> GetPlayerItems(int player_nth)
    {
        return playerItemHashSetArray[player_nth];
    }
    public void SetPlayerNth(int player_nth)
    {
        myPlayerNth = player_nth;
        
    }
    public int GetPlayerNth(int player_nth)
    {
        return myPlayerNth;
    }
    void Start()
    {
        players = new Player[2];
        playerItemHashSetArray = new HashSet<Item>[2];
        players[0] = Instantiate(playerPrefab, new Vector2(-4, 3), Quaternion.identity);
        players[1] = Instantiate(playerPrefab, new Vector2(4, 3), Quaternion.identity);
    }
    void Update()
    {

    }
}
