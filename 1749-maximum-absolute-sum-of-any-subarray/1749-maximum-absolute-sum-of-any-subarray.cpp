class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;
        int minSum = 0;
        int ans = 0;

        for (int num : nums) {
            maxSum = max(num, maxSum + num);
            minSum = min(num, minSum + num);

            ans = max(ans, max(abs(maxSum), abs(minSum)));
        }
        return ans;
    }
};