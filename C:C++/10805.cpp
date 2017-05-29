#include <stdio.h>
#include <algorithm>
using namespace std;

#define min(x, y) ((x) < (y) ? (x) : (y))

int dt[55][55];
int dt2[55][55][55][55];
int n, m, w, h;

int main() {
	int i, j, k, l, s;
	scanf("%d %d %d %d",&n,&m,&w,&h);
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			dt[i][j] = n * m;
			if(i == j) dt[i][j] = 1;
			else {
				for(k=1;k<i;k++) dt[i][j] = min(dt[i][j], dt[i-k][j] + dt[k][j]);
				for(k=1;k<j;k++) dt[i][j] = min(dt[i][j], dt[i][j-k] + dt[i][k]);
			}
		}
	}
	for(i=2;i<=n;i++) {
		for(j=2;j<=m;j++) {
			for(k=1;k<(i<w+1 ? i : w+1);k++) {
				for(l=1;l<(j<h+1 ? j : h+1);l++) {
					dt2[i][j][k][l] = n * m - w * h;

					for(s=1;s<i-k;s++) dt2[i][j][k][l] = min(dt2[i][j][k][l], dt2[i-s][j][k][l] + dt[s][j]);
					dt2[i][j][k][l] = min(dt2[i][j][k][l], dt[k][j-l] + dt[i-k][j]);
					for(s=1;s<j-l;s++) dt2[i][j][k][l] = min(dt2[i][j][k][l], dt2[i][j-s][k][l] + dt[i][s]);
					dt2[i][j][k][l] = min(dt2[i][j][k][l], dt[i][j-l] + dt[i-k][l]);
					for(s=1;s<k;s++) dt2[i][j][k][l] = min(dt2[i][j][k][l], dt2[i-s][j][k-s][l] + dt[s][j-l]);
					for(s=1;s<l;s++) dt2[i][j][k][l] = min(dt2[i][j][k][l], dt2[i][j-s][k][l-s] + dt[i-k][s]);
				}
			}
		}
	}
	printf("%d\n",dt2[n][m][w][h]);
	return 0;
}