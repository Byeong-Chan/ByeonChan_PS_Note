#include <stdio.h>
#include <algorithm>
using namespace std;
int o[1000010];
int u[1000010];
int tmp[4][1010];
int _abs(int x) {
	return x < 0 ? -x : x;
}
int main() {
	int i, j, n, m, k;
	int t;
	int d;
	int st, ed, mid;
	int ans;
	int sav;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &k, &n);
		m = n * n;
		for (i = 0; i < 4; i++) for (j = 0; j < n; j++) scanf("%d", &tmp[i][j]);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				o[j + i * n] = tmp[0][i] + tmp[1][j];
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				u[j + i * n] = tmp[2][i] + tmp[3][j];
			}
		}
		sort(u, u + m);
		ans = 500000000;
		for (i = 0; i < m; i++) {
			d = k - o[i];
			st = 0;
			ed = m - 1;
			while (st < ed) {
				mid = (st + ed) / 2;
				if (u[mid] < d) st = mid + 1;
				else ed = mid;
			}
			if (st == 0) {
				sav = u[st];
				if (_abs(k - ans) > _abs(d - sav)) ans = sav + o[i];
				else if(_abs(k - ans) == _abs(d - sav) && d - sav > 0) ans = sav + o[i];
			}
			else {
				sav = u[st];
				if (_abs(k - ans) > _abs(d - sav)) ans = sav + o[i];
				else if (_abs(k - ans) == _abs(d - sav) && d - sav > 0) ans = sav + o[i];

				sav = u[st-1];
				if (_abs(k - ans) > _abs(d - sav)) ans = sav + o[i];
				else if (_abs(k - ans) == _abs(d - sav) && d - sav > 0) ans = sav + o[i];
			}
			if (ans == k) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}