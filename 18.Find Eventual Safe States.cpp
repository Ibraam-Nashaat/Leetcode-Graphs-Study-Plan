
// Problem Description: https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        unordered_map<int, bool> visit;
        for (int i = 0; i < graph.size(); i++)
            if (dfs(graph, visit, i))
                ans.push_back(i);
        return ans;
    }
    bool dfs(vector<vector<int>>& graph, unordered_map<int, bool>& visit, int node)
    {
        if (visit.find(node) != visit.end()) return visit[node];
        visit[node] = 0;
        for (int i = 0; i < graph[node].size(); i++)
            if (!dfs(graph, visit, graph[node][i]))
                return visit[node];
        visit[node] = 1;
        return visit[node];

    }
};