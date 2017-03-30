#include <iostream>

using namespace std;

class Player
{
public:
	Player();
	~Player();
	int strength;
	int dexterity;
	int wisdom;
	int health;
	int armor;
	int magicResist;
	string name;

	void modifyStrength(int s);
	void modifyDexterity(int d);
	void modifyWisdom(int w);
	void modifyHealth(int h);
	void modifyArmor(int a);
	void modifyMagicResist(int m);
};

void Player::modifyStrength(int s)
{
	strength += s;
}

void Player::modifyDexterity(int d)
{
	dexterity += d;
}

void Player::modifyWisdom(int w)
{
	wisdom += w;
}

void Player::modifyHealth(int h)
{
	health += h;
}

void Player::modifyArmor(int a)
{
	armor += a;
}

void Player::modifyMagicResist(int m)
{
	magicResist += m;
}

Player::Player()
{
}

Player::~Player()
{
}

class Mage :public Player
{
public:
	Mage()
	{
		strength = 2;
		dexterity = 2;
		wisdom = 4;
		health = 100;
		armor = 10;
		magicResist = 75;
	}

	void setDefaultStats();
	void setSatchelSize();

};

void Mage::setDefaultStats()
{
	strength = 2;
	dexterity = 2;
	wisdom = 4;
	health = 100;
	armor = 10;
	magicResist = 75;
}

class Warrior :public Player
{
public:
	Warrior()
	{
		strength = 4;
		dexterity = 2;
		wisdom = 2;
		health = 100;
		armor = 30;
		magicResist = 25;
	}

	void setDefaultStats();
	void setSatchelSize();

};

void Warrior::setDefaultStats()
{
	strength = 4;
	dexterity = 2;
	wisdom = 2;
	health = 100;
	armor = 30;
	magicResist = 25;
}

class Ranger :public Player
{
public:
	Ranger()
	{
		strength = 4;
		dexterity = 2;
		wisdom = 2;
		health = 100;
		armor = 30;
		magicResist = 25;
	}

	void setDefaultStats();
	void setSatchelSize();

};

void Ranger::setDefaultStats()
{
	strength = 2;
	dexterity = 4;
	wisdom = 2;
	health = 100;
	armor = 20;
	magicResist = 50;
}

// struct Node
// {
// Node *next;
// int nodeNumber; // 1 - 32 to determine which node it is
// std::string programName;
//
// Node(int a): next(NULL), nodeNumber(a), programName("Free"){};
// Node(int a, std::string name): next(NULL), nodeNumber (a), programName (name){};
// };




struct eventType
{
	bool isStr; // is this an event for str wis or dex only one should be true
	bool isWis;
	bool isDex;
	bool isNoneOfTheAbove; // this is if the event is one of the other kind of events
	int req;		//depending on the type of event what is the stat req to bypas the rng prob
	int probablity; //if you dont got the stats this is your prob of winning 1-10

	eventType(bool Str, bool Wis, bool Dex, bool None, int statReq, int prob): isStr(Str), isWis(Wis), isDex(Dex), isNoneOfTheAbove(None), req(statReq), probablity(prob){};
};

class Room
{
  public:
    string dialogue;//describes the Room

		int numberOfChoices
		string *choices = new string[numberOfChoices]; // This will be the text displayed for when you get in the room ex 1. eat cheese, 2. fuck hourse
		string *consequences = new string[numberOfChoices * 2];
		eventType *situation = new eventType[numberOfChoices]; //An array of the different event's we have's type of event, and thier req / prob
		player npc; // this is monster / merchange / ect.
		string nextDialogue;



		void setChoice(int choiceCount, sting choice )
		{
			if (choiceCount > numberOfChoices || choiceCount <= 0)
			{
			std::cout << "problem in room class go to void setChoice method" << std::endl;
			return;
			}
			else
				choices[choiceCount - 1] = choice;
			return;
		}

		void setConsequences(int consequenceCount, sting consequence )
		{
			if (consequenceCount > (numberOfChoices * 2) || consequenceCount <= 0)
			{
			std::cout << "problem in room class go to void setConsequences method" << std::endl;
			return;
			}
			else
				consequences[consequenceCount - 1] = consequence;
			return;
		}

		void setSituation (int situationCount, Char type, int req, int prob)
		{
			if (situationCount > numberOfChoices  || situationCount <= 0)
			{
				std::cout << "problem in room class go to void setSituation method" << std::endl;
				return;
			}
			else if (situation[situationCount-1].isStr || situation[situationCount-1].isWis || situation[situationCount-1].isDex || situation[situationCount-1].isNoneOfTheAbove)
			{
				std::cout << "room already exist, try again." << std::endl;
				return;
			}
			else if (type = 'S')
			{
				situation[situationCount-1] = new situation(True, False, False, False, req, prob)
			}
			else if (type = 'W')
			{
				situation[situationCount-1] = new situation(False, True, False, False, req, prob)
			}
			else if (type = 'D')
			{
				situation[situationCount-1] = new situation(False, False, True, False, req, prob)
			}
			else // we no its a none of the above room the req is 0 and prob is 10, because you always sucseed
				situation[situationCount-1] = new situation(False, False, False, True, 0, 10)
		}

		void makeMonster(int typeOfMonster)
		{
			switch (typeOfMonster)
			{
				case 1: npc = new Imp; break;
				case 2: npc = new Goblin; break;
				case 3: npc = new Wraith; break;
				case 4: npc = new Skeleton; break;
				case 5: npc = new Troll; break;
				case 6: npc = new Undead; break;
				case 7: npc = new Necromancer; break;
				case 8: npc = new Demon; break;
				case 9: npc = new Spider; break;
				case 10: npc = new Dragon; break;
				case default: npc = new Player; break;
			}

		}

    void printDialog()
		{
		cout << dialouge << "std::endl";
		}

		void printNextDialog()
		{
		cout << nextDialouge << "std::endl";
		}

		void printChoices()
		{
			std::cout << "What would you like to do (1 - " << numberOfChoices << ")" ;
			for (size_t i = 0; i < numberOfChoices; ++i)
			{
				std::cout << i+1 << ". " << choices[i] << std::endl;
			}
		}

		void printConsequense(int choicePlayerMade, bool didTheyWin)
		{
			if(didTheyWin)
			{
			std::cout << consequences[choicePlayerMade];
		  }
			else
			std::cout << consequences[choicePlayerMade + 1];
		}

		// this is the combat method if combat will take place in the room.
		void printCombatMenu()
		{
				std::cout << "What would you like to do? (1-4).";
				std::cout << "1. Attack" << std::endl;
				std::Cout << "2. Defend" << std::endl;
				std::cout << "3. Backpack" << std::endl;
				std::cout << "4. Run" << std::endl;
				return;
		}

		void combatEvent(player player, player monster)
		{
			while (/* condition */)
			{
				//todo
			}
		}

    Room(std::string Dialogue, int numChoices, std::string NextDialouge): dialogue(Dialogue), numberOfChoices(numChoices), nextDialouge(NextDialouge){};
};

//making a Room


int main()
{

}
