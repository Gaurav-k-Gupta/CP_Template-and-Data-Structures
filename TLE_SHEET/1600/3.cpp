#include<bits/stdc++.h>
using namespace std;

#define ll long long

int changeJ( int j , vector<int>& deleted ){
    int n = deleted.size();
    while( j < n && deleted[j] ) j++;
    return j;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        int pos;
        cin>>pos;

        int si = s.size();
        int n = si;
        vector<int> deleted( si , 0 );
        int i = 0;
        bool iterComplete = false;

        while( pos > si ){

            if( !iterComplete ){
                int j = i + 1;
                j = changeJ(j , deleted);
                while( j < n && s[i] < s[j] ){
                    i = j;
                    j++;
                    j = changeJ( j , deleted);
                }
                if( j == n ) iterComplete = true;
            }
            else{
                while(i >= 0 && deleted[i]) i--;
                // if( i == -1 ) i = changeJ( 0 , deleted );
            }
            
            // cout<<i<<endl;
            pos -= si;
            si--;
            deleted[i] = 1;

            if( !iterComplete ){
                while(i >= 0 && deleted[i]) i--;
                if( i == -1 ) i = changeJ( 0 , deleted );
            }
            // cout<<i<<endl;
        }

        // cout<<pos<<" "<<si<<endl;

        for(int i=0 ; i<n ; i++){
            if( deleted[i] ) continue;
            if( pos == 1 ){ cout<<s[i]; break; }
            pos--;
        }


    }
}