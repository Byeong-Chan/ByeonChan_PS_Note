#include <stdio.h>
int index1[2049];
int o[1001];
int main() {
	int i, n, t;
	int d;
	int k;
	int c;
	int x;
	int tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&o[i]);
	for(k=1;k<n;k<<=1);
	for(i=k;i<k+n;i++) {
		d = i;
		while(d > 0) {
			index1[d]++;
			d >>= 1;
		}
	}
	t = 0;
	x = 1;
	printf("%d",t+1);

	d = 1;
	index1[d]--;
	while(d < k) {
		d <<= 1;
		index1[d]--;
	}
	for(c=n-1;c>=1;c--) {
		if(o[t] > 0) x--;
		x %= c;

		x += o[t];
		while(x <= 0) x += c;

		x = (x-1) % c;

		tmp = x;
		x++;
		d = 1;

		index1[d]--;
		while(d < k) {
			d <<= 1;
			if(index1[d] <= tmp) {
				tmp -= index1[d];
				d++;
			}
			index1[d]--;
		}

		t = d - k;
		printf(" %d",t+1);
	}
	return 0;
}