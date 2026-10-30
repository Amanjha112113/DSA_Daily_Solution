#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalOps = (long long)k1 + k2;
        
        std::unordered_map<int, long long> diffCount;
        int maxDiff = 0;
        long long initialDiffSum = 0;

        for (int i = 0; i < n; ++i) {
            int diff = std::abs(nums1[i] - nums2[i]);
            if (diff > 0) {
                diffCount[diff]++;
                maxDiff = std::max(maxDiff, diff);
            }
            initialDiffSum += diff;
        }

        if (initialDiffSum <= totalOps) {
            return 0;
        }

        for (int d = maxDiff; d > 0 && totalOps > 0; --d) {
            if (diffCount.find(d) == diffCount.end()) continue;

            long long count = diffCount[d];
            long long opsToTake = std::min(totalOps, count);

            diffCount[d] -= opsToTake;
            diffCount[d - 1] += opsToTake;
            totalOps -= opsToTake;
        }

        long long minSquareSum = 0;
        for (auto& pair : diffCount) {
            long long d = pair.first;
            long long count = pair.second;
            minSquareSum += count * d * d;
        }

        return minSquareSum;
    }
};