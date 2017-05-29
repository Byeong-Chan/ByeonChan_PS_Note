#include <cstring>
#include <cstdio>

///////begin
//you can change the size to your requirement(here (1<<16) means 2^16)
const int bufsize = 1 << 16 ;
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

int main() {
    int n, m, x;
    long long sum = 0;
    n = next_int();
    m = n;
    while (n--) {
        x = next_int();
        sum += x;
    }
    printf("%d\n",m);
    printf("%lld\n",sum);
    return 0;
}