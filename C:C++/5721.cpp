#include <stdio.h>
int main() {
	int n, m;
	int i, j;
	int r1, r2, r3;
	int c1, c2, c3;
	while(1) {
		scanf("%d %d",&n,&m);
		if(n==0 && m==0) break;
		r1 = r2 = r3 = c1 = c2 = c3 = -1;
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				c1 = c2;
				c2 = c3;
				scanf("%d",&c3);

				if(j-2 >= 0) c3 += c1;
				if(j-1 >= 0) c3 = c3 < c2 ? c2 : c3;
			}
			r1 = r2;
			r2 = r3;
			r3 = c3;
			if(i-2 >= 0) r3 += r1;
			if(i-1 >= 0) r3 = r3 < r2 ? r2 : r3;
		}
		printf("%d\n",r3);
	}
	return 0;
}