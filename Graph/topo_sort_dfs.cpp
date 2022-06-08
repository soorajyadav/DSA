#include <bits/stdc++.h>
using namespace std;

const int n = 1e3+10;
vector<int> graph[n];
bool vis[n];
stack<int> s;

// topo_sort:- a permutation of vertices in which for all the edjes u,v 
//             u must appear before v
void dfs(int vertex){

    //1. code when entered child/vertex
  
    vis[vertex]=true; //making visited for current node

    for(int child : graph[vertex]){
        //2.x. code before entring to each child
        
        if(vis[child]) continue;

        // visiting child
        dfs(child);
        
        

        //3.x. code after exiting from each child
    }
    s.push(vertex);
    

    //4. code while backtracking

}

int main() {
    int v,e;
    cin>>v>>e;

    //filling array of vectors (Adjacency List)
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
    }
    for(int i=0;i<v;i++){
        if(vis[i]!=true) {
            dfs(i);
        }
    }
    while (s.empty() == false) {
        cout << s.top() << "\n";
        s.pop();
    }
    



}