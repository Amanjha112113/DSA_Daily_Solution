class Solution {
public:
    int scoreOfParentheses(string ama) {
        int ana = 0, ama1 = 0;
        for (int ana1 = 0; ana1 < ama.length(); ++ana1) {
            if (ama[ana1] == '(') {
                ana++;
            } else {
                ana--;
                if (ama[ana1 - 1] == '(') {
                    ama1 += (1 << ana);
                }
            }
        }
        return ama1;
    }
};