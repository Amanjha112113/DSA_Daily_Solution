class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    vector<int> sub_sz;
    vector<int> tree;
    string node_str;
    int cur_pos;

    // First DFS to compute subtree sizes, parent, depth, and heavy child
    int dfs1(int u, int p, int d) {
        parent[u] = p;
        depth[u] = d;
        sub_sz[u] = 1;
        int max_sz = 0;
        for (int v : adj[u]) {
            if (v != p) {
                int sz = dfs1(v, u, d + 1);
                sub_sz[u] += sz;
                if (sz > max_sz) {
                    max_sz = sz;
                    heavy[u] = v;
                }
            }
        }
        return sub_sz[u];
    }

    // Second DFS to set chain heads and positions for HLD
    void dfs2(int u, int h) {
        head[u] = h;
        pos[u] = cur_pos++;
        if (heavy[u] != -1) {
            dfs2(heavy[u], h);
        }
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                dfs2(v, v);
            }
        }
    }

    // Segment Tree Operations
    void build(int node, int start, int end, const vector<int>& initial_masks) {
        if (start == end) {
            tree[node] = initial_masks[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, initial_masks);
        build(2 * node + 1, mid + 1, end, initial_masks);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    void update_tree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update_tree(2 * node, start, mid, idx, val);
        else
            update_tree(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    int query_tree(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return query_tree(2 * node, start, mid, l, r) ^ query_tree(2 * node + 1, mid + 1, end, l, r);
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        this->node_str = s;
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        sub_sz.assign(n, 0);
        cur_pos = 0;

        dfs1(0, -1, 0);
        dfs2(0, 0);

        vector<int> initial_masks(n);
        for (int i = 0; i < n; ++i) {
            initial_masks[pos[i]] = (1 << (s[i] - 'a'));
        }

        tree.assign(4 * n, 0);
        build(1, 0, n - 1, initial_masks);

        vector<bool> answer;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                node_str[u] = c;
                update_tree(1, 0, n - 1, pos[u], (1 << (c - 'a')));
            } else {
                int u, v;
                ss >> u >> v;
                int path_xor = 0;
                
                // HLD path query
                int curr_u = u, curr_v = v;
                while (head[curr_u] != head[curr_v]) {
                    if (depth[head[curr_u]] > depth[head[curr_v]]) {
                        path_xor ^= query_tree(1, 0, n - 1, pos[head[curr_u]], pos[curr_u]);
                        curr_u = parent[head[curr_u]];
                    } else {
                        path_xor ^= query_tree(1, 0, n - 1, pos[head[curr_v]], pos[curr_v]);
                        curr_v = parent[head[curr_v]];
                    }
                }
                if (depth[curr_u] > depth[curr_v]) {
                    path_xor ^= query_tree(1, 0, n - 1, pos[curr_v], pos[curr_u]);
                } else {
                    path_xor ^= query_tree(1, 0, n - 1, pos[curr_u], pos[curr_v]);
                }

                // Check if at most one bit is set
                if ((path_xor & (path_xor - 1)) == 0) {
                    answer.push_back(true);
                } else {
                    answer.push_back(false);
                }
            }
        }

        return answer;
    }
};