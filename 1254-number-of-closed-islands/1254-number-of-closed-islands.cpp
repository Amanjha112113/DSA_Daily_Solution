class Solution {
public:
    void dfs(vector<vector<int>>& ama, int ana, int ama1) {
        int ama2 = ama.size();
        int ama3 = ama[0].size();
        if (ana < 0 || ama1 < 0 || ana >= ama2 || ama1 >= ama3 || ama[ana][ama1] == 1) return;
        ama[ana][ama1] = 1;
        dfs(ama, ana + 1, ama1);
        dfs(ama, ana - 1, ama1);
        dfs(ama, ana, ama1 + 1);
        dfs(ama, ana, ama1 - 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int ama = grid.size();
        int ana = grid[0].size();
        for (int ama1 = 0; ama1 < ama; ++ama1) {
            if (grid[ama1][0] == 0) dfs(grid, ama1, 0);
            if (grid[ama1][ana - 1] == 0) dfs(grid, ama1, ana - 1);
        }
        for (int ama2 = 0; ama2 < ana; ++ama2) {
            if (grid[0][ama2] == 0) dfs(grid, 0, ama2);
            if (grid[ama - 1][ama2] == 0) dfs(grid, ama - 1, ama2);
        }
        int ama3 = 0;
        for (int ama1 = 0; ama1 < ama; ++ama1) {
            for (int ama2 = 0; ama2 < ana; ++ama2) {
                if (grid[ama1][ama2] == 0) {
                    ama3++;
                    dfs(grid, ama1, ama2);
                }
            }
        }
        return ama3;
    }
};