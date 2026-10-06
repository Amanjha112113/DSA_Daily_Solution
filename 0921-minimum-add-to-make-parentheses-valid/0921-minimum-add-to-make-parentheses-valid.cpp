class Solution {
public:
    int minAddToMakeValid(string ama) {
        int ana = 0, ama1 = 0;
        for (int ana1 = 0; ana1 < ama.length(); ++ana1) {
            if (ama[ana1] == '(') {
                ana++;
            } else {
                if (ana > 0) {
                    ana--;
                } else {
                    ama1++;
                }
            }
        }
        return ana + ama1;
    }
};