#include <stdio.h>

#define MOD 1000000007

int o[100011][3];
long long dt[100011][3];
int main() {
	int i, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &o[i][0]);
	for (i = 1; i < n; i++) {
		scanf("%d", &o[i][1]);
		o[i + 1][2] = o[i][1];
	}
	dt[0][0] = 1;
	long long tmp;
	for (i = 1; i <= n; i++) {
		dt[i][0] = dt[i - 1][0] + dt[i - 1][1] + dt[i - 1][2];
		dt[i][0] *= o[i][0];
		dt[i][0] %= MOD;

		dt[i][1] = dt[i - 1][0] + dt[i - 1][1] + dt[i - 1][2];
		dt[i][1] *= o[i][1];
		dt[i][1] %= MOD;

		dt[i][2] = dt[i - 1][0] + dt[i - 1][2];
		dt[i][2] *= o[i][2];
		dt[i][2] %= MOD;

		if (i > 1) {
			tmp = dt[i - 2][0] + dt[i - 2][1] + dt[i - 2][2];
			tmp *= o[i][2];
			tmp %= MOD;
			tmp *= (o[i][2] - 1);
			tmp %= MOD;
			dt[i][2] += tmp;
			dt[i][2] %= MOD;
		}
	}
	printf("%lld", (dt[n][0] + dt[n][1] + dt[n][2]) % MOD);
	return 0;
}