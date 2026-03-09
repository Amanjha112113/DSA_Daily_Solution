class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sums = 0;
        int left = 0;
        for(int val : nums) {
            sums += val;
        }

        for(int i = 0; i < n; i++) {
            int right = sums - nums[i] - left;
            if(left == right)
                return i;
            left += nums[i];
        }
        return -1;
    }
};
