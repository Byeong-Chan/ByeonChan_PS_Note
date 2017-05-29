#include <stdio.h>
#include <string.h>
int dt[10050][40];
int main() {
	int i, j, n;
	int x, y;
	int t;
	int tmp;
	int ans;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n + 30; i++) {
			for (j = 0; j < 30; j++) {
				dt[i][j] = 0x7fffffff;
			}
		}
		dt[0][0] = 0;
		for (i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			for (j = 0; j < 30; j++) {
				if (dt[i][j] != 0x7fffffff) {
					if (j == 0) {
						tmp = dt[i][j] + x + (y << 1);
						if (tmp < dt[i + 1][0]) dt[i + 1][0] = tmp;
						tmp = dt[i][j] + (y << 1) + 3;
						if (tmp < dt[i + 1][0]) dt[i + 1][0] = tmp;
						tmp = dt[i][j] + (y << 1) + 18;
						if (tmp < dt[i + 1][6]) dt[i + 1][6] = tmp;
						tmp = dt[i][j] + (y << 1) + 45;
						if (tmp < dt[i + 1][29]) dt[i + 1][29] = tmp;
						tmp = dt[i][j] + 6;
						if (tmp < dt[i + 1][0]) dt[i + 1][0] = tmp;
						tmp = dt[i][j] + 36;
						if (tmp < dt[i + 7][0]) dt[i + 7][0] = tmp;
						tmp = dt[i][j] + 90;
						if (tmp < dt[i + 30][0]) dt[i + 30][0] = tmp;
					}
					if (j > 0) {
						tmp = dt[i][j] + (y << 1);
						if (tmp < dt[i + 1][j - 1]) dt[i + 1][j - 1] = tmp;
						tmp = dt[i][j] + (y << 1) + 18;
						if (tmp < dt[i + 1][6]) dt[i + 1][6] = tmp;
						tmp = dt[i][j] + (y << 1) + 45;
						if (tmp < dt[i + 1][29]) dt[i + 1][29] = tmp;
						tmp = dt[i][j] + 6;
						if (tmp < dt[i + 1][j - 1]) dt[i + 1][j - 1] = tmp;
						tmp = dt[i][j] + 36;
						if (j - 7 >= 0) {
							if (tmp < dt[i + 7][j - 7]) dt[i + 7][j - 7] = tmp;
						} else {
							if (tmp < dt[i + 7][0]) dt[i + 7][0] = tmp;
						}
						tmp = dt[i][j] + 90;
						if (tmp < dt[i + 30][0]) dt[i + 30][0] = tmp;
					}
				}
			}
		}
		ans = 0x7fffffff;
		for (i = n + 29; i >= n; i--) {
			for (j = 0; j < 30; j++) {
				if (ans > dt[i][j]) ans = dt[i][j];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}