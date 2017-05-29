#include <stdio.h>
int o[100001];
int main() {
	int n, m;
	int st, ed = 0, mid;
	int i;
	int e;
	int t;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) {
		scanf("%d",&o[i]);
		ed += o[i];
	}
	st = 1;
	while(st < ed) {
		mid = (st + ed) / 2;
		e = 0;
		t = 1;
		for(i=0;i<n;i++) {
			e += o[i];
			if(e > mid) {
				if(e - o[i] == 0) {
					t = m+1;
					break;
				}
				e = o[i];
				t++;
			}
		}
		if(t <= m) ed = mid;
		else st = mid+1;
	}
	printf("%d",ed);
	return 0;
}