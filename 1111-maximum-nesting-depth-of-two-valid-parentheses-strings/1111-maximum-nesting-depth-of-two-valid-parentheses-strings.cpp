class Solution {
public:
    vector<int> maxDepthAfterSplit(string ama) {
        int ana1 = ama.length();
        vector<int> ana(ana1);
        int ama1 = 0;
        for (int ama2 = 0; ama2 < ana1; ++ama2) {
            if (ama[ama2] == '(') {
                ama1++;
                ana[ama2] = ama1 % 2;
            } else {
                ana[ama2] = ama1 % 2;
                ama1--;
            }
        }
        return ana;
    }
};