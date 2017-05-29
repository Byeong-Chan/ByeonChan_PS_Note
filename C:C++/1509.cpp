#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int table[5010];
char o[5010];
int p[5010];
int main() {
	int i, j, n;
	int k;
	int r, c;
	scanf("%s", o);
	n = strlen(o);
	for (i = n - 1; i >= 1; i--) {
		o[i << 1] = o[i];
		o[(i << 1) - 1] = '#';
	}
	n <<= 1;
	n--;
	r = c = -1;
	for (i = 0; i <= n; i++) table[i] = 0x7fffffff;
	for (i = 0; i < n; i++) {
		if (r >= i) p[i] = min(r - i, p[c * 2 - i]);
		else p[i] = 0;

		while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && o[i + p[i] + 1] == o[i - p[i] - 1]) p[i]++;
		if (i + p[i] > r) {
			r = i + p[i];
			c = i;
		}
	}
	for (i = 0; i < n; i++) {
		if (i - p[i] - 1 >= 0 && o[i - p[i] - 1] == '#') p[i]++;
		for (j = p[i]; j >= 0; j--) {
			if (i - j - 1 < 0) table[i + j] = 1;
			else table[i + j] = min(table[i + j], table[i - j - 1] + 1);
		}
	}
	printf("%d", min(table[n - 1], table[n]));

	return 0;
}