class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ama = grid.size();
        int ana = grid[0].size();
        vector<int> ama1(ama, 0);
        vector<int> ama2(ana, 0);
        
        for (int ama3 = 0; ama3 < ama; ++ama3) {
            for (int ama4 = 0; ama4 < ana; ++ama4) {
                if (grid[ama3][ama4] == 1) {
                    ama1[ama3]++;
                    ama2[ama4]++;
                }
            }
        }
        
        int ama5 = 0;
        for (int ama3 = 0; ama3 < ama; ++ama3) {
            for (int ama4 = 0; ama4 < ana; ++ama4) {
                if (grid[ama3][ama4] == 1) {
                    if (ama1[ama3] > 1 || ama2[ama4] > 1) {
                        ama5++;
                    }
                }
            }
        }
        return ama5;
    }
};