#include <cstdio>
#include <algorithm>
using namespace std;
int p[2010][2];
int o[1010];
int dt[1010][1010][2][2];
bool chk[2010];
int main() {
	int i, j, n, m = 0;
	int x, y;
	int ans = 1000;
	int d;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &x);
		x += 1000;

		if (chk[x] == 0) o[m++] = x;
		chk[x] = true;

		if (p[x][0] == 0) p[x][0] = p[x][1] = i;
		else p[x][1] = i;
	}
	sort(o, o + m);
	dt[0][p[o[0]][1]][0][0] = 1;
	dt[0][p[o[0]][0]][0][1] = 1;
	for (i = 0; i < m - 1; i++) {
		x = p[o[i + 1]][0];
		y = p[o[i + 1]][1];
		for (j = 1; j <= n; j++) {
			// once, up
			if (dt[i][j][0][0]) {
				// once, up
				if (j < x) {
					dt[i + 1][y][0][0] = min(dt[i + 1][y][0][0], dt[i][j][0][0]);
					if (dt[i + 1][y][0][0] == 0) dt[i + 1][y][0][0] = dt[i][j][0][0];
				}
				// once, up, next
				dt[i + 1][y][0][0] = min(dt[i + 1][y][0][0], dt[i][j][0][0] + 1);
				if (dt[i + 1][y][0][0] == 0) dt[i + 1][y][0][0] = dt[i][j][0][0] + 1;
				// once, down, next
				dt[i + 1][x][0][1] = min(dt[i + 1][x][0][1], dt[i][j][0][0] + 1);
				if (dt[i + 1][x][0][1] == 0) dt[i + 1][x][0][1] = dt[i][j][0][0] + 1;
			}

			// once, down
			if (dt[i][j][0][1]) {
				// once, down
				if (j > y) {
					dt[i + 1][x][0][1] = min(dt[i + 1][x][0][1], dt[i][j][0][1]);
					if (dt[i + 1][x][0][1] == 0) dt[i + 1][x][0][1] = dt[i][j][0][1];
				}
				// twice, up
				dt[i + 1][y][1][0] = min(dt[i + 1][y][1][0], dt[i][j][0][1]);
				if (dt[i + 1][y][1][0] == 0) dt[i + 1][y][1][0] = dt[i][j][0][1];
				// once, up, next
				dt[i + 1][y][0][0] = min(dt[i + 1][y][0][0], dt[i][j][0][1] + 1);
				if (dt[i + 1][y][0][0] == 0) dt[i + 1][y][0][0] = dt[i][j][0][1] + 1;
				// once, down, next
				dt[i + 1][x][0][1] = min(dt[i + 1][x][0][1], dt[i][j][0][1] + 1);
				if (dt[i + 1][x][0][1] == 0) dt[i + 1][x][0][1] = dt[i][j][0][1] + 1;
			}

			// twice, up
			if (dt[i][j][1][0]) {
				// twice, up
				if (j < x) {
					dt[i + 1][y][1][0] = min(dt[i + 1][y][1][0], dt[i][j][1][0]);
					if (dt[i + 1][y][1][0] == 0) dt[i + 1][y][1][0] = dt[i][j][1][0];
				}
				// once, up, next
				dt[i + 1][y][0][0] = min(dt[i + 1][y][0][0], dt[i][j][1][0] + 1);
				if (dt[i + 1][y][0][0] == 0) dt[i + 1][y][0][0] = dt[i][j][1][0] + 1;
				// once, down, next
				dt[i + 1][x][0][1] = min(dt[i + 1][x][0][1], dt[i][j][1][0] + 1);
				if (dt[i + 1][x][0][1] == 0) dt[i + 1][x][0][1] = dt[i][j][1][0] + 1;
			}
		}
	}
	for (i = 1; i <= n; i++) {
		x = dt[m - 1][i][0][0];
		if (x > 0 && ans > x) ans = x;
		x = dt[m - 1][i][0][1];
		if (x > 0 && ans > x) ans = x;
		x = dt[m - 1][i][1][0];
		if (x > 0 && ans > x) ans = x;
		x = dt[m - 1][i][1][1];
		if (x > 0 && ans > x) ans = x;
	}
	printf("%d", ans);
	return 0;
}