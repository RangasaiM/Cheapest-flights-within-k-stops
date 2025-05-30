#include <bits/stdc++.h>
using namespace std;
#include "../solutions/solution.cpp"

using namespace std;

int main()
{
    Solution sol;
    struct TestCase
    {
        int n;
        vector<vector<int>> flights;
        int src, dst, k, expected;
    };

    vector<TestCase> tests = {
        {5, {{0, 1, 100}, {1, 2, 100}, {2, 3, 100}, {3, 4, 100}, {0, 4, 1000}}, 0, 4, 3, 400},
        {4, {{0, 1, 100}, {1, 2, 100}, {2, 3, 100}, {0, 3, 500}}, 0, 3, 1, 500},
        {4, {{0, 1, 300}, {1, 2, 300}, {2, 3, 300}, {0, 2, 1000}, {0, 3, 2000}}, 0, 3, 2, 900},
        {5, {{0, 1, 50}, {1, 2, 50}, {2, 3, 50}, {3, 4, 50}, {0, 4, 1000}}, 0, 4, 1, 1000},
        {3, {{0, 1, 100}, {1, 0, 100}, {1, 2, 300}}, 0, 2, 10, 400},
        {6, {{0, 1, 10}, {1, 2, 10}, {2, 3, 10}, {3, 4, 10}, {4, 5, 10}, {0, 5, 1000}}, 0, 5, 4, 50},
        {3, {{0, 1, 100}, {1, 2, 100}}, 0, 2, 0, -1},
        {3, {{0, 1, 100}, {1, 2, 100}, {0, 2, 600}}, 0, 2, 2, 200},
        {4, {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {0, 3, 100}}, 0, 3, 2, 3},
        {3, {}, 0, 2, 1, -1}};

    bool failed = false;

    for (int i = 0; i < (int)tests.size(); i++)
    {
        int res = sol.findCheapestPrice(tests[i].n, tests[i].flights, tests[i].src, tests[i].dst, tests[i].k);
        cout << "Test Case " << i + 1 << ": ";
        if (res == tests[i].expected)
        {
            cout << "PASSED ✅ (Output: " << res << ")" << endl;
        }
        else
        {
            cout << "FAILED ❌ (Output: " << res << ", Expected: " << tests[i].expected << ")" << endl;
            failed = true;
        }
    }

    return failed ? 1 : 0;
}
