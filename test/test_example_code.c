/*
    This file is just a simple demo of how you
    might use the testing framework.
*/

#include <stdio.h>

// always include the test library header
#include "./c_test_lib/c_test.h"

// and include the header files for any code you want to test
#include "example_code.h"

/*
--|--------------------------------------------------------|
--|
--| Test Function Declarations
--|
--|---------------------------------------------------------|
*/

// Use some consistent naming pattern for the tests, this is one suggestion:
void Verify_increment_int(void);

void Verify_is_even(void);

void Verify_toggle_case(void);



/*
--|--------------------------------------------------------|
--|
--| Main Test Driver Method
--|
--|---------------------------------------------------------|
*/

int main(void)
{
    /* Initialize the test runner */
    C_Test_Initialize();

    /* decide if you want to see all the output or only the failing tests and a summary */

    // C_Test_Configure_Output_Mode(C_TEST_OUTPUT_MODE_SHOW_ONLY_FAILING_TESTS); // <- choose one
    C_Test_Configure_Output_Mode(C_TEST_OUTPUT_MODE_SHOW_ALL_RESULTS);           // <- or the other

    /* Call the test functions */
    Verify_increment_int();
    Verify_is_even();
    Verify_toggle_case();

    /* Display the results */
    C_Test_Show_Test_Results_In_Terminal();

    return 0;
}



/*
--|--------------------------------------------------------|
--|
--| Test Function Definitions
--|
--|---------------------------------------------------------|
*/

void Verify_increment_int(void)
{
    // For each test case, start like this:
    C_Test_Start_Next_Test_Case("Verify increment_int");

    // And then for each test sub-step add assert statements like this:
    C_Test_Add_Description_To_Next_Comparison("The successor of 0 is 1");
    C_Test_Assert_Equals_ui32(1, increment_int(0));

    C_Test_Add_Description_To_Next_Comparison("The successor of 1 is 2");
    C_Test_Assert_Equals_ui32(2, increment_int(1));

    C_Test_Add_Description_To_Next_Comparison("The successor of -1 is 0");
    C_Test_Assert_Equals_ui32(0, increment_int(-1));
}



void Verify_is_even(void)
{
    C_Test_Start_Next_Test_Case("Verify is_even");

    C_Test_Add_Description_To_Next_Comparison("One is not even");
    C_Test_Assert_Equals_ui32(0, is_even(1));

    C_Test_Add_Description_To_Next_Comparison("Two is even");
    C_Test_Assert_Equals_ui32(1, is_even(2));
}



void Verify_toggle_case(void)
{ 
    // The test runner only compares uint32_t types, but
    // with some creativity you can test strings and many
    // other data types, here is one way to test strings:

    C_Test_Start_Next_Test_Case("Verify toggle_case to upper");

    // Set up test variables
    char actual_str[]         = "tEsTInG";
    const char expected_str[] = "TeStiNg";

    char description_buffer[16];
    
    uint8_t str_index = 0u;

    // Call the function under test to update the actual string
    toggle_case(actual_str);

    // Test each char in the string individually
    while (actual_str[str_index])
    {
        sprintf(description_buffer, "actual char: %c", actual_str[str_index]);
        C_Test_Add_Description_To_Next_Comparison(description_buffer);
        C_Test_Assert_Equals_ui32(expected_str[str_index], actual_str[str_index]);
        str_index++;
    }
}
