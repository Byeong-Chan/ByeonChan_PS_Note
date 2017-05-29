#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
struct query {
    int x;
    int y;
    int z;
    int num;
    bool operator< (const query &a) const {
        return z > a.z;
    }
};
class BIT {
public:
    void init(int n) {
        N = n;
        sum.resize(n+1);
    }
    void add(int i, int val) {
        while(i <= N) {
            sum[i] += val;
            i += i & (-i);
        }
    }
    int getSum(int i) {
        int ans = 0;
        while(i > 0) {
            ans += sum[i];
            i -= i & (-i);
        }
        return ans;
    }
private:
    int N;
    vector<int> sum;
};
int lb(vector<pair<int, int> > &arr, int val) {
    int l = 0;
    int r = (int)arr.size() - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(arr[mid].first < val) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
int ub(vector<pair<int, int> > &arr, int val) {
    int l = 0;
    int r = (int)arr.size() - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(arr[mid].first <= val) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
int main() {
    int i, n;
    int q;
    int x;
    scanf("%d",&n);
    
    vector<int> u(n);
    vector<pair<int, int> > o(n);
    for(i=0;i<n;i++) {
        scanf("%d",&x);
        o[i] = make_pair(x, i+1);
        u[i] = x;
    }
    sort(u.begin(), u.end());
    u.resize(unique(u.begin(), u.end()) - u.begin());
    reverse(u.begin(), u.end());
    sort(o.begin(), o.end());
    
    scanf("%d",&q);
    vector<query> Q(q);
    vector<int> ans(q);
    for(i=0;i<q;i++) scanf("%d %d %d",&Q[i].x,&Q[i].y,&Q[i].z), Q[i].num = i;
    
    sort(Q.begin(), Q.end());
    
    int s = 0;
    BIT bit;
    bit.init(n);
    for(i=0;i<q;i++) {
        while(s < u.size() && Q[i].z < u[s]) {
            int l = lb(o, u[s]);
            int r = ub(o, u[s]);
            while(l<r) {
                bit.add(o[l].second, 1);
                l++;
            }
            s++;
        }
        ans[Q[i].num] = bit.getSum(Q[i].y) - bit.getSum(Q[i].x-1);
    }
    for(i=0;i<q;i++) printf("%d\n",ans[i]);
    return 0;
}