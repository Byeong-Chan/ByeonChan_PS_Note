#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

map<int, bool> chk;
int main() {
    int x, y, m;
    int k1, k2;
    int p;
    scanf("%d %d %d",&x,&y,&m);
    if(x > y) swap(x, y);
    
    k2 = m / y;
    p = m % y;
    k1 = p / x;
    p = p % x;
    chk[p] = true;
    
    while(k2>0) {
        k2--;
        p += y;
        p %= x;
        
        if(chk[p]) break;
        chk[p] = true;
    }
    printf("%d\n",m-chk.begin()->first);
    return 0;
}