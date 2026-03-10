/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int total = 0;

        for(int i = 0; i < len; i++) {
            int subarray = 0;

            for(int j = i; j < len; j++) {
                subarray += nums[j];
                if(subarray == k)
                    total++;
            }
        }
        return total;
    }
};
*/
// vs Optimal Appraoch (HashMap)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        unordered_map<int, int> freq;
        freq[0] = 1;
        int sum = 0;
        int ans = 0;

        for(int i = 0; i < len; i++) {
            sum += nums[i];
            int ques = (sum - k);
            int f = freq[ques];
            ans += f;
            freq[sum]++;
        }
        return ans;
    }
};

