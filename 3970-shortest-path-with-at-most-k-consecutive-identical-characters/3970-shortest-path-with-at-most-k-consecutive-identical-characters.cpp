class Solution {
public:
    int shortestPath(int ama, vector<vector<int>>& ana, string ama1, int ama2) {
        vector<vector<pair<int, int>>> ama3(ama);
        for (auto& ama4 : ana) {
            ama3[ama4[0]].push_back({ama4[1], ama4[2]});
        }
        
        vector<vector<long long>> ama5(ama, vector<long long>(ama2 + 1, 1e18));
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> ama6;
        
        ama5[0][1] = 0;
        ama6.push({0, 0, 1});
        
        while (!ama6.empty()) {
            auto ama7 = ama6.top();
            ama6.pop();
            long long ama8 = ama7[0];
            int ama9 = ama7[1];
            int ama10 = ama7[2];
            
            if (ama8 > ama5[ama9][ama10]) continue;
            if (ama9 == ama - 1) return ama8;
            
            for (auto& ama11 : ama3[ama9]) {
                int ama12 = ama11.first;
                long long ama13 = ama11.second;
                
                int ama14 = 1;
                if (ama1[ama12] == ama1[ama9]) {
                    ama14 = ama10 + 1;
                }
                
                if (ama14 <= ama2) {
                    if (ama8 + ama13 < ama5[ama12][ama14]) {
                        ama5[ama12][ama14] = ama8 + ama13;
                        ama6.push({ama5[ama12][ama14], ama12, ama14});
                    }
                }
            }
        }
        
        long long ama15 = 1e18;
        for (int ama16 = 1; ama16 <= ama2; ++ama16) {
            ama15 = min(ama15, ama5[ama - 1][ama16]);
        }
        return ama15 == 1e18 ? -1 : ama15;
    }
};