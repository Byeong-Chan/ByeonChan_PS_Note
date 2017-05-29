#include <stdio.h>
bool d[101][101];
int main() {
	int t, n, m, i, j, x;
	int ans;
	scanf("%d",&t);
	while(t--) {
		ans = 0;
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&d[i][j]);
		for(i=0;i<m;i++) {
			x = n-1;
			for(j=n-1;j>=0;j--) {
				if(d[j][i] == 1) {
					ans += x-j;
					x--;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}