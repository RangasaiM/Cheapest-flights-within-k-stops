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
        {4, {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}}, 0, 3, 1, 700},
        {3, {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}}, 0, 2, 1, 200},
        {3, {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}}, 0, 2, 0, 500},
        {2, {}, 0, 1, 1, -1},
    };

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
