#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cnt[256];
int ncnt[256];
char o[1010];
char u[1010];
bool chk[1010];
int main() {
    int k, i, j, n, m;
    int tmp = 0, f;
    int sum = 0;
    scanf("%s",o);
    scanf("%s",u);
    
    n = (int)strlen(o);
    m = (int)strlen(u);
    
    for(i=0;i<n;i++) ncnt[o[i]]++;
    for(i=0;i<m;i++) ncnt[u[i]]--;
    for(i='0';i<='9';i++) {
        if(ncnt[i] < 0) ncnt[i] = 0;
        sum += ncnt[i];
    }
    
    f = -1;
    while(sum--) {
        for(i='0';i<='9';i++) cnt[i] = 0;
        for(i=n-1;i>f;i--) {
            cnt[o[i]]++;
            for(j='0';j<='9';j++) if(ncnt[j] > cnt[j]) break;
            if(j > '9') break;
        }
        int max1 = 0;
        for(k=i;k>f;k--) {
            if(ncnt[o[k]] == 0) continue;
            if(max1 < o[k]) {
                max1 = o[k];
                tmp = k;
            }
            else if(max1 == o[k]) tmp = k;
        }
        f = tmp;
        ncnt[max1]--;
        chk[f] = true;
    }
    
    for(i=0;i<n;i++) if(chk[i]) {
        printf("%c",o[i]);
    }
    printf("\n");
    
    return 0;
}