using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.Logging;

public class Player : MonoBehaviour
{
    private static int centerX = 1;
    private static int centerY = 1;
    public int nth;
    public int posX;
    public int posY;
    public int points;
    public Player()
    {
        this.nth = -1;
        this.posX = centerX;
        this.posY = centerY;
        this.points = 0;
    }
    public Player(int nth)
    {
        this.nth = nth;
        this.posX = centerX;
        this.posY = centerY;
        this.points = 0;
    }
    public Player(Player player) {
        this.nth = player.nth;
        this.posX = player.posX;
        this.posY = player.posY;
        this.points = player.points;
    }
    public override string ToString()
    {
        return string.Format("Player {0} - pos=[{1},{2}], points={3}", nth, posX, posY, points);
    }
    public void SetPlayer(Player player)
    {
        this.nth = player.nth;
        this.posX = player.posX;
        this.posY = player.posY;
        this.points = player.points;
    }
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (nth == 0)
        {
            transform.position = new Vector3(-4 + posX, 3 + posY, 0);
        }else if (nth == 1)
        {
            transform.position = new Vector3(4 + posX, 3 + posY, 0);
        }
    }
}
