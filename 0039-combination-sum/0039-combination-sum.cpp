class Solution {
private:
    void dfs(vector<int>& c, int t, int s, vector<int>& cur, vector<vector<int>>& ans) {
        if (t == 0) {
            ans.push_back(cur);
            return;
        }
        for (int i = s; i < c.size(); ++i) {
            if (c[i] <= t) {
                cur.push_back(c[i]);
                dfs(c, t - c[i], i, cur, ans);
                cur.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(candidates, target, 0, cur, ans);
        return ans;
    }
};