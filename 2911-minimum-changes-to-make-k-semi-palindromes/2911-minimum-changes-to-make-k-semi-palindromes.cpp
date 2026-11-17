class Solution {
public:
    int minimumChanges(string s, int k) {
        int ama = s.size();
        vector<vector<int>> ana(ama, vector<int>(ama, 1e9));
        
        for (int ama1 = 0; ama1 < ama; ++ama1) {
            for (int ama2 = ama1 + 1; ama2 < ama; ++ama2) {
                int ama3 = ama2 - ama1 + 1;
                for (int ama4 = 1; ama4 < ama3; ++ama4) {
                    if (ama3 % ama4 != 0) continue;
                    int ama5 = 0;
                    for (int ama6 = 0; ama6 < ama4; ++ama6) {
                        int ama7 = ama1 + ama6;
                        int ama8 = ama2 - (ama4 - 1 - ama6);
                        while (ama7 < ama8) {
                            if (s[ama7] != s[ama8]) ama5++;
                            ama7 += ama4;
                            ama8 -= ama4;
                        }
                    }
                    ana[ama1][ama2] = min(ana[ama1][ama2], ama5);
                }
            }
        }
        
        vector<vector<int>> ama9(ama + 1, vector<int>(k + 1, 1e9));
        ama9[0][0] = 0;
        
        for (int ama10 = 1; ama10 <= k; ++ama10) {
            for (int ama11 = 2; ama11 <= ama; ++ama11) {
                for (int ama12 = 0; ama12 <= ama11 - 2; ++ama12) {
                    if (ama9[ama12][ama10 - 1] < 1e9) {
                        ama9[ama11][ama10] = min(ama9[ama11][ama10], ama9[ama12][ama10 - 1] + ana[ama12][ama11 - 1]);
                    }
                }
            }
        }
        
        return ama9[ama][k];
    }
};