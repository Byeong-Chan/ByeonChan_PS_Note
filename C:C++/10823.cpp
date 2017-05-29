#include <stdio.h>
#include <string.h>
int main() {
	long long ans = 0;
	int e, i;
	int n;
	char o[10002];
	e = 0;
	while(1) {
		if(scanf("%s",o) == -1) break;
		n = strlen(o);
		for(i=0;i<n;i++) {
			if(o[i] == ',') {
				ans += e;
				e = 0;
			}
			else {
				e *= 10;
				e += (o[i] - '0');
			}
		}
	}
	ans += e;
	e = 0;
	printf("%lld",ans);
	return 0;
}