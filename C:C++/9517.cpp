#include <stdio.h>
int main() {
	int k;
	int n;
	int t;
	int now = 0;
	bool sw = false;
	char p;
	scanf("%d",&k);
	scanf("%d",&n);
	while(n--) {
		scanf("%d %c\n",&t,&p);
		now += t;
		if(now >= 210) {
			if(sw) continue;
			printf("%d",k);
			sw = true;
		}
		else {
			if(p == 'T') k++;
			if(k == 9) k-=8;
		}
	}
	if(!sw) printf("%d",k);
	return 0;
}