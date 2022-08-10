
// Problem Description: https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        int size = connections.size(), count = 0;
        vector<vector<int>> adj(n);
        int* visit = new int[n]();
        for (int i = 0; i < size; i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for (int i = 0; i < n; i++)
            if (!visit[i])
            {
                count++;
                dfs(adj, visit, i);
            }
        return (connections.size() < (n - 1)) ? -1 : count - 1;
    }
    void dfs(vector<vector<int>>& adj, int* visit, int start)
    {
        visit[start] = 1;
        for (int j = 0; j < adj[start].size(); j++)
            if (!visit[adj[start][j]])
                dfs(adj, visit, adj[start][j]);
    }
};