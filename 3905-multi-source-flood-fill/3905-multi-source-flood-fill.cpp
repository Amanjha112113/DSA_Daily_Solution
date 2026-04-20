class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> l = sources;
        vector<vector<int>> g(n, vector<int>(m,0));
        vector<vector<int>> di(n, vector<int>(m, INT_MAX));

        queue<tuple<int, int, int, int>> q;

        for(auto &s : l){
            int r = s[0], c=s[1], color = s[2];
            q.push({r, c, 0, color});
            di[r][c] = 0;
            g[r][c] = color;
        }
        
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while(!q.empty()) {
            auto[r,c,t,color] = q.front();
            q.pop();
            for(int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

                if(di[nr][nc] > t + 1) {
                    di[nr][nc] = t + 1;
                    g[nr][nc] = color;
                    q.push({nr, nc, t+1, color});
                    
                }else if(di[nr][nc] == t+1) {
                    if(g[nr][nc] < color) {
                        g[nr][nc] = color;
                        q.push({nr, nc, t + 1, color});
                    }
                }
            }
        }
        return g;
    }
};