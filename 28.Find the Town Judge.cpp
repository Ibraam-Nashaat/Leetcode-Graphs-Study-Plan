
// Problem Description: https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int* trusted = new int[n + 1]();
        bool* trusts = new bool[n + 1]();
        for (int i = 0; i < trust.size(); i++)
        {
            trusted[trust[i][1]]++;
            trusts[trust[i][0]] = 1;
        }
        for (int i = 1; i < n + 1; i++)
            if (!trusts[i] && trusted[i] == n - 1)
                return i;
        return -1;

    }
};