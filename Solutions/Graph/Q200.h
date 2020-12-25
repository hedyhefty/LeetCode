#pragma once

#include "../Solution.h"

class Q200 : public Solution
{
public:
	void Solve() override
	{
		vector<vector<char>> grid
		{
			{'1','1','0','0','0'},
			{'1','1','0','0','0'},
			{'0','0','1','0','0'},
			{'0','0','0','1','1'}
		};
		cout << "num of islands: " << numIslands(grid);
	}

	int numIslands(vector<vector<char>>& grid) 
	{
		int numOfIslands = 0;
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[i].size(); ++j)
			{
				if (grid[i][j] == '1')
				{
					DfsDiscovIsland(grid, i, j);
					++numOfIslands;
				}
			}
		}

		return numOfIslands;
	}

	void DfsDiscovIsland(vector<vector<char>>& grid, int i, int j)
	{
		queue<pair<int,int>> proccessIndex;
		proccessIndex.push({ i,j });

		while (!proccessIndex.empty())
		{
			auto proccessing = proccessIndex.front();
			proccessIndex.pop();

			int row = proccessing.first;
			int col = proccessing.second;

			if (row < 0 || row >= grid.size())
			{
				continue;
			}

			if (col < 0 || col >= grid[0].size())
			{
				continue;
			}

			if (grid[row][col] == '1')
			{
				grid[row][col] = 'c';
				proccessIndex.push({ row + 1,col });
				proccessIndex.push({ row - 1,col });
				proccessIndex.push({ row,col - 1 });
				proccessIndex.push({ row,col + 1 });
			}
		}
	}
};