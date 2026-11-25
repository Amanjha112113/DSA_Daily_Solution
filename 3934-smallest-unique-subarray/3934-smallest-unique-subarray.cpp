class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const long long m1 = 1000000007, m2 = 1000000009;
        const long long b1 = 1315423911 % m1, b2 = 2654435761 % m2;
        
        vector<long long> p1(n + 1, 1), p2(n + 1, 1);
        vector<long long> h1(n + 1, 0), h2(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            p1[i + 1] = (p1[i] * b1) % m1;
            p2[i + 1] = (p2[i] * b2) % m2;
            h1[i + 1] = (h1[i] * b1 + nums[i]) % m1;
            h2[i + 1] = (h2[i] * b2 + nums[i]) % m2;
        }
        
        auto check = [&](int len) {
            unordered_map<long long, int> freq;
            freq.reserve(n - len + 1);
            for (int i = 0; i + len <= n; ++i) {
                long long x1 = (h1[i + len] - h1[i] * p1[len] % m1 + m1) % m1;
                long long x2 = (h2[i + len] - h2[i] * p2[len] % m2 + m2) % m2;
                freq[(x1 << 32) | x2]++;
            }
            for (auto& [k, v] : freq) {
                if (v == 1) return true;
            }
            return false;
        };
        
        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};