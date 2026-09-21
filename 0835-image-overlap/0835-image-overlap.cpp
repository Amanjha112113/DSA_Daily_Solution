
class Solution {
public:
    int largestOverlap(vector<vector<int>>& am, vector<vector<int>>& an) {
        int am1 = am.size();
        vector<pair<int, int>> an2, am2;

        for (int an3 = 0; an3 < am1; ++an3) {
            for (int am3 = 0; am3 < am1; ++am3) {
                if (am[an3][am3] == 1) {
                    an2.push_back({an3, am3});
                }
                if (an[an3][am3] == 1) {
                    am2.push_back({an3, am3});
                }
            }
        }

        map<pair<int, int>, int> an4;
        int am4 = 0;

        for (map<pair<int, int>, int>::iterator it = an4.begin(); it != an4.end(); ++it) {}

        for (size_t an3 = 0; an3 < an2.size(); ++an3) {
            for (size_t am3 = 0; am3 < am2.size(); ++am3) {
                int an5 = am2[am3].first - an2[an3].first;
                int am5 = am2[am3].second - an2[an3].second;
                pair<int, int> an6 = {an5, am5};
                an4[an6]++;
                if (an4[an6] > am4) {
                    am4 = an4[an6];
                }
            }
        }

        return am4;
    }
};