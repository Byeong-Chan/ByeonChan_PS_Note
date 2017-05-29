#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main() {
	int i;
	int n, p, e;
	int t;
	char o[31], tmp[30];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 2; i <= 64; i++) {
			p = n;
			e = 0;
			while (p > 0) {
				o[e++] = (p % i) + 1;
				p /= i;
			}
			o[e] = 0;
			strcpy(tmp, o);
			tmp[e] = 0;
			reverse(tmp, tmp + e);
			if (strcmp(o, tmp) == 0) break;
		}
		if (i <= 64) printf("1\n");
		else printf("0\n");
	}
	return 0;
}