#include "cards.h"
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <algorithm>



/* *************************************************
Card class
************************************************* */
//Default constructor for the Card class.
Card::Card() {
	srand(time(NULL));

	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}
	srand(time(NULL));
	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}
string Card::get_spanish_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "Oros";
		break;
	case COPAS:
		suitName = "Copas";
		break;
	case ESPADAS:
		suitName = "Espadas";
		break;
	case BASTOS:
		suitName = "Bastos";
		break;
	default: break;
	}
	return suitName;
}
string Card::get_spanish_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}

string Card::get_english_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "Coins";
		break;
	case COPAS:
		suitName = "Cups";
		break;
	case ESPADAS:
		suitName = "Swords";
		break;
	case BASTOS:
		suitName = "Clubs";
		break;
	default: break;
	}
	return suitName;
}

string Card::get_english_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "Ace";
		break;
	case DOS:
		rankName = "Two";
		break;
	case TRES:
		rankName = "Three";
		break;
	case CUATRO:
		rankName = "Four";
		break;
	case CINCO:
		rankName = "Five";
		break;
	case SEIS:
		rankName = "Six";
		break;
	case SIETE:
		rankName = "Seven";
		break;
	case SOTA:
		rankName = "Jack";
		break;
	case CABALLO:
		rankName = "Knight";
		break;
	case REY:
		rankName = "King";
		break;
	default: break;
	}
	return rankName;
	
}

// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}

double Card::get_value() const {
	if ((*this).get_rank() < 10)				//Cards up to Siete have the same value as their ranks
	{
		return (*this).get_rank();				
	}
	else
		return 0.5;								//Cards beyond Siete: Sota, Caballo, Rey, have a value of 0.5
}


// Comparison operator for cards
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}

std::ostream& operator<<(std::ostream& out, const Card& x) {	//To print out cards
	out << "			" << x.get_spanish_suit() << " of " << x.get_spanish_rank() << "			(" << x.get_english_suit() << " of " << x.get_english_rank() << ")";
	return out;
}

/* *************************************************
Hand class
************************************************* */
Hand::Hand() : total(0) {	//initializing a hand with no cards and a total value of 0

}

void Hand::draw_card(){
	Card newcard;
	current_hand.push_back(newcard);
	total += newcard.get_value();			//Every time we draw a card, our total value must be updated. 
}

double Hand::get_total() const {
	return total;							
}

Card& Hand::operator[] (int position) {
	return current_hand[position];
}

void Hand::print_out_hand() {
	for (int i = 0; i < current_hand.size(); i++)
	{
		cout << current_hand[i] << endl;
	}
}

Card& Hand::last_card() {
	return current_hand[current_hand.size() - 1];
}

void Hand::reset_hand() {				//Resets the hand by making the hand empty of cards and resetting the total value back to 0. 
	current_hand = {};
	total = 0;
}

/* *************************************************
Player class
************************************************* */
Player::Player(int m=100): money(m) {

}

int Player::get_money() const {
	return money;
}

void Player::add_money(const int& bet) {
	money += bet;
}