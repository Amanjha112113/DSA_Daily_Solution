class Solution {
public:
    long long ama = 1e9 + 7;
    vector<vector<long long>> ana;

    long long ama1(int ama2, int ama3) {
        if (ama3 == 0 || ama3 == ama2) return 1;
        if (ana[ama2][ama3] != -1) return ana[ama2][ama3];
        return ana[ama2][ama3] = (ama1(ama2 - 1, ama3 - 1) + ama1(ama2 - 1, ama3)) % ama;
    }

    long long ama4(vector<int>& ama5) {
        int ama6 = ama5.size();
        if (ama6 <= 2) return 1;

        vector<int> ama7, ama8;
        int ama9 = ama5[0];
        for (int ama10 = 1; ama10 < ama6; ++ama10) {
            if (ama5[ama10] < ama9) {
                ama7.push_back(ama5[ama10]);
            } else {
                ama8.push_back(ama5[ama10]);
            }
        }

        long long ama11 = ama4(ama7);
        long long ama12 = ama4(ama8);

        long long ama13 = ama1(ama6 - 1, ama7.size());
        long long ama14 = (ama13 * ama11) % ama;
        return (ama14 * ama12) % ama;
    }

    int numOfWays(vector<int>& nums) {
        int ama6 = nums.size();
        ana = vector<vector<long long>>(ama6 + 1, vector<long long>(ama6 + 1, -1));
        long long ama15 = ama4(nums);
        return (ama15 - 1 + ama) % ama;
    }
};