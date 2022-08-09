
// Problem Description: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        q.push({ entrance[0],entrance[1] });
        int size, len = -1, newr, newc;
        int dist[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
        maze[entrance[0]][entrance[1]] = '+';
        while (!q.empty())
        {
            len++;
            size = q.size();
            while (size--)
            {
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    newr = p.first + dist[i][0];
                    newc = p.second + dist[i][1];

                    if ((newr < 0 || newc < 0 || newr >= maze.size() || newc >= maze[0].size()) &&
                        !(p.first == entrance[0] && p.second == entrance[1])) return len;
                    if (newr < 0 || newc < 0 || newr >= maze.size() || newc >= maze[0].size() || maze[newr][newc] == '+')  continue;
                    q.push({ newr,newc });
                    maze[newr][newc] = '+';
                }

            }

        }
        return -1;

    }
};