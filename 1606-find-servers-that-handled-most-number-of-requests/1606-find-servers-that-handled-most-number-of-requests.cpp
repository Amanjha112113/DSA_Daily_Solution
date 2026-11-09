class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> ama;
        set<int> ana;
        for (int ama1 = 0; ama1 < k; ++ama1) {
            ana.insert(ama1);
        }
        
        vector<int> ama2(k, 0);
        int ama3 = 0;
        int ama4 = arrival.size();
        
        for (int ama5 = 0; ama5 < ama4; ++ama5) {
            long long ama6 = arrival[ama5];
            int ama7 = load[ama5];
            
            while (!ama.empty() && ama.top().first <= ama6) {
                ana.insert(ama.top().second);
                ama.pop();
            }
            
            if (ana.empty()) {
                continue;
            }
            
            int ama8 = ama5 % k;
            auto ama9 = ana.lower_bound(ama8);
            if (ama9 == ana.end()) {
                ama9 = ana.begin();
            }
            
            int ama10 = *ama9;
            ana.erase(ama9);
            ama2[ama10]++;
            ama3 = max(ama3, ama2[ama10]);
            
            ama.push({ama6 + ama7, ama10});
        }
        
        vector<int> ama11;
        for (int ama1 = 0; ama1 < k; ++ama1) {
            if (ama2[ama1] == ama3) {
                ama11.push_back(ama1);
            }
        }
        return ama11;
    }
};