
// Problem Description: https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
            if (manager[i] > -1)
                adj[manager[i]].push_back(i);
        return dfs(adj, informTime, headID);
    }
    int dfs(vector<vector<int>>& adj, vector<int>& informTime, int head)
    {
        if (adj[head].size() == 0) return 0;
        int maxt = 0;
        for (int i = 0; i < adj[head].size(); i++)
            maxt = max(maxt, dfs(adj, informTime, adj[head][i]));
        return maxt + informTime[head];
    }
};