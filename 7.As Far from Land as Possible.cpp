
// Problem Description: https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (grid[i][j] == 1)
                    q.push({ i,j });

        int dx[4] = { 1,0,-1,0 };
        int dy[4] = { 0,-1,0,1 };

        int lvl = -1;
        while (!q.empty()) {
            lvl++;
            int sz = q.size();
            while (sz--) {
                pair<int, int> curr = q.front();
                q.pop();

                int x = curr.first, y = curr.second;

                for (int i = 0; i < 4; i++) {
                    int newx = x + dx[i];
                    int newy = y + dy[i];

                    if (newx < 0 || newy < 0 || newx >= r || newy >= c || grid[newx][newy] == 1) continue;

                    q.push({ newx,newy });
                    grid[newx][newy] = 1;
                }
            }
        }

        return lvl == 0 ? -1 : lvl;

    }
};