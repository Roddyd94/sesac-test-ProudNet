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
    // Start is called before the first frame update
    public void SetPlayerNth(int player_nth, Player player)
    {
        Log.Info(player);

        if (players[player_nth] == null) {
            players[player_nth] = Instantiate(playerPrefab, new Vector2(0, 0), Quaternion.identity);

            if (player_nth == 0)
            {
                players[player_nth].centerX = -4;
                players[player_nth].centerY = 3;
            }
            else if (player_nth == 1)
            {
                players[player_nth].centerX = 4;
                players[player_nth].centerY = 3;
            }
        }
        players[player_nth].SetPlayer(player);

        Log.Info(players[player_nth]);
    }
    public void SetPlayerItems(int player_nth, HashSet<Item> playerItemHashSet)
    {
        foreach (var itemPrefab in Object.FindObjectsOfType<Item>())
        {
            Destroy(itemPrefab.gameObject);
        }

        foreach (var item in playerItemHashSet)
        {
            Item new_item = Instantiate(itemPrefab, new Vector2(0, 0), Quaternion.identity);
            new_item.SetItem(item);

            if (player_nth == 0)
            {
                new_item.centerX = -4;
                new_item.centerY = 3;
            }
            else if (player_nth == 1)
            {
                new_item.centerX = 4;
                new_item.centerY = 3;
            }
        }
    }
    public Player GetPlayer(int player_nth)
    {
        return players[player_nth];
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
    }
    void Update()
    {

    }
}
