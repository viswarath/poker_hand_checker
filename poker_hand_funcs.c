#include "poker_hand_helper.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

char hand[NUM_CARDS][CARD_FORMAT_WIDTH];
bool straight = false, flush = false, three = false, pair = false, high_card = false;
bool history[13][4] = {false};


/*
 *  returns integer representation of suit of card
 *  d, c, h, s return 0, 1, 2, 3
 *  anything else returns -1
 */
int suit_to_int(char card[static CARD_FORMAT_WIDTH])
{
    char suit = (char) toupper((int) card[1]); // I do not have to put any casts in, why?

    switch (suit)
    {
        case 'D':
            return 0;
        case 'C':
            return 1;
        case 'H':
            return 2;
        case 'S':
            return 3;
        default:
            return -1;
    }
    
    return -1;
}


/*
 *  returns integer representation of rank of card
 *  A, 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K returns 0 to 12
 *  anything else returns -1
 */
int rank_to_int(char card[static 2])
{
    char rank = (char) toupper((int) card[0]);

    switch (rank)
    {
        case 'A':
            return 0;
        case '2':
            return 1;
        case '3':
            return 2;
        case '4':
            return 3;
        case '5':
            return 4;
        case '6':
            return 5;
        case '7':
            return 6;
        case '8':
            return 7;
        case '9':
            return 8;
        case 'T':
            return 9;
        case 'J':
            return 10;
        case 'Q':
            return 11;
        case 'K':
            return 12; 
        default:
            return -1;
    }
    
    return -1;
}
/*
 *  print out cards in hand
 *  number of cards in hand is defined by NUM_CARDS
 *  number of chars per card is defined by CARD_FORMAT_WIDTH
 */
void print_hand(void)
{
    char *card;
    for (int i = 0; i < NUM_CARDS; i++)
    {
        card = hand[i];
        char symbol;
        for (int i = 0; i < CARD_FORMAT_WIDTH; i++)
        {
            symbol = *card++; // do you know precedence here? pretty sure its ++ then *
            putchar(symbol);
        }
    }
    printf("\n");
    return;
}

/*
 *  validates a card
 *  checks:
 *      does card fit the card format
 *      is card a dupe of any other card in hand
 */
bool validate_card(char card[static CARD_FORMAT_WIDTH])
{
    if (card == NULL)
    {
        return false;
    }

    int rank_index = rank_to_int(card);
    int suit_index = suit_to_int(card);

   if(rank_index == -1 || suit_index == -1)
   {
       return false;
   }

    // check card against history
    if (history[rank_index][suit_index] == true)
    {
        return false;
    }

    return true;
}


/*
 *  add card to history matrix
 *  card should be validated beforehand
 */
void add_card_to_history(char card[static CARD_FORMAT_WIDTH])
{
    int rank_index = rank_to_int(card);
    int suit_index = suit_to_int(card);
    history[rank_index][suit_index] = true;
}

void analyze_hand(void);


void read_hand(void);


