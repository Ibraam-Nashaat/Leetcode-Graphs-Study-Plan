
// Problem Description: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> incomeEdge(n, 0);
        vector<int> ans;
        for (int i = 0; i < edges.size(); i++)
            incomeEdge[edges[i][1]] = 1;
        for (int i = 0; i < n; i++)
            if (!incomeEdge[i])
                ans.push_back(i);
        return ans;
    }
};