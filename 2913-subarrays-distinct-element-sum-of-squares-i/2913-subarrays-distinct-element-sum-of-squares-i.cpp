class Solution {
public:
    int sumCounts(std::vector<int>& nums) {
        int jha1 = 0;
        int jha2 = nums.size();
        
        for (int jha3 = 0; jha3 < jha2; ++jha3) {
            std::unordered_set<int> jha4;
            for (int jha5 = jha3; jha5 < jha2; ++jha5) {
                jha4.insert(nums[jha5]);
                int jha6 = jha4.size();
                jha1 += jha6 * jha6;
            }
        }
        
        return jha1;
    }
};