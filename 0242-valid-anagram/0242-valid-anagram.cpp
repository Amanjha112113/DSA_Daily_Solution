class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>freq;

        for(int x : s) {
            freq[x]++;
        }
        
        for(int y : t) {
            freq[y]--;

            if(freq[y] == 0) {
                freq.erase(y);
            }
        }
        return freq.empty();
    }
};