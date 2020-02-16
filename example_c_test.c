/*
    This file just runs a simple demo of the c_test module
    in its present super early state.
*/

#include "c_test.h"

#include <stdio.h>
#include <stdint.h>

// return the meaning of life, the universe, and everything
uint32_t get_meaning_of_life(void);

// combine two uint16_ts into a single uint32_t
uint32_t expand_16s_to_32(uint16_t ms_word, uint16_t ls_word);


int main(void)
{
    // initialize the test runner
    C_Test_Initialize();


    // start the first test, here we'll verify the get_meaning_of_life function
    C_Test_Start_Next_Test_Case("Verify get_meaning_of_life");

    // this only requires one test comparison
    C_Test_Add_Description_To_Next_Comparison("Don't panic");
    C_Test_Assert_Equals_ui32(42, get_meaning_of_life());


    // now we'll start to verify the expand_16s_to_32 function
    // this one will require more test cases to cover various corner cases
    C_Test_Start_Next_Test_Case("Verify expand_16s_to_32");

    C_Test_Add_Description_To_Next_Comparison("Trivial case");
    C_Test_Assert_Equals_ui32(0x0u, expand_16s_to_32(0x0u, 0x0u));

    C_Test_Add_Description_To_Next_Comparison("MS word zero");
    C_Test_Assert_Equals_ui32(0x1u, expand_16s_to_32(0x0u, 0x1u));

    C_Test_Add_Description_To_Next_Comparison("LS word zero");
    C_Test_Assert_Equals_ui32(0x10000u, expand_16s_to_32(0x1u, 0x0u));

    C_Test_Add_Description_To_Next_Comparison("Both words non zero");
    C_Test_Assert_Equals_ui32(0x12345678u, expand_16s_to_32(0x1234u, 0x5678u));

    C_Test_Add_Description_To_Next_Comparison("Intentionally failing test");
    C_Test_Assert_Equals_ui32(0x12345679u, expand_16s_to_32(0x1234u, 0x5678u));

    // when all the tests are done, we'll show the results in the terminal
    C_Test_Show_Test_Results_In_Terminal();

    return 0;    
}



uint32_t get_meaning_of_life(void)
{
    return 42u;
}

uint32_t expand_16s_to_32(uint16_t ms_word, uint16_t ls_word)
{
    return (ms_word << 16u) | ls_word;
}
