/**
 * look_n_say.c by Jelle van Assema
 *
 * Implementation of look_n_say. The look_n_say algorithm is a sequence of
 * where each term is described by the makeup of the previous term.
 *
 * For instance:
 * 1 (one) 
 * 11 (one one)
 * 21 (two ones)
 * 1211 (one two, one one)
 * 111221 (one one, one two, two ones)
 * etc.
 *
 * Usage: ./look_n_say n [base]
 * n = number of iterations
 * base = starting number
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int fill_digits(char* array, int number);
int look_n_say(char* prev_look, int length_prev, char* cur_look);

int main(int argc, char* argv[])
{   
    // if too few or too many arguments, notify user and exit
    if (argc < 2 || argc > 3)
    {
        printf("Usage: ./look_n_say n [base]\n");
        return 1;
    }
    
    int n = atoi(argv[1]);
    
    // if n is not positive, notify user and exit
    if (n <= 0)
    {
        printf("n must be a positive integer!\n");
        return 1;
    }
    
    // if user specified base, use that, else use 1 as default
    char* base = argc == 3 ? argv[2] : "1";
    
    // the look at the previous sequence
    int length_prev = strlen(base);
    char* prev_look = malloc(length_prev);
    memcpy(prev_look, base, length_prev);
    
    // the look at the current sequence
    char* cur_look;
    
    // perform look and say
    for (int i = 1; i < n; i++)
    {
        // print sequence
        printf("%d : %.*s\n\n", i, length_prev, prev_look);
        
        // allocate memory for look at current sequence
        cur_look = malloc(2 * length_prev);
        
        // perform look and say, update length_prev with length of current
        length_prev = look_n_say(prev_look, length_prev, cur_look);
         
        free(prev_look);
        
        // make current the previous
        prev_look = cur_look;
    }
    
    // print final sequence
    printf("%d : %.*s\n", n, length_prev, prev_look);
    free(prev_look);
    
    return 0;
}

/**
 * Fill char array with the digits in number.
 * Returns number of digits in number.
 */
int fill_digits(char* array, int number)
{
    int i = 0;

    // write digits in number to array
    do
    {
        array[i] = number % 10 + '0';
        number /= 10;
        i++;
    }
    while (number != 0);
    
    // return number of digits written
    return i;
}

/**
 * Perform the look and say algorithm.
 * prev_look = sequence of chars representing previous look
 * length_prev = number of chars in prev_look
 * cur_look = result of looking at prev_look
 * Returns number of characters in cur_look
 */
int look_n_say(char* prev_look, int length_prev, char* cur_look)
{
    // TODO
    return 0;
}

