#include <cstdio>
#define mod 1000
short dt[1010010][2];
int main() {
	int n;
	int a, b, c;
	int i;
	scanf("%d %d %d %d", &a, &b, &c, &n);
	dt[0][0] = 1;
	dt[a][1] = 1;
	dt[b][1] = -1;
	dt[c][0] = -1;
	for (i = 0; i <= n; i++) {
		dt[i][0] += dt[i][1];
		dt[i][0] %= mod;
		dt[i + 1][0] += dt[i][0];
		dt[i + 1][1] += dt[i][1];
		dt[i + 1][1] %= mod;
		dt[i + 1][0] %= mod;

		dt[i + a][1] += dt[i][1];
		dt[i + b][1] -= dt[i][1];
		dt[i + c][0] -= dt[i][1];

		dt[i + a][1] %= mod;
		dt[i + b][1] %= mod;
		dt[i + c][0] %= mod;
	}
	if (dt[n][0] < 0) dt[n][0] += mod;

	printf("%d", dt[n][0]);
	return 0;
}