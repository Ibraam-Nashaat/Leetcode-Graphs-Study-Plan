
// problem Description: https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int* visit = new int[n]();
        int count = 0;
        bool b = 1;
        for (int i = 0; i < n; i++)
            if (!visit[i])
            {
                count++;
                dfs(isConnected, visit, i);
            }
        return count;
    }
    void dfs(vector<vector<int>>& isConnected, int* visit, int start)
    {
        visit[start] = 1;
        for (int j = 0; j < isConnected.size(); j++)
            if (isConnected[start][j] && !visit[j])
                dfs(isConnected, visit, j);
    }
};