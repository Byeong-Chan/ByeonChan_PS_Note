#include <cstring>
#include <cstdio>

int o[5000010];
///////begin
//you can change the size to your requirement(here (1<<16) means 2^16)
const int bufsize = 1 << 20 ;
int bufL1 = 0 , nowL1 = 0 , bufL2 = 0 ;
char buf1[ bufsize ] , buf2[ bufsize ] ;

inline char next_char() {
    if( nowL1 == bufL1 ) {//this means that nothing is loaded into the bufL1 array
        bufL1 = fread( buf1 , sizeof( char ) , bufsize , stdin ) ;//let's load the array using fread
        if( bufL1 == 0 ) { return 0; }//this is just to check if there's no input
        nowL1 = 0 ;
    }
    return buf1[ nowL1++ ] ;//nowL1 points to the current character in the buf1 array
}

inline int next_int() {
    char c ;
    do {
        c = next_char() ;
    } while( c < '-' ) ;//this while loop will continue until it finds '-' or ' ' or '\n'
    
    int val = 0 ;
    if( c == '-' ) {//this means the current integer is negative
        for( c = next_char() ; c >= '0' ; c = next_char() ) {
            val = val * 10 + ( c - '0' ) ;//get the integer
        }
        return - val ;//return the negative number
    }
    else {
        for( ; c >= '0' ; c = next_char() ) {
            val = val * 10 + ( c - '0' ) ;
        }
        return val ;//return the positive number
        
    }
}

int quick(int l, int r, int k) {
    int mid = (l+r) / 2;
    
    int pivot = mid;
    
    int tmp;
    tmp = o[pivot];
    o[pivot] = o[l];
    o[l] = tmp;
    pivot = l;
    int x = l+1, y = r-1;
    while (x <= y) {
        if (o[x] == o[pivot] && o[y] == o[pivot]) {
            if(y <= mid) x++;
            else y--;
        }
        else if(o[x] >= o[pivot]) {
            tmp = o[x];
            o[x] = o[y];
            o[y] = tmp;
            y--;
        }
        else x++;
    }
    tmp = o[x-1];
    o[x-1] = o[pivot];
    o[pivot] = tmp;
    if(x > k) return quick(l, x-1, k);
    else if (x < k) return quick(x, r, k);
    else return o[x-1];
}
int main() {
    int i, n, k;
    n = next_int();
    k = next_int();
    for(i=0;i<n;i++)
        o[i] = next_int();
    printf("%d\n",quick(0, n, k));
    return 0;
}