#include <stdio.h>
int main() {
	int n = 5;
	int p, q;
	int x, y;
	int k;
	int tmp1, tmp2;
	scanf("%d %d", &p, &q);
	k = q - p;
	while(n--) {
		scanf("%d %d", &x, &y);
		if (k < 0) {
			if (x <= y) {
				printf("N\n");
				continue;
			}
			tmp1 = -k;
			tmp2 = x - y;
			while (!(tmp1 & 1)) tmp1 >>= 1;
			if (tmp2 % tmp1 == 0) printf("Y\n");
			else printf("N\n");
		}
		else if(k > 0) {
			if (x >= y) {
				printf("N\n");
				continue;
			}
			tmp1 = k;
			tmp2 = y - x;
			while (!(tmp1 & 1)) tmp1 >>= 1;
			if (tmp2 % tmp1 == 0) printf("Y\n");
			else printf("N\n");
		}
		else {
			if (x == y) {
				printf("Y\n");
				continue;
			}
			printf("N\n");
		}
	}
	return 0;
}