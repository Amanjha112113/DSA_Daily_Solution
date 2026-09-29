class Solution {
    bool ama1[105][105][205];

    bool ana1(vector<vector<char>>& ama, int ana, int ama2, int ana2, int ama3, int ana3) {
        if (ana2 < 0) return false;
        if (ana == ama3 - 1 && ama2 == ana3 - 1) {
            return ana2 == 0;
        }
        if (ama1[ana][ama2][ana2]) return false;
        ama1[ana][ama2][ana2] = true;

        if (ana + 1 < ama3) {
            int ana4 = ana2 + (ama[ana + 1][ama2] == '(' ? 1 : -1);
            if (ana1(ama, ana + 1, ama2, ana4, ama3, ana3)) return true;
        }
        if (ama2 + 1 < ana3) {
            int ana4 = ana2 + (ama[ana][ama2 + 1] == '(' ? 1 : -1);
            if (ana1(ama, ana, ama2 + 1, ana4, ama3, ana3)) return true;
        }
        return false;
    }

public:
    bool hasValidPath(vector<vector<char>>& ama) {
        int ana = ama.size();
        int ama2 = ama[0].size();
        if ((ana + ama2 - 1) % 2 != 0) return false;
        if (ama[0][0] == ')' || ama[ana - 1][ama2 - 1] == '(') return false;

        for (int ana3 = 0; ana3 < ana; ++ana3) {
            for (int ama3 = 0; ama3 < ama2; ++ama3) {
                for (int ana4 = 0; ana4 <= (ana + ama2) / 2; ++ana4) {
                    ama1[ana3][ama3][ana4] = false;
                }
            }
        }

        return ana1(ama, 0, 0, 1, ana, ama2);
    }
};