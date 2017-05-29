#include <stdio.h>
long long int o[110000], hap[110000];
long long int table[2][100021];
int que[110000];
int _moth[201][100021];
int repeat[204];
int repeat2[204];
int main()
{
	int i, j, k, n, m;
	bool sw1, sw2;
	long long int tmp, tmp2, tmp3, s, pp;
	int key;
	int lev;
	int sl = 0;
	int hs;
	int hp1, hp2, hp3;
	int tail, head;
	//fropen("input.txt","rt",stdin);
	//fropen("output.txt","w",stdout);
	scanf("%d %d", &n, &m);
	for (i = 0; i<n; i++)
	{
		scanf("%lld", &o[i]);
		hap[i] = o[i];
		if (i > 0) hap[i] += hap[i - 1];
	}

	// first, [average]
	for (i = 0; i<n - m; i++)
	{
		table[0][i] = 0;
	}
	for (i = 1; i <= m; i++)
	{
		sw1 = i % 2;
		sw2 = !sw1;
		tail = head = 0;

		que[tail] = i - 1;
		tail++;
		table[sw1][i] = table[sw2][i - 1] + hap[i - 1] * (hap[i] - hap[i - 1]);
		_moth[i][i] = i - 1;

		head++;
		for (j = i + 1; j<n - m + i; j++)
		{
			if (tail == head)
			{
				tmp = table[sw2][j - 1] + hap[j - 1] * (hap[j] - hap[j - 1]);
				s = table[sw2][j - 2] + hap[j - 2] * (hap[j] - hap[j - 2]);

				if (s <= tmp)
				{
					que[tail] = j - 1;
					tail++;
					head++;
				}
				else
				{
					que[tail] = j - 1;
					tail++;
				}
			}
			else
			{
				hp1 = hap[j - 1];
				tmp = table[sw2][j - 1] + hp1 * (hap[j] - hp1);

				hs = que[tail - 1];

				hp3 = hap[hs];
				pp = table[sw2][hs] + hp3 * (hap[j] - hp3);

				while (tail > head)
				{
					hs = que[tail - 2];

					hp2 = hp3;
					hp3 = hap[hs];

					s = pp;
					pp = table[sw2][hs] + hp3 * (hap[j] - hp3);


					if (s > tmp && pp < s) {
						break;
					}
					if (s < tmp) {
						tail--;
						continue;
					}

					tmp2 = s - tmp;
					tmp3 = pp - s;

					if (tmp2 * (hp2 - hp3) <= tmp3 * (hp1 - hp2)) {
						tail--;
						continue;
					}
					else {
						break;
					}

					tail--;
				}
				que[tail] = j - 1;
				tail++;
			}

			hs = que[head-1];

			tmp = table[sw2][hs] + hap[hs] * (hap[j] - hap[hs]);
			while (tail > head)
			{
				hs = que[head];
				s = tmp;
				tmp = table[sw2][hs] + hap[hs] * (hap[j] - hap[hs]);

				if (s > tmp) break;
				else head++;
			}
			k = que[head - 1];
			table[sw1][j] = table[sw2][k] + hap[k] * (hap[j] - hap[k]);
			_moth[i][j] = k;
		}
	}

	key = n - 1;
	repeat[m] = key;

	lev = m;
	while (lev > 0)
	{
		key = _moth[lev][key];
		repeat[m - sl - 1] = key;
		sl++;
		lev--;
	}

	printf("%lld\n", table[sw1][n - 1]);
	for (i = 0; i<m; i++)
	{
		printf("%d ", repeat[i] + 1);
	}
	return 0;
}