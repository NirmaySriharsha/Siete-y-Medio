#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;
static const int dealers_wallet = 900;
static const double dealers_threshhold = 5.5;
int main() {
	Player user(100);
	Player computer(dealers_wallet);
	int game_number = 0; int bet; string answer = "y";
	while ((user.get_money() > 0) && (computer.get_money() > 0))
	{
		++game_number;
		//PLAYER'S TURN *****************************************************************************************************
		cout << "You have " << user.get_money() << "$" << ". Enter bet: ";
		cin >> bet;
		user.player_hand.draw_card();
		user.player_hand.print_out_hand();
		cout << "Your total is" << user.player_hand.get_total() << ". Do you want to draw another card? (Y/N) ";
		while (answer == "y")			//make sure that the player can't keep drawing cards even after he busts and shit. 
		{
			user.player_hand.draw_card();
			cout << "New Card: " << endl;
			cout << user.player_hand.last_card();
			user.player_hand.print_out_hand();
			cout << "Your total is" << user.player_hand.get_total() << ". Do you want to draw another card? (Y/N) ";
		}
		//COMPUTER'S TURN ***************************************************************************************************

	}
	return 0;
}