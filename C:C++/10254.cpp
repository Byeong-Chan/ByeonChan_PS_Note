#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 200010;

struct Geometry {
    struct point {
        long long x;
        long long y;
        
        bool operator < (const point &a) const {
            return x != a.x ? x < a.x : y > a.y;
        }
    };
    
    struct pointf {
        long double x;
        long double y;
        
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
        vect scalp(const vect &s, long double x) const {
            return vect(s.a1 * x, s.a2 * x);
        }
        long double inner_vector(const vect &s) const {
            return a1 * s.a1 + a2 * s.a2;
        }
        long double dist_vector(const vect &s) const {
            return sqrtl((a1 - s.a1) * (a1 - s.a1) + (a2 - s.a2) * (a2 - s.a2));
        }
        long double inner() const {
            return a1 * a1 + a2 * a2;
        }
        long double dist() const {
            return sqrtl(inner());
        }
        long double get_cos(const vect &s) const {
            return inner_vector(s) / (dist() * s.dist());
        }
        vect proj(const vect &s) const { // projection vector
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
        
        long double dist() const {
            return (x2 - x1).dist();
        }
        long double dist_vector(const vect &a) const {
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
        p1 = vect(0, 1);
        p2 = vect(0, -1);
        
        vect sub1, sub2;
        
        int l = 0, r = midl-1;
        long double cos1, cos2;
        
        //longest distance
        long long ans = 0, tmp;
        point ansp1, ansp2;
        
        while(l < midl || r < sz) {
            int pl = l, pr = r == sz ? 0 : r;
            int nl = pl + 1, nr = pr + 1 == sz ? 0 : pr + 1;
            
            //longest distance
            tmp = (convex[pl].x - convex[pr].x) * (convex[pl].x - convex[pr].x) + (convex[pl].y - convex[pr].y) * (convex[pl].y - convex[pr].y);
            if(ans < tmp) {
                ans = tmp;
                ansp1 = convex[pl];
                ansp2 = convex[pr];
            }
            tmp = (convex[pl].x - convex[nr].x) * (convex[pl].x - convex[nr].x) + (convex[pl].y - convex[nr].y) * (convex[pl].y - convex[nr].y);
            if(ans < tmp) {
                ans = tmp;
                ansp1 = convex[pl];
                ansp2 = convex[nr];
            }
            tmp = (convex[nl].x - convex[pr].x) * (convex[nl].x - convex[pr].x) + (convex[nl].y - convex[pr].y) * (convex[nl].y - convex[pr].y);
            if(ans < tmp) {
                ans = tmp;
                ansp1 = convex[nl];
                ansp2 = convex[pr];
            }
            tmp = (convex[nl].x - convex[nr].x) * (convex[nl].x - convex[nr].x) + (convex[nl].y - convex[nr].y) * (convex[nl].y - convex[nr].y);
            if(ans < tmp) {
                ans = tmp;
                ansp1 = convex[nl];
                ansp2 = convex[nr];
            }
            
            if(l == midl) r++;
            else if(r == sz) l++;
            else {
                sub1 = vect(convex[nl].x - convex[pl].x, convex[nl].y - convex[pl].y);
                sub2 = vect(convex[nr].x - convex[pr].x, convex[nr].y - convex[pr].y);
                
                cos1 = sub1.get_cos(p1);
                cos2 = sub2.get_cos(p2);
                
                if(cos1 > cos2) {
                    p1 = sub1;
                    p2 = vect(-p1.a1, -p1.a2);
                    l++;
                }
                else {
                    p2 = sub2;
                    p1 = vect(-p2.a1, -p2.a2);
                    r++;
                }
            }
        }
        
        //longest distance
        printf("%lld %lld %lld %lld\n",ansp1.x, ansp1.y, ansp2.x, ansp2.y);
    }
};

Geometry dec;

int main() {
    int t;
    int n;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        dec.init(n);
        dec.make_hull();
        dec.rotating_caliphers();
    }
    return 0;
}