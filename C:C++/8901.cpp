#include <stdio.h>
int main() {
	int a, b, c;
	int ab, bc, ca;
	int cnt;
	int t;
	int ans = 0;
	float p1, p2, p3, p4, p5;
	scanf("%d",&t);
	while(t--) {
		ans = 0;
		scanf("%d %d %d",&a,&b,&c);
		scanf("%d %d %d",&ab,&bc,&ca);
		cnt = a < b ? a : b;
		a -= cnt;
		b -= cnt;
		ans += cnt * ab;
		while(c > 0) {
			if(b == 0) p1 = -1.0;
			else p1 = (float)bc;
			if(a == 0) p2 = -1.0;
			else p2 = (float)ca;

			if(cnt == 0) p3 = p4 = p5 = -1.0;
			else {
				p3 = (float)bc - (float)ab;
				p4 = (float)ca - (float)ab;
				if(c >= 2) p5 = ((float)bc + (float)ca - (float)ab) / 2;
				else p5 = -1;
			}

			if(p1 > 0 && p1 >= p2 && p1 >= p3 && p1 >= p4 && p1 >= p5) {
				b--;
				c--;
				ans += (int)p1;
			}
			else if(p2 > 0 && p2 >= p1 && p2 >= p3 && p2 >= p4 && p2 >= p5) {
				a--;
				c--;
				ans += (int)p2;
			}
			else if(p3 > 0 && p3 >= p1 && p3 >= p2 && p3 >= p4 && p3 >= p5) {
				cnt--;
				a++;
				c--;
				ans += (int)p3;
			}
			else if(p4 > 0 && p4 >= p1 && p4 >= p2 && p4 >= p3 && p4 >= p5) {
				cnt--;
				b++;
				c--;
				ans += (int)p4;
			}
			else if(p5 > 0 && p5 >= p1 && p5 >= p2 && p5 >= p3 && p5 >= p4) {
				cnt--;
				c-=2;
				ans += (int)(p5*2);
			}
			else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}