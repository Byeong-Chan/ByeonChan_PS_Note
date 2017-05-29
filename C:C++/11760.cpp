#include <stdio.h>
int main() {
	int n;
	int chk[27]={0,};
	char o[51], u[51];
	int i;
	int r=0, s=0;
	scanf("%d %s %s",&n, o, u);
	for(i=0;i<n;i++) {
		if(o[i] == u[i]) {
			r++;
			continue;
		}
		chk[o[i]-65]++;
	}
	for(i=0;i<n;i++) {
		if(o[i] == u[i]) continue;
		if(chk[u[i]-65]) {
			chk[u[i]-65]--;
			s++;
		}
	}
	printf("%d %d",r,s);
	return 0;
}