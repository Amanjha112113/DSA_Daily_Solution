class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minval = INT_MAX;
        int n = nums.size();

        for (int low = 0; low < n; ++low) {
            int sum = 0;
            for (int high = low; high < n; ++high) {
                sum += nums[high];
                int len = high - low + 1;
                if (len >= l && len <= r && sum > 0) {
                    minval = min(minval, sum);
                }
            }
        }

        return minval == INT_MAX ? -1 : minval;
    }
};