#include <stdio.h>
int chk[110];
int ans[110];
int o[110];
int main() {
	int i, j;
	int n;
	int t;
	int p;
	scanf("%d", &t);
	while (t) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) scanf("%d", &o[i]);
		for (i = n - 1; i >= 0; i--) {
			p = 0;
			for (j = 1; j <= n; j++) {
				if (chk[j] != t) {
					if (p == o[i]) {
						chk[j] = t;
						ans[i] = j;
						break;
					}
					p++;
				}
			}
			if (j == n + 1) {
				printf("IMPOSSIBLE\n");
				break;
			}
		}
		if (i < 0) {
			for (i = 0; i < n; i++) printf("%d ", ans[i]);
			printf("\n");
		}
		t--;
	}
	return 0;
}