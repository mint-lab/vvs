/**
 * An example of VVS
 *
 * @author  Sunglok Choi (http://sites.google.com/site/sunglok)
 * @version 0.2 (05/22/2019)
 */

#include <string.h>
#include <math.h>
#include "vvs.h"

/**
 * An test function for Example #1
 */
void testExample1(void)
{
    int year = 1982;
    int month = 3;
    int day = 29;
    char name[] = "Sunglok";

    // Basic examples
    VVS_CHECK_TRUE(year == 1982);
    VVS_CHECK_FALSE(month == 4);
    VVS_CHECK_EQUAL(day, 29);
    //VVS_CHECK_EQUAL(day, 30); // Halt in DEBUG mode if enabled

    // Examples for strings
    VVS_CHECK_TRUE(strcmp(name, "Sunglok") == 0);
    VVS_CHECK_FALSE(strcmp(name, "Starmi") == 0);
}

/**
 * An test function for Example #2
 */
void testExample2(void)
{
    double pi = 3.141592;

    // Examples for real numbers
    VVS_CHECK_FALSE(atan2(0.0, -1.0) == pi);        // False due to small difference
    //VVS_CHECK_RANGE(atan2(0.0, -1.0), pi, 1e-9);  // Halt in DEBUG mode if enabled
    VVS_CHECK_NEAR(atan2(0.0, -1.0), pi);           // True up to tolerance, 'VVS_EPSILON'
}

int main(void)
{
    // Run test functions
    VVS_RUN_TEST(testExample1());
    VVS_NUN_TEST(testExample1()); // Do not run, 'NUN' instead of 'RUN'
    VVS_RUN_TEST(testExample2());
    
    return 0;
}
