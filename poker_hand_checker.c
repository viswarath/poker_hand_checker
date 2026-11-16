/*
 *  This program will check user inputted poker hands and print out what type of hand it qualifies as
 *
 *  Functions needed:
 *
 *  void read_hand(void);
 *  take in user input and verify inputted poker cards, storing the hand
 *      - no dupes, cards will be represented like "4c", "Th", ...
 *          - suits: c, h, s, d
 *          - ranks: A, 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K
 *      - if user input fails, print why and try accepting user input again
 *      - case insensitive
 *  
 *  void analyze_hand(void);
 *  check the hand for poker qualifications:
 *      straight flush
 *      flush
 *      four of a kind
 *      full house
 *      three of a kind
 *      pairs
 *      high card
 *
 *      return the highest qualification the hand has
 *
 *  void print_hand(void);
 *  print user cards
 *      - print with the same format as above
 *
 *  main func
 *      ask for hand
 *      return qualifications
 *      repeat if user wants
 *
 *  global vars needed
 *      array of cards in hand
 *      bools for each qualification (straight, flush, full house, three...)
 */

// include statements here
#include <stdio.h>
#include <stdbool.h>
#include "poker_hand_helper.h"

// define statements here, all in poker_hand_helper though tbh

// typedefs here

// global variable declarations here
extern char hand[NUM_CARDS][CARD_FORMAT_WIDTH];
extern bool straight, flush, three, pair, high_card;
extern bool history[13][4];

// func prototypes
void print_hand(void);
void analyze_hand(void);
void read_hand(void);

int main(void)
{
    return 0;
}

