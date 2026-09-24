class Solution {
public:
    int smallestIndex(vector<int>& am) {
        for (int an = 0; an < am.size(); ++an) {
            int am1 = am[an];
            int an2 = 0;
            while (am1 > 0) {
                an2 += am1 % 10;
                am1 /= 10;
            }
            if (an2 == an) {
                return an;
            }
        }
        return -1;
    }
};