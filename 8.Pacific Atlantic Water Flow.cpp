
// Problem Description: https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int row = heights.size();
        int col = heights[0].size();
        bool** pac = new bool* [row];
        bool** atl = new bool* [row];
        for (int i = 0; i < row; i++)
        {
            pac[i] = new bool[col]();
            atl[i] = new bool[col]();
        }

        for (int c = 0; c < col; c++)
        {
            dfs(0, c, pac, heights[0][c], heights);
            dfs(row - 1, c, atl, heights[row - 1][c], heights);
        }
        for (int r = 0; r < row; r++)
        {
            dfs(r, 0, pac, heights[r][0], heights);
            dfs(r, col - 1, atl, heights[r][col - 1], heights);
        }
        for (int r = 0; r < row; r++)
            for (int c = 0; c < col; c++)
            {
                string s = to_string(r) + "," + to_string(c);
                if (pac[r][c] && atl[r][c])
                    ans.push_back({ r,c });
            }
        return ans;

    }
    void dfs(int r, int c, bool**& visit, int prev, vector<vector<int>>& heights)
    {

        if (r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size() || heights[r][c] < prev || visit[r][c]) return;
        visit[r][c] = 1;
        dfs(r + 1, c, visit, heights[r][c], heights);
        dfs(r - 1, c, visit, heights[r][c], heights);
        dfs(r, c + 1, visit, heights[r][c], heights);
        dfs(r, c - 1, visit, heights[r][c], heights);
    }
};