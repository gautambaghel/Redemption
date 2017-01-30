#pragma once
#include <string>
#include "Scene.h"
#include "Player.h"

using std::string;
class Game
{
	bool loseCondn = true;
	string input,noun,name;
	int curScene =1;
	int prevScene = 1;
	Scene s;
	Player p;
	bool finalStage = false;
	bool medTrap = true;
	bool finalTrap = false;
	bool win = false;

public:
	Game();
	void GameLoop();
	void ParseInput();
	bool foundInSentence(string input, string verb);
	void ChangeSceneIfPossible(string input, int& curScene);
	bool CheckCode();
	void OnlyCave(string str, int& curScene);
	void GenerateOutput();
	void TalkIfPossible(string str, int curScene);
	void SetName(string name);
	void SetPlayer(Player pl);
	void KillIfPossible(string input, int curScene);
	bool CheckHasItem(string item);
	bool HasUsedItem(string item);
	bool GetWin();
	void ExamineIfPossible(string input, int curScene);
	void ActivateIfPossible(string input, int curScene);
	void TakeIfPossible(string input, int curScene);
	void UseIfPossible(string input, int curScene);
	~Game();
};

