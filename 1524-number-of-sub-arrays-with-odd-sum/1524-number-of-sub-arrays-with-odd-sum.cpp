class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ama = 0;
        long long ana = 0; // count of even prefix sums (starting with 0 as even prefix sum)
        long long ama1 = 0; // count of odd prefix sums
        long long ama2 = 0; // total number of odd subarrays
        
        for (int ama3 : arr) {
            ama += ama3;
            if (ama % 2 != 0) {
                ama2 += ana + 1;
                ama1++;
            } else {
                ama2 += ama1;
                ana++;
            }
            ama2 %= 1000000007;
        }
        return ama2;
    }
};