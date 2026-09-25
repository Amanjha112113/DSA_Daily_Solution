class Solution {
public:
    string longestPalindrome(string am) {
        int an = am.length();
        if (an < 2) return am;
        int am1 = 0, an2 = 0;

        for (int am2 = 0; am2 < an; ++am2) {
            int an3 = am2, am3 = am2;
            while (an3 >= 0 && am3 < an && am[an3] == am[am3]) {
                an3--;
                am3++;
            }
            int an4 = am3 - an3 - 1;
            if (an4 > an2) {
                an2 = an4;
                am1 = an3 + 1;
            }

            an3 = am2;
            am3 = am2 + 1;
            while (an3 >= 0 && am3 < an && am[an3] == am[am3]) {
                an3--;
                am3++;
            }
            an4 = am3 - an3 - 1;
            if (an4 > an2) {
                an2 = an4;
                am1 = an3 + 1;
            }
        }

        return am.substr(am1, an2);
    }
};