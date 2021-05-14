#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
	assert(c.value >= 2 && c.value <= 14);
	assert(c.suit >= SPADES && c.suit < NUM_SUITS);
}

const char * ranking_to_string(hand_ranking_t r) {
	switch(r) {
		case STRAIGHT_FLUSH :
			return "STRAIGHT_FLUSH";
			break;
		case FOUR_OF_A_KIND :
			return "FOUR_OF_A_KIND";
			break;
		case FULL_HOUSE :
			return "FULL_HOUSE";
			break;
		case FLUSH :
			return "FLUSH";
			break;
		case STRAIGHT :
			return "STRAIGHT";
			break;
		case THREE_OF_A_KIND :
			return "THREE_OF_A_KIND";
			break;
		case TWO_PAIR :
			return "TWO_PAIR";
			break;
		case PAIR :
			return "PAIR";
			break;
		case NOTHING:
			return "NOTHING";
			break;
		default :
			return "";
			break;
	}
}

char value_letter(card_t c) {
	assert_card_valid(c);
	int value = c.value;
	char letter;
	if(value >= 2 && value <= 9) {
		letter = '0' + value; // 48 is ascii value for '0'
	} else {
		switch(value) {
			case 10:
				letter = '0';
				break;
			case VALUE_JACK:
				letter = 'J';
				break;
			case VALUE_QUEEN:
				letter = 'Q';
				break;
			case VALUE_KING:
				letter = 'K';
				break;
			case VALUE_ACE:
				letter = 'A';
				break;
		}
	}
	return letter;
}


char suit_letter(card_t c) {
	assert_card_valid(c);
	char letter;
	switch(c.suit) {
		case SPADES:
			letter = 's';
			break;
		case HEARTS:
			letter = 'h';
			break;
		case DIAMONDS:
			letter = 'd';
			break;
		case CLUBS:
			letter = 'c';
			break;
		default:
			letter = ' ';
			break;
	}
	return letter;
}

void print_card(card_t c) {
	printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
	card_t temp;
	if (value_let >= '2' && value_let <= '9') {
		temp.value = value_let - '0';
	} else {
		switch(value_let) {
			case '0':
				temp.value = 10;
				break;
			case 'J':
				temp.value = 11;
				break;
			case 'Q':
				temp.value = 12;
				break;
			case 'K':
				temp.value = 13;
				break;
			case 'A':
				temp.value = 14;
				break;
		}
	}
	//suit
	switch(suit_let) {
		case 's':
			temp.suit = SPADES;
			break;
		case 'h':
			temp.suit = HEARTS;
			break;
		case 'd':
			temp.suit = DIAMONDS;
			break;
		case 'c':
			temp.suit = CLUBS;
			break;
	}
	assert_card_valid(temp);
	return temp;
}

card_t card_from_num(unsigned c) {
	card_t temp;
	temp.value = (c / 4) + 2;
	temp.suit = c % 4;
	return temp;
}
