/*
    This file just contains some simple function declarations
    which are used to demo the testing framework.
*/

#ifndef EXAMPLE_CODE_H_INCLUDED
#define EXAMPLE_CODE_H_INCLUDED

#include <stdbool.h>



/*-----------------------------------------------------------------------------------------------
Function Name:
    increment_int

Function Description:
    Returns the successor of a given integer.

Inputs:
    x: The integer to increment.

Outputs:
    int: The given integer plus one.

Error Handling:
    None
-------------------------------------------------------------------------------------------------*/
int increment_int(int x);



/*-----------------------------------------------------------------------------------------------
Function Name:
    is_even

Function Description:
    Determine whether a given integer is even.

Inputs:
    x: The integer to check for even-ness.

Outputs:
    bool: true if the given integer is even, false otherwise.

Error Handling:
    None
-------------------------------------------------------------------------------------------------*/
bool is_even(int x);



/*-----------------------------------------------------------------------------------------------
Function Name:
    toggle_case

Function Description:
    Modifies a given c string by toggling all of the alphabetic chars from upper to lower, 
    and vice versa.

Inputs:
    c_str: The c string to modify.

Outputs:
    The given c string is modified in place.

Error Handling:
    None
-------------------------------------------------------------------------------------------------*/
void toggle_case(char * c_str);



#endif
