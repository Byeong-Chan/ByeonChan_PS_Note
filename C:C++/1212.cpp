#include <stdio.h>
#include <string.h>
char o[333335];
bool b[1000006];
int main() {
	int i, j;
	int n, t = 0, p;
	int x;
	bool sw;
	scanf("%s",o);
	n = strlen(o);
    if(n == 1) {
        if(o[0] == '0') printf("0\n");
        return 0;
    }
	for(i=0;i<n;i++) {
		x = o[i] - '0';
		p = t+3;
		t += 3;
		for(j=1;j<=3;j++) {
			b[p-j] = x&1;
			x >>= 1;
		}
	}
	sw = true;
	for(i=0;i<t;i++) {
        if(sw) {
            if(!b[i]) continue;
            sw = false;
            printf("1");
        }
        else {
            if(b[i]) printf("1");
            else printf("0");
        }
	}
    printf("\n");
	return 0;
}