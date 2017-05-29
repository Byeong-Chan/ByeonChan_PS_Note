#include <stdio.h>
char o[50002];
long long m;
long long table[50002][12][5];
long long s;
int ans[50002];
int tr(char x) {
	if(x == 'A') return 1;
	if(x == 'C') return 2;
	if(x == 'G') return 3;
	return 4;
}
int main() {
	int i, j, n, k, l, t;
	int p;
	//freopen("input.txt","rt",stdin);
	scanf("%d %d %lld",&n,&k,&m);
	scanf("%s",o);
	table[n][0][0] = 1;
	for(i=n-1;i>=0;i--) {
		if(o[i] == 'N') {
			for(p=1;p<=4;p++) {
				for(j=0;j<=k;j++) {
					table[i][j+1][p] += table[i+1][j][0];

					if(p <= 1) table[i][j][p] += table[i+1][j][1];
					else table[i][j+1][p] += table[i+1][j][1];

					if(p <= 2) table[i][j][p] += table[i+1][j][2];
					else table[i][j+1][p] += table[i+1][j][2];

					if(p <= 3) table[i][j][p] += table[i+1][j][3];
					else table[i][j+1][p] += table[i+1][j][3];

					if(p <= 4) table[i][j][p] += table[i+1][j][4];
					else table[i][j+1][p] += table[i+1][j][4];
				}
			}
		}
		else {
			p = tr(o[i]);
			for(j=0;j<=k;j++) {
				table[i][j+1][p] += table[i+1][j][0];

				if(p <= 1) table[i][j][p] += table[i+1][j][1];
				else table[i][j+1][p] += table[i+1][j][1];

				if(p <= 2) table[i][j][p] += table[i+1][j][2];
				else table[i][j+1][p] += table[i+1][j][2];

				if(p <= 3) table[i][j][p] += table[i+1][j][3];
				else table[i][j+1][p] += table[i+1][j][3];

				if(p <= 4) table[i][j][p] += table[i+1][j][4];
				else table[i][j+1][p] += table[i+1][j][4];
			}
		}
	}
	for(i=0;i<n;i++) {
		for(j=1;j<=4;j++) {
			t = 0;
			if(i > 0 && ans[i-1] > j) t--;
			s = 0;
			for(l=1;l<=k+t;l++) s += table[i][l][j];
			if(s >= m) {
				k += t;
				ans[i] = j;
				break;
			}
			m -= s;
		}
	}
	for(i=0;i<n;i++) {
		if(ans[i] == 1) printf("A");
		if(ans[i] == 2) printf("C");
		if(ans[i] == 3) printf("G");
		if(ans[i] == 4) printf("T");
	}
	return 0;
}