#include <stdbool.h>
#include <stdio.h>

#define NUM_CARDS 5
#define CARD_FORMAT_WIDTH 2

extern bool history[13][4];
extern char hand[NUM_CARDS][CARD_FORMAT_WIDTH];
extern bool straight, flush, three, pair, high_card;

void print_hand(void);
bool validate_card(char card[static CARD_FORMAT_WIDTH]);
int read_hand(void);
void analyze_hand(void);

