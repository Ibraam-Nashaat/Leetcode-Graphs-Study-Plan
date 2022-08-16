
// Problem Description: https://leetcode.com/problems/maximal-network-rank/
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>counte(n, 0);
        vector<vector<int>> adj(n);
        int sum, maxe = 0;
        for (int i = 0; i < roads.size(); i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
            counte[roads[i][0]]++;
            counte[roads[i][1]]++;
        }
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                sum = counte[i] + counte[j];
                if (count(adj[i].begin(), adj[i].end(), j))
                    sum--;
                maxe = max(maxe, sum);
            }
        return maxe;
    }
};