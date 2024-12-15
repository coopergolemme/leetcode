#include <vector>


using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++){
                if (i == 0)
                {
                    obstacleGrid.at(i).at(j) += obstacleGrid.at(i).at(j - 1);
                }
                else if (j == 0){
                    obstacleGrid.at(i).at(j) += obstacleGrid.at(i - 1).at(j);
                }
                else{
                    obstacleGrid.at(i).at(j) += min(obstacleGrid.at(i - 1).at(j), obstacleGrid.at(i).at(j - 1));
                }
            }
        }
        return obstacleGrid.at(n).at(m);
    }
};