#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXK 1000
bool chk[MAXK + 2];
int prime[1001];
pair<bool, int> dt[3][1002];
int main() {
	int i, j;
	int t;
	int n = 0;
	int k;
	int tmp;
	int a, b, c;
	chk[1] = 1;
	for (i = 2; i <= MAXK; i++) if (!chk[i]) {
		prime[n++] = i;
		dt[0][i].first = true;
		dt[0][i].second = -1;
		for (j = i; j <= MAXK; j += i) chk[j] = true;
	}
	for (k = 1; k < 3; k++) {
		for (i = 0; i < n; i++) {
			tmp = prime[i];
			for (j = 1; j <= MAXK - tmp; j++) {
				if (j + tmp <= MAXK) {
					if (dt[k - 1][j].first == true) {
						dt[k][j + tmp].first = true;
						dt[k][j + tmp].second = j;
					}
				}
			}
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &k);
		if (dt[2][k].first) {
			tmp = dt[2][k].second;
			a = k - tmp;
			c = tmp;
			tmp = dt[1][tmp].second;
			b = c - tmp;
			c = tmp;

			if (a > b) swap(a, b);
			if (a > c) swap(a, c);
			if (b > c) swap(b, c);
			printf("%d %d %d\n", a, b, c);
		}
		else printf("0\n");
	}
	return 0;
}