#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class segtree {
public:
    segtree() {
        hl = 0;
        hr = 0;
        val = 0;
        surv = 0;
        left = NULL;
        right = NULL;
    }
    void init(int l, int r, vector<int> &o) {
        hl = l;
        hr = r;
        if(l == r) {
            val = o[l];
            surv = 1;
            return;
        }
        int mid = (l + r) >> 1;
        (left = new segtree)->init(l, mid, o);
        (right = new segtree)->init(mid+1, r, o);
        if(left->val == right->val) {
            val = left->val;
            surv = left->surv + right->surv;
        }
        else {
            if(left->surv >= right->surv) {
                val = left->val;
                surv = left->surv - right->surv;
            }
            else {
                val = right->val;
                surv = right->surv - left->surv;
            }
        }
    }
    void query(int l, int r, vector<segtree*> &p) {
        if(hl >= l && hr <= r) {
            p.push_back(this);
            return;
        }
            
        int mid = (hl + hr) >> 1;
        
        if(l <= mid) left->query(l, r, p);
        if(r > mid) right->query(l, r, p);
    }
    int getSurv() {
        return surv;
    }
    int getVal() {
        return val;
    }
private:
    int hl;
    int hr;
    int val;
    int surv;
    segtree* left;
    segtree* right;
};
int lb(vector<int> &arr, int val) {
    int l = 0;
    int r = (int)arr.size() - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(arr[mid] < val) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
int ub(vector<int> &arr, int val) {
    int l = 0;
    int r = (int)arr.size() - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(arr[mid] <= val) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
int main() {
    int n, m;
    int i;
    int q;
    scanf("%d %d",&n,&m);
    segtree *tree = new segtree();
    vector<int> o(n+1);
    vector<int> color(m+1);
    vector<vector<int> > u(m+1, vector<int>());
    vector<segtree*> p;
    for(i=1;i<=n;i++) {
        scanf("%d",&o[i]);
        u[o[i]].push_back(i);
    }
    tree->init(1, n, o);
    scanf("%d",&q);
    for(i=0;i<q;i++) {
        int x, y;
        scanf("%d %d",&x,&y);
        tree->query(x, y, p);
        int max1 = -1, tmp = 1;
        for(auto v : p) {
            int val = v->getVal();
            int surv = v->getSurv();
            color[val] += surv;
            if(color[val] > max1) {
                max1 = color[val];
                tmp = val;
            }
        }
        for(auto v : p) {
            int val = v->getVal();
            color[val] = 0;
        }
        if(ub(u[tmp], y) - lb(u[tmp], x) > (y-x+1)/2) printf("yes %d\n",tmp);
        else printf("no\n");
        p.clear();
    }
    return 0;
}