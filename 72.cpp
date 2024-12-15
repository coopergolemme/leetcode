#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length() + 1;
        int m = word2.length() + 1;

        vector<vector<int>> DP(n, vector<int>(m, 0));

        for (int i = 0; i <= n; i++){
            DP.at(0).at(i) = i;
            DP.at(i).at(0) = i;
        }

        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                int val1 = DP.at(i - 1).at(j) + 1;
                int val2 = DP.at(i).at(j-1) + 1;
                int val3 = DP.at(i).at(j);

                int minimum = min(val1, val2);

                if (word1.at(i) == word2.at(j)){
                    minimum = min(minimum, val3);
                }

                DP.at(i).at(j) = minimum;
            }
        }
        return DP.at(n - 1).at(m - 1);
    }
};