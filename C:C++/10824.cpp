#include <stdio.h>
int main() {
	long long a, b, c, d;
	long long tmp1, tmp2;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	tmp1 = b;
	tmp2 = d;
	while(b > 0) {
		a *= 10;
		b /= 10;
	}
	while(d > 0) {
		c *= 10;
		d /= 10;
	}
	printf("%lld",a+c+tmp1+tmp2);
	return 0;
}