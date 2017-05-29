#include <stdio.h>
#include <string.h>
int o[10001][5];
int table[10001][6], max1[6];
int n, k;
void sub(int l) {
	int tmpmax[6] = {0,};
	int i, j;
	for(i=0;i<n;i++) {
		for(j=5;j>=0;j--) {
			if(j <= 4) {
				if(table[i][j+1] < max1[j] + o[i][l]) table[i][j+1] = max1[j] + o[i][l];
				if(tmpmax[j+1] < table[i][j+1]) tmpmax[j+1] = table[i][j+1];
			}
			if(j > 0) table[i][j] = table[i][j] + o[i][l];
			if(tmpmax[j] < table[i][j]) tmpmax[j] = table[i][j];
		}
	}
	for(i=0;i<=5;i++) max1[i] = tmpmax[i];
}
int main() {
	int t;
	int i, j;
	int a, b, c, d, e;
	int ans;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++) scanf("%d %d %d %d %d",&o[i][0],&o[i][1],&o[i][2],&o[i][3],&o[i][4]);
		ans = 0;
		if(k > 5) {
			memset(max1, 0, sizeof(max1));
			for(i=0;i<n;i++) {
				for(j=0;j<5;j++) {
					if(max1[j] < o[i][j]) max1[j] = o[i][j];
				}
			}
			printf("%d\n",max1[0]+max1[1]+max1[2]+max1[3]+max1[4]);
			continue;
		}
		if(k == 1) {
			for(i=0;i<n;i++) if(ans < o[i][0] + o[i][1] + o[i][2] + o[i][3] + o[i][4]) ans = o[i][0] + o[i][1] + o[i][2] + o[i][3] + o[i][4];
			printf("%d\n",ans);
			continue;
		}
		for(a=0;a<5;a++) {
			for(b=0;b<5;b++) {
				if(a != b) for(c=0;c<5;c++) {
					if(a != c && b != c) for(d=0;d<5;d++) {
						if(a != d && b != d && c != d) for(e=0;e<5;e++) {
							if(a != e && b != e && c != e && d != e) {
								memset(max1, 0, sizeof(max1));
								memset(table, 0, sizeof(table));
								sub(a);
								sub(b);
								sub(c);
								sub(d);
								sub(e);
								for(i=0;i<=k;i++) if(ans < max1[i]) ans = max1[i];
							}
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}