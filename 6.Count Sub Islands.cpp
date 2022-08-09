
// Problem Description: https://leetcode.com/problems/count-sub-islands/

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        for (int i = 0; i < grid1.size(); i++)
            for (int j = 0; j < grid1[0].size(); j++)
                if (grid1[i][j] == 1 && grid2[i][j] == 1 && dfs(grid1, grid2, i, j))
                    count++;
        return count;
    }
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c)
    {
        if (r < 0 || r >= grid1.size() || c < 0 || c >= grid1[0].size()) return 1;
        if (grid1[r][c] == 0 && grid2[r][c] == 0) return 1;
        if (grid1[r][c] == 1 && grid2[r][c] == 0) return 1;
        if (grid1[r][c] == 0 && grid2[r][c] == 1) return 0;
        grid1[r][c] = grid2[r][c] = 0;
        bool res = dfs(grid1, grid2, r - 1, c);
        res = dfs(grid1, grid2, r + 1, c) && res;
        res = dfs(grid1, grid2, r, c - 1) && res;
        res = dfs(grid1, grid2, r, c + 1) && res;
        return res;
    }
};