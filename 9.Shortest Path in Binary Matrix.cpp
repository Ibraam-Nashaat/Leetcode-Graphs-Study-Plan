
// Problem Description: https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        queue<pair<int, int>> q;
        if (!grid[0][0]) q.push({ 0,0 });
        int len = 0;
        int newx, newy;
        int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
        int dy[8] = { 1,0,1,1,0,-1,-1,-1 };
        while (!q.empty())
        {
            len++;
            int size = q.size();
            while (size--)
            {
                pair<int, int> p = q.front();
                q.pop();
                if (p.first == grid[0].size() - 1 && p.second == grid.size() - 1)  ans = min(ans, len);
                for (int i = 0; i < 8; i++)
                {
                    newx = p.first + dx[i];
                    newy = p.second + dy[i];
                    if (newx < 0 || newy < 0 || newx >= grid[0].size() || newy >= grid.size() || grid[newx][newy])                       continue;
                    grid[newx][newy] = 1;
                    q.push({ newx,newy });
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};