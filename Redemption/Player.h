#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Player
{
	string name;
	int health;
	int respect;
	vector<string> inventory;
	vector<string> usedItems;

public:
	Player();
	Player(std::string name,int health,int respect);
	~Player();
	std::string GetName();
	std::vector<string> GetInventory();
	std::vector<string> GetUsedItems();
	void AddItemsToInventory(string item);
	void IncrementRespect(int amt);
	void DecrementHealth(int amt);
	void AddItemsToUsed(string item);
	int GetRespect();
	int GetHealth();
};

#endif