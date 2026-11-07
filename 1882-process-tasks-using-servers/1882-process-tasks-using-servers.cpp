class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int ama = servers.size();
        int ana = tasks.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ama1;
        for (int ama2 = 0; ama2 < ama; ++ama2) {
            ama1.push({servers[ama2], ama2});
        }
        
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> ama3;
        vector<int> ama4(ana);
        long long ama5 = 0;
        
        for (int ama6 = 0; ama6 < ana; ++ama6) {
            ama5 = max(ama5, (long long)ama6);
            
            if (ama1.empty()) {
                ama5 = max(ama5, ama3.top()[0]);
            }
            
            while (!ama3.empty() && ama3.top()[0] <= ama5) {
                auto ama7 = ama3.top();
                ama3.pop();
                ama1.push({(int)ama7[1], (int)ama7[2]});
            }
            
            auto ama8 = ama1.top();
            ama1.pop();
            int ama9 = ama8.first;
            int ama10 = ama8.second;
            
            ama4[ama6] = ama10;
            ama3.push({ama5 + tasks[ama6], ama9, ama10});
        }
        
        return ama4;
    }
};