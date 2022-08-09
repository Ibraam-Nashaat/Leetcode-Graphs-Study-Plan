
// Problem Description: https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int* visit = new int[rooms.size()]();
        return dfs(rooms, visit, 0) == rooms.size();
    }
    int dfs(vector<vector<int>>& rooms, int* visit, int i)
    {
        if (visit[i]) return 0;
        visit[i] = 1;
        int count = 1;
        for (int j = 0; j < rooms[i].size(); j++)
            count += dfs(rooms, visit, rooms[i][j]);
        return count;
    }
};