#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int main() {
	int n;
	int m;
	int i, j;
	char o[103][21];
	char u[21];
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%s",o[i]);
	for(i=0;i<n;i++) {
		strcpy(u, o[i]);
		m = strlen(u);
		reverse(u, u+m);
		for(j=i;j<n;j++) if(strcmp(u, o[j]) == 0) {
			printf("%d %c",m,u[m/2]);
			break;
		}
		if(j < n) break;
	}
	return 0;
}