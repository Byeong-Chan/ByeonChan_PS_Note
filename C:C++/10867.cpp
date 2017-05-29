#include <stdio.h>
bool chk[2001];
int main() {
	int n;
	int d;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&d);
		chk[d+1000] = true;
	}
	for(i=0;i<=2000;i++) {
		if(chk[i]) printf("%d ",i-1000);
	}
	return 0;
}