#include <bits/stdc++.h>
using namespace std;

long long binary_multiply(long long n, long long b){
    long long ans = 1;
    while(b > 0){
        if((b&1)) ans *= n;
        n*=n;
        b = b>>1;
    }
    return ans;
}


void solve(){
    float n, k;
    cin >> n >> k;
    if(k == 1){ 
        cout << n << "\n";
        return;
    }
    long long ctr = 0;
    while(n > 0){
        long long fact = floor(log(n)/log(k));
        // cout << "pre: " << n << "\n";
        // cout << "fact:-  " << fact << "\n";
        n -= binary_multiply(k,fact);
        // cout << "post: " << n << "\n";
        ctr++;
    }
    cout << ctr << "\n";
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