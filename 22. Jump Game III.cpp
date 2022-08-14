
// Problem Description: https://leetcode.com/problems/jump-game-iii/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int>visit(arr.size(), 0);
        return dfs(arr, start, visit);
    }
    bool dfs(vector<int>& arr, int start, vector<int>& visit)
    {
        if (start >= arr.size() || start < 0) return 0;
        if (visit[start]) return 0;
        if (arr[start] == 0) return 1;
        visit[start] = 1;
        return dfs(arr, start + arr[start], visit) || dfs(arr, start - arr[start], visit);
    }
};