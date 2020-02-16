#ifndef C_TEST_H_INCLUDED
#define C_TEST_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>


/*
--|--------------------------------------------------------|
--|
--| Public C Test Defines
--|
--|---------------------------------------------------------|
*/

#define MAX_NUM_TEST_CASES 99u
#define MAX_NUM_COMPARISONS_PER_TEST_CASE 99u

#define MAX_TEST_DESCRIPTION_LENGTH 32u


/*
--|--------------------------------------------------------|
--|
--| Public Function Declarations
--|
--|---------------------------------------------------------|
*/


/*-----------------------------------------------------------------------------------------------
Function Name:
    C_Test_Initialize

Function Description:
    Initialize the c_test framework and test log.

Inputs:
    None

Returns:
    None

Assumptions/Limitations:
    This initialization function is to be called prior to any other c_test function
-------------------------------------------------------------------------------------------------*/
void C_Test_Initialize(void);



/*-----------------------------------------------------------------------------------------------
Function Name:
    C_Test_Start_Next_Test_Case

Function Description:
    Start a new test case by incrementing the test case counter, reseting the test comparison 
    counter, and updating the test log with the provided description.

Inputs:
    description: the c string description to add to the test log.

Returns:
    None.

Assumptions/Limitations:
    The given description must be less than MAX_TEST_DESCRIPTION_LENGTH.
-------------------------------------------------------------------------------------------------*/
void C_Test_Start_Next_Test_Case(const char * description);



/*-----------------------------------------------------------------------------------------------
Function Name:
    C_Test_Add_Description_To_Next_Comparison

Function Description:
    Add a description to the next comparison that is called.

Inputs:
    description: the c string description to add to the test log.

Returns:
    None.

Assumptions/Limitations:
    The given description must be less than MAX_TEST_DESCRIPTION_LENGTH.
-------------------------------------------------------------------------------------------------*/
void C_Test_Add_Description_To_Next_Comparison(const char * description);



/*-----------------------------------------------------------------------------------------------
Function Name:
    C_Test_Assert_Equals_ui32

Function Description:
    Compare two 32 bit unsigned integers, record the result in the test log, and
    return the result.

Inputs:
    expected: the expected uint32_t value.
    actual:   the actual uint32_t value.

Returns:
    bool: true if the expected and actual values are identical, false otherwise.

Assumptions/Limitations:
    None.
-------------------------------------------------------------------------------------------------*/
bool C_Test_Assert_Equals_ui32(uint32_t expected, uint32_t actual);



/*-----------------------------------------------------------------------------------------------
Function Name:
    C_Test_Show_Test_Results_In_Terminal

Function Description:
    Print the current test results to the terminal.

Inputs:
    None.

Returns:
    None.

Assumptions/Limitations:
    None.
-------------------------------------------------------------------------------------------------*/
void C_Test_Show_Test_Results_In_Terminal(void);

#endif
