#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector<vector<int>>& graph, vector<int>& visited, int start){
    int cur;
    queue<int> q;
    q.push(start);
    visited[start]=1;
    while(!q.empty()){
        cur= q.front();
        q.pop();
        cout<< cur<< " ";
        for(auto neigh: graph[cur]){
            if(!visited[neigh]){
                q.push(neigh);
                visited[neigh]=1;
            }
        }
    }
}

int bfs_path(vector<vector<int>>& graph, int start, int target, vector<int>& path){
    int cur, f=0;
    queue<int> q;
    vector<int> visited(graph.size(), -1);
    q.push(start);
    visited[start]=-2;
    while(!q.empty()){
        cur= q.front();
        q.pop();
        if(cur==target){
            f=1;
            break;
        }
        for(auto neigh: graph[cur]){
            if(visited[neigh]==-1){
                q.push(neigh);
                visited[neigh]=cur;
            }
        }
    }
    path.clear();
    if(f){
        while(cur!=start){
            path.push_back(cur);
            cur= visited[cur];
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
    }
    return f;
}

int main(){
    int v,e,i,a,b, start, target, ch;
    cin>> v>> e;
    vector<vector<int>> graph(v);
    vector<int> visited_1(v,0);
    vector<int> path(v,0);
    for(i=0;i<e;i++){
        cin>> a>> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout<< "Enter start node: ";
    cin>> start;

    cout<< "BFS traversal: ";
    for(i=0;i<v;i++){
        if( !visited_1[i])
            bfs(graph, visited_1, i);
    }
    cout<< endl;
    
    cout<< "Enter\n1 - to find shortest path to a node\n2 - to exit\n";
    while(true){
        cout<< "your choice: ";
        cin >> ch;
        switch(ch){
            case 1:
                cout<< "Enter target node: ";
                cin>> target;
                if(bfs_path(graph, start, target, path)){
                    for(auto i: path)
                        cout<< i<< " ";
                }
                else
                    cout<< "No path exists from start node to target node";
                cout<< endl;
                break;
            case 2:
                exit(0);
                break;
            default:
                cout<< "Invalid choice\n";
        }
    }
    return 0;
}