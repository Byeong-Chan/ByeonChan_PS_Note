#include <stdio.h>
bool chk[1000002];
int main() {
	int n, m;
	int i, j;
	scanf("%d %d",&m,&n);
	if(m <= 2) printf("2\n");
	for(i=3;i<=n;i+=2) {
		if(!chk[i]) {
			for(j=i;j<=n;j+=i) chk[j] = true;
			if(i >= m) printf("%d\n",i);
		}
	}
	return 0;
}