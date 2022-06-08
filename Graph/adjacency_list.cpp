#include <bits/stdc++.h>
using namespace std;

const int n = 1e3+10;
vector<pair<int,int>> graph[n];

int main() {
    int v,e;
    cin>>v>>e;

    //filling array of vectors (Adjacency List)
    for(int i=0;i<e;i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back(make_pair(v2,wt));
        graph[v2].push_back(make_pair(v1,wt));
    }
    
    //printing all edges with weight
    for(int i=0;i<e;i++){
        for(pair<int,int> child : graph[i]){
            cout<<"from "<<i<<" to "<<child.first<<" distance of "<<child.second<<"\n";
        }
    }

    //is there an edge from 1 to 2 and what its weight
    int flag=0;
    for(pair<int,int> child : graph[1]){
        if(child.first==2) {cout<<"yes there is edge of weight "<<child.second;flag++;}
    }
    if(flag==0) cout<<"sorry no edge present";


}
