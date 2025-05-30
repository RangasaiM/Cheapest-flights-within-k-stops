/* Write your C test cases here */
#include <stdio.h>
#include <stdlib.h>
#include "../solutions/solution.c"

// Declare the function prototype from solution.c
int findCheapestPrice(int n, int **flights, int flightsSize, int *flightsColSize, int src, int dst, int k);

// Helper to create flights matrix for a test case
int **createFlights(int flights[][3], int size)
{
    int **arr = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        arr[i] = (int *)malloc(3 * sizeof(int));
        arr[i][0] = flights[i][0];
        arr[i][1] = flights[i][1];
        arr[i][2] = flights[i][2];
    }
    return arr;
}

int main()
{
    struct TestCase
    {
        int n;
        int flights[10][3];
        int flightsSize;
        int src, dst, k, expected;
    } tests[] = {
        {5, {{0, 1, 100}, {1, 2, 100}, {2, 3, 100}, {3, 4, 100}, {0, 4, 1000}}, 5, 0, 4, 3, 400},
        {4, {{0, 1, 100}, {1, 2, 100}, {2, 3, 100}, {0, 3, 500}}, 4, 0, 3, 1, 500},
        {4, {{0, 1, 300}, {1, 2, 300}, {2, 3, 300}, {0, 2, 1000}, {0, 3, 2000}}, 4, 0, 3, 2, 900},
        {5, {{0, 1, 50}, {1, 2, 50}, {2, 3, 50}, {3, 4, 50}, {0, 4, 1000}}, 5, 0, 4, 1, 1000},
        {3, {{0, 1, 100}, {1, 0, 100}, {1, 2, 300}}, 3, 0, 2, 10, 400},
        {6, {{0, 1, 10}, {1, 2, 10}, {2, 3, 10}, {3, 4, 10}, {4, 5, 10}, {0, 5, 1000}}, 6, 0, 5, 4, 50},
        {3, {{0, 1, 100}, {1, 2, 100}}, 3, 0, 2, 0, -1},
        {3, {{0, 1, 100}, {1, 2, 100}, {0, 2, 600}}, 3, 0, 2, 2, 200},
        {4, {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {0, 3, 100}}, 4, 0, 3, 2, 3},
        {3, {}, 3, 0, 2, 1, -1}};

    int flightsColSize[10] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

    int failed = 0;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        int **flightsArr = createFlights(tests[i].flights, tests[i].flightsSize);
        int res = findCheapestPrice(tests[i].n, flightsArr, tests[i].flightsSize, flightsColSize, tests[i].src, tests[i].dst, tests[i].k);
        printf("Test Case %d: ", i + 1);
        if (res == tests[i].expected)
        {
            printf("PASSED ✅ (Output: %d)\n", res);
        }
        else
        {
            printf("FAILED ❌ (Output: %d, Expected: %d)\n", res, tests[i].expected);
            failed = 1;
        }
        for (int j = 0; j < tests[i].flightsSize; j++)
        {
            free(flightsArr[j]);
        }
        free(flightsArr);
    }
    return failed;
}
