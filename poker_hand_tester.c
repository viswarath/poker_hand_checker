#include "poker_hand_helper.h"

char hand[NUM_CARDS][CARD_FORMAT_WIDTH] = {{'5','c'}, {'T','h'}, {'9','c'}, {'Q','d'}, {'A','s'}};
extern bool history[NUM_RANK][NUM_SUIT]; 

int test_validate_card(void);
int test_read_hand(void);
int test_analyze_hand(void);

int main(void)
{
    // testing printing cards
    print_hand();

    // testing validating cards
    // test_validate_card();

    // testing reading a hand
    // issue, user inputs 2d3d4d5d6d
    test_read_hand();

    test_analyze_hand();
}

// needs error messages, and some way to be sure about loop execution time too
int test_validate_card(void)
{
    // ask user for cards, and validate each card. If card fails validation, ask user again
    char card[CARD_FORMAT_WIDTH];
    
    int i = 0;
    // could use for loop, want to practice do loop
    do
    {
        printf("please input your card (%d characters): \n", CARD_FORMAT_WIDTH);
        // not compatible with other widths
        scanf(" %c", &card[0]);
        scanf(" %c", &card[1]); // try card + 1
        
        if (validate_card(card))
        {
            i++;
        } else
        {
            printf("Please try again\n");
        }
    } while (i < NUM_CARDS);

    return 0;
}

int test_read_hand(void)
{
    read_hand();
    print_hand();
    return 0;
}

int test_analyze_hand(void)
{
    analyze_hand();
    return 0;
}
