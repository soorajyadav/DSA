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
        cout<< x.first<<" ";
        for(pair<int,int> child : graph[x.first]){
            if(vis[child.first]==0){
                q.push(child);
                vis[child.first]=1;
                level[child.first]=level[x.first]+1;
            }
            

        }

    }
    cout<<"\n";
    for(int i=1;i<=v;i++){
        cout<< level[i]<<" ";
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

    bfs(1,v);

 }