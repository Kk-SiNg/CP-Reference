#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, a;
    cin >> n;
    if((n&1)){
        cout << (n/2)*(n/2 + 1) +1 << "\n";
    }
    else{
        cout << (n/2)*(n/2) +1 << "\n";
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}