#include <stdio.h>
int o[110];
int main() {
	int n, m;
	int x, y;
	int tmp;
	int i;
	int t;
	int p;
	int pos;
	int h;
	int ans = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		h = 1;
		x = 0;
		ans = 0;
		for (i = 0; i < m; i++) {
			scanf("%d", &tmp);
			x *= 10;
			x += tmp;
		}
		for (i = 1; i < m; i++) h *= 10;
		y = 0;
		for (i = 0; i < m; i++) {
			scanf("%d", &tmp);
			y *= 10;
			y += tmp;
		}
		for (i = 0; i < n; i++) scanf("%d", &o[i]);
		p = 0;
		for (i = 0; i < m; i++) {
			p *= 10;
			p += o[i];
		}
		if (x <= p && p <= y) ans++;
		for (i = m; i < n + m - 1; i++) {
			pos = i % n;
			p %= h;
			p *= 10;
			p += o[pos];
			if (x <= p && p <= y) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}