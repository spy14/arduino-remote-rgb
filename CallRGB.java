package com.sipterbalint.arduino;


import java.net.*;
import java.io.*;


class CallRGB
{

    private static final String IP="192.168.1.126";
    private static final int port=80;
 
     public static void main(String argv[]) throws Exception
     {
          String RGBColor;

 
          Socket clientSocket = new Socket(IP, port);
          DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());

 
          RGBColor = "000000000";
          outToServer.writeBytes(RGBColor+'\n');

          System.out.println(RGBColor+" sent\n");
          clientSocket.close();

     }
}