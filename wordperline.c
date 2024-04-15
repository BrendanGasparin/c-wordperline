/*
    wordperline.c
    Author: Brendan Gasparin <Brendan.Gasparin@gmail.com>
    Date: 16 April 2024
    Reads the standard input and prints it out one word per line.
*/

#include <ctype.h>
#include <stdio.h>

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */

int main()
{
    int c, state; /* c is the input character, state is whether or not we are inside a word */

    state = OUT;

    // While we are not at the end of the file
    while ((c = getchar()) != EOF) {
        // If we have whitespace then we are outside of a word
        if ((c == ' ' || c == '\n' || c == '\t') && state == IN)
        {
            state = OUT;
            printf("\n");
        }
        // Otherwise we are in a word
        else if (state == OUT) {
            state = IN;
        }
        
        // Print alphanumeric characters and apostrophes
        if (isalnum(c) || c == '\'')
            printf("%c", c);
    }
}