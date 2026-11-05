class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ama = 0;
        for (int ana : arr1) {
            auto ama1 = lower_bound(arr2.begin(), arr2.end(), ana - d);
            if (ama1 == arr2.end() || *ama1 > ana + d) {
                ama++;
            }
        }
        return ama;
    }
};