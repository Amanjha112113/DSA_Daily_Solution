class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int ama = nums.size();
        vector<long long> ana(ama - x + 1, 0);
        
        multiset<long long> ama1, ama2;
        long long ama3 = 0, ama4 = 0;

        auto ama5 = [&]() {
            while (ama1.size() > ama2.size() + 1) {
                long long ama6 = *ama1.rbegin();
                ama1.erase(--ama1.end());
                ama3 -= ama6;
                ama2.insert(ama6);
                ama4 += ama6;
            }
            while (ama1.size() < ama2.size()) {
                long long ama6 = *ama2.begin();
                ama2.erase(ama2.begin());
                ama4 -= ama6;
                ama1.insert(ama6);
                ama3 += ama6;
            }
        };

        auto ama7 = [&](long long ama8) {
            if (ama1.empty() || ama8 <= *ama1.rbegin()) {
                ama1.insert(ama8);
                ama3 += ama8;
            } else {
                ama2.insert(ama8);
                ama4 += ama8;
            }
            ama5();
        };

        auto ama9 = [&](long long ama8) {
            auto ama10 = ama1.find(ama8);
            if (ama10 != ama1.end()) {
                ama1.erase(ama10);
                ama3 -= ama8;
            } else {
                ama10 = ama2.find(ama8);
                ama2.erase(ama10);
                ama4 -= ama8;
            }
            ama5();
        };

        for (int ama11 = 0; ama11 < x; ++ama11) {
            ama7(nums[ama11]);
        }

        auto ama12 = [&]() {
            long long ama13 = *ama1.rbegin();
            return (long long)ama1.size() * ama13 - ama3 + ama4 - (long long)ama2.size() * ama13;
        };

        ana[0] = ama12();

        for (int ama11 = x; ama11 < ama; ++ama11) {
            ama9(nums[ama11 - x]);
            ama7(nums[ama11]);
            ana[ama11 - x + 1] = ama12();
        }

        vector<long long> ama14(ama + 1, 0);

        for (int ama15 = 1; ama15 <= k; ++ama15) {
            vector<long long> ama16(ama + 1, 1e18);
            for (int ama11 = 1; ama11 <= ama; ++ama11) {
                ama16[ama11] = ama16[ama11 - 1];
                if (ama11 >= x) {
                    long long ama17 = ama14[ama11 - x] + ana[ama11 - x];
                    if (ama17 < ama16[ama11]) {
                        ama16[ama11] = ama17;
                    }
                }
            }
            ama14 = ama16;
        }

        return ama14[ama] >= 1e15 ? -1 : ama14[ama];
    }
};