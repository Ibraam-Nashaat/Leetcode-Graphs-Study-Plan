
// Problem Description: https://leetcode.com/problems/minimum-jumps-to-reach-home/

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        set<pair<int, bool>>s;
        queue<pair<int, bool>>q;
        unordered_set<int> forb(forbidden.begin(), forbidden.end());
        q.push({ 0,0 });
        int ans = 0, size, curr, lastBackward;
        while (!q.empty())
        {
            size = q.size();
            while (size--)
            {
                auto p = q.front();
                q.pop();
                curr = p.first;
                lastBackward = p.second;
                if (curr == x) return ans;
                int nextPosition = curr + a;
                if (forb.find(nextPosition) == forb.end() && nextPosition <= 6000 && !s.count({ nextPosition,0 }))
                {
                    q.push({ nextPosition,0 });
                    s.insert({ nextPosition,0 });
                }
                if (!lastBackward)
                {
                    int nextPosition = curr - b;
                    if (forb.find(nextPosition) == forb.end() && nextPosition >= 0 && !s.count({ nextPosition,1 }))
                    {
                        q.push({ nextPosition,1 });
                        s.insert({ nextPosition,1 });
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};