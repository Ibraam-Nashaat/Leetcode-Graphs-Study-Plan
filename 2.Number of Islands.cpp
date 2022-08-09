
//Problem Description: https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        string loc;
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    count++;
                }

            }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        if (grid[r][c] == '0') return;
        grid[r][c] = '0';
        if (r - 1 >= 0) dfs(grid, r - 1, c);
        if (r + 1 < grid.size()) dfs(grid, r + 1, c);
        if (c - 1 >= 0) dfs(grid, r, c - 1);
        if (c + 1 < grid[0].size()) dfs(grid, r, c + 1);

    }
};