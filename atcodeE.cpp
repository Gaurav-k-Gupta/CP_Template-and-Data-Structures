#include<bits/stdc++.h>
using namespace std;


long long xor_1_to_n( long long n ){
    if( n % 4 == 0 ) return n;
    if( n % 4 == 1 ) return 1;
    if( n % 4 == 2 ) return n+1;
    return 0;
}



long long range_xor(long long a , long long b){
    return xor_1_to_n(a-1) ^ xor_1_to_n(b);
}



int main(){
    int n;
    cin>>n;
        
    long long grundy = 0;

    for(int i = 0 ; i < n ; i++){
        long long xi,mi;
        cin>>xi>>mi;

        grundy = grundy ^ range_xor( xi , xi + mi - 1 );
    }

    if( grundy > 0 ) cout<<"tolik"<<endl;
    else cout<<"bolik"<<endl;
    return 0;
}