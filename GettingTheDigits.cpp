#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>

using namespace std;

void GettingTheDigits(const string& S)
{
	vector<string> digits = { "ZR", "N", "TW", "THR", "FR", "FV", "SX", "SVN", "GHT", "NN" };
	vector<int> cdigits(10);

	for (char c : S)
	{
		for (size_t i = 0; i < digits.size(); i++ )
		{
			if (digits[i].find(c) != string::npos)
				cdigits[i] += 1;
		}
	}

	for (size_t i = 0; i < digits.size(); i++)
	{
		cout << "dbg " << i << ": " << cdigits[i] << endl;

		if (int occur = int(cdigits[i] / digits.size()) )
		{
			for (int j = 0; j < occur; j++ )
				cout << i;
		}
	}
}

int main()
{
	int T = 0;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		string S;
		cin >> S;
		cout << "Case #" << i << ": ";
		GettingTheDigits(S);
		cout << endl;
	}
}
