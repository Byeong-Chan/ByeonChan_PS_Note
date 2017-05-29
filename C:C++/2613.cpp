#include <stdio.h>
int o[310];
int u[310];
int lc ,ans[310];
int main() {
	int i, n, m;
	int st = 1, ed = 0;
	int mid;
	int e;
	int p;
	int t;
	int gap;
	scanf("%d %d",&n, &m);
	for(i=0;i<n;i++) {
		scanf("%d",&o[i]);
		ed += o[i];
	}
	while(st < ed) {
		mid = (st + ed) / 2;
		e = p = t = 0;
		for(i=0;i<n;i++) {
			if(o[i] > mid) break;
			e += o[i];
			p++;
			if(e > mid) {
				u[t++] = p - 1;
				p = 1;
				e = o[i];
			}
			if(e == mid) {
				u[t++] = p;
				p = 0;
				e = 0;
			}
		}
		if(e > 0) {
			u[t++] = p;
			e = 0;
			p = 0;
		}
		if(i == n && t <= m) {
			lc = t;
			for(i=0;i<lc;i++) ans[i] = u[i];
			ed = mid;
		}
		else st = mid + 1;
	}
	printf("%d\n",ed);
	gap = m - lc;
	for(i=0;i<lc;i++) {
		while(gap && (ans[i]-1)) {
			gap--;
			printf("1 ");
			ans[i]--;
		}
		printf("%d ",ans[i]);
	}
	return 0;
}