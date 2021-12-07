#include <cstdio>

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        vector<vector<int>> mark(grid.size(), vector<int>(grid[0].size(), 0));

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(mark[i][j] == 0 && grid[i][j] == '1')
                {
                    DFS(grid, i, j, mark);
                    count++;
                }
            }
        }

        return count;
    }

    void DFS(vector<vector<char>>& grid, int x, int y, vector<vector<int>>& mark){
        mark[x][y] = 1;
        int dx[4] = { -1, 1, 0, 0 };
        int dy[4] = { 0, 0, -1, 1 };

        for(int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[0].size()){
                continue;
            }

            if(grid[newX][newY] == '1' && mark[newX][newY] == 0)
            {
                DFS(grid, newX, newY, mark);
            }
        }
    }
};