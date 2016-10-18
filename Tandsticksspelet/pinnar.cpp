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

// Denna behövs egentligen inte. Har flyttat den till min klass StickGame, men ragtest vill ha den här.
string stickString(int nbr, int length){
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

class StickGame{
public:
	StickGame(int startSticks):
		_startStickPile(startSticks),
		_stickPile(_startStickPile){}
	string stickString(int nbr, int length){
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

	int getMove(){
		int myMove = 0;
		while (myMove < 1 || myMove > 2){
			cin.clear();
			fflush(stdin);
			cin >> myMove;
			if (myMove < 1 || myMove > 2){
				cout << "Du måste plocka 1 eller 2 stickor" << endl;
			}
		}
		return myMove;
	}

	int computerMove(){
		if (_stickPile <= 0){
			return 0;
		}
		if (_stickPile <= 2){
			return _stickPile;
		}
		return (1 + rand() % 2);
	}

	void run(){
		while (_stickPile > 0){
			cout << "Aktuell hög: ";
			cout << stickString(_stickPile, 32);
			cout << "Hur många vill du plocka?";
			int userMove = getMove();
			_stickPile -= userMove;
			if (_stickPile <= 0){
				cout << "Du vann, turgubbe!" << endl;
				break;
			}
			int myMove = computerMove();
			cout << "Jag tar " << myMove << endl;
			_stickPile -= myMove;
			if (_stickPile <= 0){
				cout << "Jag vann, looooser!!" << endl;
				break;
			}
		}
	}

private:
	int _startStickPile;
	int _stickPile;
};

/*****************************************************************
ANROP:   playGame();
VERSION: xxxxx xx
UPPGIFT: Låter användaren spela ett parti pinne mot datorn
******************************************************************/
void playGame()
{
	StickGame game(15 + rand() % 11);
	game.run();
}


void main()
{ setlocale( LC_ALL, "swedish");

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

