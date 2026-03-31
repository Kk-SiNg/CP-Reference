#include <iostream>
#include <vector>
#include <set>
#include <array>

using namespace std;
const int N = 10e5;
int INF = 10e9 + 10;

array <vector<pair<int,int>>, N> graph;


void djkestras(int source){
    array<int, N> vis;
    array<int, N> dist;
    dist.fill(INF);                     //take all the distances to other vertices from source node = infinity at start
    vis.fill(0);
    set <pair<int, int>> st;            //set will also work fine in place of priority queue, it stores <distance, node>

    st.insert({0, source});
    dist[source] = 0;

    while(st.size() > 0){               //task ---> we will go to min dist node traverse through it's childs if we find shorter dist to any of child then new optimised path found => add it in set
        auto node = *st.begin();        //we begin from source node
        int v = node.second;
        int d = node.first;
        if(vis[v]){                     //if a node is 'coming out' of queue then that happens only when it's dist in min possible
            continue;
        }
        vis[v] = 1;                     //we will mark a node as visited once all of it's child are covered

        st.erase(st.begin());

        for(auto child: graph[v]){
            int child_v = child.first;
            int wt = child.second;
            if (dist[v] + wt < dist[child_v]){
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});    // updating set as soon as shorter or more optimised path to that node is found
            }
        }
    }
} 

int main(){
    int n, m;
    cin >> n >> m;
    int x, y , wt;          // for storing directed graph from node x to y with weight wt

    for(int i = 0; i < m; i++){
        cin >> x >> y >> wt;
    }

    graph[x].push_back({y, wt});


    return 0;
}