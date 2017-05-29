#include <stdio.h>
int chk[2100000];
int main() {
	int i, j;
	long long p;
	long long ans = 0;
	int n;
	int x;
	int max1 = 0;
	int st;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&x);
		chk[x]++;
		max1 = max1 < x ? x : max1;
	}
	for(i=max1;i>=1;i--) {
		p = 0;
		st = (int)(max1 / i) * i;
		for(j=st;j>=1;j-=i) {
			p += chk[j];
			if(p < 2) continue;
			ans = p * i > ans ? p * i : ans;
		}
	}
	printf("%lld",ans);
	return 0;
}