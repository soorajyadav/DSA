#include <bits/stdc++.h>
using namespace std;

const int n=1e5+10;
vector<pair<int,int>> graph[n];
int vis[n];
int level[n];

void bfs(int vertex,int v){
    queue<pair<int,int>> q;
    q.push({vertex,1});
    vis[vertex]=1;
    while(!q.empty()){
        pair<int,int> x = q.front();
        q.pop();
      
        for(pair<int,int> child : graph[x.first]){
            if(vis[child.first]==0){
                q.push(child);
                vis[child.first]=1;
                level[child.first]=level[x.first]+1;
            }
        }

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
    int x1=5,x2=10;

    bfs(13,v);
    cout<<level[11];


 }