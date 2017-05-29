#include <stdio.h>
int o[8193];
bool x[15];
int main() {
	int n, m, i, j;
	int d;
	scanf("%d", &n);
	scanf("%d", &m);
	if (m & 1) {
		o[0] = 1;
		o[1] = 2;
		m --;
	}
	else {
		o[0] = 2;
		o[1] = 1;
		m -= 2;
	}
	for (i = 0; m > 0; m >>= 1,i++) x[i] = m & 1;
	for (i = 1, d = 2; d < n; d <<= 1, i++) {
		for (j = 0; j < d; j++) o[(d << 1) - j - 1] = o[j];
		for (j = !x[i]; j < d * 2; j += 2) o[j] += d;
	}
	for (i = 0; i < n; i++) printf("%d ", o[i]);
	return 0;
}