#include <stdbool.h>
#include <stdio.h>

#define NUM_CARDS 5
#define CARD_FORMAT_WIDTH 2
#define NUM_SUIT 4
#define NUM_RANK 13

// all listed for testing, consider making a test.h
extern bool history[NUM_RANK][NUM_SUIT];
extern char hand[NUM_CARDS][CARD_FORMAT_WIDTH]; 
extern bool straight, flush, four, full_house, three, pair, high_card; 

void print_hand(void);
bool validate_card(char card[static CARD_FORMAT_WIDTH]);
int read_hand(void);
int analyze_hand(void);

