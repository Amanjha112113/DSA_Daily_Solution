class Solution {
    struct Node {
        int prod;
        int cnt[5];
        Node() {
            prod = 1;
            for (int i = 0; i < 5; ++i) cnt[i] = 0;
        }
    };

    int k_mod;
    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right) {
        Node res;
        res.prod = (left.prod * right.prod) % k_mod;
        for (int i = 0; i < k_mod; ++i) {
            res.cnt[i] = left.cnt[i];
        }
        for (int i = 0; i < k_mod; ++i) {
            if (right.cnt[i] > 0) {
                int rem = (left.prod * i) % k_mod;
                res.cnt[rem] += right.cnt[i];
            }
        }
        return res;
    }

    void buildTree(int idx, int l, int r, const vector<int>& nums) {
        if (l == r) {
            int val = nums[l] % k_mod;
            tree[idx].prod = val;
            tree[idx].cnt[val] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(2 * idx, l, mid, nums);
        buildTree(2 * idx + 1, mid + 1, r, nums);
        tree[idx] = mergeNodes(tree[2 * idx], tree[2 * idx + 1]);
    }

    void updateTree(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            val %= k_mod;
            tree[idx].prod = val;
            for (int i = 0; i < k_mod; ++i) tree[idx].cnt[i] = 0;
            tree[idx].cnt[val] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            updateTree(2 * idx, l, mid, pos, val);
        } else {
            updateTree(2 * idx + 1, mid + 1, r, pos, val);
        }
        tree[idx] = mergeNodes(tree[2 * idx], tree[2 * idx + 1]);
    }

    Node queryTree(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[idx];
        }
        int mid = l + (r - l) / 2;
        if (qr <= mid) {
            return queryTree(2 * idx, l, mid, ql, qr);
        }
        if (ql > mid) {
            return queryTree(2 * idx + 1, mid + 1, r, ql, qr);
        }
        Node left = queryTree(2 * idx, l, mid, ql, qr);
        Node right = queryTree(2 * idx + 1, mid + 1, r, ql, qr);
        return mergeNodes(left, right);
    }

public:
    vector<int> resultArray(vector<int>& am, int an, vector<vector<int>>& am1) {
        int an2 = am.size();
        k_mod = an;
        tree.resize(4 * an2);

        buildTree(1, 0, an2 - 1, am);

        vector<int> am2;
        for (size_t an3 = 0; an3 < am1.size(); ++an3) {
            int am3 = am1[an3][0];
            int an4 = am1[an3][1];
            int am4 = am1[an3][2];
            int an5 = am1[an3][3];

            updateTree(1, 0, an2 - 1, am3, an4);

            Node am5 = queryTree(1, 0, an2 - 1, am4, an2 - 1);
            am2.push_back(am5.cnt[an5]);
        }

        return am2;
    }
};