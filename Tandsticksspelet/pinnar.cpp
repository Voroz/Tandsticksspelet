// pinnar.cpp : Defines the entry point for the console application.
// från pinnar2

#include "stdafx.h"
#include "ragtest.h"
#include "pinnar.h"

#include <string>

using std::string;


string stringRepeat(string str, int amount){
	string repeatedStr = "";
	for (int i = 0; i < amount; i++){
		repeatedStr += str;
	}
	return repeatedStr;
}

/*****************************************************************
ANROP:   str = stickString(nbrSticks, stringWidth);
VERSION: xxx
UPPGIFT: Returnerar en sträng av längd stringWidth som illustrerar nbrSticks
         stycken tändstickor grupperade i "femhögar". 
         Exempel:
         stickString(7, 30) blir  "||||| ||                      "
         stickString(25, 30) blir "||||| ||||| ||||| ||||| ||||| "

******************************************************************/
string stickString(int nbr, int length)
{
	string stickStr = "";
	for (int i = 0; i < nbr; i++){
		if (i % 5 == 4){
			stickStr += "| ";
			continue;
		}
		stickStr += '|';
	}
	stickStr += stringRepeat(" ", length - stickStr.length());
    return stickStr;
}

/*****************************************************************
ANROP:   playGame();
VERSION: xxxxx xx
UPPGIFT: Låter användaren spela ett parti pinne mot datorn
******************************************************************/
void playGame()
{
	cout << stickString(20, 30) << "test" << endl;
	cout << stickString(7, 30) << "test" << endl;
	cout << stickString(16, 30) << "test" << endl;
// TODO: 
// Implementera! Dela gärna upp den i flera funktioner så att koden blir snygg
// och välstrukturerad.

// det är ok att låna koden från gföreläsningen!

// det är meningen att du skall anropa din egen  stickString funktion

}// playGame


void main()
{ setlocale( LC_ALL, "swedish");

  // TODO: Ändra till ditt eget namn och de sista 4 siffrorna i ditt personnummer
  ragnarsTest("Jonny 2472");

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

