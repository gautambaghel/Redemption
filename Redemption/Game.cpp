#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <string>
#include "Scene.h"

using std::string;

Game::Game()
{
}

void Game::GameLoop() {

	while (loseCondn) {
		ParseInput();
		GenerateOutput();
	}
}

void Game::ParseInput()
{

	//std::cout << "Your action : ";
	std::getline(std::cin, input);

	//handling exception for command with no spaces
	if (foundInSentence(input," ")) {
		int temp = input.find_last_of(" ");
		int temp2 = input.length();
		noun = input.substr((temp+1), (temp2 - 2));
	}
	else noun = "next";
	 
	if (foundInSentence(input,"go to")) 
	{
		ChangeSceneIfPossible(noun,curScene);
	}
	
	else if (foundInSentence(input, "talk to") || foundInSentence(input,"talk with")) {
		TalkIfPossible(noun,curScene);
	}
	
	else if (foundInSentence(input, "shoot") || foundInSentence(input, "kill")) {
		KillIfPossible(noun, curScene);
	}
	
	else if(foundInSentence(input, "look") || foundInSentence(input, "inspect") || foundInSentence(input, "examine")) {
		ExamineIfPossible(noun, curScene);
	}

	else if (foundInSentence(input, "take") || foundInSentence(input, "pick up") || foundInSentence(input, "pick")) {
		TakeIfPossible(noun, curScene);
	}
	
	else if (foundInSentence(input, "press") || foundInSentence(input,"activate")) {
		ActivateIfPossible(noun, curScene);
	}
	else if (foundInSentence(input, "use")) {
		UseIfPossible(noun, curScene);
	} 
	else if (input == "");
	else std::cout << "I do not understand the command\n";

}

bool Game::foundInSentence(string input, string verb)
{
	if (input.find(verb) != std::string::npos)
		return true;
	else
	    return false;
}

void Game::ChangeSceneIfPossible(string input, int & curScene)
{
	switch (curScene) {
	case 1:
		if (input == "gate") {
			std::cout << "You entered the tunnels.\n";
			curScene = 2;
		}
		else std::cout << "Did not understand after go to \n";
		break;

	case 2:
		if (input == "cave") {
			std::cout << "You entered the cave again. \n";
			curScene = 1;
			break;

		}

		// EQUIP FLASHLIGHT FLAG 
		if (!HasUsedItem("flashlight")) {
			// DIE
			loseCondn = false;
			std::cout << " !!! YOU DIED !!! : walking into the dark tunnel and fell into deep pit. \n";
			break;
		}

		if (input == "tower") {
			if (!CheckCode()) break;
			std::cout << "You've arrived at the radio tower \n";
			curScene = 3;
		}
		else if (input == "forest") {
			if (!CheckCode()) break;
			std::cout << "You've arrived at the forest \n";
			curScene = 4;
		}
		else if (input == "warehouse") {
			if (!CheckCode()) break;
			std::cout << "You've arrived at the warehouse \n";
			curScene = 5;
		}
		else if (input == "hospital") {
			if (!CheckCode()) break;
			std::cout << "You've arrived at the hospital \n";
			curScene = 6;
		}
		else if (input == "lab") {
			if (!CheckCode()) break;
			std::cout << "You've arrived at the lab \n";
			curScene = 7;
		}
		else std::cout << "I do not understand the command \n";
		break;

	case 3:
		if (input == "cave") {
			std::cout << "You entered the cave again. \n";
			curScene = 1;
			break;
		}

		if (finalStage) 
		  if (input.compare("hq") == 0) {
			std::cout << "You've arrived at the machine hq \n";
			curScene = 8;
		}break;
	case 4: OnlyCave(input, curScene); break;
	case 5: OnlyCave(input, curScene); 
		if (input == "hospital") {
			std::cout << "You've arrived at the hospital \n";
			curScene = 6;
		}
		else if (input == "tower") {
			std::cout << "You've arrived at the radio tower \n";
			curScene = 3;
		}
		else std::cout << "Did not understand after go to \n";
			
			break;
	case 6: OnlyCave(input, curScene); break;
	case 7: OnlyCave(input, curScene); break;
	default: std::cout << "Going there not possible \n";
	}
}

bool Game::CheckCode()
{
	int code;
	std::cout << "To get out of tunnels you must take a route\n";
	std::cout << "Try using a route code \n";
	scanf_s("%i",&code);
	if (code == 7411) return true;
	else {
		//DIE
		std::cout << " !!! YOU DIED !!! : You were lost in the tunnels and eventually died of hunger and thirst. \n";
		loseCondn = false;
		return false;
	}
}

void Game::OnlyCave(string input,int& curScene)
{
	if (input == "cave") {
		std::cout << "You entered the cave again. \n";
		curScene = 1;
	}
	else std::cout << "Did not understand after go to \n";
}

void Game::GenerateOutput()
{
	if (curScene != prevScene && loseCondn != false)
		std::cout << s.CurrentScene(curScene) << "\n";
	prevScene = curScene;

	if (p.GetHealth() <= 0) {
	//DIE
	loseCondn = false;
	std::cout << " !!! YOU DIED !!! : Your health turned 0. \n";
  }
}
void Game::TalkIfPossible(string str, int curScene)
{
	switch (curScene) {
	case 1: 
		if (str == "charles" || str == "meera") {
			std::cout << "Hi " << p.GetName() << "\n";
			std::cout << "Here's what you need to know. You can visit forest, warehouse, lab , tower and hospital "
				"after leaving here.\nBut for prevention from robot scouts we have specific route which leads to "
				"the passage outside.\nThe route is 7411. Also Meera is really sick, you have to help her.\n"
				"You can commence attack from the radio tower once you have resources\n\n";

			if (CheckHasItem("medicine")) {
				std::cout << "You gave medicine to Meera and gained everyone's respect \n";
				p.IncrementRespect(20);
			}
		}
		else std::cout << "Did not understand after talk \n";
		break;
	case 7: 
		if (str == "sam") {
			std::cout << "Hi I am Sam! \n \n";
		}
		else if (str == "richard") {
			// COMMENT ON VIRUS
			std::cout << "I have the solution , I've found it! Here take this virus and \n"
				         "plug it into machine HQ's mainframe, godspeed! \n.";
			p.AddItemsToInventory("virus");
		}
		else std::cout << "Did not understand after talk \n";
		break;
	default: std::cout << "No one to talk to \n";
	}
}
void Game::SetName(string n)
{
	name = n;
}
void Game::SetPlayer(Player pl)
{
	p = pl;
}
void Game::KillIfPossible(string input, int curScene)
{
	if (CheckHasItem("guns")) {
		switch (curScene) {
		case 4: 
			if (input == "rabbit") {
				std::cout << "You shot the rabbit and gathered food.\n";
				p.IncrementRespect(10);
			}
			else
				std::cout << "Did not understand after shoot\n";
			break;
		case 8: 
			if (input == "robot"|| input == "soldiers") {
				std::cout << "You shot and killed the robots.\n";
				//OKAY TO UPLOAD VIRUS FLAG
				finalTrap = true;
			}
			else
				std::cout << "Did not understand after shoot\n" ;
				break;
		default: std::cout << "Nothing as such to shoot at. \n";
		}
	}
	else std::cout << "You don't have any guns!\n";

}


bool Game::CheckHasItem(string item) {

	vector<string> inv = p.GetInventory();

	for (int i = 0; i < inv.size(); i++) {
		if (inv[i] == item)
			return true;
	}
	return false;
}

bool Game::HasUsedItem(string item)
{
	vector<string> inv = p.GetUsedItems();

	for (int i = 0; i < inv.size(); i++) {
		if (inv[i] == item)
			return true;
	}
	return false;
}

bool Game::GetWin()
{
	return win;
}

void Game::ExamineIfPossible(string input, int curScene)
{
	switch (curScene) {
	case 1:
		if (input == "cabinet")
		{
			std::cout << "In the cabinet you found alchohol, capacitors, inductors and a flashlight.\n";
			p.AddItemsToInventory("flashlight");
			p.AddItemsToInventory("capacitors");
			p.AddItemsToInventory("inductors");
			p.AddItemsToInventory("alchohol");
		}
		else if (input == "table") {

			std::cout << "Frustrated by not having a decent place to sit you tried to fix the dining \n"
				"table but it broke into pieces over which others frowned upon.\n";
			p.IncrementRespect(-10);
		}
		else
			std::cout << "Did not understand what to look for\n ";
			break;
	case 4: 
		 if (input == "behind") {
			std::cout << "There was nothing there. \n";
		}
		else
			std::cout << "Did not understand what to look for\n";
			break;
	case 5:
		if (input == "shiny" || input == "thing") {
			std::cout << "You found an old picture of soldiers fighting the enemy.\n";
		}
		else std::cout << "Did not understand what to look for\n";
		break;
	case 6: 
		if (medTrap) {
			//DIE
			loseCondn = false;
			std::cout << " !!! YOU DIED !!! : you were electrocuted ! \n";
			break;
		}

		if (input == "cabinet") {
			std::cout << "You found medicines \n";
			p.AddItemsToInventory("medicine");
		}
		else std::cout << "Did not understand what to look for\n";
			break;
	case 7:
		if (input == "resonator") {
			std::cout << "You looked at the machine and though not all machines are bad. \n";
			p.IncrementRespect(10);
		}
		else std::cout << "Did not understand what to look for\n";
		break;
	case 9: 
		if (input == "human") {
			std::cout << "With Humans divided by several prejudices , Religion, color, creed ,sexuality ,cast ,gender to name a few.\n"
				"Conflict with some reason or another was bound to happen and with weapons of mass destructions\n"
				"they had the power to wipe out entire planet.It read turn over at the end.\n";
		}
		else if (input == "over") {
			std::cout << "Machines came to an obvious conclusion that they needed a common enemy to unite as one. But the first generations would still hold those prejudices\n"
				"they had to hold off generations of human into seeing what they actually were.One species on the verge of extinction and in thier survival would form \n"
				"a better lasting world.So the machines calculated the appropriate time it would take to do this and set up a virus to destroy iteslf in the machine of \n"
				"a scientist called Richard.\n THE END";

			//loseCondn = false;
			// TWO CHOICES TO BE IMPLEMENTED
		}
		else std::cout << "Did not understand what to look for\n";

			break;
	default: std::cout <<"Nothing to examine here.\n";
	}
}

void Game::ActivateIfPossible(string input, int curScene)
{
	switch (curScene) {
	case 1:if (input == "switch") {
		std::cout << "You flicked the switch releasing the powerful emp which electrocuted as few as \n"
			"1000 machines in the area but gave away 50 mile radius location of your base to \n"
			"machines over which other members of the cave frowned upon.\n";
		p.IncrementRespect(-20);
	}
		   else std::cout << "Did not understand after activate \n";
		   break;
	case 3: if (input == "attack") {
		if (HasUsedItem("capacitors") && HasUsedItem("inductors") && CheckHasItem("virus") && p.GetRespect() > 150) {
			std::cout << "Attack can now begin. \n";
			std::cout << "You can now proceed to machine HQ. \n";
			finalStage = true;
		}
		else {
			std::cout << "Insufficient resources to commence attack. \n";
		}
	}
			else std::cout << "Did not understand after activate \n";
			break;
	case 6:
		if (input == "lever") {
			std::cout << "As you pulled the lever the spark burst seemed to stop. \n";
			medTrap = false;
		}
		else std::cout << "Did not understand after activate \n";
		break;
	case 8: if (input == "virus") {
			if (finalStage && finalTrap) {
				// YOU WIN
				//loseCondn = false;
				std::cout << " !!! YOU WON !!! \n";
				//win = true;
				curScene = 9;
				break;
			}
			else {
				// YOU DIE
				loseCondn = false;
				std::cout << " !!! YOU DIED !!! : Robots from the right killed you. \n";
				break;
			}
	}
		else std::cout << "Did not understand after activate \n";
		break;
	default: std::cout << "Nothing to activate here. \n";
	}
}

void Game::TakeIfPossible(string input, int curScene)
{
	switch (curScene) {
	case 4: 
		if (input == "mushrooms") { 
		std::cout << "You collected mushrooms\n";
		p.IncrementRespect(10);
	    }
		else std::cout << "Did not understand after take/pick up";
		break;
	
	case 5:
		if (input == "guns") {
			std::cout << "You have picked up guns! \n";
			p.AddItemsToInventory("guns");
		}
		else  std::cout << "Did not understand after take/pick up";
		break;

	default: std::cout << "Not much to take here. \n";
	}
}

void Game::UseIfPossible(string input, int curScene)
{
	if (input == "alchohol") {
		if (CheckHasItem("alchohol")) {
		std::cout << "You feel good for a while but then your stomach starts to hurt. \n";
		p.DecrementHealth(30);
	  }else
	    std::cout << "You dont have alchohol \n";
	}

	switch (curScene) {
	case 2: if (input == "flashlight" && CheckHasItem("flashlight")) {
		std::cout << "You used flashlight now you can see your way out of tunnel. \n";
		p.AddItemsToUsed("flashlight");
	}
			else std::cout <<"Cannot use \n";
			break;
	case 3: if (input == "capacitors") {
		std::cout << "You used capacitors which is essential in radio braodcast. \n";
		p.AddItemsToUsed("capacitors");
	}
			else if (input == "inductors") {
				std::cout << "You used inductors which is essential in radio braodcast. \n";
				p.AddItemsToUsed("inductors");
	}
			else std::cout << "Cannot use \n";
			break;
	
	default: std::cout << "Nothing to use here \n";
	}
	
}

Game::~Game()
{
}
