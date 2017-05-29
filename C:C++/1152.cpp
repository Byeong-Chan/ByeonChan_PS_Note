#include <stdio.h>
int main() {
	char o[1000001];
	int t = 0;
	while(1) {
		if(scanf("%s",o) == -1) break;
		t++;
	}
	printf("%d",t);
	return 0;
}