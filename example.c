/**
 * An example of VVS
 *
 * @author  Sunglok Choi (http://sites.google.com/site/sunglok)
 * @version 0.1 (10/23/2013)
 */

#include <string.h>
#include <math.h>
#include "unit-test.h"

/**
 * An test function for Example #1
 */
void testExample1(void)
{
    int bMonth = 12;
    int bDay = 1;
    char name[] = "PerceptRUN";

    // Basic examples
    VVS_CHECK_TRUE (bMonth == 12);
    VVS_CHECK_FALSE(bDay == 12);

    // Examples for strings
    VVS_CHECK_TRUE (strcmp(name, "PerceptRUN") == 0);
    VVS_CHECK_TRUE (strcmp(name, "ETRI") == 0);
}

/**
 * An test function for Example #2
 */
void testExample2(void)
{
    double pi = 3.141592;

    // Examples for real numbers
    VVS_CHECK_TRUE (atan2(0.0, -1.0) == pi); // False due to small difference
    VVS_CHECK_CLOSE(atan2(0.0, -1.0), pi);   // True up to tolerance, 'VVS_EPSILON'
}

int main(void)
{
    // Run test functions
    VVS_RUN_TEST(testExample1());
    VVS_NUN_TEST(testExample1()); // Do not run, 'NUN' instead of 'RUN'
    VVS_RUN_TEST(testExample2());
    
    return 0;
}