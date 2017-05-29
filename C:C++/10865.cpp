#include <stdio.h>
int o[100005];
int main() {
	int i, x, y;
	int n, m;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++) {
		scanf("%d %d",&x,&y);
		o[x]++;
		o[y]++;
	}
	for(i=1;i<=n;i++) printf("%d\n",o[i]);
	return 0;
}