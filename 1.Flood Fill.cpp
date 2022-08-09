

// Problem Description: https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        unordered_set<string> s;
        dfs(image, sr, sc, color, image[sr][sc], s);
        return image;
    }
    void dfs(vector<vector<int>>& image, int r, int c, int color, int srcColor, unordered_set<string>& s)
    {
        string str = to_string(r) + "," + to_string(c);
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size()) return;
        if (image[r][c] != srcColor || s.find(str) != s.end()) return;
        s.insert(str);
        image[r][c] = color;
        dfs(image, r + 1, c, color, srcColor, s);
        dfs(image, r - 1, c, color, srcColor, s);
        dfs(image, r, c + 1, color, srcColor, s);
        dfs(image, r, c - 1, color, srcColor, s);
    }
};