class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int ama = queries.size();
        vector<vector<int>> ana(ama, vector<int>(2));
        for (int ama1 = 0; ama1 < ama; ++ama1) {
            ana[ama1][0] = queries[ama1];
            ana[ama1][1] = ama1;
        }
        sort(ana.begin(), ana.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> ama2(ama);
        vector<int> ama3(n + 1, 0);
        int ama4 = 0;
        int ama5 = 0, ama6 = 0;
        int ama7 = logs.size();

        for (int ama8 = 0; ama8 < ama; ++ama8) {
            int ama9 = ana[ama8][0];
            int ama10 = ana[ama8][1];
            int ama11 = ama9 - x;

            while (ama6 < ama7 && logs[ama6][1] <= ama9) {
                if (ama3[logs[ama6][0]] == 0) {
                    ama4++;
                }
                ama3[logs[ama6][0]]++;
                ama6++;
            }

            while (ama5 < ama7 && logs[ama5][1] < ama11) {
                ama3[logs[ama5][0]]--;
                if (ama3[logs[ama5][0]] == 0) {
                    ama4--;
                }
                ama5++;
            }

            ama2[ama10] = n - ama4;
        }
        return ama2;
    }
};