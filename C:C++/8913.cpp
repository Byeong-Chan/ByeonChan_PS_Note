#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int o[35];
char _in[35];
bool dt[35][35];
int main() {
	int t;
	int len;
	int e;
	int i, j, k, l;
	scanf("%d",&t);
	while(t--) {
		n = 0;
		memset(dt, 0, sizeof(dt));
		memset(_in, 0, sizeof(_in));
		memset(o, 0, sizeof(o));
		scanf("%s",_in);
		len = strlen(_in);
		for(i=0;i<len;i++) {
			if(i == 0) e = 1;
			else {
				if(_in[i] == _in[i-1]) e++;
				else {
					if(e < 2) o[n++] = (_in[i-1] == 'a' ? 1 : 2);
					else o[n++] = (_in[i-1] == 'a' ? 3 : 4);
					e = 1;
				}
			}
		}
		if(e > 0) {
			if(e < 2) o[n++] = (_in[len-1] == 'a' ? 1 : 2);
			else o[n++] = (_in[len-1] == 'a' ? 3 : 4);
		}

		for(i=0;i<n;i++) if(o[i] > 2) dt[i][i] = true;
		for(k=0;k<n;k++) {
			for(i=0;i<n;i++) {
				for(j=i+2;j<n;j+=2) {
					dt[i][j] = dt[i][j] | dt[i+1][j-1];
				}
			}
			for(i=0;i<n;i++) {
				for(j=i+1;j<n;j++) {
					for(l=j;l>=i;l--) {
						if(dt[i][l] && dt[l][j]) dt[i][j] = true;
						if(l+1 <= j && dt[i][l] && dt[l+1][j]) dt[i][j] = true;
						if(l-1 >= i && dt[i][l-1] && dt[l][j]) dt[i][j] = true;
					}
				}
			}
		}
		printf("%d\n",dt[0][n-1]);
	}
    return 0;
}