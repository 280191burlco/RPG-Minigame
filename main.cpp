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
	int monsterHealth = 50;
	int monsterAttack = 15;
	int playerInput; //Store the player input
	int potions = 2; //Potions the player has left

	//Explain the program to the player
	cout << "Welcome to the dungeon! You have grabbed your sword and began your quest." << endl;
	cout << "Before you stands a skeleton, whose health is 50 and attacks for 15 \n" << endl;
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
				int playerDamage = playerAttack;
				int critChance = rand() % 100;
				if (critChance < 35) {
					playerDamage *= 2;
					cout << "\nYour attack is a critical, doubling your damage!" << endl;
				}
				monsterHealth -= playerDamage;
				cout << "\nYou hit the skeleton for " << playerDamage << " damage!" << endl;
			} else {
				cout << "\nThe skeleton dodges your attack!" << endl;
			}
		} else if (playerInput == 2) {
			cout << "\nYou raise your shield to block half the skeleton's damage!" << endl;
		} else if (playerInput == 3) {
			if (potions > 0) {
				potions -= 1;
				playerHealth += 25;
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
		        cout << "\nYou did not escape in time, turn skipped." << endl;
		    }
		}
		if (monsterHealth > 0) {
			int extra = (rand() % 6) * 5;
			int damage = monsterAttack + extra;
			if (damage > 25) damage = 25;
			if (playerInput == 2) damage /= 2;
			playerHealth -= damage;
			cout << "\nThe skeleton strikes! You take " << damage << " damage." << endl;
		}
	}
	if (monsterHealth <= 0) {
		cout << "\nYou have defeated the skeleton! Congratulations!" << endl;
	} else if (playerHealth <= 0) {
		cout << "\nThe skeleton has defeated you. Game over!" << endl;
	}
}
