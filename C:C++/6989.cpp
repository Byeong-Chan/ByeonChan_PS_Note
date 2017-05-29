#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> o[160];
int _score[160];
int total_score[160];
int s[160][160];
int check1[1510000];
int main()
{
	int x;
	int n, m;
	int i, j, k, l;
	int c, d;
	int _size;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		_score[i] = _score[i - 1] + x;
		total_score[i] = _score[i] + total_score[i - 1];
	}
	scanf("%d", &m);
	for (i = 1; i <= n; i++)
	{
		for (j = i; j <= n; j++)
		{
			s[i][j] = total_score[j] - total_score[i - 1] - _score[i - 1] * (j - i + 1);
		}
	}
	o[0].push_back(0);
	check1[0] = 1;
	for (i = 1; i <= n; i++)
	{
		for (j = i; j >= 1; j--)
		{
			d = j - 2;
			if (d < 0) d = 0;
			for (k = d; k >= 0; k--)
			{
				_size = o[k].size();
				for (l = 0; l < _size; l++)
				{
					c = o[k][l] + s[j][i];
					if (check1[c] == 0)
					{
						check1[c] = 1;
						o[i].push_back(c);
					}
				}
			}
		}
	}
	if (s[1][n] < m)
	{
		printf("%d", m);
	}
	else
	{
		for (i = m; i <= s[1][n]; i++)
		{
			if (check1[i] == 0) break;
		}
		printf("%d", i);
	}
	return 0;
}