
// Problem Description: https://leetcode.com/problems/minimum-genetic-mutation/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(), bank.end());
        unordered_set<string> visit;
        queue<string> q;
        int size, count = 0;
        string temp, s1;
        q.push(start);
        visit.insert(start);
        char diff[4] = { 'A','C','G','T' };
        while (!q.empty())
        {
            size = q.size();
            while (size--)
            {
                temp = q.front();
                q.pop();
                if (temp == end) return count;
                for (int j = 0; j < temp.size(); j++) {
                    for (int i = 0; i < 4; i++)
                    {
                        s1 = temp;
                        s1[j] = diff[i];
                        if (visit.find(s1) == visit.end() && bankset.find(s1) != bankset.end())
                        {
                            visit.insert(s1);
                            q.push(s1);
                        }
                    }
                }

            }
            count++;
        }
        return -1;
    }
};