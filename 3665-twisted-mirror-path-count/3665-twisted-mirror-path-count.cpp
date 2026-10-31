class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int ama = grid.size();
        int ana = grid[0].size();
        long long ama1 = 1000000007;
        vector<vector<long long>> ama2(ama, vector<long long>(ana, 0));
        ama2[0][0] = 1;

        auto ama3 = [&](int r, int c, int d) {
            while (true) {
                if (d == 0) c++;
                else r++;
                if (r < 0 || r >= ama || c < 0 || c >= ana) return make_pair(-1, -1);
                if (grid[r][c] == 0) return make_pair(r, c);
                d = 1 - d;
            }
        };

        for (int ama4 = 0; ama4 < ama; ++ama4) {
            for (int ama5 = 0; ama5 < ana; ++ama5) {
                if (ama2[ama4][ama5] == 0) continue;
                if (ama4 == ama - 1 && ama5 == ana - 1) continue;
                
                pair<int, int> ama6 = ama3(ama4, ama5, 0);
                if (ama6.first != -1) {
                    ama2[ama6.first][ama6.second] = (ama2[ama6.first][ama6.second] + ama2[ama4][ama5]) % ama1;
                }
                
                pair<int, int> ama7 = ama3(ama4, ama5, 1);
                if (ama7.first != -1) {
                    ama2[ama7.first][ama7.second] = (ama2[ama7.first][ama7.second] + ama2[ama4][ama5]) % ama1;
                }
            }
        }
        return ama2[ama - 1][ana - 1];
    }
};