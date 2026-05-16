class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        stack<int>st;
        unordered_map<int, int>freq;
        vector<int>res;
        
        for(int i = n - 1; i >= 0; --i) {

            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if(st.empty()) {
                freq[nums2[i]] = -1;
            }else{
                freq[nums2[i]] = st.top();
            }
            
            st.push(nums2[i]);

        }
        for(int i = 0; i < nums1.size(); i++) {
            int val = freq[nums1[i]];
            res.push_back(val);
        }

        return res;
    }
};



