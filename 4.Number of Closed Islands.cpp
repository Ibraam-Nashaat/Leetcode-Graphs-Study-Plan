
// Problem Description: https://leetcode.com/problems/number-of-closed-islands/

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 0 && dfs(grid, i, j))
                    count++;
        return count;
    }
    bool dfs(vector<vector<int>>& grid, int r, int c)
    {
        if (r < 0 || r >= grid.size() || c >= grid[0].size() || c < 0) return 0;
        if (grid[r][c] == 1) return 1;
        grid[r][c] = 1;
        bool bottom = dfs(grid, r + 1, c);
        bool top = dfs(grid, r - 1, c);
        bool right = dfs(grid, r, c + 1);
        bool left = dfs(grid, r, c - 1);

        return bottom && top && right && left;
    }
};