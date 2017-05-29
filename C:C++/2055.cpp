#include <stdio.h>
int gcd(int a, int b) {
	if (a % b == 0) return b;
	else return gcd(b, a%b);
}
long long comb3(long long a) {
	long long tmp = (a*(a - 1)*(a - 2));
	return tmp / 6;
}
int main() {
	int i, j;
	int n, m;
	int x, y;
	int tmp;
	long long ans;
	long long k;
	long long all;
	scanf("%d %d", &n, &m);
	all = (n + 1) * (m + 1);
	ans = comb3(all) - comb3(n + 1) * (m + 1) - comb3(m + 1) * (n + 1);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			tmp = gcd(i, j);

			k = tmp - 1;
			ans -= (k * (n - i + 1) * (m - j + 1) * 2);
		}
	}
	printf("%lld", ans);
	return 0;
}