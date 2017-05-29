#include <stdio.h>
#include <string.h>
int main() {
	int n;
	int i;
	int q[5];
	char o[110];
	while(1) {
		if(gets(o) == 0) break;
		memset(q, 0, sizeof(q));
		n = strlen(o);
		for(i=0;i<n;i++) {
			if(o[i] >= 'a' && o[i] <= 'z') q[0]++;
			if(o[i] >= 'A' && o[i] <= 'Z') q[1]++;
			if(o[i] >= '0' && o[i] <= '9') q[2]++;
			if(o[i] == ' ') q[3]++;
		}
		for(i=0;i<4;i++) printf("%d ",q[i]);
		printf("\n");
	}
}