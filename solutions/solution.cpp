#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> costs(n, INT_MAX);
        costs[src] = 0;

        // Perform k+1 iterations (k stops = k+1 flights)
        for (int stops = 0; stops <= k; stops++)
        {
            vector<int> tempCosts = costs; // Copy to avoid using updated values

            // Try all flights
            for (const auto &flight : flights)
            {
                int from = flight[0], to = flight[1], price = flight[2];

                // If we can reach 'from' city and found a cheaper path to 'to'
                if (costs[from] != INT_MAX && costs[from] + price < tempCosts[to])
                {
                    tempCosts[to] = costs[from] + price;
                }
            }
            costs = tempCosts;
        }

        return costs[dst] == INT_MAX ? -1 : costs[dst];
    }
};
