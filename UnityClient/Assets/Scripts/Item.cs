using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item : MonoBehaviour
{
    public int type;
    public int scale;
    public int posX;
    public int posY;
    public int centerX;
    public int centerY;
    public Item() : this(0, 0)
    {

    }
    public Item(Item other)
    {
        this.type = other.type;
        this.posX = other.posX;
        this.posY = other.posY;
        this.scale = other.scale;
    }
    public Item(int x, int y) : this((int)'@', 1, x, y)
    {

    }
    public Item(int type, int scale, int x, int y)
    {
        this.type = type;
        this.posX = x;
        this.posY = y;
        this.scale = scale;
    }

    public void SetItem(Item other)
    {
        this.type = other.type;
        this.posX = other.posX;
        this.posY = other.posY;
        this.scale = other.scale;
    }

    public void SetCenterXY(int playerNth)
    {
        if (playerNth == 0)
        {
            centerX = -4;
            centerY = 3;
        }
        else if (playerNth == 1)
        {
            centerX = 4;
            centerY = 3;
        }
    }

    public override string ToString()
    {
        return string.Format("Item: {0} [{1},{2}], {3}", (char)type, posX, posY, scale);
    }

    public override bool Equals(object obj)
    {
        if (this == obj) return true;
        if (obj == null || obj is not Item)
            return false;
        Item other = obj as Item;

        return this.type == other.type
            && this.posX == other.posX
            && this.posY == other.posY
            && this.scale == other.scale;
    }

    public override int GetHashCode()
    {
        int result;
        int c;
        
        c = this.type.GetHashCode();
        result = c;

        c = this.posX.GetHashCode();
        result = 31 * result + c;

        c = this.posY.GetHashCode();
        result = 31 * result + c;

        c = this.scale.GetHashCode();
        result = 31 * result + c;

        return result;
    }

    void Start()
    {
        
    }

    void Update()
    {
        this.transform.position = new Vector3(centerX + posX - 1, centerY + posY - 1, 0);
    }
}
