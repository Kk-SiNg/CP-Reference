#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x ,y;
    cin >> x >> y;

    for(int i = 0; i <= 100; i++){
        cout << (i^x) << " ";
    }
    cout << "\n";
    for(int i = 0; i <= 100; i++){
        cout << (i^y) << " ";
    }

    cout << "\nx^y:- " << (x^y) << "\n";
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