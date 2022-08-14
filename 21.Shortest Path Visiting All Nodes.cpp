
// Problem Description: https://leetcode.com/problems/shortest-path-visiting-all-nodes/

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int allVisitedMask = (1 << n) - 1;
        queue<pair<int, pair<int, int>>>Q; // pair<currNode,pair<dist,mask>>
        set<pair<int, int>>seen;//<currNode,mask as path>
        // Initially push all nodes in Queue to start the path with all nodes;
        for (int i = 0; i < n; i++) {
            Q.push({ i,{0,1 << i} });
            seen.insert({ i,1 << i });
        }
        while (!Q.empty()) {
            auto curr = Q.front();
            Q.pop();
            int node = curr.first, dist = curr.second.first, mask = curr.second.second;
            //If all nodes are visited
            if (mask == allVisitedMask)return dist;
            // Go through all neighbours
            for (auto& nei : graph[node]) {
                int nextMask = mask | (1 << nei);
                if (!seen.count({ nei,nextMask })) {
                    Q.push({ nei,{dist + 1,nextMask} });
                    seen.insert({ nei,nextMask });
                }
            }
        }
        return 0;
    }
};