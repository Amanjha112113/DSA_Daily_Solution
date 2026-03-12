/*
create a hashmap for the nums1, store each freq in using forloop.
cheak that the nums2 ele is present in hashmap or not
if true:
    ans1 += freq-count; 
    ans2 += freq-count;



class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        unordered_map<int, int>freq;
        int ans1 = 0, ans2 = 0;

        for(int i = 0; i < m; i++) {
            freq[nums1[i]]++;
        }

        for(int i = 0; i < n; i++) { 
            if (freq.count(nums2[i])) {
            ans1 += freq[nums2[i]];
            freq[nums2[i]] = 0;
            ans2++;
        }
        }
        return {ans1, ans2};
    }
};

// vs
*/

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        int ans1 = 0, ans2 = 0;

        for(int x : nums1){
            if(set2.count(x)){
                ans1++;
            }
        }

        for(int x : nums2){
            if(set1.count(x)){
                ans2++;
            }
        }

        return {ans1, ans2};
    }
};