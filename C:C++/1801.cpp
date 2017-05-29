#include <stdio.h>
int n;
int e = 0;
bool chk[17];
int o[17];
int max1 = 0;
int p[65537];
void sub(int a, int b, int sum) {
	if(a == n) {
		bool dt[162] = {0,};
		int i;
		int j;
		int hap = 0;
		dt[0] = true;
		for(i=0;i<n;i++) if(chk[i] == 1) {
			hap += o[i];
			for(j=hap;j>=0;j--) dt[j+o[i]] = (dt[j+o[i]] || dt[j]);
		}
		if((!(hap&1)) && dt[hap/2]) p[sum] = hap/2;
		return;
	}

	chk[a] = true;
	sub(a+1, b << 1, sum + b);
	chk[a] = false;

	sub(a+1, b << 1, sum);
}
void sub2(int a, int b, int sum, int sum2) {
	if(a == n) {
		if(max1 < p[sum] * p[sum2]) max1 = p[sum] * p[sum2];
		return;
	}

	sub2(a+1, b << 1, sum + b, sum2);
	sub2(a+1, b << 1, sum, sum2 + b);
	sub2(a+1, b << 1, sum, sum2);
}
int main() {
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&o[i]);
		e += o[i];
	}
	sub(0, 1, 0);
	sub2(0, 1, 0, 0);
	if(max1 == 0) printf("-1");
	else printf("%d",max1);
	return 0;
}