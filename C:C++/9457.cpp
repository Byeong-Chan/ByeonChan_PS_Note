#include <stdio.h>
#include <string.h>
#define MOD 10007;
bool bin[33];
int o[3][3];
int p[3][3];
int tmp[3][3];
int main() {
    int i, j, l;
    int k;
    int t, n;
    int ans1, ans2;
    scanf("%d",&t);
    p[0][0] = 3;
    p[0][1] = 2;
    p[0][2] = 2;
    p[1][0] = 1;
    p[1][1] = 1;
    p[1][2] = 0;
    p[2][0] = 0;
    p[2][1] = 0;
    p[2][2] = 1;
    while(t--) {
        scanf("%d",&n);
        o[0][0] = 1;
        o[0][1] = 0;
        o[0][2] = 0;
        o[1][0] = 0;
        o[1][1] = 1;
        o[1][2] = 0;
        o[2][0] = 0;
        o[2][1] = 0;
        o[2][2] = 1;
        for(k=0, i=n-1; i>0; i>>=1, k++) bin[k] = i&1;
        while(k--) {
        	memset(tmp, 0, sizeof(tmp));
        	for(i=0;i<3;i++) {
        		for(j=0;j<3;j++) {
        			for(l=0;l<3;l++) tmp[i][j] += o[i][l] * o[l][j];
        			tmp[i][j] %= MOD;
        		}
        	}
        	for(i=0;i<3;i++) {
        		for(j=0;j<3;j++) {
        			o[i][j] = tmp[i][j];
        		}
        	}
        	if(bin[k]) {
				memset(tmp, 0, sizeof(tmp));
				for(i=0;i<3;i++) {
					for(j=0;j<3;j++) {
						for(l=0;l<3;l++) tmp[i][j] += o[i][l] * p[l][j];
						tmp[i][j] %= MOD;
					}
				}
				for(i=0;i<3;i++) {
					for(j=0;j<3;j++) {
						o[i][j] = tmp[i][j];
					}
				}
        	}
        }
        ans1 = o[0][0] + o[1][0];
        ans2 = o[0][2] + o[1][2];
        ans2 *= n;
        ans2 += ans1 * n;

        ans1 %= MOD;
        ans2 %= MOD;
        printf("%d %d\n",ans1, ans2);
    }
    return 0;
}