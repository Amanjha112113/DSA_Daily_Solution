class Solution {
public:
    string reverseParentheses(string ama) {
        vector<int> ana;
        for (int ama1 = 0; ama1 < ama.length(); ++ama1) {
            if (ama[ama1] == '(') {
                ana.push_back(ama1);
            } else if (ama[ama1] == ')') {
                int ana2 = ana.back();
                ana.pop_back();
                reverse(ama.begin() + ana2 + 1, ama.begin() + ama1);
            }
        }
        string ama2 = "";
        for (int ama1 = 0; ama1 < ama.length(); ++ama1) {
            if (ama[ama1] != '(' && ama[ama1] != ')') {
                ama2 += ama[ama1];
            }
        }
        return ama2;
    }
};