#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>

using namespace std;

void RestoreHorizontal(vector<vector<int>>& grid, int pos, vector<int>& line, vector<int>& backup)
{
	grid[pos] = backup;
	line = grid[pos];
}

void RestoreVertical(vector<vector<int>>& grid, int pos, vector<int>& line, vector<int>& backup)
{
	for (size_t i = 0; i < line.size(); i++)
	{
		line[i] = grid[i][pos];
		grid[i][pos] = backup[i];
	}
}

bool FitHorizontal(vector<vector<int>>& grid, int pos, vector<int>& line, vector<int>& backup)
{
	if (line[0] == -1) return false;
	for (size_t i = 0; i < line.size(); i++)
		if (grid[pos][i] != -1 && grid[pos][i] != line[i])
			return false;
	backup = grid[pos];
	grid[pos] = line;
	line = vector<int>(line.size(), -1);
	return true;
}

bool FitVertical(vector<vector<int>>& grid, int pos, vector<int>& line, vector<int>& backup)
{
	if (line[0] == -1) return false;
	for (size_t i = 0; i < line.size(); i++)
		if (grid[i][pos] != -1 && grid[i][pos] != line[i])
			return false;
	for (size_t i = 0; i < line.size(); i++)
	{
		backup[i] = grid[i][pos];
		grid[i][pos] = line[i];
	}
	line = vector<int>(line.size(), -1);
	return true;
}

void Print(const vector<vector<int>>& grid)
{
	const int N = (int)grid.size();
	for (auto it = grid.begin(); it != grid.end(); it++)
	{
		for (auto it2 = it->begin(); it2 != it->end(); it2++)
		{
			cout << ' ' << *it2;
		}
		cout << endl;
	}
}

bool Fill(vector<vector<int>>& grid, vector<vector<int>>& lines)
{
	bool ret = false;
	const int N = (int) lines[0].size();

	for (int pos = 0; pos < N; pos++)
	{
		for (auto it = lines.begin(); it != lines.end(); it++)
		{
			vector<int> backup(N, -1);

			if (FitHorizontal(grid, pos, *it, backup) )
			{
				if (!Fill(grid, lines))
					RestoreHorizontal(grid, pos, *it, backup);
				else
					ret = true;
			}

			if (FitVertical(grid, pos, *it, backup) )
			{
				if (!Fill(grid, lines))
					RestoreVertical(grid, pos, *it, backup);
				else
					ret = true;
			}
		}
	}

	Print(grid);
	return ret;
}

string RankAndLine(vector<vector<int>>& lines)
{
	const int N = (int) lines[0].size();
	string ret;

	vector<int> empty(N, -1);
	vector<vector<int>> grid(N, empty);

	sort(lines.begin(), lines.end(), [&](const auto& line1, const auto& line2) { return line1[0] < line2[0]; });

	Fill(grid, lines);

	return ret;
}

int main()
{
	int T = 0;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		int N = 0;
		cin >> N;

		vector<vector<int>> lines;

		for (int i = 0; i < 2*N-1; i++)
		{
			vector<int> line;

			for (int i = 0; i < N; i++)
			{
				int h = 0;
				cin >> h;
				line.push_back(h);
			}

			lines.push_back(line);
		}

		cout << "Case #" << i << ": " << RankAndLine(lines) << endl;
	}
}
