
// Problem Description: https://leetcode.com/problems/shortest-path-with-alternating-colors/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        int b = blueEdges.size(), r = redEdges.size();
        vector<vector<int>> redrec(n);
        vector<vector<int>> bluerec(n);
        unordered_set<int> redvisit, bluevisit;
        queue<vector<int>> q;
        vector<int> ans(n, INT_MAX);
        for (int i = 0; i < r; i++)
            redrec[redEdges[i][0]].push_back(redEdges[i][1]);
        for (int i = 0; i < b; i++)
            bluerec[blueEdges[i][0]].push_back(blueEdges[i][1]);
        q.push({ 0,1,0 });
        q.push({ 0,0,0 });
        ans[0] = 0;
        int idx, isRed, level;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            idx = p[0], isRed = p[1], level = p[2];
            if (isRed && bluerec[idx].size())
                for (auto end : bluerec[idx])
                    if (bluevisit.find(end) == bluevisit.end())
                    {
                        q.push({ end,0,level + 1 });
                        ans[end] = min(ans[end], level + 1);
                        bluevisit.insert(end);
                    }
            if (!isRed && redrec[idx].size())
                for (auto end : redrec[idx])
                    if (redvisit.find(end) == redvisit.end())
                    {
                        q.push({ end,1,level + 1 });
                        ans[end] = min(ans[end], level + 1);
                        redvisit.insert(end);
                    }
        }
        for (int i = 0; i < n; i++)
            if (ans[i] == INT_MAX)
                ans[i] = -1;
        return ans;


    }
};