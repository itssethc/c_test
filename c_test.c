
#include "c_test.h"
#include <stdio.h>
#include <stdlib.h>



/*
--|--------------------------------------------------------|
--|
--| Private C Test Defines
--|
--|---------------------------------------------------------|
*/

#define MAX_COMPARISON_FEILD_LENGTH 16u



/*
--|--------------------------------------------------------|
--|
--| Private C Test Types
--|
--|---------------------------------------------------------|
*/

typedef struct c_test_comparison_type
{
    char description[MAX_TEST_DESCRIPTION_LENGTH];
    char expected[MAX_COMPARISON_FEILD_LENGTH];
    char actual[MAX_COMPARISON_FEILD_LENGTH];
    bool result;
} c_test_comparison_t;



typedef struct c_test_case_type
{
    char description[MAX_TEST_DESCRIPTION_LENGTH];
    c_test_comparison_t comparisons[MAX_NUM_COMPARISONS_PER_TEST_CASE];
    uint32_t num_comparisons;
} c_test_case_t;


/*
--|--------------------------------------------------------|
--|
--| Private C Test Variables
--|
--|---------------------------------------------------------|
*/

c_test_case_t test_cases[MAX_NUM_TEST_CASES];

// the current test case number, each test case is made up of a number of test comparisons
static uint32_t Test_Case_Number;

// the current test comparison number, these are the sub-steps for each test case
static uint32_t Test_Comparison_Number;

// the total number of comparisons done
static uint32_t Total_Num_Comparisons;

// the current number of test that have passed
static uint32_t Num_Passing_Tests;

// the current number of tests that have failed
static uint32_t Num_Failing_Tests;

/*
--|--------------------------------------------------------|
--|
--| Private Helper Function Declarations
--|
--|---------------------------------------------------------|
*/

// log the result of a uint32 comparison
void Log_Result_Of_Compare_ui32(uint32_t expected, uint32_t actual, bool result);



/*
--|--------------------------------------------------------|
--|
--| Public Function Definitions
--|
--|---------------------------------------------------------|
*/

void C_Test_Initialize(void)
{
    Test_Case_Number = 0u;
    Test_Comparison_Number = 0u;
    Total_Num_Comparisons = 0u;
    Num_Passing_Tests = 0u;
    Num_Failing_Tests = 0u;
}


void C_Test_Start_Next_Test_Case(const char * description)
{
    Test_Case_Number++;

    Test_Comparison_Number = 0u;

    sprintf(test_cases[Test_Case_Number].description, "%s", description);
}



void C_Test_Add_Description_To_Next_Comparison(const char * description)
{
    sprintf(test_cases[Test_Case_Number].
            comparisons[Test_Comparison_Number + 1u].
            description, 
            "%s",
            description);
}



bool C_Test_Assert_Equals_ui32(uint32_t expected, uint32_t actual)
{
    Test_Comparison_Number++;
    Total_Num_Comparisons++;
    test_cases[Test_Case_Number].num_comparisons++;

    bool result = (expected == actual);

    if (result)
    {
        Num_Passing_Tests++;
    }
    else
    {
        Num_Failing_Tests++;
    }
    
    Log_Result_Of_Compare_ui32(expected, actual, result);
    
    return result;
}



void C_Test_Show_Test_Results_In_Terminal(void)
{
    for (int test_case = 1; test_case <= Test_Case_Number; test_case++)
    {
        printf("\n\n--| Test Case %2d: %-32s --- expected --------- actual --------- result ---\n\n", 
            test_case, 
            test_cases[test_case].description);

        for (int comparison = 1; comparison <= test_cases[test_case].num_comparisons; comparison++)
        {
            printf("#%02d.%02d: %-38s %16s %16s %16s\n", 
                test_case, 
                comparison, 
                test_cases[test_case].comparisons[comparison].description,
                test_cases[test_case].comparisons[comparison].expected,
                test_cases[test_case].comparisons[comparison].actual,
                test_cases[test_case].comparisons[comparison].result == true ? "PASS" : "FAIL");
        }
    }

    printf("\n---- Test Results -------------\n-------------------------------\n");
    printf("---| Num test comparisons: %u\n", Total_Num_Comparisons);
    printf("---|\n");
    printf("---| Passing tests: %u\n", Num_Passing_Tests);
    printf("---| Failing tests: %u\n", Num_Failing_Tests);
    printf("\n---| Test %s\n\n", Num_Failing_Tests == 0u ? "PASSED" : "FAILED");
}



/*
--|--------------------------------------------------------|
--|
--| Private Helper Function Definitions
--|
--|---------------------------------------------------------|
*/

void Log_Result_Of_Compare_ui32(uint32_t expected, uint32_t actual, bool result)
{
    c_test_comparison_t * p_test_comparison = &(test_cases[Test_Case_Number].comparisons[Test_Comparison_Number]);

    snprintf(p_test_comparison->expected, 16, "0x%x", expected);
    snprintf(p_test_comparison->actual,   16, "0x%x", actual);
    p_test_comparison->result = result;
}
