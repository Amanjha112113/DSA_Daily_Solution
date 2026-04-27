class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        int m = firstList.size();
        int n = secondList.size();

        vector<vector<int>> res;
        int i = 0, j = 0;

        while(i < m && j < n) {
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            if(start1 <= start2) {
                if(end1 >= start2) {
                    // overlap
                    int s = max(start1, start2);
                    int e = min(end1, end2);
                    res.push_back({s, e});
                }
            }else{
                if(end2 >= start1) {
                    int s = max(start1, start2);
                    int e = min(end1, end2);
                    res.push_back({s, e});
                }
            }
            if(end1 <= end2) i++; else j++;
        }
        return res;
    }
};

//vs Two intervals overlap if and only if : max(start1, start2) <= min(end1, end2)
/*
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        int i = 0, j = 0;
        vector<vector<int>> res;

        while(i < firstList.size() && j < secondList.size()) {

            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            int s = max(start1, start2);
            int e = min(end1, end2);

            if(s <= e) {
                res.push_back({s, e});
            }

            if(end1 < end2) i++;
            else j++;
        }

        return res;
    }
};
*/