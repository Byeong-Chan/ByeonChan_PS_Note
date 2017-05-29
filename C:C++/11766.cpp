#include <stdio.h>
char o[101][101];
bool chk[101][101];
int ans[101][101];
int main() {
	int e = 0;
	int i, j, n, m;
	int all = 0;
	scanf("%d %d\n", &n ,&m);
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			scanf("%c\n",&o[i][j]);
			if(o[i][j] == 'T') all++;
		}
	}
	while(all) {
		e++;
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				if(o[i][j] != 'T') continue;
				if(i+1 >= n) {chk[i][j] = true; all--; continue;}
				else if(o[i+1][j] != 'T') {chk[i][j] = true; all--; continue;}
				if(i-1 < 0) {chk[i][j] = true; all--; continue;}
				else if(o[i-1][j] != 'T') {chk[i][j] = true; all--; continue;}
				if(j+1 >= m) {chk[i][j] = true; all--; continue;}
				else if(o[i][j+1] != 'T') {chk[i][j] = true; all--; continue;}
				if(j-1 < 0) {chk[i][j] = true; all--; continue;}
				else if(o[i][j-1] != 'T') {chk[i][j] = true; all--; continue;}
			}
		}
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				if(chk[i][j]) {
					ans[i][j] = e;
					o[i][j] = '.';
				}
				chk[i][j] = false;
			}
		}
	}
	if(e < 10) {
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				printf(".");
				if(ans[i][j] == 0) printf(".");
				else printf("%d",ans[i][j]);
			}
			printf("\n");
		}
	}
	else {
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				printf(".");
				if(ans[i][j] < 10) printf(".");
				if(ans[i][j] == 0) printf(".");
				else printf("%d",ans[i][j]);
			}
			printf("\n");
		}
	}
    return 0;
}