#include <stdio.h>
int main() {
	int s, v1, v2;
	int t;
	bool sw;
	scanf("%d %d %d",&s,&v1,&v2);
	for(t=0;t<=s/v2;t++) {
		sw = true;
		if((s - v2*t) % v1 == 0) break;
		sw = false;
	}
	if(sw) printf("%d %d",(s-v2*t)/v1, t);
	else printf("Impossible");
	return 0;
}