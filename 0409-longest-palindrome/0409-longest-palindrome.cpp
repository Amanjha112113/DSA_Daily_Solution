class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();

        unordered_map<char, int> f;

        for(int i = 0; i < n; i++) {
            f[s[i]]++;
        }

        bool odd = false;
        int res = 0;

        for(auto i : f) {

            int val = i.second;
            if(val % 2 == 0) {
                res += val;
            }else{
                odd = true;
                res += val - 1;
            }
        }
        if(odd == false) {
            return res;
        }
        return res + 1;
    }
};