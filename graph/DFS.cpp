#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& visited, int start){
    int cur;
    stack<int> s;
    s.push(start);
    visited[start]=1;
    while(!s.empty()){
        cur= s.top();
        s.pop();
        cout<< cur<< " ";
        for(vector<int>::reverse_iterator it=graph[cur].rbegin(); it<graph[cur].rend(); it++){
            int neigh= *it;
            if(!visited[neigh]){
                s.push(neigh);
                visited[neigh]=1;
            }
        }
    }
}

void dfs_recursive(vector<vector<int>>& graph, vector<int>& visited, int cur){
    if(visited[cur])
        return;
    visited[cur]=1;
    cout<< cur<< " ";
    for(auto neigh: graph[cur]){
        if(!visited[neigh]){
            dfs_recursive(graph, visited, neigh);
        }
    }
}

int main(){
    int v,e,i,a,b, start;
    cin>> v>> e;
    vector<vector<int>> graph(v);
    vector<int> visited_1(v,0);
    vector<int> visited_2(v,0);
    for(i=0;i<e;i++){
        cin>> a>> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout<< "Enter start node: ";
    cin>> start;

    cout<< "Iterative DFS traversal: ";
    for(i=0;i<v;i++){
        if( !visited_1[i])
            dfs(graph, visited_1, i);
    }
    cout<< endl;
    
    cout<< "Recursive DFS traversal: ";
    for(i=0;i<v;i++){
        if( !visited_2[i])
            dfs_recursive(graph, visited_2, i);
    }
    cout<< endl;

    return 0;
}