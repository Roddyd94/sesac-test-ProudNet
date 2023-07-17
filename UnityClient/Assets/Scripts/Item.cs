using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item : MonoBehaviour
{
    public enum ItemType : byte { COIN = (byte)'$' };
    public ItemType type;
    public uint scale;
    public int posX;
    public int posY;
    public Item() : this(0, 0)
    {

    }
    public Item(int x, int y) : this(ItemType.COIN, 1, x, y)
    {

    }
    public Item(ItemType type, uint scale, int x, int y)
    {
        this.type = type;
        this.scale = scale;
        this.posX = x;
        this.posY = y;
    }

    public override string ToString()
    {
        return string.Format("Item: {0} [{1},{2}], {3}", type, posX, posY, scale);
    }

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }
}
