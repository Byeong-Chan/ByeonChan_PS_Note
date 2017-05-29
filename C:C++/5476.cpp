#include <cstdio>
#include <algorithm>
using namespace std;
int indextree[1024290];
unsigned short dia[2][373][373][77]; // 0 : (/), 1 : (\)
unsigned short dp[373][373][77];
unsigned short dpo[373][373][77];
int sav[77];
long long cnt(int cx, int cy, int z, int D) {
	int dx = cx + D;
	int dy = cy;
	return dp[dx][dy][z] + dp[cx - D - 1][cy][z] - dp[dx - D - 1][dy - D][z] - dp[dx - D - 1][dy + D][z] - dia[0][dx - D - 1][dy + D + 1][z] - dia[1][dx - D - 1][dy - D - 1][z];
}
long long updatedp(int x, int y, int z) {
	if (x < 2) {
		if (y >= 1) return dp[x][y][z] + dp[x - 1][y - 1][z] + dp[x - 1][y + 1][z] + dpo[x - 1][y][z];
		else return dp[x][y][z] + dp[x - 1][y - 1][z] + dp[x - 1][y + 1][z] + dpo[x - 1][y][z];
	}
	if (y == 0) return dp[x][y][z] + dp[x - 1][y + 1][z] + dpo[x - 1][y][z];
	return dp[x][y][z] + dp[x - 1][y - 1][z] + dp[x - 1][y + 1][z] - dp[x - 2][y][z] + dpo[x - 1][y][z];
}
long long updatedia(int x, int y, int z, int sw) {
	if (sw) return dia[sw][x][y][z] + dia[sw][x - 1][y - 1][z];
	else return dia[sw][x][y][z] + dia[sw][x - 1][y + 1][z];
}
struct bung {
	int B;
	int x;
	int y;
	int z;
}o[100010];
bool cmp1(bung a, bung b) {
	return a.x < b.x;
}
bool cmp2(bung a, bung b) {
	if (a.y - a.x != b.y - b.x) return a.y - a.x > b.y - b.x;
	else return a.x + a.y < b.x + b.y;
}
bool cmp3(bung a, bung b) {
	return a.z < b.z;
}
int main() {
	int i, j, k;
	int B, n, D, maxD;
	int x, y, z;
	scanf("%d %d %d %d", &B, &n, &D, &maxD);
	for (i = 0; i < n; i++) {
		o[i].B = B;
		if (B == 1) scanf("%d", &o[i].x);
		else if (B == 2) scanf("%d %d", &o[i].x, &o[i].y);
		else {
			scanf("%d %d %d", &o[i].x, &o[i].y, &o[i].z);
			x = o[i].x + 148;
			y = o[i].y + 148;
			z = o[i].z;
			dp[x][y][z]++;
			dpo[x][y][z]++;
			dia[0][x][y][z]++;
			dia[1][x][y][z]++;
			sav[z]++;
		}
	}
	if (B == 1) {
		sort(o, o + n, cmp1);
		int st, ed;
		long long ans = 0;
		for (ed = 0, st = 0; ed < n; ed++) {
			while (o[ed].x - o[st].x > D) st++;
			ans += ed - st;
		}
		printf("%lld\n", ans);
	}
	else if (B == 2) {
		int l, r;
		int k = 524288;
		int d;
		int dx, dy;
		long long ans = 0;
		sort(o, o + n, cmp2);
		int st, ed;
		for (ed = 0, st = 0; ed < n; ed++) {
			while (o[st].y - o[st].x - (o[ed].y - o[ed].x) > D) {
				d = k + o[st].x + o[st].y;
				while (d > 0) {
					indextree[d]--;
					d >>= 1;
				}
				st++;
			}
			dx = o[ed].x;
			dy = o[ed].y + D;

			l = k + dx + dy - 2 * D;
			if (l < k) l = k;
			d = r = k + dx + dy;
			while (1) {
				if (l == r) {
					ans += indextree[l];
					break;
				}
				if (l & 1) {
					ans += indextree[l];
					l++;
				}
				if (!(r & 1)) {
					ans += indextree[r];
					r--;
				}
				if (l > r) break;
				l >>= 1;
				r >>= 1;
			}

			d -= D;
			while (d > 0) {
				indextree[d]++;
				d >>= 1;
			}
		}
		printf("%lld\n", ans);
	}
	else {
		sort(o, o + n, cmp3);
		x = 371;
		for (i = 0; i <= maxD + 1; i++) {
			for (j = 1; j <= x; j++) {
				for (k = 0; k <= x; k++) {
					dp[j][k][i] = updatedp(j, k, i);
					dia[0][j][k][i] = updatedia(j, k, i, 0);
					dia[1][j][k][i] = updatedia(j, k, i, 1);
				}
			}
		}
		long long ans = 0;
		long long cov[80] = { 0, };
		for (i = 0; i < n; i++) {
			x = o[i].x + 148;
			y = o[i].y + 148;
			for (j = o[i].z, k = D; j >= 0; j--, k--) {
				if (k == -1) break;
				if (k == D) {
					if (k > 148) {
						cov[j] += sav[j] - 1;
						continue;
					}
					cov[j] += cnt(x, y, j, k) - 1;
				}
				else {
					if (k > 148) {
						ans += sav[j];
						continue;
					}
					ans += cnt(x, y, j, k);
				}
			}
		}
		for (i = 0; i <= maxD; i++) ans += cov[i] >> 1;
		printf("%lld\n", ans);
	}
	return 0;
}