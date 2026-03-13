class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        vector<string> v;


        for(int i = 0; i < n; i++) {
            if(s[i] == ' '){
                continue;
            }
            string newstring = "";
            while(i < n && s[i] != ' '){
                newstring += s[i];
                i++;
            }
            v.push_back(newstring);
        }


        int len = v.size(); 
        int left = 0;
        int right = len - 1;

        while(left < right) {
            swap(v[left], v[right]);
            left++;
            right--;
        }


        string res = "";
        for(int i = 0; i < len; i++) {
            res += v[i];
            if(i < len - 1)
                res += " ";
        }

        return res;
    }
};