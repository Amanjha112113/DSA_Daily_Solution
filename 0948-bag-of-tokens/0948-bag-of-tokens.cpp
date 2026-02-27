class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int len = tokens.size();

        sort(tokens.begin(), tokens.end());
        int points = 0;
        int maxpoints = 0;

        int left = 0; 
        int right = len - 1;

        while(left <= right) {

            if(power >= tokens[left]) {
                power -= tokens[left];
                points++;
                left++;
                maxpoints = max(maxpoints, points);

            }else if(power < tokens[left] && points > 0){      // (score) only also work...
                power += tokens[right];
                points--;
                right--;

            }else {
                break;
            }
        }
        return maxpoints;
    }
};