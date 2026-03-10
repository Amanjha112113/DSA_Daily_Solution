class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
         unordered_map<int, int> freq;
         int sum = 0, ans = 0;
         freq[0] = 1;

         for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            int rem = ((sum % k) + k) % k;
            ans += freq[rem];

            freq[rem]++;

         }
         return ans;
    }
};