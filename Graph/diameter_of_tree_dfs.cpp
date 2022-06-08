#include <bits/stdc++.h>
using namespace std;

const int n = 1e3+10;
vector<pair<int,int>> graph[n];
bool vis[n];
int depth[n];

void dfs(int vertex,int x){

    depth[vertex]=x;
    vis[vertex]=true; 

    for(pair<int,int> child : graph[vertex]){
        
        if(vis[child.first]) continue;

        x++;
        dfs(child.first,x);
        x--;
        
    }

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

    dfs(1,0);

    int maxind=0;
    int maxval=0;
    for(int i=1;i<=v;i++){
        if(depth[i] > maxval) {maxval=depth[i];maxind=i;}
        depth[i]=0;
        vis[i]=0;
    }  

    dfs(maxind,0);
    maxval=0;
    for(int i=1;i<=v;i++){
        if(depth[i]>maxval) maxval=depth[i];
    } 
    cout<<maxval;
}

// using visited array