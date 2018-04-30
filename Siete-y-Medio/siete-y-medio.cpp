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
	srand(time(NULL));
	Player user(100);
	Player computer(dealers_wallet);
	int game_number = 0; int bet; char answer = 'y'; bool player_bust = false; bool computer_bust = false;
	ofstream fout;
	fout.open("Gamelog.txt", ios::out|ios::trunc);
	while ((user.get_money() > 0) && (computer.get_money() > 0))
	{
		++game_number; player_bust = false; computer_bust = false;
		cout << "Game Number: " << game_number << endl;
		//PLAYER'S TURN *****************************************************************************************************
		cout << "You have " << user.get_money() << "$" << ". Enter bet: ";
		cin >> bet;
		user.player_hand.draw_card();
		cout << "Your cards: " << endl;
		user.player_hand.print_out_hand(cout);
		cout << "Your total is " << user.player_hand.get_total() << ". Do you want to draw another card? (Y/N) ";
		cin >> answer;
		while (answer == 'y' && user.player_hand.get_total()<=7.5) 
		{
			user.player_hand.draw_card();
			cout << "New Card: " << endl;
			cout << user.player_hand.last_card() << endl;
			cout << "Your cards: " << endl;
			user.player_hand.print_out_hand(cout);
			cout << "Your total is " << user.player_hand.get_total() << endl;
			if (user.player_hand.get_total() > 7.5)
			{
				cout << "Bust!" << endl; player_bust = true;
				break;
			}
			else 
			{
				cout << ". Do you want to draw another card? (Y/N) ";
				cin >> answer;
			}
		}
		//COMPUTER'S TURN ***************************************************************************************************
		computer.player_hand.draw_card();
		cout << "Dealer's cards: " << endl;
		computer.player_hand.print_out_hand(cout);
		cout << "The Dealer's total is " << computer.player_hand.get_total() << endl << endl;
		while (computer.player_hand.get_total() < dealers_threshhold)
		{
			computer.player_hand.draw_card();
			cout << "New card: " << endl;
			cout << computer.player_hand.last_card() << endl;
			cout << "Dealer's cards: " << endl;
			computer.player_hand.print_out_hand(cout);
			cout << "The Dealer's total is " << computer.player_hand.get_total() << endl << endl;
			if (computer.player_hand.get_total() > 7.5)
			{
				cout << "Bust!" << endl; computer_bust = true;
			}
		}
		//EVALUATING RESULT ***********************************************************************************************
		if (player_bust==true && computer_bust==true)
		{
			cout << "House advantage! You lose " << bet << "$" << endl;
			user.add_money(bet*-1);
		}
		else if (player_bust==false &&  computer_bust==true)
		{
			cout << "CPU busted and you didn't. You win " << bet << " $"  << endl;
			user.add_money(bet);
		}
		else if (player_bust==true && computer_bust==false)
		{
			cout << "You busted and CPU didn't. You lose " << bet << " $"  << endl;
			user.add_money(bet*-1);
		}
		else
		{
			if (user.player_hand.get_total() > computer.player_hand.get_total())
			{
				cout << "Neither busted but you have a higher total. You win " << bet << " $"<<  endl;
				user.add_money(bet);
			}
			else if (user.player_hand.get_total() < computer.player_hand.get_total())
			{
				cout << "Neither busted but you have a lower total. You lose " << bet << " $" << endl;
				user.add_money(-1 * bet);
			}
			else
			{
				cout << "Draw. No loss or gain " << endl;
			}

		}
		//WRITING GAMELOG FILE *************************************************************************************
		fout.open("Gamelog.txt", ios::app);
		fout << "******************************************************************************************************" << endl;
		fout << "Game number" << game_number << "			Money left: $ " << user.get_money() << endl;
		fout << "Bet: $" << bet << endl << endl;
		fout << "Your cards: " << endl;
		user.player_hand.print_out_hand(fout);
		fout << "Your total: " << user.player_hand.get_total() << endl << endl;
		fout << "Dealer's cards: " << endl;
		computer.player_hand.print_out_hand(fout);
		fout << "Dealer's total is " << computer.player_hand.get_total() << endl;
		fout << "******************************************************************************************************" << endl;
		fout.close();
		//RESET GAME **************************************************************************************************
		user.player_hand.reset_hand();
		computer.player_hand.reset_hand();

	}
	return 0;
}