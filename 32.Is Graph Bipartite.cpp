
// Problem Description: https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visit(n, 0);
        for (int i = 1; i < n; i++)
            if (!visit[i] && !dfs(graph, visit, i, 1))
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