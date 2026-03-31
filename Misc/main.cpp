#include <bits/stdc++.h>
using namespace std;

int M = 1e6+1;
vector <int> primes(M, 1);
vector <int> hpf(M, 0);
vector <int> vect(M, 0);

void seive(){
    primes[0] = 0, primes[1] = 0;
    hpf[1] = 1;
    for(int i = 2; i <= M; i++){
        if(primes[i]){
            for(int j = 2*i; j <= M; j+=i) primes[j] = 0, hpf[j] = i;
        }
    }
    cout << "pass1\n";
}

void factorise(int num){
    int ctr = 0;
    cout << "pass2\n";
    unordered_map <int, int> mp; 
    while(num > 1){
        int hpf_t = hpf[num];
        num /= hpf_t;
        if(hpf_t > 1) mp[hpf_t]++;
    }
    for (auto it:mp){
        if(vect[it.first]) ctr++;
    }
    if(ctr == 2) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    int n, t;
    cin >> n >> t;
    int a, x;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect[a] = 1;
    }
    // seive();
    for(int i = 0; i < t; i++){
        cin >> x;
        cout << "call1\n";
        factorise(x);
    }
}