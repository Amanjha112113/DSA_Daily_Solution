class Solution {
public:
    int minOperations(string s) {
        int ama = s.size();
        bool ana = true;
        for (int ama1 = 1; ama1 < ama; ++ama1) {
            if (s[ama1] < s[ama1 - 1]) {
                ana = false;
                break;
            }
        }
        if (ana) {
            return 0;
        }
        if (ama == 2) {
            return -1;
        }
        char ama2 = *min_element(s.begin(), s.end());
        char ama3 = *max_element(s.begin(), s.end());
        if (s[0] == ama2 || s[ama - 1] == ama3) {
            return 1;
        }
        for (int ama1 = 1; ama1 < ama - 1; ++ama1) {
            if (s[ama1] == ama2 || s[ama1] == ama3) {
                return 2;
            }
        }
        return 3;
    }
};