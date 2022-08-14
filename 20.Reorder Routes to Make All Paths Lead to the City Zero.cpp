
// Problem Description: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
class Solution {

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // create 2 graphs: normal graph, and reverse graph
        vector<vector<int>> graph(n, vector<int>());
        vector<vector<int>> rgraph(n, vector<int>());

        for (auto con : connections) {
            graph[con[0]].push_back(con[1]);
            rgraph[con[1]].push_back(con[0]);
        }
        int count = 0;
        vector<bool> visited(n, false);
        // graph will be used to find the next node for bfs traversal
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            visited[node] = true;
            q.pop();

            for (auto i : rgraph[node]) {
                if (!visited[i]) {
                    q.push(i);
                }
            }

            // all the edges that needs to be reversed so count++
            for (auto i : graph[node]) {
                if (!visited[i]) {
                    q.push(i);
                    count++;
                }
            }

        }

        return count;
    }
};