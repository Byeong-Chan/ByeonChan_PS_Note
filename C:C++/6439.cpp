#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 200010;

struct Geometry {
    struct point {
        long long x;
        long long y;
        
        point() {}
        point(long long ix, long long iy) {
            x = ix;
            y = iy;
        }
        
        bool operator < (const point &a) const {
            return x != a.x ? x < a.x : y > a.y;
        }
        bool operator == (const point &a) const {
            return a.x == x && a.y == y;
        }
    };
    
    struct pointf {
        long double x;
        long double y;
        
        pointf() {}
        pointf(long double ix, long double iy) {
            x = ix;
            y = iy;
        }
        
        bool operator < (const point &a) const {
            return x != a.x ? x < a.x : y > a.y;
        }
    };
    
    struct vec {
        long double a1;
        long double a2;
        vec() {}
        vec(long double ia1, long double ia2) {
            a1 = ia1;
            a2 = ia2;
        }
        vec operator - (const vec &s) const {
            return vec(a1 - s.a1, a2 - s.a2);
        }
        vec operator + (const vec &s) const {
            return vec(a1 + s.a1, a2 + s.a2);
        }
        vec scalp(const vec &s, long double x) const {
            return vec(s.a1 * x, s.a2 * x);
        }
        long double inner_vector(const vec &s) const {
            return a1 * s.a1 + a2 * s.a2;
        }
        long double dist_vector(const vec &s) const {
            return sqrtl((a1 - s.a1) * (a1 - s.a1) + (a2 - s.a2) * (a2 - s.a2));
        }
        long double inner() const {
            return a1 * a1 + a2 * a2;
        }
        long double dist() const {
            return sqrtl(inner());
        }
        long double get_cos(const vec &s) const {
            return inner_vector(s) / (dist() * s.dist());
        }
        vec proj(const vec &s) const { // projection vector
            return scalp(*this, (inner_vector(s) / inner()));
        }
    };
    
    struct lineseg {
        vec x1;
        vec x2;
        lineseg() {}
        lineseg(vec ix1, vec ix2) {
            x1 = ix1;
            x2 = ix2;
        }
        
        long double dist() const {
            return (x2 - x1).dist();
        }
        long double dist_vector(const vec &a) const {
            vec k = (a - x1);
            vec l = (x2 - x1).proj(k);
            return (k - l).dist();
        }
    };
    
    int N;
    int sz;
    int midl;
    vec p1, p2, p3; // three vector
    lineseg li; // line segment
    point o[MAXN];
    // pointf of[MAXN];
    point convex[MAXN];
    // pointf convexf[MAXN];
    
    pair<point, point> lis;
    pair<point, point> rec;
    point r1, r2, r3, r4;
    
    
    // main work
    
    void init(int n) {
        N = n;
        sz = 0;
        for(int i = 0; i < N; i++) scanf("%lld %lld", &o[i].x, &o[i].y);
        sort(o, o+n);
    }
    
    int ccw(point a, point b, point c) {
        long long tmp = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
        if(tmp < 0) return -1; // clock
        else if(tmp > 0) return 1; // counter clock
        return 0;
    }
    
    int ccwf(pointf a, pointf b, pointf c) {
        long double tmp = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
        if(tmp < 0) return -1; // clock
        else if(tmp > 0) return 1; // counter clock
        return 0;
    }
    
    int across(point a1, point a2, point b1, point b2) { // 0never, 1cross, 2touch, 3touchpoint, 4infinite
        int tmp1 = ccw(a1, a2, b1) * ccw(a1, a2, b2);
        int tmp2 = ccw(b1, b2, a1) * ccw(b1, b2, a2);
        if(tmp1 <= 0 && tmp2 <= 0) {
            if(tmp1 == 0 && tmp2 == 0) {
                if((a1.x - a2.x) * (b1.y - b2.y) - (a1.y - a2.y) * (b1.x - b2.x) != 0) return 3;
                
                if(a1.x == a2.x) {
                    if(a2.y < a1.y) swap(a1, a2);
                    if(b2.y < b1.y) swap(b1, b2);
                    
                    if(a1.y < b1.y && a2.y > b1.y) return 4;
                    if(a1.y < b2.y && a2.y > b2.y) return 4;
                    if(b1.y < a1.y && b2.y > a1.y) return 4;
                    if(b1.y < a2.y && b2.y > a2.y) return 4;
                    if(a1 == b1 && a2 == b2) return 4;
                    if(a1 == b1 || a2 == b1 || a1 == b2 || a2 == b2) return 3;
                    return 0;
                }
                if(a2.x < a1.x) swap(a1, a2);
                if(b2.x < b1.x) swap(b1, b2);
                
                if(a1.x < b1.x && a2.x > b1.x) return 4;
                if(a1.x < b2.x && a2.x > b2.x) return 4;
                if(b1.x < a1.x && b2.x > a1.x) return 4;
                if(b1.x < a2.x && b2.x > a2.x) return 4;
                if(a1 == b1 && a2 == b2) return 4;
                if(a1 == b1 || a2 == b1 || a1 == b2 || a2 == b2) return 3;
                return 0;
            }
            else if(tmp1 == 0) return 2;
            else if(tmp2 == 0) return 2;
            return 1;
        }
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
    
    void rotating_caliphers() {
        p1 = vec(0, 1);
        p2 = vec(0, -1);
        
        vec sub1, sub2;
        
        int l = 0, r = midl-1;
        long double cos1, cos2;
        
        while(l < midl || r < sz) {
            int pl = l, pr = r == sz ? 0 : r;
            int nl = pl + 1, nr = pr + 1 == sz ? 0 : pr + 1;
            
            if(l == midl) r++;
            else if(r == sz) l++;
            else {
                sub1 = vec(convex[nl].x - convex[pl].x, convex[nl].y - convex[pl].y);
                sub2 = vec(convex[nr].x - convex[pr].x, convex[nr].y - convex[pr].y);
                
                cos1 = p1.get_cos(sub1);
                cos2 = p2.get_cos(sub2);
                
                if(cos1 > cos2) {
                    p1 = sub1;
                    p2 = vec(-p1.a1, -p1.a2);
                    l++;
                }
                else {
                    p2 = sub2;
                    p1 = vec(-p2.a1, -p2.a2);
                    r++;
                }
            }
        }
    }
};

Geometry dec;

int main() {
    int t;
    int tmp1, tmp2, tmp3, tmp4;
    scanf("%d",&t);
    while(t--) {
        scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &dec.lis.first.x, &dec.lis.first.y, &dec.lis.second.x, &dec.lis.second.y, &dec.rec.first.x, &dec.rec.first.y, &dec.rec.second.x, &dec.rec.second.y);
        if(dec.rec.first.x > dec.rec.second.x) swap(dec.rec.first.x, dec.rec.second.x);
        if(dec.rec.first.y > dec.rec.second.y) swap(dec.rec.first.y, dec.rec.second.y);
        
        dec.r1 = Geometry::point(dec.rec.first.x, dec.rec.first.y);
        dec.r2 = Geometry::point(dec.rec.second.x, dec.rec.first.y);
        dec.r3 = Geometry::point(dec.rec.first.x, dec.rec.second.y);
        dec.r4 = Geometry::point(dec.rec.second.x, dec.rec.second.y);
        
        tmp1 = dec.across(dec.lis.first, dec.lis.second, dec.r1, dec.r2);
        tmp2 = dec.across(dec.lis.first, dec.lis.second, dec.r1, dec.r3);
        tmp3 = dec.across(dec.lis.first, dec.lis.second, dec.r2, dec.r4);
        tmp4 = dec.across(dec.lis.first, dec.lis.second, dec.r3, dec.r4);
        if(dec.ccw(dec.r1, dec.r2, dec.lis.first) >= 0 && dec.ccw(dec.r2, dec.r4, dec.lis.first) >= 0 && dec.ccw(dec.r4, dec.r3, dec.lis.first) >= 0 && dec.ccw(dec.r3, dec.r1, dec.lis.first) >= 0) printf("T\n");
        else if(dec.ccw(dec.r1, dec.r2, dec.lis.second) >= 0 && dec.ccw(dec.r2, dec.r4, dec.lis.second) >= 0 && dec.ccw(dec.r4, dec.r3, dec.lis.second) >= 0 && dec.ccw(dec.r3, dec.r1, dec.lis.second) >= 0) printf("T\n");
        else if(tmp1 || tmp2 || tmp3 || tmp4) printf("T\n");
        else printf("F\n");
    }
    return 0;
}