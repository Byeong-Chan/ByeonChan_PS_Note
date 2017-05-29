#include <stdio.h>
long long tmp[2][2] = { 0, 1, 1 ,1 };
long long o[2][2] = { 1, 0, 0 ,1 };
long long u[2][2];
long long ans = 0;
bool chk[65];
int main() {
	int i, j, k;
	int n;
	int m = 0;
	scanf("%d", &n);
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	if (n == 2) {
		printf("1\n");
		return 0;
	}
	n -= 3;
	while (n > 0) {
		chk[m++] = n & 1;
		n >>= 1;
	}
	while (m--) {
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2; j++) {
				u[i][j] = o[i][j];
				o[i][j] = 0;
			}
		}
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2; j++) {
				for (k = 0; k < 2; k++) {
					o[i][j] += u[i][k] * u[k][j];
				}
			}
		}
		if (chk[m]) {
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 2; j++) {
					u[i][j] = o[i][j];
					o[i][j] = 0;
				}
			}
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 2; j++) {
					for (k = 0; k < 2; k++) {
						o[i][j] += u[i][k] * tmp[k][j];
					}
				}
			}
		}
	}
	ans = (o[0][0] + o[0][1] + o[1][0] + o[1][1]);
	printf("%lld", ans);
	return 0;
}