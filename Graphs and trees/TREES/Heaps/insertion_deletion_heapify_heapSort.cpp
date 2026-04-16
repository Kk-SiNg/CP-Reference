//we will insert the ele to the end of the heap array and compare with the parent(floor(idx_child/2)), if parent <= child then return as
//min heap is satisfied
#include <bits/stdc++.h>
using namespace std;

class heap{
    public:
    vector <int> vect;
    int size;
    
    heap(){
        vect.push_back(0);
        size = 0;
    }
    void insert(int num){
        vect.push_back(num);
        size++;             //pointing to current index of num in vect.
        int index = size;
        
        while(index > 1){
            int parent = index/2;
            if(vect[parent] > vect[index]) swap(vect[parent], vect[index]);
            else break;
        }
    }

    void print(){
        for(int i:vect) cout << i << " ";
        cout << "\n";
    }
};

int main(){
    heap hp;
    hp.insert(50);
    hp.insert(55);
    hp.insert(53);
    hp.insert(52);
    hp.insert(54);
    hp.print();    
}