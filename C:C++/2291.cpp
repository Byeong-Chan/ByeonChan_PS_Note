#include <stdio.h>
int o[223][223][11];
int a[11];
int main() {
	int i, j, k, l;
	int d;
	int n, m, c;
	int tmpn;
	int e = 0;
	scanf("%d %d %d", &n, &m, &c);
	tmpn = n;
	for (i = m; i >= 1; i--) {
		o[i][i][1] = 1;
		for (j = i; j <= m; j++) {
			for (k = 1; k < n; k++) {
				for (l = i; l >= 1; l--) {
					if (j + l <= m) o[l][j + l][k + 1] += o[i][j][k];
				}
			}
		}
	}

	for (i = 1; i < m; i++) {
		e += o[i][m][n];
	}
	d = 1;
	for (; n>0; n--) {
		for (i = d; i <= m; i++) {
			if (c <= o[i][m][n]) break;
			c -= o[i][m][n];
		}
		d = i;
		m -= i;
		a[n - 1] = i;
	}
	for (i = tmpn-1; i>=0; i--) printf("%d ", a[i]);
	return 0;
}