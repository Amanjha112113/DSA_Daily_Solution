class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int slow = 0, fast = 0;       // LinkedList in Array Problem.

        while(true) {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];

            if(slow == fast) {
                slow = 0;
                while(slow != fast) {  // Match the starting point of circle.
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
        return NULL;
    }
};