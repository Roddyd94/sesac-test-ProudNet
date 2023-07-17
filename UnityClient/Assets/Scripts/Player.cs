using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.Logging;

public class Player : MonoBehaviour
{
    public int nth;
    public int posX;
    public int posY;
    public int points;
    public int centerX;
    public int centerY;

    public Player()
    {
        this.nth = -1;
        this.posX = 1;
        this.posY = 1;
        this.points = 0;
    }
    public Player(int nth)
    {
        this.nth = nth;
        this.posX = 1;
        this.posY = 1;
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

    public void SetPlayer(Player other)
    {
        this.nth = other.nth;
        this.posX = other.posX;
        this.posY = other.posY;
        this.points = other.points;
    }

    void Start()
    {

    }

    void Update()
    {
        this.transform.position = new Vector3(centerX + posX - 1, centerY + posY - 1, 0);
    }
}
