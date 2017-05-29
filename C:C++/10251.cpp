#include <stdio.h>
#include <string.h>
int dt[101][101][201][2];
int _down[101][101];
int _right[101][101];
int _min(int x, int y) {
	if(x < y) return x;
	else return y;
}
int main() {
	int t;
	int n, m , L, G;
	int e;
	int i, j, k, tmp;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d %d %d",&n,&m,&L,&G);
		e = L * (n + m - 2);
		G++;
		memset(dt, 0, sizeof(dt));
		dt[0][0][0][0] = 1;
		dt[0][0][0][1] = 1;
		for(i=0;i<n;i++) for(j=0;j<m-1;j++) scanf("%d",&_right[i][j]);
		for(i=0;i<n-1;i++) for(j=0;j<m;j++) scanf("%d",&_down[i][j]);
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				tmp = _min(i,j) * 2;
				// 아래
				for(k=0;k<=tmp;k++) {
					if(dt[i][j][k][0] == 0) continue;
					// 아래
					if(i+1 < n && (dt[i+1][j][k][0] == 0 || dt[i+1][j][k][0] > dt[i][j][k][0] + _down[i][j]))
						dt[i+1][j][k][0] = dt[i][j][k][0] + _down[i][j];
					// 오른쪽
					if(j+1 < m && (dt[i][j+1][k+1][1] == 0 || dt[i][j+1][k+1][1] > dt[i][j][k][0] + _right[i][j]))
						dt[i][j+1][k+1][1] = dt[i][j][k][0] + _right[i][j];
				}
				// 오른쪽
				for(k=0;k<=tmp;k++) {
					if(dt[i][j][k][1] == 0) continue;
					// 아래
					if(i+1 < n && (dt[i+1][j][k+1][0] == 0 || dt[i+1][j][k+1][0] > dt[i][j][k][1] + _down[i][j]))
						dt[i+1][j][k+1][0] = dt[i][j][k][1] + _down[i][j];
					// 오른쪽
					if(j+1 < m && (dt[i][j+1][k][1] == 0 || dt[i][j+1][k][1] > dt[i][j][k][1] + _right[i][j]))
						dt[i][j+1][k][1] = dt[i][j][k][1] + _right[i][j];
				}
			}
		}
		tmp = _min(n, m) * 2;
		bool sw = false;
		n--;
		m--;
		for(k=1;k<=tmp;k++) {
			if(dt[n][m][k][0] > 0 && dt[n][m][k][0] <= G) break;
			if(dt[n][m][k][1] > 0 && dt[n][m][k][1] <= G) break;
			if (dt[n][m][k][0] == 0 && dt[n][m][k][1] == 0) {
				sw = true;
				break;
			}
		}
		if(sw) {
			printf("-1\n");
			continue;
		}
		e+=k;
		printf("%d\n",e);
	}
}