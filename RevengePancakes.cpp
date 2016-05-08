#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int Count(string s, char c)
{
	int ret = 0;
	for (char c2 : s)
		if (c2 == c)
			ret++;
	return ret;
}

int CountBottom(string s, char c)
{
	int ret = 0;
	for (int i = s.size() - 1; i > 0; i--)
	{
		if (s[size_t(i)] == c)
			ret++;
		else
			break;
	}
	return ret;
}

int CountTop(string s, char c)
{
	int ret = 0;
	for( char c2: s )
	{
		if( c2 == c )
			ret++;
		else
			break;
	}
	return ret;
}

void Reverse(string& s, int pancakes)
{
	std::reverse(s.begin(), s.begin() + pancakes);
	for (auto it = s.begin(); it < s.begin() + pancakes; ++it )
	{
		if (*it == '+')
			*it = '-';
		else
			*it = '+';
	}
}

int FlipOnce(string& s)
{
	// consider everything's happy
	if (Count(s, '+') == s.size())
		return 0;

	// consider everything's blank
	if (Count(s, '-') == s.size())
	{
		Reverse(s, s.size());
		return 1;
	}

	// count blank sides on top
	int blankTop = CountTop(s, '-');

	// count blank sides on bottom
	int blankBottom = CountBottom(s, '-');

	// blank sides on bottom is less than on top but not zero?
	if (blankBottom < blankTop && blankBottom != 0)
	{
		Reverse(s, s.size());
		return 1;
	}

	// blank sides on bottom is more than on top but top is zero?
	if (blankBottom > blankTop && blankTop == 0)
	{
		int happyTop = CountTop(s, '+');
		Reverse(s, happyTop);
		return 1;
	}

	if (blankTop != 0)
	{
		Reverse(s, blankTop);
		return 1;
	}

	int happyBottom = CountBottom(s, '+');
	string ss = s.substr(0, s.size() - happyBottom);
	string hs = s.substr(s.size() - happyBottom);
	int ret = FlipOnce(ss);
	s = ss + hs;
	return ret;
}

int Flip(string s)
{
	int ret = 0;
	while (true)
	{
		if( FlipOnce(s) == 0 )
			break;
		ret++;
	}
	return ret;
}

int main()
{
	int T = 0;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		string s;
		cin >> s;
		cout << "Case #" << i << ": " << Flip(s) << endl;
	}
}
