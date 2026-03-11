class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target) {
                return mid;

            }else if(nums[mid] > target) {
                right--;

            }else{
                left++;
            }
        }
        return -1;
    }
};