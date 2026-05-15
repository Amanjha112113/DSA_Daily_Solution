class Solution {
public:
    string removeDuplicates(string s) {

        int length = s.size();
        stack<char>stack1;
        stack1.push(s[0]);

        for(int i = 1; i < length; i++) {

            if(stack1.empty()) {
                stack1.push(s[i]);

            }else {

                char ch = stack1.top();
                if(ch == s[i]) {
                    stack1.pop();
                }else{
                    stack1.push(s[i]);
                }
            }
        }

        string ans;

        while(!stack1.empty()) {
            ans.push_back(stack1.top());
            stack1.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
