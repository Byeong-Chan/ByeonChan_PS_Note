#include <stdio.h>
#include <algorithm>
using namespace std;
struct bung {
	int x;
	int num;
}o[500001];
bool cmp(bung a, bung b) {
	if (a.x != b.x) return a.x < b.x;
	return a.num < b.num;
}
int n;
int main() {
	int i;
	int max1 = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &o[i].x);
		o[i].num = i;
	}
	sort(o, o + n, cmp);
	for (i = 0; i < n; i++) if (o[i].num - i >= 0) if (o[i].num - i > max1) max1 = o[i].num - i;
	printf("%d", max1);
	return 0;
}