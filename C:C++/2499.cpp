#include <stdio.h>

#define max(x, y) ((x) > (y) ? (x) : (y))
#define _abs(x) ((x) < 0 ? -(x) : (x))

struct bung {
	bool chk;
	int trace;
	int now;
}table[22][40002];
int o[22][22];
int pushup[22][22];
int p[22];
int main() {
	int n;
	int i, j, l;
	int hap = 0;
	int d;
	int tmp;
	int sav;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) for (j = 0; j < n; j++) scanf("%d", &o[i][j]);
	for (i = 0; i < n; i++) {
		for (j = 1; j <= n; j++) pushup[j][i] = pushup[j - 1][i] + o[j][i];
	}
	d = 0;
	for (i = 1; i <= n; i++) {
		table[0][pushup[i][0]].chk = true;
		table[0][pushup[i][0]].trace = -1;
		table[0][pushup[i][0]].now = i;
		hap += pushup[n][i-1];
		d = max(d, pushup[i][0]);
	}
	for (i = 1; i < n; i++) {
		tmp = d;
		table[i - 1][0].chk = true;
		table[i - 1][0].trace = 0;
		table[i - 1][0].now = 0;
		for (j = 0; j <= tmp; j++) {
			if (table[i - 1][j].chk) {
				for (l = table[i - 1][j].now; l >= 0; l--) {
					sav = j + pushup[l][i];
					if (table[i][sav].chk && table[i][sav].now > l) continue;
					table[i][sav].chk = true;
					table[i][sav].trace = j;
					table[i][sav].now = l;
					d = max(d, j + pushup[l][i]);
				}
			}
		}
	}
	for (i = hap >> 1; i >= 0; i--) {
		if (table[n - 1][i].chk) break;
	}
	for (j = hap >> 1; j <= hap; j++) {
		if (table[n - 1][j].chk) break;
	}
	if (hap - j > i) i = hap - j;
	else j = i;
	printf("%d\n", _abs(hap - (i * 2)));
	d = j;
	for (i = n-1; i >= 0; i--) {
		p[i] = table[i][d].now;
		d = table[i][d].trace;
	}
	for (i = 0; i < n; i++) printf("%d ", n - p[i]);
	return 0;
}