
// Problem Description:https://leetcode.com/problems/shortest-bridge/

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {

        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                {
                    dfs(grid, i, j, q);
                    return bfs(grid, q);
                }
        return -1;
    }
    void dfs(vector<vector<int>>& grid, int r, int c, queue<pair<int, int>>& q)
    {

        if (invalid(r, c, grid.size()) || !grid[r][c] || grid[r][c] == -1) return;
        grid[r][c] = -1;
        q.push({ r,c });
        int dist[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
        for (int i = 0; i < 4; i++)
            dfs(grid, r + dist[i][0], c + dist[i][1], q);
    }
    bool invalid(int r, int c, int size)
    {
        return r < 0 || c < 0 || r >= size || c >= size;
    }
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q)
    {
        cout << q.size();
        int res = 0, newr, newc;
        int dist[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    newr = p.first + dist[i][0];
                    newc = p.second + dist[i][1];
                    if (invalid(newr, newc, grid.size()) || grid[newr][newc] == -1)continue;
                    if (grid[newr][newc]) return res;
                    q.push({ newr,newc });
                    grid[newr][newc] = -1;
                }
            }
            res++;
        }
        return -1;
    }

};