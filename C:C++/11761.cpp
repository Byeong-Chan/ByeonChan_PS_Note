#include <stdio.h>
#include <string.h>
int uclid(int a, int b) {
	if(a%b == 0) return b;
	else return uclid(b, a%b);
}
int main() {
	int i;
	int cnt;
	int p;
	int n;
	int gcd = 1;
	char o[5];
	scanf("%d %s",&n,o);
	if(strcmp(o, "in") == 0) {
		for(i=1;i<=n;i++) {
			p = i;
			cnt = 0;
			do {
				cnt++;
				if(p <= n/2) p = p*2;
				else p = (p-n/2) * 2 - 1;
			}while(i != p);
			gcd = gcd * cnt / uclid(gcd, cnt);
		}
	}
	else {
		for(i=1;i<=n;i++) {
			p = i;
			cnt = 0;
			do {
				cnt++;
				if(p <= (n+1)/2) p = p*2-1;
				else p = (p-(n+1)/2) *2;
			}while(i != p);
			gcd = gcd * cnt / uclid(gcd, cnt);
		}
	}
	printf("%d",gcd);
	return 0;
}