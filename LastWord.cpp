#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string LastWord(const string& s)
{
	string ret;

	for (char c : s)
	{
		string cs(1, c);

		if (ret.empty())
		{
			ret.push_back(c);
		}
		else
		{
			if (c >= ret[0])
				ret = cs + ret;
			else
				ret = ret + cs;
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
		string S;
		cin >> S;
		cout << "Case #" << i << ": " << LastWord(S) << endl;
	}
}
