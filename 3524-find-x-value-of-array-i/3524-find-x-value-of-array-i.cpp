class Solution {
public:
    vector<long long> resultArray(vector<int>& am, int an) {
        vector<long long> am1(an, 0);
        vector<long long> an2(an, 0);
        
        for (int am2 : am) {
            vector<long long> an3(an, 0);
            int am3 = am2 % an;
            an3[am3]++;
            for (int am4 = 0; am4 < an; ++am4) {
                if (an2[am4] > 0) {
                    int an4 = (am4 * am3) % an;
                    an3[an4] += an2[am4];
                }
            }
            for (int am4 = 0; am4 < an; ++am4) {
                am1[am4] += an3[am4];
            }
            an2 = move(an3);
        }
        return am1;
    }
};