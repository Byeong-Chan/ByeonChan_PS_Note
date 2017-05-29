#include <stdio.h>
#include <string.h>
int n;
char a[1000001];
int main() {
	int i;
	int tmp;
	int e = 0;
	int t;
	scanf("%s",a);
	n = strlen(a);
	if(n == 1) {
		e = a[0] - '0';
		printf("0\n");
		if(e % 3 == 0) printf("YES");
		else printf("NO");
		return 0;
	}
	for(i=0;i<n;i++) {
		e += a[i] - '0';
	}
	for(i=1;;i++) {
		tmp = e;
		t = 0;
		while(e > 0) {
			t += (e % 10);
			e /= 10;
		}
		if(tmp == (e = t)) break;
	}
	printf("%d\n",i);
	if(e % 3 == 0) printf("YES");
	else printf("NO");
}