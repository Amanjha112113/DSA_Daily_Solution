class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++) {      // O(N)
            nums[i] *= nums[i]; 
        }

        vector<int>res(len);
        int left = 0;
        int right = len - 1;
        int index = len - 1;

        while(left <= right) {        // O(n)    
            if(nums[left] < nums[right]){
                res[index] = nums[right];
                right--;

            }else{
                res[index] = nums[left];
                left++;
            }
            index--;
        }   
        return res;
    }
};  




// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int len = nums.size();
//         for(int i = 0; i < len; i++) {      // O(N)
//             nums[i] *= nums[i]; 
//         }
//         sort(nums.begin(), nums.end());     // O(N logN)  // O(N logN) * O(n) == O(N logN)  
//         return nums;
//     }
// };  


