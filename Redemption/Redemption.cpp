// Redemption.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include <iostream>
#include <string>
#include "Redemption.h"

using namespace std;

int main()
{
	char a;
	cout << "                         REDEMPTION\n\n\n";
	string name, lastStr;
	cout << "What is your name saviour ?\n";
	std::getline(std::cin, name);

	cout << "Welcome, " << name <<"\n";
	Player p(name,100,50);
	
	Scene s;
	std::cout << s.CurrentScene(0);
	std::cout << s.CurrentScene(1);
	Game g;
	g.SetName(name);
	g.SetPlayer(p);
	g.GameLoop();

	if (g.GetWin()) {

		cout << "GREAT JOB!\n ";
		cin >> lastStr;
	}

	else {
		std::cout << "REPEAT? (y/n)\n";
		std::cin >> a;

		if (a == 'y') {
			system("CLS");
			main();
		}
		else
			exit;
	}
    return 0;
}

