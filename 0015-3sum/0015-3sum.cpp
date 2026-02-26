class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>>res;

        for(int i = 0; i < len - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int left = i + 1;
            int right = len - 1;
            
            while(left < right) {
                int sums = nums[i] + nums[left] + nums[right];

                if(sums == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    
                    // remove dublicates. left
                    while(left < right && nums[left] == nums[left - 1]){
                        left++;
                    }

                    // remove dublicates. right
                    while(left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }

                }else if(sums < 0) {
                    left++;

                }else{
                    right--;
                }
            }
        }
        return res;
    }
};