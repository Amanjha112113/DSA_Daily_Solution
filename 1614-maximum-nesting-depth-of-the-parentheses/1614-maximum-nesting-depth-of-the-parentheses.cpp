class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, c = 0;
        for (char x : s) {
            if (x == '(') {
                c++;
                ans = max(ans, c);
            } else if (x == ')') {
                c--;
            }
        }
        return ans;
    }
};