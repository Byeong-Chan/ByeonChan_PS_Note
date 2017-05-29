#include <stdio.h>
#define MOD 1000000003;
int o[1001][1001];
int main() {
	int n, m;
	int i, j;
	int e = 0;
	int t = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 1; i <= n-1; i++) o[i][1] = 1;
	for (i = 2; i <= m; i++) {
		t = 0;
		for (j = i * 2 - 1; j <= n - 1; j++) {
			t += o[j-2][i-1];
			t %= MOD;
			o[j][i] = t;
		}
	}
	for (i = 1; i <= n-1; i++) {
		e += o[i][m];
		e %= MOD;
	}
	e += o[i - 1][m];
	e %= MOD;

	printf("%d", e);
	return 0;
}