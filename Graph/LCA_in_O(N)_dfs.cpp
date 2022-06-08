#include <bits/stdc++.h>
using namespace std;

const int n = 1e3+10;
vector<pair<int,int>> graph[n];

int par[n];

void dfs(int vertex,int parr){

    par[vertex]=parr;
    for(pair<int,int> child : graph[vertex]){
        if(child.first==parr) continue;
        dfs(child.first,vertex);    
    }
}

vector<int> path(int x){
    vector<int> pat;
    while(x!=-1){
        pat.push_back(x);
        x=par[x];
    }
    reverse(pat.begin(), pat.end());
    return pat;
}

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
    par[0]=-1;
    dfs(1,0);
    vector<int> v1,v2;
    int x1=6,x2=12;
    v1 = path(9);
    v2 = path(11);
    int ans=-1;
    for(int i=0;i<v;i++){
        if(v1[i]!=v2[i]) {ans=v1[i-1];break;}
    }
    cout<<ans;


}