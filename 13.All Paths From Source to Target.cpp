
// Problem Description: https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> vec;
        dfs(graph, ans, vec, 0);
        return ans;
    }
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& vec, int i)
    {
        vec.push_back(i);
        if (i == graph.size() - 1)
        {
            ans.push_back(vec);
            return;
        }
        for (int j = 0; j < graph[i].size(); j++)
        {
            dfs(graph, ans, vec, graph[i][j]);
            vec.pop_back();
        }
    }
};