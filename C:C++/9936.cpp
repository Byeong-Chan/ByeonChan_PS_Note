#include <stdio.h>
#define mini -((long long)0x7fffffff << 1)
struct bung {
	long long gap;
	bool chk;
}dt[1010][9], tmp[1010][9], clr;
int main() {
	int i, j, k;
	long long x, y, z;
	long long tmpx, tmpy, tmpz;
	long long tmpgap;
	int n, m;
	long long ans = mini;
	scanf("%d %d", &n, &m);
	scanf("%lld %lld %lld", &x, &y, &z);
	dt[0][0].chk = true;
	dt[1][3].chk = true;
	dt[1][3].gap = x + y;
	dt[1][6].chk = true;
	dt[1][6].gap = y + z;
	for (i = 1; i < n; i++) {
		tmpx = x;
		tmpy = y;
		tmpz = z;
		scanf("%lld %lld %lld", &x, &y, &z);
		for (j = 0; j <= m; j++) {
			for (k = 0; k < 8; k++) {
				if (j == m && dt[j][k].chk) {
					if (ans < dt[j][k].gap) ans = dt[j][k].gap;
				}
				tmp[j][k] = dt[j][k];
				dt[j][k] = clr;
			}
		}
		for (j = 0; j <= m; j++) {
			for (k = 0; k < 8; k++) {
				if (tmp[j][k].chk) {
					// 0
					if (dt[j][0].chk) {
						if (dt[j][0].gap < tmp[j][k].gap) dt[j][0].gap = tmp[j][k].gap;
					}
					else dt[j][0] = tmp[j][k];

					// 1
					if (!(k & 1)) {
						if (j + 1 <= m) {
							if (dt[j + 1][1].chk) {
								if (dt[j + 1][1].gap < tmp[j][k].gap + tmpx + x) dt[j + 1][1].gap = tmp[j][k].gap + tmpx + x;
							}
							else {
								dt[j + 1][1] = tmp[j][k];
								dt[j + 1][1].gap += tmpx + x;
							}
						}
					}
					
					// 2
					if (!(k & 2)) {
						if (j + 1 <= m) {
							if (dt[j + 1][2].chk) {
								if (dt[j + 1][2].gap < tmp[j][k].gap + tmpy + y) dt[j + 1][2].gap = tmp[j][k].gap + tmpy + y;
							}
							else {
								dt[j + 1][2] = tmp[j][k];
								dt[j + 1][2].gap += tmpy + y;
							}
						}
					}

					// 3
					tmpgap = x + y + tmp[j][k].gap;
					if (j + 1 <= m) {
						if (dt[j + 1][3].chk) {
							if (dt[j + 1][3].gap < tmpgap) dt[j + 1][3].gap = tmpgap;
						}
						else {
							dt[j + 1][3].chk = true;
							dt[j + 1][3].gap = tmpgap;
						}
					}

					tmpgap = x + y + tmpx + tmpy + tmp[j][k].gap;
					if (!(k & 3)) {
						if (j + 2 <= m) {
							if (j + 2 <= m) {
								if (dt[j + 2][3].chk) {
									if (dt[j + 2][3].gap < tmpgap) dt[j + 2][3].gap = tmpgap;
								}
								else {
									dt[j + 2][3].chk = true;
									dt[j + 2][3].gap = tmpgap;
								}
							}
						}
					}

					// 4
					if (!(k & 4)) {
						if (j + 1 <= m) {
							if (dt[j + 1][4].chk) {
								if (dt[j + 1][4].gap < tmp[j][k].gap + tmpz + z) dt[j + 1][4].gap = tmp[j][k].gap + tmpz + z;
							}
							else {
								dt[j + 1][4] = tmp[j][k];
								dt[j + 1][4].gap += tmpz + z;
							}
						}
					}

					// 5
					tmpgap = x + z + tmpx + tmpz + tmp[j][k].gap;
					if (!(k & 5)) {
						if (j + 2 <= m) {
							if (j + 2 <= m) {
								if (dt[j + 2][5].chk) {
									if (dt[j + 2][5].gap < tmpgap) dt[j + 2][5].gap = tmpgap;
								}
								else {
									dt[j + 2][5].chk = true;
									dt[j + 2][5].gap = tmpgap;
								}
							}
						}
					}

					// 6
					tmpgap = y + z + tmp[j][k].gap;
					if (j + 1 <= m) {
						if (dt[j + 1][6].chk) {
							if (dt[j + 1][6].gap < tmpgap) dt[j + 1][6].gap = tmpgap;
						}
						else {
							dt[j + 1][6].chk = true;
							dt[j + 1][6].gap = tmpgap;
						}
					}

					tmpgap = y + z + tmpy + tmpz + tmp[j][k].gap;
					if (!(k & 6)) {
						if (j + 2 <= m) {
							if (j + 2 <= m) {
								if (dt[j + 2][6].chk) {
									if (dt[j + 2][6].gap < tmpgap) dt[j + 2][6].gap = tmpgap;
								}
								else {
									dt[j + 2][6].chk = true;
									dt[j + 2][6].gap = tmpgap;
								}
							}
						}
					}

					// 7

					tmpgap = x + y + z + tmpz + tmp[j][k].gap;
					if (!(k & 4)) {
						if (j + 2 <= m) {
							if (j + 2 <= m) {
								if (dt[j + 2][7].chk) {
									if (dt[j + 2][7].gap < tmpgap) dt[j + 2][7].gap = tmpgap;
								}
								else {
									dt[j + 2][7].chk = true;
									dt[j + 2][7].gap = tmpgap;
								}
							}
						}
					}

					tmpgap = x + y + z + tmpx + tmp[j][k].gap;
					if (!(k & 1)) {
						if (j + 2 <= m) {
							if (j + 2 <= m) {
								if (dt[j + 2][7].chk) {
									if (dt[j + 2][7].gap < tmpgap) dt[j + 2][7].gap = tmpgap;
								}
								else {
									dt[j + 2][7].chk = true;
									dt[j + 2][7].gap = tmpgap;
								}
							}
						}
					}

					tmpgap = x + y + z + tmpx + tmpy + tmpz + tmp[j][k].gap;
					if (!(k & 7)) {
						if (j + 3 <= m) {
							if (j + 3 <= m) {
								if (dt[j + 3][7].chk) {
									if (dt[j + 3][7].gap < tmpgap) dt[j + 3][7].gap = tmpgap;
								}
								else {
									dt[j + 3][7].chk = true;
									dt[j + 3][7].gap = tmpgap;
								}
							}
						}
					}
				}
			}
		}
	}
	for (k = 0; k < 8; k++) {
		if (dt[m][k].chk) {
			if (ans < dt[m][k].gap) ans = dt[m][k].gap;
		}
	}
	printf("%lld", ans);
	return 0;
}