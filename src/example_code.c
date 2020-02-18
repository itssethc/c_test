/*
    This file just contains some simple function implementations
    which are used to demo the testing framework.
*/

#include "example_code.h"

#include <stdlib.h>
#include <stdbool.h>



int increment_int(int x)
{
    return x + 1;
}



bool is_even(int x)
{
    return !(x & 1);
}



void toggle_case(char * c_str)
{
    while (*c_str)
    {
        const bool char_is_alpha = ('A' <= *c_str && *c_str <= 'Z') || ('a' <= *c_str && *c_str <= 'z');

        if (char_is_alpha)
        {
            *c_str ^= (1 << 5);
        }
        else
        {
            /* leave the char alone if it is not alphabetic */
        }
        
        c_str++;
    }
}
