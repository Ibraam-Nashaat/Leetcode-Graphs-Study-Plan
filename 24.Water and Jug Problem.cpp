
// Problem Description: https://leetcode.com/problems/water-and-jug-problem/

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int newv, node, total = jug1Capacity + jug2Capacity;
        if (total < targetCapacity) return 0;
        queue<int> q;
        vector<bool> visit(total + 1, 0);
        visit[0] = 1;
        q.push(0);
        int diff[4] = { jug1Capacity,-jug1Capacity,jug2Capacity,-jug2Capacity };
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                newv = node + diff[i];
                if (newv == targetCapacity) return 1;
                if (newv < 0 || newv >= total) continue;
                if (!visit[newv])
                {
                    q.push(newv);
                    visit[newv] = 1;
                }
            }
        }
        return 0;
    }
};