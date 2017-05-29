#include <stdio.h>
#include <string.h>
char o[1002];
char ans[1002];
int nxt[1002];
int cycle[1002];
int k[1002][1002];
bool chk[1002];
int main() {
	int i, j;
	int m, n;
	int d;
	int e;
	int p;
	int sz;
	scanf("%d",&m);
	scanf("%s",o);
	n = strlen(o);
	for(i=1;i<n;i++) {
		if(i < (n+1)/2) nxt[i*2] = i;
		else nxt[(n-i)*2-1] = i;
	}
	chk[0] = true;
	cycle[0] = 1;
	for(i=1;i<n;i++) {
		if(!chk[i]) {
			d = i;
			chk[d] = true;
			e = 0;
			do {
				k[i][e++] = d;
				d = nxt[d];
				chk[d] = true;
			}while(d != i);
			cycle[i] = e;
		}
	}
	ans[0] = o[0];
	for(i=1;i<n;i++) {
		if(cycle[i] > 0) {
			sz = cycle[i];
			p = m % sz;
			for(j=0;j<sz;j++) {
				d = (j + p) % sz;
				ans[k[i][d]] = o[k[i][j]];
			}
		}
	}
	printf("%s",ans);
    return 0;
}