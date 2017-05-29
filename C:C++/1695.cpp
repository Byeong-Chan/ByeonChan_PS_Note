#include <stdio.h>
#include <algorithm>
using namespace std;

#define max(x, y) ((x) > (y) ? (x) : (y))

short table[5002][5002];
int o[5002];
int u[5002];
int main() {
	int n;
	int i, j;
	int d;
	int almax = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &o[i]);
		u[i] = o[i];
	}
	reverse(u + 1, u + n + 1);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (o[i] == u[j]) d = table[i - 1][j - 1] + 1;
			else d = 0;
			d = max(d, table[i - 1][j]);
			d = max(d, table[i][j - 1]);
			table[i][j] = d;
			almax = (almax, d);
		}
	}
	printf("%d", n - almax);
	return 0;
}