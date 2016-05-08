#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>

using namespace std;


void SenateEvacuation(int total, int senators[])
{
	while (true)
	{
		int p = 0;

		for (int s = 1; s < 26; ++s)
		{
			if (senators[s] > senators[p])
				p = s;
		}

		cout << char('A' + p);
		senators[p] -= 1;
		total -= 1;

		p = -1;
		for (int s = 0; s < 26; ++s)
		{
			if (senators[s] > (total / 2) )
				p = s;
		}

		if (p >= 0)
		{
			cout << char('A' + p);
			senators[p] -= 1;
			total -= 1;
		}

		if (total)
			cout << ' ';
		else
			break;
	}
}


int main()
{
	int T = 0;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		int N = 0;
		cin >> N;

		int total = 0;
		int senators[26] = {};
		for (int j = 0; j < N; ++j)
		{
			int n = 0;
			cin >> n;
			senators[j] = n;
			total += n;
		}

		cout << "Case #" << i << ": ";
		SenateEvacuation(total, senators);
		cout << endl;
	}
}
