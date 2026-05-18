class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = magazine.size();
        unordered_map<char, int> f;

        for(int i = 0; i < n; i++) {
            f[magazine[i]]++; 
        }

        for(int i = 0; i < ransomNote.size(); i++) {
            
            if(f[ransomNote[i]] <= 0) {
                return false;
            }
            
            f[ransomNote[i]]--;
        }
        return true;
    }
};