#include <stdio.h>
bool chk[1001];
int main() {
	int n;
	int x;
	int i, j;
	int ans = 0;
	chk[1] = true;
	for(i=2;i<=1000;i++) if(!chk[i]) for(j=i*2;j<=1000;j+=i) chk[j] = true;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&x);
		if(!chk[x]) ans++;
	}
	printf("%d",ans);
	return 0;
}