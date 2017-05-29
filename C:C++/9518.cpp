#include <stdio.h>
int o[71][71];
bool chk[71][71];
int main() {
	int n, m;
	int i, j;
	int kx, ky;
	int ans = 0;
	int max1 = 0;
	char x;
	scanf("%d %d\n",&n,&m);
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			scanf("%c\n",&x);
			if(x == 'o') {
				chk[i][j] = true;
				o[i+1][j]++;
				o[i-1][j]++;
				o[i][j+1]++;
				o[i][j-1]++;
				o[i+1][j+1]++;
				o[i+1][j-1]++;
				o[i-1][j+1]++;
				o[i-1][j-1]++;
			}
		}
	}
	kx = ky = 1;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			if(chk[i][j]) continue;
			if(o[i][j] > max1) {
				max1 = o[i][j];
				kx = i;
				ky = j;
			}
		}
	}
	chk[kx][ky] = true;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			if(!chk[i][j]) continue;
			if(chk[i+1][j]) ans++;
			if(chk[i][j+1]) ans++;
			if(chk[i+1][j+1]) ans++;
			if(chk[i+1][j-1]) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}