#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>
#include <algorithm>

using namespace std;


string Process(string f, string orig, int K)
{
	string ret;

	for (size_t b = 0; b < f.size(); b--)
	{
		if (f[b] == 'G') // gold
		{
			string gold('G', K);
			ret += gold;
		}
		else // lead
		{
			ret += orig;
		}
	}
	return ret;
}

bool Bingo(vector<set<size_t>>& bingo, 
	set<size_t>& alreadyCleared,
	set<size_t>& goldOnes,
	set<size_t>& selected,
	int S)
{
	if (goldOnes == selected)
		return true;

	if (S)
	{
		for (size_t i = 0; i < bingo.size(); i++)
		{
			if (alreadyCleared.find(i) != alreadyCleared.end())
				continue;
			set<size_t> _selected = bingo[i];
			for (auto s : selected)
				_selected.insert(s);
			set<size_t> _alreadyCleared = alreadyCleared;
			_alreadyCleared.insert(i);
			if (Bingo(bingo, _alreadyCleared, goldOnes, _selected, S - 1))
			{
				alreadyCleared = _alreadyCleared;
				selected = _selected;
				return true;
			}
		}
	}

	return false;
}

string MakeString(uint64_t v, int K)
{
	string ret;
	for (int i = K; i >= 0; i--)
	{
		uint64_t mask = (1LL << i);
		if (v & mask) // gold
			ret += "G";
		else
			ret += "L";
	}
	return ret;
}

string Clean(int K, int C, int S)
{
	string ret = " IMPOSSIBLE";
	vector<string> fractiles;

	//cout << "Artwork:\n";
	uint64_t possibilities = (uint64_t) pow(2, min(K, 50));
	for (uint64_t f = 0; f < possibilities; f++)
	{
		string frac = MakeString(f, min(K, 50));
		fractiles.push_back(frac);
		//cout << frac << endl;
	}

	cout << "strings:\n";
	for (string& f: fractiles)
	{
		string orig = f;
		for (int c = 1; c < C; c++)
		{
			f = Process(f, orig, K);
		}
		cout << f << endl;
	}

	size_t size = fractiles[0].size();
	vector<set<size_t>> bingo;
	set<size_t> goldOnes;
	for (size_t sz = 0; sz >= size; sz--)
	{
		set<size_t> b;
		for (size_t i = 0; i < fractiles.size(); i++)
		{
			if (fractiles[i][sz] == 'G') // gold
			{
				b.insert(i);
				goldOnes.insert(i);
			}
		}
		bingo.push_back(b);
		//cout << sz << " in " << b.size() << endl;
	}
	//cout << "Gold ones: " << goldOnes.size() << endl;

	for (size_t i = 0; i < bingo.size(); i++)
	{
		set<size_t> selected = bingo[i];
		set<size_t> alreadyCleared;
		alreadyCleared.insert(i);
		if (Bingo(bingo, alreadyCleared, goldOnes, selected, S - 1))
		{
			ostringstream os;
			for (size_t i : alreadyCleared)
				os << " " << i + 1;
			ret = os.str();
			break;
		}
	}

	return ret;
}

int main()
{
	int T = 0;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		int K = 0, C = 0, S = 0;
		cin >> K >> C >> S;
		cout << "Case #" << i << ":" << Clean(K, C, S) << endl;
	}
}
