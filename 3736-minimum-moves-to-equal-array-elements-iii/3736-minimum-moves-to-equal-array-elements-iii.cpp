class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxVal = nums[0];
        long long sum = 0;
        for (int x : nums) {
            maxVal = max(maxVal, x);
            sum += x;
        }
        return (long long)maxVal * nums.size() - sum;
    }
};



