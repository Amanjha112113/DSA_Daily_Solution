class Solution {
public:
    bool checkValidString(string ama) {
        int ana = 0, ama1 = 0;
        for (int ana1 = 0; ana1 < ama.length(); ++ana1) {
            if (ama[ana1] == '(') {
                ana++;
                ama1++;
            } else if (ama[ana1] == ')') {
                ana--;
                ama1--;
            } else {
                ana--;
                ama1++;
            }
            if (ama1 < 0) return false;
            if (ana < 0) ana = 0;
        }
        return ana == 0;
    }
};