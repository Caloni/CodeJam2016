#include <iostream>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

void IncrementCoin(string& coin)
{
	long long coinI = stoll(coin, 0, 2);
	coinI += 2;
	if (coin.size() == 16)
		coin = bitset<16>(coinI).to_string();
	else
		coin = bitset<32>(coinI).to_string();
}

long long Divisor(long long n)
{
	long long ret = 0;
	for (long long i = 2; i < sqrt(n); i++)
	{
		if ((n / i) * i == n)
			return i;
	}
	return ret;
}

string JamCoin(string& coinCandidate, int64_t divisors[9])
{
	string coin;

	while (divisors[8] == 0)
	{
		coin = coinCandidate;

		for (int b = 2; b <= 10; b++)
		{
			long long n = stoll(coin, 0, b);
			if (long long d = Divisor(n))
			{
				divisors[b - 2] = d;
			}
			else
			{
				break;
			}
		}

		IncrementCoin(coinCandidate);
		//cout << coinCandidate << "...\n";
	}

	return coin;
}

void JamCoins(int N, int J)
{
	string coinCandidate = (N == 16) ? 
		"1000000000000001": "10000000000000000000000000000001";

	for (int i = 0; i < J; i++)
	{
		long long divisors[9] = {};
		string coin = JamCoin(coinCandidate, divisors);
		cout << coin;
		for (long long d : divisors)
			cout << " " << d;
		cout << endl;
	}
}

int main()
{
	long long l = stoll("10000000000000000000000000000001", 0, 5);
	int T = 0;
	cin >> T;

	for (int i = 1; i <= T; ++i)
	{
		int N = 0;
		int J = 0;
		cin >> N >> J;
		cout << "Case #" << i << ":" << endl;
		JamCoins(N, J);
	}
}
