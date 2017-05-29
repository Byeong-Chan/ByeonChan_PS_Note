#include <stdio.h>
int o[1001][1001];
int main() {
	int n;
	int tri;
	int t;
	int i, j;
	bool x;
	int a, b;
	int ans;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		tri = n*(n-1)*(n-2)/6;
		for(i=1;i<n;i++) {
			for(j=i+1;j<=n;j++) {
				scanf("%d",&x);
				o[i][j] = x;
				o[j][i] = x;
			}
		}
		ans = 0;
		for(i=1;i<=n;i++) {
			a = 0;
			b = 0;
			for(j=1;j<=n;j++) {
				if(i != j) {
					if(o[i][j]) a++;
					else b++;
				}
			}
			ans += a*b;
		}
		printf("%d\n",tri-ans/2);
	}
	return 0;
}