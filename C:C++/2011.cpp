#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char o[5020];
int dt[5020];
int main() {
	int i, n;
	int k;
	scanf("%s", o);
	n = strlen(o);
	dt[0] = 1;
	for (i = 1; i <= n; i++) {
		if(o[i - 1] != '0') dt[i] = dt[i - 1];
		dt[i] %= 1000000;
		if (i - 2 >= 0) {
			if (o[i - 2] == '0') continue;
			k = o[i - 2] - '0';
			k = (k << 3) + (k << 1);
			k += o[i - 1] - '0';
			if (k <= 26) dt[i] += dt[i - 2];
		}
		dt[i] %= 1000000;
	}
	printf("%d", dt[n]);
	return 0;
}