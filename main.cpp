#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	//Begin the random loop
	srand(time(0));
	//Player and monster stats to be stored
	int playerHealth = 100;
	int playerAttack = 20;
	int monsterHealth;
	int monsterAttack;
	int playerInput; //Store the player input
	int potions = 2; //Potions the player has left

//Let the player select a difficulty
	cout << "Please select difficulty:\n";
	cout << "1 - Easy Mode (HP: 25, DMG: 5)\n";
	cout << "2 - Normal Mode (HP: 50, DMG: 15)\n";
	cout << "3 - Hard Mode (HP 100, DMG 20)\n";
	cout << "**Please keep in mind an additional 0-14 DMG will be added on to the monster's attack!**\n";
	cout << "Your choice: ";
	int Difficulty;
	cin >> Difficulty;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		Difficulty = 2;
		cout << "Invalid input. Defaulting to Normal Mode.\n";
	}

//Difficulty Selection Functionn
	if (Difficulty == 1) {
		monsterHealth = 25;
		monsterAttack = 5;
		cout << "You have selected easy mode. \n";
	} else if (Difficulty == 2) {
		monsterHealth = 50;
		monsterAttack = 15;
		cout << "You have selected normal mode. \n";
	} else if (Difficulty == 3) {
		monsterHealth = 100;
		monsterAttack = 20;
		cout << "You have selected hard mode. \n";
	} else {
		monsterHealth = 50;
		monsterAttack = 15;
		cout << "Invalid Input, defaulting to Normal Mode.\n";
	}
	//Explain the program to the player
	cout << "\nWelcome to the dungeon! You have grabbed your sword and began your quest." << endl;
	cout << "Before you stands a skeleton, whose health is " << monsterHealth << " and attacks for " << monsterAttack << endl;
	while (monsterHealth > 0 && playerHealth > 0) {
		cout << "\n Your HP: " << playerHealth << " || Skeleton HP: " << monsterHealth << " || Potions remaining: " << potions << endl;
		cout << "Choose your action: 1-Attack | 2-Defend | 3-Drink a Potion | 4-Attempt to escape ";
		cin >> playerInput;
		if (cin.fail()) {
			cout << "\nInvalid input!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		if (playerInput == 1) {
			int chance = rand() % 100;
			if (chance < 70) {
				int playerDamage = playerAttack + rand() % 6;
				int critChance = rand() % 100;
				if (critChance < 35) {
					playerDamage *= 2;
					cout << "\nYour attack is a critical, doubling your damage!" << endl;
				}
				monsterHealth -= playerDamage;
				if (monsterHealth < 0) monsterHealth = 0;
				cout << "\nYou hit the skeleton for " << playerDamage << " damage!" << endl;
			} else {
				cout << "\nThe skeleton dodges your attack!" << endl;
			}
		} else if (playerInput == 2) {
			cout << "\nYou raise your shield to block half the skeleton's damage!" << endl;
		} else if (playerInput == 3) {
			if (potions > 0) {
				potions -= 1;
				playerHealth += 40;
				if (playerHealth > 100) playerHealth = 100;
				cout << "\nYou drink a healing potion! Your HP is now: " << playerHealth << endl;
			} else {
				cout << "\nNo potions left to drink! Turn wasted..." << endl;
			}
		} else if (playerInput == 4) {
			int escape = rand() % 100;
			if (escape < 25) {
				cout << "\nYou have successfully escaped from the skeleton!" << endl;
				break;
			} else {
				cout << "\nYou failed to escape! The skeleton attacks." << endl;
			}
		} else {
			cout << "\nInvalid Input! Turn Wasted...";
		}
		if (monsterHealth > 0) {
			int extra = rand() % 15;
			int damage = monsterAttack + extra;
			if (damage > 25) damage = 25;
			if (playerInput == 2) damage /= 2;
			playerHealth -= damage;
			if (playerHealth < 0) playerHealth = 0;
			cout << "\nThe skeleton strikes! You take " << damage << " damage." << endl;
		}
	}
	if (monsterHealth <= 0) {
		cout << "\nYou have defeated the skeleton! Congratulations!" << endl;
	} else if (playerHealth <= 0) {
		cout << "\nThe skeleton has defeated you. Game over!" << endl;
	}
}
