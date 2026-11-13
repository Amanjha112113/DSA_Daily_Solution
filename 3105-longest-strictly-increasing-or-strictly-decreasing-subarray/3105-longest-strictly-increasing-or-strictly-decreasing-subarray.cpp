class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ama = 1, ana = 1, ama1 = 1;
        for (int ama2 = 1; ama2 < nums.size(); ++ama2) {
            if (nums[ama2] > nums[ama2 - 1]) {
                ana++;
                ama1 = 1;
            } else if (nums[ama2] < nums[ama2 - 1]) {
                ama1++;
                ana = 1;
            } else {
                ana = 1;
                ama1 = 1;
            }
            ama = max(ama, max(ana, ama1));
        }
        return ama;
    }
};