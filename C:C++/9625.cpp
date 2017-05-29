#include <stdio.h>
int pibo[47];
int main() {
	int i;
	int n;
	scanf("%d", &n);
	pibo[0] = 1;
	pibo[1] = 0;
	for (i = 2; i <= n + 1; i++) pibo[i] = pibo[i - 1] + pibo[i - 2];
	printf("%d %d", pibo[n], pibo[n + 1]);
	return 0;
}