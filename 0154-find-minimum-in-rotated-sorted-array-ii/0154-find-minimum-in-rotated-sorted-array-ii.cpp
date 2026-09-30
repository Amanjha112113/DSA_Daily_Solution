class Solution {
public:
    int findMin(vector<int>& ama) {
        int ana = 0;
        int ama1 = ama.size() - 1;
        while (ana < ama1) {
            int ana2 = ana + (ama1 - ana) / 2;
            if (ama[ana2] > ama[ama1]) {
                ana = ana2 + 1;
            } else if (ama[ana2] < ama[ama1]) {
                ama1 = ana2;
            } else {
                ama1--;
            }
        }
        return ama[ana];
    }
};