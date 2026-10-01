class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& ama) {
        unordered_map<double, long long> ana;
        long long ama1 = 0;
        for (const auto& ana1 : ama) {
            double ama2 = (double)ana1[0] / ana1[1];
            ama1 += ana[ama2];
            ana[ama2]++;
        }
        return ama1;
    }
};