class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int left = 0; 
        int right = len - 1;
        int maxcap = INT_MIN;

        while(left < right) {
            int val = abs(right - left) * min(height[left], height[right]);
            maxcap = max(maxcap, val);

            if(height[left] < height[right]) {
                left++;
            }else{
                right--;
            }
        }
        return maxcap;
    }
};
