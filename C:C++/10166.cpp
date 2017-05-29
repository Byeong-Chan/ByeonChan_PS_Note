#include <stdio.h>
int n, m;
bool chk[2100][2100];
int e = 0;
int sub(int a, int b) {
	if(a % b == 0) return b;
	else return sub(b, a%b);
}
void in() {scanf("%d %d",&n, &m);}
void solv() {
	int i, j;
	int x, y;
	int tmp;
	for(i=n;i<=m;i++) {
		for(j=1;j<=i;j++) {
			x = i;
			y = j;
			tmp = sub(x, y);
			x /= tmp;
			y /= tmp;

			if(!chk[x][y]) {
				e++;
				chk[x][y] = true;
			}
		}
	}
}
void out() {printf("%d",e);}
int main() {
	in();
	solv();
	out();
	return 0;
}