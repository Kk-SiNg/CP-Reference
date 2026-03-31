#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, a;
    cin >> n;
    int z = (n+1)/2;
    int o = n/2;
    while(z--){
        cout << "0";
        if(o--) cout << "1";
    }
    cout << endl;
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