
// Problem Description: https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1)
                    count = max(dfs(grid, i, j), count);
        return count;
    }
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        if (grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int count = 1;
        if (r - 1 >= 0) count += dfs(grid, r - 1, c);
        if (r + 1 < grid.size()) count += dfs(grid, r + 1, c);
        if (c - 1 >= 0) count += dfs(grid, r, c - 1);
        if (c + 1 < grid[0].size()) count += dfs(grid, r, c + 1);
        return count;
    }
};