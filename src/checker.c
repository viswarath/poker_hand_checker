#include "checker.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/*
 *  array of cards, represented by chars.
 *  the default CARD_FORMAT_WIDTH is two, and so the array may look like:
 *  ["4h", "ad", "10s", "Kc", "2s"]
 */
char hand[NUM_CARDS][CARD_FORMAT_WIDTH];

/*
 * array of number of cards per suit
 */
int num_in_suit[NUM_SUIT];

/*
 * array of number of cards per rank
 */
int num_in_rank[NUM_RANK];

/*
 *  series of booleans that represent the rank of the hand the user has
 */
bool straight = false, flush = false, four = false, full_house = false, 
     three = false, pair = false, high_card = true;

/*
 *  2D matrix representing which cards have already been dealt
 *  rows are ranks, row 0 is a 2, ..., row 12 is an ace
 *  columns are suits, col 0 is diamond, 1 is clubs, 2 is hearts, and 3 is spade
 */
bool history[NUM_RANK][NUM_SUIT] = {false};

/*
 *  checks card follows format, is a valid card, and is not a duplicate card.
 *  has issues when reading multiple cards inputted into stdin at once
 */
bool validate_card(char card[static CARD_FORMAT_WIDTH]); // testing problem with this and read hand!

// function prototypes for fully internally used functions
void add_card_to_history(char card[static CARD_FORMAT_WIDTH]);
int suit_to_int(char card[static CARD_FORMAT_WIDTH]);
int rank_to_int(char card[static CARD_FORMAT_WIDTH]);
int print_hand_class(void);

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
 *  returns integer representation of the rank of the inputted card
 *  2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A returns 0 to 12
 *  anything else returns -1
 */
int rank_to_int(char card[static CARD_FORMAT_WIDTH])
{
    char rank = (char) toupper((int) card[0]);

    switch (rank)
    {
        case '2':
            return 0;
        case '3':
            return 1;
        case '4':
            return 2;
        case '5':
            return 3;
        case '6':
            return 4;
        case '7':
            return 5;
        case '8':
            return 6;
        case '9':
            return 7;
        case 'T':
            return 8;
        case 'J':
            return 9;
        case 'Q':
            return 10;
        case 'K':
            return 11; 
        case 'A':
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

   if (rank_index == -1 || suit_index == -1)
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
    num_in_suit[suit_index]++;
    num_in_rank[rank_index]++;
    history[rank_index][suit_index] = true;
}

/*
 *  sorts hand by rank, lowest rank to highest rank
 */
void sort_hand()
{
}

/*
 *  reads the history matrix and sets the global booleans representing the poker hands
 *  returning the specific cards relevant to each poker hand has not been implemented yet
 */
int analyze_hand(void)
{
    //  straight check
    //      card in consective ranks
    //  flush check
    //      cards in one suit
    // straight flush? royal?
    //      both above
    // 4 of a kind
    //      count of 4 cards in one rank
    // full house
    //      3 in one rank and 2 in another rank
    // 3 of a kind
    //      3 in one rank only
    // pair
    //      2 in one rank
    // high card
    //      highest rank card

    // traverse num in rank and num in suit
    int rank_count = 0;
    int suit_count = 0;
    int consecutive = 0;

    for (int i = 0; i < NUM_RANK; i++)
    {
        rank_count = num_in_rank[i];

        switch (rank_count)
        {
            case 4:
                four = true;
                break;
            case 3:
                three = true;
                break;
            case 2:
                pair = true;
                break;
            case 1:
                consecutive++;
                break;
            case 0:
                consecutive = 0;
                break;
        }
            
        // hard coded A, 2, 3, 4, 5
        if (consecutive == 4 && i == 3 && num_in_rank[12])
        {
            straight = true;
        }

        if (consecutive == 5)
        {
            straight = true;
        }
    }


    for (int i = 0; i < NUM_SUIT; i++)
    {
        suit_count = num_in_suit[i];

        if (suit_count == NUM_CARDS)
        {
            flush = true;
        }
    }

    if (straight && flush)
    {
        // royal flush here
    }

    if (three && pair)
    {
        full_house = true;
    }

    print_hand_class();
    return 0;
}

// this is garbage, please change asap
int print_hand_class(void)
{
    if (straight)
    {
        printf("straight\n");
        return 0;
    }

    if (flush)
    {
        printf("flush\n");
        return 0;
    }

    if (four)
    {
        printf("four\n");
        return 0;
    }

    if (full_house)
    {
        printf("full_house\n");
        return 0;
    }

    if (three)
    {
        printf("three\n");
        return 0;
    }

    if (pair)
    {
        printf("pair\n");
        return 0;
    }
    
    printf("high card\n");
    return 0;
}


int read_hand(void)
{
    // ask user for cards, and validate each card. If card fails validation, ask user again
    char card[CARD_FORMAT_WIDTH];
    
    int i = 0;
    // could use for loop, want to practice do loop
    printf("please input your cards (%d characters per card): \n", CARD_FORMAT_WIDTH);
    do
    {
        // not compatible with other widths
        scanf(" %c", &card[0]);
        scanf(" %c", &card[1]); // try card + 1
        
        if (validate_card(card))
        {
            add_card_to_history(card);
            i++;
        } else
        {
            printf("Please try again\n");
        }
    } while (i < NUM_CARDS);

    return 0;
}


