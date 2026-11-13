class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long ama = 0;
        long long ana = 0;
        deque<int> ama1;
        for (int ama2 = nums.size() - 1, ama3 = nums.size() - 1; ama2 >= 0; --ama2) {
            while (!ama1.empty() && nums[ama1.back()] < nums[ama2]) {
                int ama4 = ama1.back();
                ama1.pop_back();
                int ama5 = ama1.empty() ? ama3 + 1 : ama1.back();
                ana += (long long)(ama5 - ama4) * (nums[ama2] - nums[ama4]);
            }
            ama1.push_back(ama2);
            while (ana > k) {
                ana -= nums[ama1.front()] - nums[ama3];
                if (ama1.front() == ama3)
                    ama1.pop_front();
                --ama3;
            }
            ama += ama3 - ama2 + 1;
        }
        return ama;
    }
};