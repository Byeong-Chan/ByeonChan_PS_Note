#include <stdio.h>
int o[43];
int main() {
	int t, n, i;
	int sz;
	int ans[43];
	o[0] = 1;
	o[1] = 2;
	for (i = 2; i < 43; i++) {
		o[i] = o[i - 1] + o[i - 2];
	}
	scanf("%d", &t);
	while (t--) {
		sz = 0;
		scanf("%d", &n);
		for (i = 42; i >= 0; i--) {
			if (n >= o[i]) {
				n -= o[i];
				ans[sz++] = o[i];
			}
		}
		for (i = sz - 1; i >= 0; i--) printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}