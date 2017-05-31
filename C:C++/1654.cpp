#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n, k;
    unsigned int l = 1, r = ((unsigned int)1 << 31) - 1;
    scanf("%d %d",&n,&k);
    vector<int> lan(n);
    for(int i = 0; i < n; i++) scanf("%d",&lan[i]);
    while(l <= r) {
        int mid = (l + r) >> 1;
        long long sum = 0;
        for(int i = 0; i < n; i++) sum += lan[i] / mid;
        if(sum >= k) l = (unsigned int)mid + 1;
        else r = mid - 1;
    }
    printf("%u\n",l-1);
    return 0;
}
