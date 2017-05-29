#include <stdio.h>
#include <algorithm>
using namespace std;
bool chk[20000001];
int main() {
	int i, n, x;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		x += 10000000;
		chk[x] = true;
	}
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		x += 10000000;
		printf("%d ",chk[x]);
	}
	return 0;
}