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
    private HashSet<Item>[] itemSetArray;
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
        List<Item> items_to_delete = new List<Item>();
        foreach (var item in itemSetArray[player_nth])
        {
            items_to_delete.Add(item);
        }

        while (items_to_delete.Count > 0)
        {
            Item item = items_to_delete[items_to_delete.Count - 1];
            items_to_delete.RemoveAt(items_to_delete.Count - 1);
            Destroy(item.gameObject);
        }

        itemSetArray[player_nth] = new HashSet<Item>();

        foreach (var item in playerItemHashSet)
        {
            Item new_item = Instantiate(itemPrefab, new Vector2(0, 0), Quaternion.identity);
            
            new_item.SetItem(item);
            new_item.SetCenterXY(player_nth);

            itemSetArray[player_nth].Add(new_item);
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
        itemSetArray = new HashSet<Item>[2];

        itemSetArray[0] = new HashSet<Item>();
        itemSetArray[1] = new HashSet<Item>();
    }
    void Update()
    {

    }
}
