#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
char o[110];
map<int, bool> chk;
int main() {
    int i, j, n;
    int p;
    while(1) {
        scanf("%s",o);
        if(o[0] == '*') break;
        n = (int)strlen(o);
        for(i=1;i<n;i++) {
            for(j=0;j<n-i;j++) {
                p = (int)o[j] * 256 + (int)o[i+j];
                if(chk[p]) break;
                else chk[p] = true;
            }
            chk.clear();
            if(j < n-i) break;
        }
        if(i==n) printf("%s is surprising.\n", o);
        else printf("%s is NOT surprising.\n",o);
    }
    return 0;
}