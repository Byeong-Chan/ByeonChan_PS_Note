#include <stdio.h>
int o[129][129];
int all[129];
bool ch[129];
int main()
{
	int i, j;
	int k;
	int n, m;
	int max1, tmp;
	scanf("%d",&m);
	for(k=0;k<m;k++) {
		scanf("%d",&n);
		for(i=1;i<=n;i++) {
			ch[i] = true;
			for(j=i+1;j<=n;j++) {
				o[i][j] = o[j][i] = (i ^ j);
				if((i^j) <= n) all[(i ^ j)]++;
			}
		}
		for(i=0;;i++) {
			tmp = -1;
			max1 = 0;
			for(j=1;j<=n;j++) {
				if(ch[j]) {
					if(max1 < all[j]) {
						max1 = all[j];
						tmp = j;
					}
				}
			}
			if(tmp == -1) break;
			ch[tmp] = false;
			all[tmp] = 0;
			for(j=1;j<=n;j++) {
				if(ch[o[tmp][j]]) all[o[tmp][j]]--;
			}
		}
		printf("%d\n",n-i);
		for(i=1;i<=n;i++) {
			if(ch[i]) printf("%d ",i);
		}
		printf("\n");
	}
}