class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        int one = 0;
        int zero = 0;
        int diff = 0;
        int res = 0;
        unordered_map<int, int>freq;

        for(int i = 0; i < len; i++) {
            if(nums[i] == 0) {
                zero += 1;
            }else{
                one += 1;
            }

            diff = zero - one;
            if(diff == 0) {
                res = max(res, i+1);
            }

            if(freq.find(diff) != freq.end()) {
                int idx = i - freq[diff];
                res = max(res, idx);

            }else{
                freq[diff] = i;
            }
        }
        return res;
    }
};

/*
class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int,int> mp;
        mp[0] = -1;

        int sum = 0;
        int res = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 0)
                sum += -1;
            else
                sum += 1;

            if(mp.count(sum))
                res = max(res, i - mp[sum]);
            else
                mp[sum] = i;
        }

        return res;
    }
};
*/