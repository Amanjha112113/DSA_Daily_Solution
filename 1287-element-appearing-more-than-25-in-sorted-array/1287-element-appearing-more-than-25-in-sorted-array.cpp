class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        unordered_map<int, int> freq;

        for(int x : arr) {
            freq[x]++;
        }
        for(auto x : freq) {
            if(x.second > (n/4)) {
                return x.first;
            }
        }
        return -1;
    }
};