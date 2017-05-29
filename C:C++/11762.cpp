#include <stdio.h>
#include <algorithm>
using namespace std;
int o[7];
int ans1[3];
int ans2[3];
int m1, m2;
bool sw;
void sub(int a, int sum, int top, int top2) {
	if(sw) return;

	if(a == 6) {
		if(top == 0) {
			if(sum == m1) {
				printf("%d %d %d\n",ans1[0],ans1[1],ans1[2]);
				printf("%d %d %d",ans2[0],ans2[1],ans2[2]);
				sw = true;
			}
		}
		return;
	}

	if(top > 0) {
		if(sw) return;
		ans1[top-1] = o[a];
		sub(a+1, sum + o[a], top-1, top2);
		ans1[top-1] = 0;
	}

	if(top2 > 0) {
		if(sw) return;
		ans2[top2-1] = o[a];
		sub(a+1, sum, top, top2-1);
		ans2[top2-1] = 0;
	}
}
int main() {
	scanf("%d %d %d %d %d %d %d %d",&o[0],&o[1],&o[2],&o[3],&o[4],&o[5],&m1,&m2);
	sort(o, o+6);
	sw = false;
	sub(0, 0, 3, 3);
	return 0;
}