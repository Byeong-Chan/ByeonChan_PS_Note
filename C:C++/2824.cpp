#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define tab 1000000000

vector<int> factor;
vector<int> factorA;
vector<int> factorB;

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
    int i, j, n, m;
    int x;
    int tmp;
    bool sw = false;
    long long ans = 1;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        tmp = x;
        for(j=2;j*j<=tmp;j++) {
            while(x % j == 0) {
                x /= j;
                factor.push_back(j);
                factorA.push_back(j);
            }
        }
        if(x > 1) {
            factor.push_back(x);
            factorA.push_back(x);
        }
    }
    scanf("%d",&m);
    for(i=0;i<m;i++) {
        scanf("%d",&x);
        tmp = x;
        for(j=2;j*j<=tmp;j++) {
            while(x % j == 0) {
                x /= j;
                factor.push_back(j);
                factorB.push_back(j);
            }
        }
        if(x > 1) {
            factor.push_back(x);
            factorB.push_back(x);
        }
    }
    sort(factor.begin(), factor.end());
    sort(factorA.begin(), factorA.end());
    sort(factorB.begin(), factorB.end());
    factor.resize(unique(factor.begin(), factor.end()) - factor.begin());
    for(auto i : factor) {
        int cnt1 = ub(factorA, 0, (int)factorA.size()-1, i) - lb(factorA, 0, (int)factorA.size()-1, i);
        int cnt2 = ub(factorB, 0, (int)factorB.size()-1, i) - lb(factorB, 0, (int)factorB.size()-1, i);
        tmp = min(cnt1, cnt2);
        for(j=0;j<tmp;j++) {
            ans *= i;
            if(ans >= tab) {
                sw = true;
                ans %= tab;
            }
        }
    }
    if(sw) printf("%09lld\n",ans);
    else printf("%lld\n",ans);
    return 0;
}