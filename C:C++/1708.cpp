#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct vect {
    // constructor, setter
    vect() {
        x = 0;
        y = 0;
    }
    vect(double x, double y) {
        this->x = x;
        this->y = y;
    }
    void set_x(double x) {
        this->x = x;
    }
    void set_y(double y) {
        this->y = y;
    }
    
    // for sorting
    const bool operator< (const vect &a) const {
        return x != a.x ? x < a.x : y < a.y;
    }
    
    // operator definition
    const bool operator== (const vect &a) const {
        return x - a.x < 1e-9 && x - a.x > -(1e-9) && y - a.y < 1e-9 && y - a.y > -(1e-9);
    }
    
    const double operator* (const vect &a) const {
        return x * a.x + y * a.y;
    }
    
    const vect operator* (const double &a) const {
        return vect(x * a, y * a);
    }
    
    const double cross(const vect &a) const {
        return x * a.y - y * a.x;
    }
    
    const vect operator- (const vect &a) const {
        return vect(x - a.x, y - a.y);
    }
    
    const vect operator+ (const vect &a) const {
        return vect(x + a.x, y + a.y);
    }
    const long long scalar() {
        return x * x + y * y;
    }
    
    // getter
    const double get_x() const {
        return x;
    }
    
    const double get_y() const {
        return y;
    }
private:
    double x;
    double y;
};
const vect operator* (const double &a, const vect &b) {
    return vect(a * b.get_x(), a * b.get_y());
}

int main() {
    int n;
    vect p;
    scanf("%d",&n);
    vector<vect> neg(n);
    vector<vect> pos(n);
    vector<vect> convex;
    for(int i=0;i<n;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        neg[i].set_x(x);
        neg[i].set_y(y);
    }
    sort(neg.begin(), neg.end());
    convex.push_back(neg[0]);
    for(int i=1;i<n;i++) {
        vect c = neg[i];
        while(convex.size() > 1) {
            vect a = convex[convex.size() - 2];
            vect b = convex[convex.size() - 1];
            double tmp = (b-a).cross(c-a);
            if(tmp > 1e-9) break;
            convex.pop_back();
        }
        convex.push_back(c);
    }
    int bound = (int)convex.size();
    for(int i=n-2;i>=0;i--) {
        vect c = neg[i];
        while(convex.size() > bound) {
            vect a = convex[convex.size() - 2];
            vect b = convex[convex.size() - 1];
            double tmp = (b-a).cross(c-a);
            if(tmp > 1e-9) break;
            convex.pop_back();
        }
        convex.push_back(c);
    }
    convex.pop_back();
    printf("%d\n",(int)convex.size());
    return 0;
}