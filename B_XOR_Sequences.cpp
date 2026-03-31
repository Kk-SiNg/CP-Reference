#include <bits/stdc++.h>
using namespace std;





void solve(){
    long long x, y;
    cin >> x >> y;

    for(long long i = 0; i <= 33; i++){
        if((!((x&1ll)^(y&1ll))));
        else{
            cout << (1ll << i) << "\n";
            // cout << "x:  " << x << endl;
            // cout << "y:  " << y << endl; 
            return;
        }
        x >>=1ll, y >>=1ll;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}