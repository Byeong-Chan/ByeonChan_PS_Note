#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
class segtree {
public:
    segtree() {
        left = NULL;
        right = NULL;
        val = 0;
    }
    void init(int l, int r) {
        this->l = l;
        this->r = r;
        if(l == r) return;
        int mid = (l+r) >> 1;
        if(left == NULL) left = new segtree();
        if(right == NULL) right = new segtree();
        left->init(l, mid);
        right->init(mid+1, r);
    }
    void update(int h, int d) {
        if(l == r) {
            if(val < d) val = d;
            return;
        }
        int mid = (l + r) >> 1;
        if(mid >= h) left->update(h, d);
        if(mid < h) right->update(h, d);
        
        if(val < left->val) val = left->val;
        if(val < right->val) val = right->val;
    }
    int query(int hl, int hr) {
        if(hl <= l && r <= hr) return val;
        
        int mid = (l + r) >> 1;
        int tmp1 = 0, tmp2 = 0;
        if(mid >= hl) tmp1 = left->query(hl, hr);
        if(mid < hr) tmp2 = right->query(hl, hr);
        return tmp1 < tmp2 ? tmp2 : tmp1;
    }
private:
    segtree *left;
    segtree *right;
    int l;
    int r;
    int val;
};
struct node {
    int x2;
    int y2;
    int d;
    node() {}
    node(int x2, int y2, int d) {
        this->x2 = x2;
        this->y2 = y2;
        this->d = d;
    }
    bool operator< (const node &a) const {
        return x2 > a.x2;
    }
};
struct rec {
    int x1;
    int y1;
    int x2;
    int y2;
    bool operator< (const rec &a) const {
        return x1 < a.x1;
    }
};
int lb(vector<int> &arr, int val) {
    int mid;
    int l = 0;
    int r = (int)arr.size() - 1;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(arr[mid] < val) l = mid + 1;
        else r = mid - 1;
    }
    return l + 1;
}
int main() {
    int i, n;
    int ans = 1;
    scanf("%d",&n);
    vector<rec> o(n);
    vector<int> dy;
    priority_queue<node> pq;
    
    for(i=0;i<n;i++) {
        scanf("%d %d %d %d",&o[i].x1,&o[i].y1,&o[i].x2,&o[i].y2);
        dy.push_back(o[i].y1);
        dy.push_back(o[i].y2);
    }
    sort(dy.begin(), dy.end());
    sort(o.begin(), o.end());
    dy.resize(unique(dy.begin(), dy.end()) - dy.begin());
    
    segtree *tree = new segtree();
    tree->init(1, (int)dy.size());
    for(auto &v : o) {
        while(!pq.empty() && v.x1 > pq.top().x2) {
            tree->update(pq.top().y2, pq.top().d);
            pq.pop();
        }
        int ty1 = lb(dy, v.y1), ty2 = lb(dy, v.y2);
        int tmp = 0;
        if(ty1 > 1) tmp = tree->query(1, ty1 - 1);
        pq.push(node(v.x2, ty2, tmp + 1));
        if(ans < tmp + 1) ans = tmp + 1;
    }
    printf("%d\n",ans);
    return 0;
}