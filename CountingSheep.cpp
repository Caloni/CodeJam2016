#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string Count(int N)
{
	char digits[11] = {};
	int i = 1;

	for (; ; )
	{
		int n = N * i;
		string ns = std::to_string(n);

		for (auto c : ns)
			digits[c - '0'] = '1';

		if (strlen(digits) == 10)
			return std::to_string(n);

		if (i > 1 && n == N) 
			break;

		if (n < N)
			break;

		++i;
	}

	return "INSOMNIA";
}

int main()
{
	int T = 0;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		int N = 0;
		cin >> N;
		cout << "Case #" << i << ": " << Count(N) << endl;
	}
}
