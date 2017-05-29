#include <stdio.h>
#define MOD 1000000000
int dt[110][10][4];
int main() {
	int i, j;
	int n;
	int ans = 0;
	scanf("%d", &n);
	dt[1][1][0] = 1;
	dt[1][2][0] = 1;
	dt[1][3][0] = 1;
	dt[1][4][0] = 1;
	dt[1][5][0] = 1;
	dt[1][6][0] = 1;
	dt[1][7][0] = 1;
	dt[1][8][0] = 1;
	dt[1][9][2] = 1;
	for (i = 1; i < n; i++) {
		for (j = 0; j < 10; j++) {
			if (j - 1 >= 0) {
				dt[i + 1][j - 1][1] = (dt[i + 1][j - 1][1] + dt[i][j][1]) % MOD;
				dt[i + 1][j - 1][3] = (dt[i + 1][j - 1][3] + dt[i][j][3]) % MOD;

				if (j - 1 == 0) {
					dt[i + 1][j - 1][1] = (dt[i + 1][j - 1][1] + dt[i][j][0]) % MOD;
					dt[i + 1][j - 1][3] = (dt[i + 1][j - 1][3] + dt[i][j][2]) % MOD;
				}
				else {
					dt[i + 1][j - 1][0] = (dt[i + 1][j - 1][0] + dt[i][j][0]) % MOD;
					dt[i + 1][j - 1][2] = (dt[i + 1][j - 1][2] + dt[i][j][2]) % MOD;
				}
			}
			if (j + 1 < 10) {
				dt[i + 1][j + 1][2] = (dt[i + 1][j + 1][2] + dt[i][j][2]) % MOD;
				dt[i + 1][j + 1][3] = (dt[i + 1][j + 1][3] + dt[i][j][3]) % MOD;

				if (j + 1 == 9) {
					dt[i + 1][j + 1][2] = (dt[i + 1][j + 1][2] + dt[i][j][0]) % MOD;
					dt[i + 1][j + 1][3] = (dt[i + 1][j + 1][3] + dt[i][j][1]) % MOD;
				}
				else {
					dt[i + 1][j + 1][0] = (dt[i + 1][j + 1][0] + dt[i][j][0]) % MOD;
					dt[i + 1][j + 1][1] = (dt[i + 1][j + 1][1] + dt[i][j][1]) % MOD;
				}
			}
		}
	}
	for (i = 0; i < 10; i++) {
		ans += dt[n][i][3];
		ans %= MOD;
	}
	printf("%d", ans);
	return 0;
}