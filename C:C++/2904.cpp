#include <cstdio>
#include <vector>
using namespace std;
int cnt[1000010];
vector<int> fator;
vector<int> mov[110];
int lb(vector<int> &arr, int l, int r, int val) {
    while(l <= r) {
        int mid = (l+r) >> 1;
        if(arr[mid] < val) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
int ub(vector<int> &arr, int l, int r, int val) {
    while(l <= r) {
        int mid = (l+r) >> 1;
        if(arr[mid] <= val) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
int main() {
    int i, j, n;
    int x;
    int tmp;
    int num = 0;
    long long ans = 1;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        tmp = x;
        for(j=2;j*j<=tmp;j++) {
            while(x % j == 0) {
                x /= j;
                mov[i].push_back(j);
                cnt[j]++;
            }
        }
        if(x > 1) {
            mov[i].push_back(x);
            cnt[x]++;
        }
    }
    for(i=2;i<1000000;i++) {
        x = cnt[i] / n;
        if(x > 0) {
            for(j=0;j<x;j++) ans *= i;
            for(j=0;j<n;j++) {
                tmp = ub(mov[j], 0, (int)mov[j].size()-1, i) - lb(mov[j], 0, (int)mov[j].size()-1, i);
                if(x > tmp) num += x - tmp;
            }
        }
    }
    printf("%lld %d\n",ans,num);
    return 0;
}