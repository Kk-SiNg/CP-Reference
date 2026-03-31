#include <iostream>
#include <vector>
#include <set>
#include <array>

using namespace std;

const int N = 10e3;
const long int INF = 10e7;

array<vector<pair<int, int>>, N> graph;
set <pair<int, int>> st;
int dist[N] = {INF};

void BFS(int source){
    st.insert({0,1});
    

}

int main(){

    int n , m;
    cin >> n >> m;
    int x, y;

    for(int i = 0; i < m; i++){
        cin >> x >> y;                      //this indicates that there is a unidirectional edge from x to y(always given in question)
        graph[x].push_back({y, 0});         //we assign 0 wt to given wdge
        graph[y].push_back({x, 1});         //and insert a reverse edge which will cost 1 wt
    }



}