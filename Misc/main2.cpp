#include <bits/stdc++.h>
using namespace std;

const long long M = 1e6 + 5; 
vector<long long> primes(M, 1);
vector<long long> hpf(M, 0);
vector<long long> vect(M, 0);
vector<long long> availables(M, 0);

void seive() {
    primes[0] = 0; 
    primes[1] = 0;
    hpf[1] = 1;
    
    for (long long i = 2; i < M; i++) {
        if (primes[i]) {
            hpf[i] = i;
            for (long long j = 2 * i; j < M; j += i) {
                primes[j] = 0;
                hpf[j] = i;
            }
        }
    }
}
void is_available(){
    availables[1] = M;
    for(long long i = 2; i < M; i++){
        if(vect[i]){
            if(i <= 1) continue;
            for(long long j = i; j < M; j*=i){
                availables[j] = 1;
            }
        }
    }
}
void factorise(long long num) {
    long long ctr = 0;
    unordered_map<long long, long long> mp; 
    long long flg2 = 0;
    long long copy_num = num;
    
    while (copy_num > 1) {
        long long hpf_t = hpf[copy_num];
        copy_num /= hpf_t;
        if (hpf_t > 1) mp[hpf_t]++;
    }
    for(auto it = mp.begin(); it != mp.end(); it++){
        for(auto it2 = it; it2!= mp.end(); it2++){
            // cout << it->first << " " << it2->first <<endl;
            // cout << "av_check:- " << num/(it->first + it2->first) << endl;
            if(availables[num/(it->first*it2->first)]) {
                if(availables[num/(it->first*it2->first)] == it->first && it->second <= 2) continue;
                if(it->first == it2->first && it->second < 2) continue;
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, t;
    cin >> n >> t;
    
    long long a, x;
    for (long long i = 0; i < n; i++) {
        cin >> a;
        vect[a] = 1;
    }
    
    seive(); 
    is_available();
    
    for (long long i = 0; i < t; i++) {
        cin >> x;
        factorise(x);
    }
    
    return 0;
}