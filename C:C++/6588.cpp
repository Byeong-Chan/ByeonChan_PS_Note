#include <cstdio>
#include <vector>
using namespace std;
int o[1000010];
vector<int> fac;
int main() {
    int i, j;
    o[0] = o[1] = 1;
    for(i=2;i<=1000;i++) {
        if(o[i] == 1) continue;
        for(j=i*i;j<=1000000;j+=i) o[j] = 1;
    }
    for(i=3;i<=1000000;i++) if(o[i] == 0) fac.push_back(i);
    while(1) {
        int n;
        bool flag = false;
        scanf("%d",&n);
        if(n == 0) break;
        for(auto k : fac) {
            if(k > n) break;
            if(o[n-k] == 0) {
                flag = true;
                printf("%d = %d + %d\n",n, k, n-k);
                break;
            }
        }
        if(flag == false) printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}