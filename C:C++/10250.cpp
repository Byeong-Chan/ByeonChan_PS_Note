#include <stdio.h>
int main() {
	int t, n, m, k;
	int h, w;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d %d",&n,&m,&k);
		if(k%n > 0) w = k/n+1;
		else w = k/n;
		h = k%n;
		if(h == 0) h = n;
		printf("%d",h);
		if(w / 10 == 0) printf("0");
		printf("%d\n",w);
	}
	return 0;
}