class Solution {
    set<string> am1(const string& am, int& an) {
        set<string> am2;
        while (an < am.length() && am[an] != '}') {
            set<string> an2 = am3(am, an);
            am2.insert(an2.begin(), an2.end());
            if (an < am.length() && am[an] == ',') {
                an++;
            }
        }
        return am2;
    }

    set<string> am3(const string& am, int& an) {
        set<string> am2 = {""};
        while (an < am.length() && am[an] != ',' && am[an] != '}') {
            set<string> an2 = am4(am, an);
            set<string> am5;
            for (const string& am6 : am2) {
                for (const string& an3 : an2) {
                    am5.insert(am6 + an3);
                }
            }
            am2 = am5;
        }
        return am2;
    }

    set<string> am4(const string& am, int& an) {
        if (am[an] == '{') {
            an++;
            set<string> am2 = am1(am, an);
            an++;
            return am2;
        }
        string am2 = "";
        while (an < am.length() && isalpha(am[an])) {
            am2 += am[an++];
        }
        return {am2};
    }

public:
    vector<string> braceExpansionII(string am) {
        int an = 0;
        set<string> am2 = am1(am, an);
        return vector<string>(am2.begin(), am2.end());
    }
};