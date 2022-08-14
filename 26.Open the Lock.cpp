
// Problem Description: https://leetcode.com/problems/open-the-lock/
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.find("0000") != dead.end()) return -1;
        unordered_set<string> visit;
        queue<string> q;
        q.push("0000");
        int size;
        int count = 0;
        while (!q.empty())
        {
            size = q.size();
            while (size--)
            {
                string temp = q.front(), s1, s2;

                q.pop();
                if (temp == target) return count;
                for (int i = 0; i < 4; i++)
                {
                    s1 = s2 = temp;
                    s1[i] = (((s1[i] - '0') + 1) % 10) + '0';
                    s2[i] = (((s2[i] - '0') + 9) % 10) + '0';
                    if (visit.find(s1) == visit.end() && dead.find(s1) == dead.end())
                    {
                        visit.insert(s1);
                        q.push(s1);
                    }
                    if (visit.find(s2) == visit.end() && dead.find(s2) == dead.end())
                    {
                        visit.insert(s2);
                        q.push(s2);
                    }

                }
            }
            count++;
        }
        return -1;
    }
};