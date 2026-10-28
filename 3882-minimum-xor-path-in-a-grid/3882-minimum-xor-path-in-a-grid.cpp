class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(1024, false)));
        dp[0][0][grid[0][0]] = true;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int v = 0; v < 1024; ++v) {
                    if(!dp[i][j][v]) continue;
                    
                    if(j + 1 < n) {
                        dp[i][j + 1][v ^ grid[i][j + 1]] = true;
                    }
                    if(i + 1 < m) {
                        dp[i + 1][j][v ^ grid[i + 1][j]] = true;
                    }
                }
            }
        }
        for(int v = 0; v < 1024; ++v) {
            if(dp[m - 1][n - 1][v]) return v;
        }
        return -1;
    }
};