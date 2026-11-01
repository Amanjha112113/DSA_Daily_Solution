class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ama = nums[0];
        long long ana = 0;
        for (int ama1 : nums) {
            ama = min(ama, ama1);
            ana += ama1;
        }
        return ana - (long long)ama * nums.size();
    }
};