#pragma once
/* *************************************
Nirmay Singaram, April 30, 2018

Interface of a simple Card class
************************************* */

#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H
#define CARDS_H

using namespace std;

enum suit_t { OROS, COPAS, ESPADAS, BASTOS };

/*
The values for this type start at 0 and increase by one
afterwards until they get to SIETE.
The rank reported by the function Card::get_rank() below is
the value listed here plus one.
E.g:
The rank of AS is reported as    static_cast<int>(AS) + 1   = 0 + 1 =  1
The rank of SOTA is reported as  static_cast<int>(SOTA) + 1 = 9 + 1 = 10
*/
enum rank_t { AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA = 9, CABALLO = 10, REY = 11 };

class Card {
public:
	// Constructor assigns random rank & suit to card.
	Card();

	// Accessors 
	string get_spanish_suit() const;
	string get_spanish_rank() const;
	string get_english_suit() const;
	string get_english_rank() const;
	// Converts card rank to number.
	// The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
	int get_rank() const;
	// Compare rank of two cards. E.g: Eight<Jack is true.
	double get_value() const;
	bool operator < (Card card2) const;
	friend std::ostream& operator<<(std::ostream&, const Card&);

private:
	suit_t suit;
	rank_t rank;
};


class Hand {
public:
	Hand();
	void draw_card();					//Draws a card
	double get_total() const;			//Finds out the total value of the hand
	Card& operator[] (int);				//Locate specific cards in the hand
	void print_out_hand();				//Display the hand
	Card& last_card();					//Locate the last card in the hand
	void reset_hand();					//Used at the end, to start a new game. 
private:
	vector<Card> current_hand;
	double total;
};


class Player {
public:
	Player(int m);
	int get_money() const;			//Returns the player's wallet
	Hand player_hand;				//Hand is a public field in order to access the functions that are available in the hand class. Slightly inelegant, but it gets the job done. 
	void add_money(const int&);		//Adding or subtracting money after a game. 
private:
	int money;
};

#endif