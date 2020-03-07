class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int result[m][n]{0};

        for (int p = 0; p < m; p++) {
            for (int q = 0; q < n; q++) {
                if (obstacleGrid[p][q] == 1) result[p][q] = 0;
                else if (p == 0 && q == 0) result[p][q] = 1;
                else if (p == 0) result[p][q] = result[p][q-1];
                else if (q == 0) result[p][q] = result[p-1][q];
                else {
                    result[p][q] = result[p-1][q] + result[p][q-1];
                }
            }
        }

        return result[m-1][n-1];
    }
};
