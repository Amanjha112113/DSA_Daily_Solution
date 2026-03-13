/*
    use two pointer approach
    while loop with left and right
    condition :
        if(s[left] != vowels) left++ same for the right.
    initialize temp and switch position
    left++ right--
*/

class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        string v = "aeiouAEIOU";

        while(left <= right) {
            if(v.find(s[left])!=string::npos && v.find(s[right])!=string::npos){
                swap(s[left],s[right]);
                left++;
                right--;
            }
            else if(v.find(s[left])!=string::npos && v.find(s[right])==string ::npos){
                right--;
            }
            else{
                left++;
            }
        }
        return s;
    }
};