class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ama = nums.size();
        int ana = nums[ama / 2];
        long long ama1 = 0;
        for (int ama2 = 0; ama2 < ama; ++ama2) {
            ama1 += abs(nums[ama2] - ana);
        }
        return ama1;
    }
};