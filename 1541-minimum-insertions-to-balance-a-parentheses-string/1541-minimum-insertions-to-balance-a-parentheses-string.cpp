class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        int needed_right = 0;

        for (char c : s) {
            if (c == '(') {
                needed_right += 2;
                if (needed_right % 2 != 0) {
                    res++;
                    needed_right--;
                }
            } else { // c == ')'
                needed_right--;
                if (needed_right < 0) {
                    res++; // Add an opening '('
                    needed_right += 2;
                }
            }
        }

        return res + needed_right;
    }
};