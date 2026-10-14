 class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int ama = num;
        int ana = sum;
        string ama1 = "";
        for (int ama2 = 0; ama2 < ama; ++ama2) {
            int ama3 = min(9, ana);
            ama1 += to_string(ama3);
            ana -= ama3;
        }
        if (ana > 0) {
            return "";
        }
        return ama1;
    }
};