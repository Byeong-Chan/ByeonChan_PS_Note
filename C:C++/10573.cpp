#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char o[90];
int p[90];
long long dt[90][10][3];
int main() {
	int n;
	int t;
	int i, j, k;
	int x, prev;
	long long ans = 0;
	bool sw;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", o);
		n = strlen(o);
		reverse(o, o + n);
		sw = false;
		for (i = 0; i < n; i++) {
			p[i] = o[i] - '0';
			if (i > 0 && p[i - 1] < p[i]) sw = true;
		}
		if (sw) {
			printf("-1\n");
			continue;
		}
		ans = 0;
		memset(dt, 0, sizeof(dt));
		for (i = 0; i <= 9; i++) {
			if (p[0] > i) {
				dt[0][i][0] = 1;
				if(i > 0) ans += 1;
			}
			else if(p[0] == i) {
				dt[0][i][1] = 1;
				if (i > 0 && n > 1) ans += 1;
			}
			else {
				dt[0][i][2] = 1;
				if (n > 1) ans += 1;
			}
		}
		for (i = 1; i < n; i++) {
			for (j = 0; j <= 9; j++) {
				for (k = j; k >= 0; k--) {
					if (p[i] > k) {
						dt[i][k][0] += dt[i - 1][j][0];
						dt[i][k][0] += dt[i - 1][j][1];
						dt[i][k][0] += dt[i - 1][j][2];
					}
					else if (p[i] == k) {
						dt[i][k][0] += dt[i - 1][j][0];
						dt[i][k][1] += dt[i - 1][j][1];
						dt[i][k][2] += dt[i - 1][j][2];
					}
					else {
						dt[i][k][2] += dt[i - 1][j][0];
						dt[i][k][2] += dt[i - 1][j][1];
						dt[i][k][2] += dt[i - 1][j][2];
					}
				}
			}
			for (j = 0; j <= 9; j++) {
				if (j > 0) ans += dt[i][j][0];
				if (j > 0 && n > i+1) ans += dt[i][j][1];
				if (n > i+1) ans += dt[i][j][2];
			}
		}
		printf("%lld\n", ans+1);
	}
	return 0;
}