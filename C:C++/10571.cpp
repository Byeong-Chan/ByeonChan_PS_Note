#include <stdio.h>
struct bung {
	float ci;
	float wi;
	int l;
}o[210];
int main() {
	int i, j, n;
	int t;
	int ans;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ans = 1;
		for (i = 0; i < n; i++) {
			scanf("%f %f", &o[i].wi, &o[i].ci);
			o[i].l = 1;
			for (j = 0; j < i; j++) if (o[j].wi < o[i].wi && o[j].ci > o[i].ci) o[i].l = o[i].l < o[j].l + 1 ? o[j].l + 1 : o[i].l;
			ans = ans > o[i].l ? ans : o[i].l;
		}
		printf("%d\n", ans);
	}
	return 0;
}