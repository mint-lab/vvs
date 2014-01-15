/**
 * VVS: A Very Very Simple Unit Testing Tool for C/C++
 *
 * VVS aims to provide a very small and simple framework for unit testing in C and C++.
 * It consists of a single header file, unit-test.h, which only utilize C standard libraries.
 * Just include the file to your project. It will work without complex configuration and dependency.
 * VVS is Beerware so that it is free to use and distribute.
 *
 * @author  Sunglok Choi (http://sites.google.com/site/sunglok)
 * @version 0.1 (10/23/2013)
 */

#ifndef __VVS_UNIT_TEST__
#define __VVS_UNIT_TEST__

#include <stdio.h>
#include <time.h>

/**
 * An output stream to display test results
 * @see stdout, stderr
 */
#define VVS_OUTPUT                      (stdout)

/**
 * A constant to identify similarity of real values
 * @see VVS_TEST_CLOSE
 */
#define VVS_EPSILON                     (1e-6)

/**
 * A text to notify the given test is successful
 */
#define VVS_SUCCESS_MSG                 (" --> Success!\n")

/**
 * A text to notify the given test is failed
 */
#define VVS_FAILURE_MSG                 (" --> Failure!\n")

/**
 * A string format to show location of the given expression
 */
#define VVS_LOCATION_MSG                (" --> File: %s / Line: %d\n")

/**
 * TODO
 */
#define VVS_TIME_MSG                    (" --> Time: %.6f [sec]\n")

/**
 * Verify that the given expression is true
 * @param EXP the given expression
 */
#define VVS_CHECK_TRUE(EXP) \
{ \
    int _isTrue = (int)(EXP); \
    fprintf(VVS_OUTPUT, "[CHECK_TRUE ] " #EXP); \
    if (_isTrue) fprintf(VVS_OUTPUT, VVS_SUCCESS_MSG); \
    else \
    { \
        fprintf(VVS_OUTPUT, VVS_FAILURE_MSG); \
        fprintf(VVS_OUTPUT, VVS_LOCATION_MSG, __FILE__, __LINE__); \
    } \
}

/**
 * Verify that the given expression is false
 * @param EXP the given expression
 */
#define VVS_CHECK_FALSE(EXP) \
{ \
    int _isTrue = (int)(EXP); \
    fprintf(VVS_OUTPUT, "[CHECK_FALSE] " #EXP); \
    if (!_isTrue) fprintf(VVS_OUTPUT, VVS_SUCCESS_MSG); \
    else \
    { \
        fprintf(VVS_OUTPUT, VVS_FAILURE_MSG); \
        fprintf(VVS_OUTPUT, VVS_LOCATION_MSG, __FILE__, __LINE__); \
    } \
}

/**
 * Verify that the given two real values are near
 * @param VAL1 the first real value
 * @param VAL2 the second real value
 */
#define VVS_CHECK_CLOSE(VAL1, VAL2) \
{ \
    double _delta = ((double)(VAL1) - (double)(VAL2)); \
    int _isClose = (-VVS_EPSILON < _delta) && (_delta < +VVS_EPSILON); \
    fprintf(VVS_OUTPUT, "[CHECK_CLOSE] " #VAL1 " == " #VAL2); \
    if (_isClose) fprintf(VVS_OUTPUT, VVS_SUCCESS_MSG); \
    else \
    { \
        fprintf(VVS_OUTPUT, VVS_FAILURE_MSG); \
        fprintf(VVS_OUTPUT, VVS_LOCATION_MSG, __FILE__, __LINE__); \
    } \
}

/**
 * Run the given expression or function (a set of tests)
 * @param EXP the given expression or function
 */
#define VVS_RUN_TEST(EXP) \
{ \
    fprintf(VVS_OUTPUT, "=== " #EXP " ===" "\n"); \
    clock_t _t = clock(); \
    (EXP); \
    _t = clock() - _t; \
    fprintf(VVS_OUTPUT, VVS_TIME_MSG, ((double)_t) / CLOCKS_PER_SEC); \
} \

/**
 * Do not run the given expression
 * <p>
 * It is useful to disable RUN_UNIT_TEST instead of applying comment.
 * @param EXP the given expression or function
 */
#define VVS_NUN_TEST(EXP)               { }

#endif // End of '__VVS_UNIT_TEST__'
