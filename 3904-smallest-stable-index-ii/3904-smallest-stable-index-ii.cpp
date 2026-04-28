class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> v = nums;
        vector<int> pm(n), sm(n);

        pm[0] = v[0];
        for(int i = 1; i < n; i++) {
            pm[i] = max(pm[i - 1], v[i]);
        }

        sm[n - 1] = v[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            sm[i] = min(sm[i + 1], v[i]);
        }

        for(int i = 0; i < n; i++) {
            if(pm[i] - sm[i] <= k){
                return i;
            }
        }
        return -1;
    }
};