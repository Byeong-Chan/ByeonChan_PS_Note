#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 110;

struct Geometry {
    struct point {
        long long x;
        long long y;
        
        bool operator < (const point &a) const {
            return x != a.x ? x < a.x : y > a.y;
        }
    };
    
    struct vect {
        long double a1;
        long double a2;
        vect() {}
        vect(long double ia1, long double ia2) {
            a1 = ia1;
            a2 = ia2;
        }
        vect operator - (const vect &s) const {
            return vect(a1 - s.a1, a2 - s.a2);
        }
        vect operator + (const vect &s) const {
            return vect(a1 + s.a1, a2 + s.a2);
        }
        vect scalp(const vect &s, long double x) {
            return vect(s.a1 * x, s.a2 * x);
        }
        long double inner_vector(const vect &s) {
            return a1 * s.a1 + a2 * s.a2;
        }
        long double dist_vector(const vect &s) {
            return sqrtl((a1 - s.a1) * (a1 - s.a1) + (a2 - s.a2) * (a2 - s.a2));
        }
        long double inner() {
            return a1 * a1 + a2 * a2;
        }
        long double dist() {
            return sqrtl(inner());
        }
        vect proj(const vect &s) { // projection vector
            return scalp(*this, (inner_vector(s) / inner()));
        }
    };
    
    struct lineseg {
        vect x1;
        vect x2;
        lineseg() {}
        lineseg(vect ix1, vect ix2) {
            x1 = ix1;
            x2 = ix2;
        }
        
        long double dist() {
            return (x2 - x1).dist();
        }
        long double dist_vector(const vect &a) {
            vect k = (a - x1);
            vect l = (x2 - x1).proj(k);
            return (k - l).dist();
        }
    };
    
    int N;
    int sz;
    int midl;
    vect p1, p2, p3; // three vector
    lineseg li; // line segment
    point o[MAXN];
    point convex[MAXN];
    
    // main work
    
    void init(int n) {
        N = n;
        sz = 0;
        for(int i = 0; i < N; i++) scanf("%lld %lld", &o[i].x, &o[i].y);
        sort(o, o+n);
    }
    
    long long ccw(point a, point b, point c) {
        long long tmp = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
        if(tmp < 0) return -1; // clock
        else if(tmp > 0) return 1; // counter clock
        return 0;
    }
    
    void make_hull() {
        int i, t;
        
        convex[sz++] = o[0];
        for(i = 1, t = 1; i < N; i++) {
            while(sz > t && ccw(convex[sz-2], convex[sz-1], o[i]) >= 0) sz--;
            convex[sz++] = o[i];
        }
        midl = sz;
        for(i= N - 2, t = midl; i >= 0; i--) {
            while(sz > t && ccw(convex[sz-2], convex[sz-1], o[i]) >= 0) sz--;
            convex[sz++] = o[i];
        }
        sz--;
    }
};

Geometry dec;

int main() {
    int i, n;
    int a, b, c;
    int cnt = 0;
    while(1) {
        long double max1;
        long double min1 = (long double)0x7fffffff;
        long double len;
        scanf("%d",&n);
        if(n == 0) break;
        dec.init(n);
        dec.make_hull();
        for(i=0;i<dec.sz;i++) {
            a = i;
            b = i + 1;
            if(b == dec.sz) b = 0;
            max1 = 0.0;
            for(c=0;c<dec.sz;c++) {
                if(a == c || b == c) continue;
                dec.p1 = Geometry::vect(dec.convex[a].x, dec.convex[a].y);
                dec.p2 = Geometry::vect(dec.convex[b].x, dec.convex[b].y);
                dec.p3 = Geometry::vect(dec.convex[c].x, dec.convex[c].y);
                dec.li = Geometry::lineseg(dec.p1, dec.p2);
                
                len = dec.li.dist_vector(dec.p3);
                if(max1 < len) max1 = len;
            }
            if(max1 < min1) min1 = max1;
        }
        long double judge = min1 * 100.0 - (long double)((long long)(min1 * 100.0));
        if(judge * 10 >= 1.0) min1 += 0.005;
        printf("Case %d: %.2Lf\n",++cnt, min1);
    }
    return 0;
}