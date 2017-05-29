#include <stdio.h>
int table[1503][1503];
int p[1503][1503];
int main() {
	int n;
	int i, j;
	int st;
	int tmp;
	int ans = 0x7fffffff;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			scanf("%d",&p[i][j]);
			table[i][j] = 0x7fffffff;
		}
		table[i][n+1] = 0x7fffffff;
		table[n+1][i] = 0x7fffffff;
	}
	for(i=n;i>=1;i--) {
		st = i+2 <= n+1 ? i+2 : n+1;
		for(j=st;j<=n+1;j++) {
			if(i == 1) {
				if(table[i+1][j] != 0x7fffffff) {
					tmp = table[i+1][j] + p[i+1][i] + p[i][j];
					ans = ans > tmp ? tmp : ans;
				}

				if(table[j][i+1] != 0x7fffffff) {
					tmp = table[j][i+1] + p[j][i] + p[i][i+1];
					ans = ans > tmp ? tmp : ans;
				}
				continue;
			}
			if(table[i+1][j] != 0x7fffffff) {
				tmp = table[i+1][j] + p[i][j];
				table[i+1][i] = table[i+1][i] < tmp ? table[i+1][i] : tmp;

				tmp = table[i+1][j] + p[i+1][i];
				table[i][j] = table[i][j] < tmp ? table[i][j] : tmp;
			}

			if(table[j][i+1] != 0x7fffffff) {
				tmp = table[j][i+1] + p[i][i+1];
				table[j][i] = table[j][i] < tmp ? table[j][i] : tmp;

				tmp = table[j][i+1] + p[j][i];
				table[i][i+1] = table[i][i+1] < tmp ? table[i][i+1] : tmp;
			}
		}
	}
	printf("%d",ans);
	return 0;
}