#include "stdafx.h"
#include "Scene.h"


Scene::Scene()
{
}


Scene::~Scene()
{
}

std::string Scene::CurrentScene(int choice)
{
	std::string str;

	switch (choice) {
		
	case 0:
		str = "In the year 2117 sentient machines started making decisions more than humans.\n"
		"Machines in their conscience sought humans as a threat.They waged war on us.\n"
		"Attacks on the leftovers(what we call humans) had been severe in differentparts of the world.\n\n";
		break;

	case 1: 
		str = "You are in a cave with a cabinet in front of you. Charles and Meera talking\n"
		"at the broken dining table.You can see the exit gate which camouflaged the surrounding rocks.\n"
		"Behind you was a switch which was connected to the water supply and said emergencies only.\n\n";
	    break;

	case 2: 
		str = "The tunnels were dark you could not see a shred of light, moving forward in any direction\n"
			"seemed dangerous. Then you decided where to go.\n\n";
		break;
	case 3: 
		str = "You are at the radio tower to initiate attack on the machines and hoped that you have \n"
			"enough respect in the leftover community to convince everyone to foray the enemy.But to transmit\n"
			"radio you needed something.\n";
			break;
	case 4: 
		str = "You figured to earn respect of people you'd need food. After approaching a forest you could see\n"
			"a rabbit in his hole behind bunch of edible shitake mushrooms.But you hear a ruffle behind.\n \n";
			break;
	case 5: 
		str = "You figured the machines had measures to protect their headquaters so you needed guns. You knew the warehouse\n"
			"where the guns and ammunations were kept and went there.You could see the guns in the storage.Behind it\n"
			"you also saw some thing shining beside the walls.At the distant interval you can see the radio tower and" 
			"something reminded you of task of healing someone special.\n\n";
			break;
	case 6: 
		str = "The old medical facility was run down by militia robots but some medicine may still have been left. You entered the building\n"
			"and saw a room filled with water and electric sparks hanging around.On futher inspection there was a cabinet at the\n"
			"north west corner on the building with antibiotics written on it. A lever was just around the corner .\n \n";
			break;
	case 7: 
		str = "You knew that only breaching the machine headquaters wont be enough. You needed the virus that Charles talked about. So you \n"
			"went to Richards hideout.Sam was at the door keeping guard, Richard as usual was at his quantum resonator. \n\n";
			break;
	case 8: 
		str = "With heavy courage and with hopes of saving the leftovers you secretly breach the machine headquater. On the left you could \n"
			"see the input slot for the mainframe.But you hear a rustling sound coming from the right approaching towards you closer and closer. \n"
			"In seconds, multiple soldier robots will stand towards your right. \n \n";
		    break;
	case 9: 
		str = "Upon pondering bit further you realise that virus was designed in such a way that computer would actually release the core files of the computer \n"
			"At this point you can type 'end' and you would have saved humanity.But if your curiosity got the better of you then folder drive was named something \n"
			"called as Human \n";
			break;

	}

	return str;
}


