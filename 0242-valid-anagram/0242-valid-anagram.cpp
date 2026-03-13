class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();

        if(len1 != len2) return false;

        //unordered_map<char, int>freq;  // hash or vector Both applicable
        vector<int> freq(26, 0);

        for(int i = 0; i < len1; i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for(auto x : freq) {
            if(x != 0)
                return false;
        }
        return true;
    }
};

