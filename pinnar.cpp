// pinnar.cpp : Defines the entry point for the console application.
// fr�n pinnar2

#include "stdafx.h"
#include "ragtest.h"
#include "pinnar.h"

#include <string>

using std::string;

/*****************************************************************
ANROP:   str = stickString(nbrSticks, stringWidth);
VERSION: xxx
UPPGIFT: Returnerar en str�ng av l�ngd stringWidth som illustrerar nbrSticks
         stycken t�ndstickor grupperade i "femh�gar". 
         Exempel:
         stickString(7, 30) blir  "||||| ||                      "
         stickString(25, 30) blir "||||| ||||| ||||| ||||| ||||| "

******************************************************************/
string stickString(int nbr, int length)
{

    // TODO implementera denna funktion
    // 
    return "||||| ||  ";
}

/*****************************************************************
ANROP:   playGame();
VERSION: xxxxx xx
UPPGIFT: L�ter anv�ndaren spela ett parti pinne mot datorn
******************************************************************/
void playGame()
{
   
// TODO: 
// Implementera! Dela g�rna upp den i flera funktioner s� att koden blir snygg
// och v�lstrukturerad.

// det �r ok att l�na koden fr�n gf�rel�sningen!

// det �r meningen att du skall anropa din egen  stickString funktion

}// playGame


void main()
{ setlocale( LC_ALL, "swedish");

  // TODO: �ndra till ditt eget namn och de sista 4 siffrorna i ditt personnummer
  ragnarsTest("Homer 1234");

  while (true)
  {
    playGame();
    cout << "Vill du spela mera?";
    string answ;
    cin >> answ;
    if (answ[0]!='j' && answ[0]!='J')
    {  
      cout << "Fegis!!" << endl;
      break;
    }     
  }
  system("pause");
}// main

