#include <stdio.h>
#include <algorithm>
using namespace std;
int o[100002];
int main() {
	int t;
	int i;
	int n;
	int st, ed;
	int mid;
	int q, nex;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) scanf("%d", &o[i]);
		sort(o, o + n);
		st = 0;
		ed = o[n - 1] - o[0];
		while (st < ed) {
			mid = (st + ed) / 2;
			q = 0;
			nex = 0;
			for (i = 1; i < n-1; i++) {
				if (o[i] - o[q] > mid) {
					if (q == nex) break;
					q = nex;
					i--;
				}
				else nex = i - 1;
			}
			q = nex;

			if (o[n - 1] - o[q] <= mid) ed = mid;
			else st = mid + 1;
		}
		printf("%d\n", st);
	}
	return 0;
}