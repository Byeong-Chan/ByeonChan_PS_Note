#include <stdio.h>
int main() {
	char x;
	int i, j;
	int m, n;
	int tm, tn;
	int u, l, r, d;
	scanf("%d %d\n", &n, &m);
	scanf("%d %d %d %d\n", &u, &l, &r, &d);
	tn = n + d;
	tm = m + r;
	for (i = -u; i < tn; i++) {
		for (j = -l; j < tm; j++) {
			if (i < 0 || j < 0 || i >= n || j >= m) {
				if ((i + j + u + l) & 1) printf(".");
				else printf("#");
			}
			else {
				scanf("%c\n", &x);
				printf("%c", x);
			}
		}
		printf("\n");
	}
	return 0;
}