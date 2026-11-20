/*
 * This program reads a poker hand from user input,
 * returning the poker class of the hand
 */

// include statements here
#include "checker.h"

// func prototypes
void print_hand(void);
int analyze_hand(void);
int read_hand(void);

int main(void)
{
    read_hand();
    print_hand();
    analyze_hand();
    return 0;
}

