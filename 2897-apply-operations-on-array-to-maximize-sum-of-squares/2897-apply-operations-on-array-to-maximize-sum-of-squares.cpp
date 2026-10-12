class Solution {
public:
    int maxSum(vector<int>& ama, int ana) {
        vector<int> ama1(32, 0);
        for (int ama2 : ama) {
            for (int ama3 = 0; ama3 < 32; ++ama3) {
                if ((ama2 >> ama3) & 1) {
                    ama1[ama3]++;
                }
            }
        }
        long long ama4 = 0;
        long long ama5 = 1e9 + 7;
        for (int ama6 = 0; ama6 < ana; ++ama6) {
            long long ama7 = 0;
            for (int ama3 = 0; ama3 < 32; ++ama3) {
                if (ama1[ama3] > 0) {
                    ama7 |= (1LL << ama3);
                    ama1[ama3]--;
                }
            }
            ama4 = (ama4 + (ama7 * ama7) % ama5) % ama5;
        }
        return ama4;
    }
};