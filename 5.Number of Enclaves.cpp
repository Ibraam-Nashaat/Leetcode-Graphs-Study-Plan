
// Problem Description: https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int total = 0;
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
            {
                count = 0;
                if (grid[i][j] == 1 && !dfs(grid, i, j, count))
                    total += count;
            }
        return total;
    }
    int dfs(vector<vector<int>>& grid, int r, int c, int& count)
    {

        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return 1;
        if (grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        count++;
        bool top = dfs(grid, r - 1, c, count);
        bool bottom = dfs(grid, r + 1, c, count);
        bool left = dfs(grid, r, c - 1, count);
        bool right = dfs(grid, r, c + 1, count);
        return top || bottom || left || right;
    }
};