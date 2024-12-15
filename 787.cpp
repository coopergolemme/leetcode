#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Using dynamic programming to find the cheapest price with at most k stops
        // adj is an adjacency list where adj[u] contains pairs {v, w} meaning there is a flight from u to v with cost w
        // dp[i][j] represents the minimum cost to reach node j using at most i flights
        vector<vector<pair<int, int>>> adj(n);
        
        // Construct the adjacency list from the input
        // flights is a list of triples {u, v, w} meaning there is a flight from u to v with cost w
        // We add this flight to the adjacency list adj[u] as a pair {v, w}
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        //  dp[i][j] represents the minimum cost to reach node j using at most i flights
        // Initialize all values to INT_MAX except for dp[0][src] which is 0
        vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX));
        dp[0][src] = 0;
        
        // Iterate over all possible number of flights from 1 to k + 1
        // For each number of flights i, we update the minimum cost to reach each node j
        // by considering all flights from the previous number of flights i - 1
        for (int i = 1; i <= k + 1; i++) {
            dp[i][src] = 0;
            for (int j = 0; j < n; j++) {
                dp[i][j] = dp[i - 1][j];
            }
            for (int j = 0; j < n; j++) {
                for (auto& p : adj[j]) {
                    int v = p.first;
                    int w = p.second;
                    if (dp[i - 1][j] != INT_MAX) {
                        dp[i][v] = min(dp[i][v], dp[i - 1][j] + w);
                    }
                }
            }
        }

        return dp[k + 1][dst] == INT_MAX ? -1 : dp[k + 1][dst];
    }
};