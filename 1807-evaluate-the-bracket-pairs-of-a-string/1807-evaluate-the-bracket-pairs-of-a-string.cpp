class Solution {
public:
    string evaluate(string am, vector<vector<string>>& an) {
        unordered_map<string, string> am1;
        for (size_t an2 = 0; an2 < an.size(); ++an2) {
            am1[an[an2][0]] = an[an2][1];
        }

        string am2 = "";
        string an3 = "";
        bool am3 = false;

        for (size_t an4 = 0; an4 < am.length(); ++an4) {
            if (am[an4] == '(') {
                am3 = true;
                an3 = "";
            } else if (am[an4] == ')') {
                am3 = false;
                if (am1.count(an3)) {
                    am2 += am1[an3];
                } else {
                    am2 += "?";
                }
            } else {
                if (am3) {
                    an3 += am[an4];
                } else {
                    am2 += am[an4];
                }
            }
        }

        return am2;
    }
};