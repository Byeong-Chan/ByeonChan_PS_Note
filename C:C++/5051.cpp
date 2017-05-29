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

int main() {
    long long i;
    long long n;
    long long hap = 0;
    long long sav = 0;
    scanf("%lld",&n);
    vector<int> o(n), ans(n);
    fft dec((int)n, (int)n);
    for(i=1;i<n;i++) o[(i*i)%n]++;
    for(i=0;i<n;i++) sav += o[i] * o[(i<<1)%n];
    dec.init(o, o);
    ans = dec.multiplication();
    for(i=0;i<ans.size();i++) hap += (long long)o[i%n] * ans[i];
    hap = (hap + sav) / 2;
    printf("%lld\n",hap);
    return 0;
}