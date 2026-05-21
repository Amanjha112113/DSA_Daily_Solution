class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, int>f;
        bool b = false;

        for(int i = 0; i < n; i++) {
            f[nums[i]]++;
        }
        for(auto i : f) {
            if(i.second > 1){
                 b = true;
            }
        }
        return b;
    }
};
