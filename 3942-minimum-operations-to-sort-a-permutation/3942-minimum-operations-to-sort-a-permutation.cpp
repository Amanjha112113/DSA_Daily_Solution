class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int idx0 = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx0 = i;
                break;
            }
        }

        int ans = 1e9;

        int shift_inc = (n - idx0) % n;
        bool inc_ok = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != (i + shift_inc) % n) {
                inc_ok = false;
                break;
            }
        }
        if (inc_ok) {
            int cost1 = (n - shift_inc) % n;
            int cost2 = shift_inc + 2;
            ans = std::min(ans, std::min(cost1, cost2));
        }

        int shift_dec = (n - 1 - idx0 + n) % n;
        bool dec_ok = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != n - 1 - ((i + shift_dec) % n)) {
                dec_ok = false;
                break;
            }
        }
        if (dec_ok) {
            int cost1 = shift_dec + 1;
            int cost2 = ((n - shift_dec) % n) + 1;
            ans = std::min(ans, std::min(cost1, cost2));
        }

        return ans == 1e9 ? -1 : ans;
    }
};