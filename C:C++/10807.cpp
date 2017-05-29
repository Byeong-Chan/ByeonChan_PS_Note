#include <stdio.h>
short chk[2][102];
int main() {
	short i, n;
	short x;
	bool sw;
	scanf("%hd",&n);
	for(i=0;i<n;i++) {
		scanf("%hd",&x);
		sw = false;
		if(x < 0) {
			x *= -1;
			sw = true;
		}
		chk[sw][x]++;
	}
	scanf("%hd",&x);
	sw = false;
	if(x < 0) {
		x *= -1;
		sw = true;
	}
	printf("%hd",chk[sw][x]);
	return 0;
}