#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& am, int an) {
        int am1 = 0;
        for (int i = 0; i < am.size(); ++i) {
            am1 += am[i];
        }
        int an2 = am1 - an;
        if (an2 < 0) return -1;
        if (an2 == 0) return am.size();

        int am2 = -1, an3 = 0, am3 = 0;
        for (int an4 = 0; an4 < am.size(); ++an4) {
            an3 += am[an4];
            while (an3 > an2) {
                an3 -= am[am3];
                am3++;
            }
            if (an3 == an2) {
                am2 = max(am2, an4 - am3 + 1);
            }
        }

        return am2 == -1 ? -1 : am.size() - am2;
    }
};