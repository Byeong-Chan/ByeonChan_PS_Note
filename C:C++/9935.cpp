#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
char o[1000010];
char bomb[38];
struct bung {
	int x;
	int pos;
	int length;
}stk[1000010];
int main() {
	int i, j, n;
	int m;
	int top;
	int st, ed;
	bool sw;
	scanf("%s", o);
	scanf("%s", bomb);
	n = strlen(o);
	m = strlen(bomb);
	top = 0;
	for (i = 0; i < n; i++) {
		if (top > 0) {
			if (o[i] == bomb[stk[top - 1].length]) {
				if(stk[top-1].x + stk[top-1].pos == i) stk[top - 1].pos++;
				else {
					stk[top].x = i;
					stk[top].pos = 1;
					stk[top].length = stk[top-1].length;
					top++;
				}
				if (++stk[top - 1].length == m) {
					while (1) {
						top--;
						st = stk[top].x;
						ed = st + stk[top].pos;
						for (j = st; j < ed; j++) o[j] = 0;
						if (stk[top].length == stk[top].pos) break;
					}
				}
			}
			else if (o[i] == bomb[0]) {
				stk[top].x = i;
				stk[top].length = 1;
				stk[top].pos = 1;
				top++;
			}
			else top = 0;
		}
		else {
			if (o[i] == bomb[0]) {
				stk[top].x = i;
				stk[top].length = 1;
				stk[top].pos = 1;
				top++;
				if (m == 1) {
					o[i] = 0;
					top--;
				}
			}
		}
	}
	sw = false;
	for (i = 0; i < n; i++) if(o[i] != 0) printf("%c", o[i]), sw= true;
	if (!sw) printf("FRULA");
	printf("\n");
	return 0;
}