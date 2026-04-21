class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < len - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1])
                    continue;
            
            for(int j = i + 1; j < len - 2; j++) {
                
                if (j > i + 1 && nums[j] == nums[j - 1]) 
                    continue;

                
                int left = j + 1; 
                int right = len - 1;
                
                
                while(left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if(sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        
                        // Skip duplicates for left
                        while (left < right && nums[left] == nums[left - 1]) 
                            left++;
                        // Skip duplicates for right
                        while (left < right && nums[right] == nums[right + 1]) 
                            right--;

                    }else if(sum < target) {
                        left++;
                    }else{
                        right--;
                    }
                }
            }
        }
        return res;
    }
};