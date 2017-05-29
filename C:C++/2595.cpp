#include <stdio.h>
#include <string.h>
char a[189700], b[189007];
int table[15][30160][2], table2[1897][4000][2];
int main()
{
	int i, j, k, l;
	int f2, f5;
	int n, m;
	int min1 = 0x7fffffff, t;
	int h = 0, w;
	int pp = 1, p = 1, e = 0, s = 0;
	int d, lev;
	int tmp1, tmp2;
	int sub1, sub2;
	int sup1, sup2;
	//freopen("input.txt","rt", stdin);
	//freopen("output.txt","w", stdout);
	scanf("%d",&n);
	m = n;
	f2 = f5 = 0;
	while(!(n & 1) || !(n % 5))
	{
		if((n & 1) && n % 25 != 0) {
			if(n % 5 == 0) p = 5;
			break;
		}
		if(n % 16 != 0 && n % 5 != 0) {
			if(n % 8 == 0) p = 8;
			else if(n % 4 == 0) p = 4;
			else if(!(n & 1)) p = 2;
			break;
		}

		if(!(n & 1)) {n /= 2; f2++;}
		if(!(n % 5)) {n /= 5; f5++;}
		h++;
	}

	w = h;
	if(p == 8) w += 3;
	if(p == 4) w += 2;
	if(p == 2 || p ==5) w++;

	pp *= p;
	for(i=0;i<f2;i++) pp *= 2;
	for(i=0;i<f5;i++) pp *= 5;

	for(i=1;i<=9;i++)
	{
		if(i % p != 0) continue;
		d = i;

		d %= n;
		e += i;
		e %= n;
		for(j=1;e;j++)
		{
			d *= 10;
			d %= n;
			e += d;
			e %= n;
		}
		if(min1 > j) {
			min1 = j;
			t = i;
		}
	}
	for(i=0;i<min1;i++) a[i] = t + '0';
	for(i=min1;i<min1+h;i++) a[i] = '0';
	min1 += h;
	a[min1] = 0;

	if(h == 0)
	{
		printf("%s",a);
		return 0;
	}

	n = m;
	m = n / pp;
	for(i=0;i<10;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(!(n & 1) && (i & 1) && (j & 1)) continue;

			for (k = 0; k < w; k++)
			{
				for (l = 0; l <= n; l++) {
					table[k][l][0] = 0;
					table[k][l][1] = 0;
				}
			}
			for (k = w-1; k <= min1; k++)
			{
				for (l = 0; l <= m; l++) {
					table2[k][l][0] = 0;
					table2[k][l][1] = 0;
				}
			}

			s = 0;

			tmp1 = i;
			tmp1 %= n;
			tmp2 = j;
			tmp2 %= n;

			table[0][tmp2][0] = 2;
			table[0][tmp1][0] = 1;

			for(k=1;k<w;k++)
			{
				if(k > min1) break;
				tmp1 *= 10;
				tmp1 %= n;
				tmp2 *= 10;
				tmp2 %= n;

				for(l=0;l<n;l++)
				{
					if(table[k-1][l][0] == 0) continue;
					sup1 = l + tmp1;
					if(sup1 > n) sup1 -= n;
					sup2 = l + tmp2;
					if(sup2 > n) sup2 -= n;

					table[k][sup1][0] = 1;
					table[k][sup1][1] = l;

					if(table[k][sup2][0] == 0)
					{
						table[k][sup2][0] = 2;
						table[k][sup2][1] = l;
					}
				}
				if(table[k][n][0] == 1 && min1 >= k)
				{
					lev = k;
					d = n;
					if(table[lev][d][0] == 1) b[s++] = i + '0';
					if(table[lev][d][0] == 2) b[s++] = j + '0';

					while(lev > 0)
					{
						d = table[lev][d][1];
						lev --;
						if(table[lev][d][0] == 1) b[s++] = i + '0';
						if(table[lev][d][0] == 2) b[s++] = j + '0';
					}
					b[s] = 0;

					if(min1 > k)
					{
						min1 = k;
						strcpy(a, b);
						p = 0;
					}
					else
					{
						if(strcmp(a, b) == 1) strcpy(a, b);
						p = 0;
					}
					break;
				}
			}
			if(k < w && table[k][n][0] == 1) continue;

			s = 0;

			for(k=0;k<n;k++)
			{
				if(k % pp == 0 && table[w-1][k][0] != 0)
				{
					table2[w-1][k/pp][0] = table[w-1][k][0];
					table2[w-1][k/pp][1] = k;
				}
			}

			for(k=w;k<=min1;k++)
			{
				tmp1 *= 10;
				tmp1 %= n;
				tmp2 *= 10;
				tmp2 %= n;

				sub1 = tmp1 / pp;
				sub2 = tmp2 / pp;
				for(l=0;l<m;l++)
				{
					if(table2[k-1][l][0] == 0) continue;
					sup1 = l + sub1;
					if(sup1 > m) sup1 -= m;
					sup2 = l + sub2;
					if(sup2 > m) sup2 -= m;

					table2[k][sup1][0] = 1;
					table2[k][sup1][1] = l;

					if(table2[k][sup2][0] == 0)
					{
						table2[k][sup2][0] = 2;
						table2[k][sup2][1] = l;
					}
				}

				if(table2[k][m][0] != 0 && min1 >= k)
				{
					lev = k;
					d = m;
					if(table2[lev][d][0] == 1) b[s++] = i + '0';
					if(table2[lev][d][0] == 2) b[s++] = j + '0';

					while(lev >= w)
					{
						d = table2[lev][d][1];
						lev --;
						if(table2[lev][d][0] == 1) b[s++] = i + '0';
						if(table2[lev][d][0] == 2) b[s++] = j + '0';
					}

					d *= pp;

					while(lev > 0)
					{
						d = table[lev][d][1];
						lev --;
						if(table[lev][d][0] == 1) b[s++] = i + '0';
						if(table[lev][d][0] == 2) b[s++] = j + '0';
					}

					b[s] = 0;

					if(min1 > k)
					{
						min1 = k;
						strcpy(a, b);
						p = 0;
					}
					else
					{
						if(strcmp(a, b) == 1) strcpy(a, b);
						p = 0;
					}

					break;
				}
			}
		}
	}
	printf("%s",a);
	return 0;
}