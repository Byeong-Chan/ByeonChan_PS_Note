#include <stdio.h>
int main() {
	int ans = 0;
	int e;
	char a;
	while(1) {
		scanf("%d",&e);
		ans += e;
		if(scanf("%c",&a) == -1) break;
		if(a == 10) break;
	}
	printf("%d",ans);
	return 0;
}