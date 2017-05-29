#include <stdio.h>
int o[1026];
int tmp[1026];
int ans[1026];
int chk(int d) {
	if(d == 1) return 1;
	if(d >= 2 && d < 4) return 2;
	if(d >= 4 && d < 8) return 4;
	if(d >= 8 && d < 16) return 8;
	if(d >= 16 && d < 32) return 16;
	if(d >= 32 && d < 64) return 32;
	if(d >= 64 && d < 128) return 64;
	if(d >= 128 && d < 256) return 128;
	if(d >= 256 && d < 512) return 256;
	if(d >= 512 && d < 1024) return 512;
	return 1024;
}
int main() {
	int i;
	int n, m, c;
	int k;
	int x;
	scanf("%d",&n);
	o[0] = 1;
	m = c = 1;
	for(k=1;k<n;k++) {
		m = 1 << k;
		c = m << 1;
		m--;
		c--;
		for(i=0;i<m;i++) tmp[i] = o[i];
		for(i=0;i<m;i++) o[i] = tmp[i] + chk(tmp[i]);
		o[m] = 1;
		for(i=m+1;i<c;i++) o[i] = tmp[i-m-1] + (chk(tmp[i-m-1]) << 1);
	}
	for(i=0;i<c;i++) {
		scanf("%d",&x);
		ans[o[i]] = x;
	}
	x = 2;
	for(i=1;i<=c;i++) {
		if(x <= i) {
			x <<= 1;
			printf("\n");
		}
		printf("%d ",ans[i]);
	}
	return 0;
}