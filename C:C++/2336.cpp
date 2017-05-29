#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
    int x;
    int y;
    int z;
    bool flag;
    bool operator< (const node &a) const {
        if(x != a.x) return x < a.x;
        if(y != a.y) return y < a.y;
        return z < a.z;
    }
};
int merge(vector<node> &tmp) {
    if(tmp.size() == 1) return 0;
    if(tmp.size() == 2) {
        if(tmp[0].y > tmp[1].y) {
            swap(tmp[0], tmp[1]);
            return 0;
        }
        if(tmp[0].z < tmp[1].z && !tmp[0].flag) {
            tmp[0].flag = true;
            return 1;
        }
        return 0;
    }
    
    int sz = (int)tmp.size();
    int mid = sz / 2;
    vector<node> tmpl(sz/2), tmpr((sz+1)/2);
    for(int i=0;i<mid;i++) tmpl[i] = tmp[i];
    for(int i=mid;i<sz;i++) tmpr[i-mid] = tmp[i];
    
    int sum = 0;
    sum += merge(tmpl);
    sum += merge(tmpr);
    
    int l = 0, r = 0;
    int cnt = 0;
    
    vector<int> maxz(tmpr.size());
    maxz[maxz.size()-1] = tmpr[tmpr.size()-1].z;
    
    for(int i = (int)maxz.size()-2; i>=0; i--) {
        if(tmpr[i].z > maxz[i+1]) maxz[i] = tmpr[i].z;
        else maxz[i] = maxz[i+1];
    }
    while(l < tmpl.size() && r < tmpr.size()) {
        if(tmpl[l].y < tmpr[r].y) {
            if(tmpl[l].z < maxz[r] && !tmpl[l].flag) {
                tmpl[l].flag = true;
                sum++;
            }
            tmp[cnt++] = tmpl[l++];
        }
        else {
            tmp[cnt++] = tmpr[r++];
        }
    }
    while(l < tmpl.size()) tmp[cnt++] = tmpl[l++];
    while(r < tmpr.size()) tmp[cnt++] = tmpr[r++];
    
    return sum;
}
int main() {
    int n;
    scanf("%d",&n);
    vector<node> o(n);
    for(int i=0;i<n;i++) {
        int x;
        scanf("%d",&x);
        o[x-1].x = n-i;
    }
    for(int i=0;i<n;i++) {
        int y;
        scanf("%d",&y);
        o[y-1].y = n-i;
    }
    for(int i=0;i<n;i++) {
        int z;
        scanf("%d",&z);
        o[z-1].z = n-i;
    }
    sort(o.begin(), o.end());
    printf("%d\n",n-merge(o));
    return 0;
}