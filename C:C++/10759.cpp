#include <stdio.h>
int sav[510][510];
char o[510][510];
unsigned int dt[2][510][510];
int dx1[4] = { 1, 1, 0, 0 }, dy1[4] = { 0, 0, 1, 1 }, dx2[4] = { -1, 0, -1, 0 }, dy2[4] = { 0, -1, 0, -1 };
int main() {
	int i, j, l;
	int x1, y1, x2, y2;
	int n;
	int e1, e2;
	int sw;
	int k;
	int h1, h2;
	int s1, s2;
	int nex1, ney1, nex2, ney2;
	scanf("%d\n", &n);
	e1 = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) scanf("%c\n", &o[i][j]);
		sav[i][n - i - 1] = ++e1;
		dt[0][e1][e1] = 1;
	}
	for (i = 1; i < n; i++) {
		x1 = 0;
		y1 = n - i - 1;
		x2 = i;
		y2 = n - 1;
		e1 = e2 = 0;
		while (1) {
			sav[x1][y1] = ++e1;
			sav[x2][y2] = ++e2;
			x1++;
			y1--;
			x2++;
			y2--;
			if (x1 == n || y1 == -1) break;
		}

		k = i + 1;
		sw = i & 1;
		x1 = 0;
		y1 = n - i - 1;
		while (1) {
			x2 = i;
			y2 = n - 1;
			while (1) {
				if (o[x1][y1] == o[x2][y2]) {
					s1 = sav[x1][y1];
					s2 = sav[x2][y2];
					for (l = 0; l < 4; l++) {
						nex1 = x1 + dx1[l];
						ney1 = y1 + dy1[l];
						nex2 = x2 + dx2[l];
						ney2 = y2 + dy2[l];
						h1 = sav[nex1][ney1];
						h2 = sav[nex2][ney2];
						dt[sw][s1][s2] += dt[!sw][h1][h2];
					}
					dt[sw][s1][s2] %= 1000000007;
				}
				x2++;
				y2--;
				if (x2 == n || y2 == -1) break;
			}
			x1++;
			y1--;
			if (x1 == n || y1 == -1) break;
		}
		for (j = 0; j <= n - i; j++) for (l = 0; l <= n - i; l++) dt[!sw][j][l] = 0;
	}
	printf("%d", dt[sw][1][1]);
	return 0;
}