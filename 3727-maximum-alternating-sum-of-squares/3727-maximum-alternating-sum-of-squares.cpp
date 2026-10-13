class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int ama = nums.size();
        vector<long long> ana(ama);
        for (int ama1 = 0; ama1 < ama; ++ama1) {
            long long ama2 = nums[ama1];
            ana[ama1] = ama2 * ama2;
        }
        sort(ana.begin(), ana.end());
        long long ama3 = 0;
        for (int ama1 = 0; ama1 < ama; ++ama1) {
            ama3 += ana[ama1];
        }
        long long ama4 = 0;
        int ama5 = ama / 2;
        for (int ama1 = 0; ama1 < ama5; ++ama1) {
            ama4 += ana[ama1];
        }
        return ama3 - 2 * ama4;
    }
};