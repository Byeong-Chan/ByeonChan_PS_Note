#include <cstdio>
int main() {
	int n;
	int p, x;
	int k = 0, m;
	scanf("%d", &n);
	m = n;
	p = 0;
	while (n--) {
		scanf("%d", &x);
		p ^= x;
		if (x == 1) k++;
	}
	if (m == k) {
		if (m & 1) printf("cubelover");
		else printf("koosaga");
		return 0;
	}
	if (p == 0) printf("cubelover");
	else printf("koosaga");
	return 0;
}