#include "stdafx.h"
#include "Player.h"
#include <string>


Player::Player(std::string n, int h, int r)
{
	name = n;
	health = h;
	respect = r;
}

Player::Player()
{
}

Player::~Player()
{
}

std::string Player::GetName()
{
	return name;
}

std::vector<string> Player::GetInventory()
{
	return inventory;
}

std::vector<string> Player::GetUsedItems()
{
	return usedItems;
}

void Player::AddItemsToInventory(string item)
{
	inventory.push_back(item);
}

void Player::IncrementRespect(int amt)
{
	respect = respect + amt;
}

void Player::DecrementHealth(int amt)
{
	health = health - amt;
}

void Player::AddItemsToUsed(string item)
{
	usedItems.push_back(item);
}

int Player::GetRespect()
{
	return respect;
}

int Player::GetHealth()
{
	return health;
}
