#include <bits/stdc++.h>
using namespace std;

const int n = 1e3+10;
vector<pair<int,int>> graph[n];
bool vis[n];
int depth[n] = {0};
int height[n] = {0};

int dfs(int vertex, int d){

    //1. code when entered child/vertex
     
    vis[vertex]=true; 
    depth[vertex]=d;
    

    int max=0;
    for(pair<int,int> child : graph[vertex]){
        //2.x. code before entring to each child
        
        if(vis[child.first]) continue;
        d++;

        // visiting child
        int h = dfs(child.first,d);
        if(h>max) max=h;
        d--;


        //3.x. code after exiting from each child

    }

    //4. code while backtracking
    height[vertex]=max;
    return max+1;

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
    for(int i=1;i<=v;i++){
        if(vis[i]!=true) {
            dfs(i,0);// this loop will make sure to enter every connected component
        }
    }
    for(int i=1;i<=v;i++){
        cout<<depth[i]<<" ";
        
    }
    cout<<"\n";
    for(int i=1;i<=v;i++){
        cout<<height[i]<<" ";
        
    }


}