#include <stdio.h>
#include <algorithm>
using namespace std;
int p[130];
int e = 0;
int dt[1000003][2];
void sub(int sum) {
	if (sum > 1000000) return;
	if (sum > 0) p[e++] = sum;
	sub((sum << 3) + (sum << 1) + 4);
	sub((sum << 3) + (sum << 1) + 7);
}
int ans[250001];
int main() {
	int n;
	int i, j;
	int tmp;
	int k;
	int m = 0;
	int d, t;
	sub(0);
	sort(p, p + e);
	scanf("%d", &n);
	dt[0][0] = 1;
	dt[0][1] = -1;
	for (i = e-1; i >= 0; i--) {
		tmp = p[i];
		k = n - tmp;
		for (j = 0; j <= k; j++) {
			if (dt[j][0] > 0) {
				if (dt[j + tmp][0] == 0 || dt[j + tmp][0] >= dt[j][0] + 1) {
					dt[j + tmp][0] = dt[j][0] + 1;
					dt[j + tmp][1] = tmp;
				}
			}
		}
	}
	d = t = n;
	while (1) {
		d = dt[d][1];
		if (d == 0) {
			printf("-1");
			return 0;
		}
		if (d == -1) break;
		ans[m++] = d;
		d = t - d;
		t = d;
	}
	sort(ans, ans + m);
	for (i = 0; i < m; i++) printf("%d ", ans[i]);
	return 0;
}