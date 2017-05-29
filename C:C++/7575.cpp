#include <stdio.h>
#include <algorithm>
using namespace std;
int m[110];
int pi[1100] = {-1, 0, };
int dcode[110][1100];
int rcode[110][1100];
int cmp[1100];
int n, k;
void find_pi() {
    int x = 0, y = -1;
    while(x < k) {
        if(y == -1 || (y >= 0 && cmp[x] == cmp[y])) {
            x++;
            y++;
            pi[x] = y;
        }
        else y = pi[y];
    }
}
bool kmp(int* cd, int al) {
    int x = 0, y = 0;
    bool sw1 = false;
    while(x < al) {
        if(y == -1 || (y >=0 && *(cd+x) == cmp[y])) {
            x++;
            y++;
        }
        else y = pi[y];
        if(y == k) {
            sw1 = true;
            break;
        }
    }
    return sw1;
}
int main() {
    int i, j;
    bool sw1 = false;
    scanf("%d %d",&n, &k);
    for(i=0;i<n;i++) {
        scanf("%d",&m[i]);
        for(j=0;j<m[i];j++) scanf("%d",&dcode[i][j]);
        reverse_copy(dcode[i], dcode[i]+m[i], rcode[i]);
    }
    for(i=0;i<m[0]-k;i++) {
        for(j=i;j<i+k;j++) cmp[j-i] = dcode[0][j];
        find_pi();
        for(j=1;j<n;j++) {
            if(kmp(dcode[j], m[j])) continue;
            if(kmp(rcode[j], m[j])) continue;
            break;
        }
        if(j == n) {
            sw1 = true;
            break;
        }
    }
    if(sw1 == true) printf("YES");
    else printf("NO");
    return 0;
}