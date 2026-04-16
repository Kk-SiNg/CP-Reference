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

    void del_root_node(){
        vect[1] = vect[size];    //save the last node
        vect.pop_back();
        size--;
        //now since structural property is satisfied so to satisfy min-heap property move this saved node to it's correct position:-
        //compare with l/r-child whichever is more small swap with it.
        int idx = 1;
        while(idx < size){
            int l_child = vect[idx*2];
            int r_child = vect[idx*2 + 1];
            if(l_child < r_child && vect[idx] > l_child) swap(vect[idx*2], vect[idx]), idx = idx*2;
            else if(r_child < l_child && vect[idx] > r_child) swap(vect[idx*2 + 1], vect[idx]), idx = idx*2 + 1;
            else return;
        }
    }

    void print(){
        for(int i:vect) cout << i << " ";
        cout << "\n";
    }

};

//in heapify we simply specify which index to heapify in given heap, and everything in the subtree with idx as root will become a heap
//after algo finishes.Note-> written heapify is for min_heap
//TC:- O(ln(n))
void heapify(vector <int> &vect, int n, int i){

    int idx = i;
    int l_child = 2*idx;
    int r_child = 2*idx + 1;

    if (l_child <= n && vect[idx] > vect[l_child]){
        idx = l_child;
    }
    if (r_child <= n && vect[idx] > vect[r_child]){
        idx = r_child;
    }

    if(idx != i){
        swap(vect[i], vect[idx]);
        heapify(vect, n, idx);
    }
}

//suppose we are given a min, then root ele always represent minima of all ele present in heap, so print root, swap it with right most,
//delete the right_most, call heapify for root, and repeat this until size == 0;
void heap_sort(vector <int> vect, int n){
    vector <int> sorted_arr;
    
    while(n > 0){
        sorted_arr.push_back(vect[1]);
        vect[1] = vect[n];
        n--;
        heapify(vect, n, 1);
    }

    for(int i:sorted_arr) cout << i << " ";
    cout << "\n";
}
int main(){
    heap hp;
    int n;
    cin >> n;
    int a;
    vector <int> vect;
    vect.push_back(-1);
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
        hp.insert(a);
    }
    //making a given array into heap ---> TC:- O(n)
    for(int i = n/2; i >0; i--){
        heapify(vect, n, i);
    }

    heap_sort(vect, n);

}