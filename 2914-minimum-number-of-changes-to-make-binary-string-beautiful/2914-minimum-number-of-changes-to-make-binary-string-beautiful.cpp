class Solution {
public:
    int minChanges(string s) {
        int ama = 0;
        for (int ana = 0; ana < s.size(); ana += 2) {
            if (s[ana] != s[ana + 1]) {
                ama++;
            }
        }
        return ama;
    }
};
