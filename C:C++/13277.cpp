#include <cstdio>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>
#include <cstring>
using namespace std;

const double pi = 2.0 * acos(0.0);

struct fft {
public:
    const int upper(int x) const {
        int k;
        for(k=1;k<x;k<<=1);
        return k << 1;
    }
    fft(): N(1) {}
    fft(int iN, int iM): N(upper(max(iN, iM))) {
        leftpoly.resize(N);
        rightpoly.resize(N);
        wn1.resize(N);
        wn2.resize(N);
    }
    ~fft() {
        wn1.clear();
        wn2.clear();
        leftpoly.clear();
        rightpoly.clear();
    }
    void init(vector<int> &x, vector<int> &y) {
        for(int i=0;i<(int)x.size();i++) leftpoly[i] = x[i];
        for(int i=0;i<(int)y.size();i++) rightpoly[i] = y[i];
    }
    void dft(vector<complex<double> > &p, complex<double> w) {
        int n = (int)p.size();
        if(n == 1) return;
        
        vector<complex<double> > even(n/2), odd(n/2);
        for(int i = 0; i < n/2; i++) {
            even[i] = p[i*2];
            odd[i] = p[i*2+1];
        }
        
        dft(even, w * w);
        dft(odd, w * w);
        
        complex<double> complex_pow = 1;
        for(int i=0;i<n/2;i++) {
            complex<double> odd_pow = complex_pow * odd[i];
            p[i] = even[i] + odd_pow;
            p[i+n/2] = even[i] - odd_pow;
            complex_pow *= w;
        }
    }
    vector<int> multiplication() {
        int i;
        
        for(i=0;i<N;i++) wn1[i] = leftpoly[i];
        for(i=0;i<N;i++) wn2[i] = rightpoly[i];
        
        dft(wn1, polar(1.0, 2.0 * pi / N));
        dft(wn2, polar(1.0, 2.0 * pi / N));
        for(i=0;i<N;i++) wn1[i] *= wn2[i];
        
        dft(wn1, polar(1.0, -2.0 * pi / N));
        for(i=0;i<N;i++) wn1[i] /= N;
        
        vector<int> ans(N);
        for(i=0;i<N;i++) ans[i] = (int)round(wn1[i].real());
        return ans;
    }
private:
    const int N;
    vector<complex<double> > wn1;
    vector<complex<double> > wn2;
    vector<int> leftpoly;
    vector<int> rightpoly;
};

char o[300010], u[300010];
int main() {
    int i;
    int n, m;
    scanf("%s %s",o,u);
    n = (int)strlen(o);
    m = (int)strlen(u);
    fft dec(n, m);
    vector<int> x, y, ans;
    
    for(i=n-1;i>=0;i--) x.push_back(o[i] - '0');
    for(i=m-1;i>=0;i--) y.push_back(u[i] - '0');
    
    dec.init(x, y);
    ans = dec.multiplication();
    for(i=0;i<(int)ans.size();i++) {
        if(i+1 == ans.size() && ans[i] >= 10) ans.push_back(ans[i] / 10);
        else ans[i+1] += ans[i] / 10;
        ans[i] %= 10;
    }
    for(i=(int)ans.size()-1;i>=0;i--) if(ans[i] != 0) break;
    if(i == -1) printf("0\n");
    else for(;i>=0;i--) printf("%d",ans[i]);
    printf("\n");
    return 0;
}