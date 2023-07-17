using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TestGame;
using Nettention.Proud;

public class TestKeyboard : MonoBehaviour
{
    private bool keyboardOn = false;
    public GameClient client;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (!keyboardOn)
            StartCoroutine(pressKeyRoutine());

    }
    IEnumerator pressKeyRoutine()
    {
        keyboardOn = true;

        if (Input.GetKey(KeyCode.W))
            client.CallClientMove((byte)'w');
        if (Input.GetKey(KeyCode.S))
            client.CallClientMove((byte)'s');
        if (Input.GetKey(KeyCode.A))
            client.CallClientMove((byte)'a');
        if (Input.GetKey(KeyCode.D))
            client.CallClientMove((byte)'d');

        yield return new WaitForSeconds(0.1f);

        keyboardOn = false;
    }
}
