#include <stdio.h>
#include <string.h>

#define _max(x, y) ((x) > (y) ? (x) : (y))

int n, m, k;
int table[4][1503][1503];
int o[1503][1503];
int maxdt[1503][4];
int table2[1503][1503][4];
void findx() {
	int i, j;
	int a, b;
	int tmp, f;
	for (i = k; i <= n; i++) {
		memset(maxdt, 0, sizeof(maxdt));
		for (j = k; j <= m; j++) {
			if (table2[i - 1][j][1] > 0) table2[i][j][1] = _max(table2[i][j][1], table2[i - 1][j][1]);
			if (table2[i][j - 1][1] > 0) table2[i][j][1] = _max(table2[i][j][1], table2[i][j - 1][1]);
			if (table2[i - 1][j][2] > 0) table2[i][j][2] = _max(table2[i][j][2], table2[i - 1][j][2]);
			if (table2[i][j - 1][2] > 0) table2[i][j][2] = _max(table2[i][j][2], table2[i][j - 1][2]);
			if (table2[i - 1][j][3] > 0) table2[i][j][3] = _max(table2[i][j][3], table2[i - 1][j][3]);
			if (table2[i][j - 1][3] > 0) table2[i][j][3] = _max(table2[i][j][3], table2[i][j - 1][3]);

			f = o[i][j] - o[i - k][j] - o[i][j - k] + o[i - k][j - k];

			if (maxdt[j - 1][1] > 0) maxdt[j][1] = maxdt[j - 1][1];
			if (maxdt[j - 1][2] > 0) maxdt[j][2] = maxdt[j - 1][2];
			if (maxdt[j - 1][3] > 0) maxdt[j][3] = maxdt[j - 1][3];

			tmp = f;
			maxdt[j][1] = _max(maxdt[j][1], tmp);
			if (maxdt[j - k][1] > 0) {
				tmp = maxdt[j - k][1] + f;
				maxdt[j][2] = _max(maxdt[j][2], tmp);
			}
			if (maxdt[j - k][2] > 0) {
				tmp = maxdt[j - k][2] + f;
				maxdt[j][3] = _max(maxdt[j][2], tmp);
			}

			for (a = 0; a <= 3; a++) {
				for (b = 0; b <= 3 - a; b++) {
					if (a + b == 0) continue;
					tmp = 0;
					if ((a == 0 || maxdt[j][a] > 0) && (b == 0 || table2[i - k][j][b] > 0)) tmp = maxdt[j][a] + table2[i - k][j][b];
					table2[i][j][a + b] = _max(table2[i][j][a + b], tmp);
				}
			}
		}
	}
}
void findy() {
	int i, j;
	int a, b;
	int tmp, f;
	for (i = k; i <= m; i++) {
		memset(maxdt, 0, sizeof(maxdt));
		for (j = k; j <= n; j++) {
			if (table2[j - 1][i][1] > 0) table2[j][i][1] = _max(table2[j][i][1], table2[j - 1][i][1]);
			if (table2[j][i - 1][1] > 0) table2[j][i][1] = _max(table2[j][i][1], table2[j][i - 1][1]);
			if (table2[j - 1][i][2] > 0) table2[j][i][2] = _max(table2[j][i][2], table2[j - 1][i][2]);
			if (table2[j][i - 1][2] > 0) table2[j][i][2] = _max(table2[j][i][2], table2[j][i - 1][2]);
			if (table2[j - 1][i][3] > 0) table2[j][i][3] = _max(table2[j][i][3], table2[j - 1][i][3]);
			if (table2[j][i - 1][3] > 0) table2[j][i][3] = _max(table2[j][i][3], table2[j][i - 1][3]);

			f = o[j][i] - o[j - k][i] - o[j][i - k] + o[j - k][i - k];

			if (maxdt[j - 1][1] > 0) maxdt[j][1] = maxdt[j - 1][1];
			if (maxdt[j - 1][2] > 0) maxdt[j][2] = maxdt[j - 1][2];
			if (maxdt[j - 1][3] > 0) maxdt[j][3] = maxdt[j - 1][3];

			tmp = f;
			maxdt[j][1] = _max(maxdt[j][1], tmp);
			if (maxdt[j - k][1] > 0) {
				tmp = maxdt[j - k][1] + f;
				maxdt[j][2] = _max(maxdt[j][2], tmp);
			}
			if (maxdt[j - k][2] > 0) {
				tmp = maxdt[j - k][2] + f;
				maxdt[j][3] = _max(maxdt[j][2], tmp);
			}

			for (a = 0; a <= 3; a++) {
				for (b = 0; b <= 3 - a; b++) {
					if (a + b == 0) continue;
					tmp = 0;
					if ((a == 0 || maxdt[j][a] > 0) && (b == 0 || table2[j][i - k][b] > 0)) tmp = maxdt[j][a] + table2[j][i - k][b];
					table2[j][i][a + b] = _max(table2[j][i][a + b], tmp);
				}
			}
		}
	}
}
int main() {
	int i, j;
	int a, b;
	int tmp;
	int e = 0;
	int max1 = 0;
	scanf("%d %d %d", &n, &m, &k);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%d", &o[i][j]);
			o[i][j] += o[i - 1][j];
			o[i][j] += o[i][j - 1];
			o[i][j] -= o[i - 1][j - 1];
		}
	}
	// 왼쪽 위
	for (i = k; i <= n; i++) {
		for (j = k; j <= m; j++) {
			a = i;
			b = j;
			tmp = o[i][j] - o[i - k][j] - o[i][j - k] + o[i - k][j - k];
			table[0][a][b] = _max(table[0][a][b], table[0][a - 1][b]);
			table[0][a][b] = _max(table[0][a][b], table[0][a][b - 1]);
			table[0][a][b] = _max(table[0][a][b], tmp);
		}
	}
	// 오른쪽 위
	for (i = k; i <= n; i++) {
		for (j = m; j >= k; j--) {
			a = i;
			b = j - k + 1;
			tmp = o[i][j] - o[i - k][j] - o[i][j - k] + o[i - k][j - k];
			table[1][a][b] = _max(table[1][a][b], table[1][a - 1][b]);
			table[1][a][b] = _max(table[1][a][b], table[1][a][b + 1]);
			table[1][a][b] = _max(table[1][a][b], tmp);
		}
	}
	// 왼쪽 아래
	for (i = n; i >= k; i--) {
		for (j = k; j <= m; j++) {
			a = i - k + 1;
			b = j;
			tmp = o[i][j] - o[i - k][j] - o[i][j - k] + o[i - k][j - k];
			table[2][a][b] = _max(table[2][a][b], table[2][a + 1][b]);
			table[2][a][b] = _max(table[2][a][b], table[2][a][b - 1]);
			table[2][a][b] = _max(table[2][a][b], tmp);
		}
	}
	// 오른쪽 아래
	for (i = n; i >= k; i--) {
		for (j = m; j >= k; j--) {
			a = i - k + 1;
			b = j - k + 1;
			tmp = o[i][j] - o[i - k][j] - o[i][j - k] + o[i - k][j - k];
			table[3][a][b] = _max(table[3][a][b], table[3][a + 1][b]);
			table[3][a][b] = _max(table[3][a][b], table[3][a][b + 1]);
			table[3][a][b] = _max(table[3][a][b], tmp);
		}
	}
	for (i = k; i <= n - k; i++) {
		for (j = k; j <= m - k; j++) {
			e = table[0][i][m] + table[2][i + 1][j] + table[3][i + 1][j + 1];
			if (max1 < e) max1 = e;
		}
	}
	for (i = k; i <= n - k; i++) {
		for (j = k; j <= m - k; j++) {
			e = table[2][i+1][m] + table[0][i][j] + table[1][i][j + 1];
			if (max1 < e) max1 = e;
		}
	}
	for (i = k; i <= n - k; i++) {
		for (j = k; j <= m - k; j++) {
			e = table[0][n][j] + table[1][i][j+1] + table[3][i+1][j + 1];
			if (max1 < e) max1 = e;
		}
	}
	for (i = k; i <= n - k; i++) {
		for (j = k; j <= m - k; j++) {
			e = table[1][n][j+1] + table[0][i][j] + table[2][i + 1][j];
			if (max1 < e) max1 = e;
		}
	}
	findx();
	findy();
	findx();
	findy();
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (table2[i][j][3] > max1) max1 = table2[i][j][3];
		}
	}
	printf("%d", max1);
	return 0;
}