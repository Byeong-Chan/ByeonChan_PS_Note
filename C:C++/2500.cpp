#include <stdio.h>
int table[21000], t[21000];
int e = 0;
long long tmp[21000];
bool a[18];
int main() {
	int i, j, l;
	int n, m, k, x;
	int hap = 0;
	scanf("%d %d %d", &k, &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &x);
		t[x]++;
		t[x] %= 42043;
	}
	for (; k > 0; k >>= 1) a[e++] = k & 1;
	table[0] = 1;
	for (i = e - 1; i >= 0; i--) {
		for (j = 0; j <= n; j++) for (l = 0; l <= n - j; l++) tmp[j + l] += table[j] * table[l];
		for (j = 0; j <= n; j++) {
			table[j] = (int)(tmp[j]%42043);
			tmp[j] = 0;
		}
		if (a[i]) {
			for (j = 0; j <= n; j++) for (l = 0; l <= n - j; l++) tmp[j + l] += table[j] * t[l];
			for (j = 0; j <= n; j++) {
				table[j] = (int)(tmp[j] % 42043);
				tmp[j] = 0;
			}
		}
	}
	for (i = 0; i <= n; i++) {
		hap += table[i];
	}
	hap %= 42043;
	printf("%d", hap);
	return 0;
}