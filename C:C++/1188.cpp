#include <stdio.h>
int main() {
	int i;
	int n, m;
	int p, q;
	int ans = 0;
	scanf("%d %d", &n, &m);
	n %= m;
	q = n;
	for (i = 1; i <= n; i++) {
		p = m;
		while (p > 0) {
			if (q - p >= 0) {
				q -= p;
				p = 0;
			}
			else {
				ans++;
				p -= q;
				q = n;
			}
		}
		if (q == 0) q = n;
	}
	printf("%d", ans);
	return 0;
}