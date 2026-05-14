class Solution {
public:
    bool isGood(vector<int>& nums) {
        int s = nums.size();
        sort(nums.begin(), nums.end());

        if(s != nums[s - 1] + 1) {
            return false;
        }

        for(int i = 0; i < s - 1; i++) {
            if(nums[i] != i + 1) {
                return false;
            }
        }
        return nums[s - 1] = s - 1; 
    }
};

