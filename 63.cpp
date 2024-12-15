#include <vector>


using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> DP(n, vector<int>(m, 0));

        if(obstacleGrid.at(0).at(0) == 0)
            return false;
    
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++){
                if(obstacleGrid.at(i).at(j) == 0){
                    DP.at(i).at(j) = 0;
                }
                else if (i == 0 && j == 0)
                {
                    DP.at(i).at(j) = 1;
                }
                else if (i == 0)
                {
                    DP.at(i).at(j) = DP.at(i).at(j - 1);
                }
                else if (j == 0){
                    DP.at(i).at(j) = DP.at(i-1).at(j);
                }
                else{

                DP.at(i).at(j) = DP.at(i - 1).at(j) + DP.at(i).at(j - 1);
                }
            }
        }
    }
};