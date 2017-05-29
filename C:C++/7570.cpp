#include <stdio.h>
int o[1100000];
int main() {
	int i, n, d, tmp;
	int max1 = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&d);
		o[d] = tmp =  o[d-1] + 1;
		if(max1 < tmp) max1 = tmp;
	}
	printf("%d",n-max1);
	return 0;
}