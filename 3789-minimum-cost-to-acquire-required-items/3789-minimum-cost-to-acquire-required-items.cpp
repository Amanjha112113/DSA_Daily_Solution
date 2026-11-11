class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;
        
        long long common = min(n1, n2);
        long long costBothEffective = min(cb, c1 + c2);
        long long totalCost = common * costBothEffective;
        
        n1 -= common;
        n2 -= common;
        
        if (n1 > 0) {
            totalCost += n1 * min(c1, cb);
        }
        
        if (n2 > 0) {
            totalCost += n2 * min(c2, cb);
        }
        
        return totalCost;
    }
};