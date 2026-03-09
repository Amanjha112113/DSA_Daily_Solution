class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.empty()) return "";
        
        int n = strs.size();
        sort(strs.begin(), strs.end());
        int i = 0;
        string str = "";

        while(i < strs[0].size() && i < strs[n - 1].size()) {
            if(strs[0][i] == strs[n - 1][i]) {
                str += strs[0][i];
                i++;
            }else{
                break;
            }
        }
        return str;
    }
};