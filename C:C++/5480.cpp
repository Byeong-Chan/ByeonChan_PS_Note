#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class coord {
public:
    coord() {
        dx.clear();
        dy.clear();
    }
    ~coord() {
        dx.clear();
        dy.clear();
    }
    void clear() {
        dx.clear();
        dy.clear();
    }
    void add_x(int x) { dx.push_back(x); }
    void add_y(int y) { dy.push_back(y); }
    void compress() {
        sort(dx.begin(), dx.end());
        sort(dy.begin(), dy.end());
        dx.resize(unique(dx.begin(), dx.end()) - dx.begin());
        dy.resize(unique(dy.begin(), dy.end()) - dy.begin());
    }
    const int get_x(int x) {
        int l = 0;
        int r = (int)dx.size() - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(dx[mid] < x) l = mid + 1;
            else r = mid - 1;
        }
        return l + 1;
    }
    const int get_y(int y) {
        int l = 0;
        int r = (int)dy.size() - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(dy[mid] < y) l = mid + 1;
            else r = mid - 1;
        }
        return l + 1;
    }
    vector<int>& get_dx() {
        return dx;
    }
    vector<int>& get_dy() {
        return dy;
    }
private:
    vector<int> dx;
    vector<int> dy;
};
class segtree {
public:
    segtree() {
        val = 0x7fffffff;
        l = r = 0;
        left = right = NULL;
    }
    void init(int rng_l, int rng_r) {
        l = rng_l;
        r = rng_r;
        if(l == r) return;
        
        int mid = (l + r) >> 1;
        left = new segtree();
        right = new segtree();
        left->init(l, mid);
        right->init(mid + 1, r);
    }
    void update(int d, int val) {
        if(l == r) {
            if(this->val > val) this->val = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(d <= mid) left->update(d, val);
        else right->update(d, val);
        
        if(left->val < this->val) this->val = left->val;
        if(right->val < this->val) this->val = right->val;
    }
    int query(int dl, int dr) {
        if(dl <= l && r <= dr) return val;
        
        int tmp1 = 0x7fffffff, tmp2 = 0x7fffffff;
        int mid = (l + r) >> 1;
        if(mid >= dl) tmp1 = left->query(dl, dr);
        if(mid < dr) tmp2 = right->query(dl, dr);
        
        return tmp1 < tmp2 ? tmp1 : tmp2;
    }
    void clear() {
        if(left != NULL) {
            left->clear();
            delete left;
            left = NULL;
        }
        if(right != NULL) {
            right->clear();
            delete right;
            right = NULL;
        }
    }
private:
    segtree *left;
    segtree *right;
    int l;
    int r;
    int val;
};
struct ship {
    int x1;
    int y1;
    int x2;
    int y2;
    int w;
};
int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++) {
        int n, k, l;
        coord p;
        scanf("%d %d %d",&n,&k,&l);
        vector<ship> o(k);
        for(int i = 0; i < k; i++) {
            scanf("%d %d %d %d %d", &o[i].x1, &o[i].y1, &o[i].x2, &o[i].y2, &o[i].w);
            if(o[i].x1 > o[i].x2) swap(o[i].x1, o[i].x2);
            if(o[i].y1 > o[i].y2) swap(o[i].y1, o[i].y2);
            p.add_x(o[i].x1);
            p.add_x(o[i].x2);
            p.add_y(o[i].y1);
            p.add_y(o[i].y2);
        }
        vector<int> x(l), y(l);
        for(int i = 0; i < l; i++) {
            scanf("%d %d",&x[i], &y[i]);
            if(y[i]) p.add_x(x[i]);
            else p.add_y(x[i]);
        }
        p.compress();
        segtree *tx = new segtree();
        segtree *ty = new segtree();
        tx->init(1, (int)p.get_dx().size());
        ty->init(1, (int)p.get_dy().size());
        vector<int> ans(l);
        for(int i = 0; i < l; i++) {
            if(y[i]) tx->update(p.get_x(x[i]), i);
            else ty->update(p.get_y(x[i]), i);
        }
        for(int i = 0; i < k; i++) {
            int tmp1 = tx->query(p.get_x(o[i].x1), p.get_x(o[i].x2));
            int tmp2 = ty->query(p.get_y(o[i].y1), p.get_y(o[i].y2));
            tmp1 = tmp1 < tmp2 ? tmp1 : tmp2;
            if(tmp1 == 0x7fffffff) continue;
            if(ans[tmp1] < o[i].w) ans[tmp1] = o[i].w;
        }
        for(int i = 0; i < l; i++) printf("%d\n",ans[i]);
        
        // clear
        tx->clear();
        ty->clear();
        delete tx;
        delete ty;
        o.clear();
        p.clear();
    }
    return 0;
}