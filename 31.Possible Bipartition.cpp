
// Problem Description: https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        vector<int>visit(n + 1, 0);
        for (int i = 0; i < dislikes.size(); i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for (int i = 1; i < n + 1; i++)
            if (!visit[i] && !dfs(adj, visit, i, 1))
                return 0;
        return 1;
    }
    bool dfs(vector<vector<int>>& adj, vector<int>& visit, int g, int color)
    {
        if (visit[g]) return visit[g] == color;
        visit[g] = color;
        color = (color == 1) ? 2 : 1;
        for (int i = 0; i < adj[g].size(); i++)
            if (!dfs(adj, visit, adj[g][i], color))
                return 0;
        return 1;
    }
};

