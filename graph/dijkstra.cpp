#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

struct edge{
    int dest, weight;
    bool operator<(const edge& other) const {
        return weight > other.weight;
    }
};

void dijkstra(vector<vector<edge>>& graph, vector<int>& distance, vector<int>& parent, int start){
    int cur, cur_dist, new_dist;
    priority_queue<edge> q;
    vector<int> visited(graph.size(), 0);
    distance[start]=0;
    q.push({start,0});
    while(!q.empty()){
        cur=q.top().dest;
        cur_dist= q.top().weight;
        q.pop();
        if(visited[cur])
            continue;
        visited[cur]=1;
        distance[cur]= cur_dist;
        for(auto neigh : graph[cur]){
            new_dist= cur_dist + neigh.weight;
            if(new_dist<distance[neigh.dest]){
                distance[neigh.dest]=new_dist;
                parent[neigh.dest]= cur;
                q.push({neigh.dest, new_dist});
            }
        }
        
    }
}


int main(){
    int v, e, a, b, w, i, start;
    cin>> v>> e;
    vector<vector<edge>> graph(v);
    vector<int> parent(v,-1);
    vector<int> distance(v,INT_MAX);
    for(i=0;i<e;i++){
        cin>> a>> b>> w;
        graph[a].push_back({b,w});
        graph[b].push_back({a, w});
    }
    cout<< "Enter start node: ";
    cin>> start;
    dijkstra(graph, distance, parent, start);
    for(i=0;i<v;i++){
        cout<< i<< " --> "<< distance[i]<< "\tparent: "<< parent[i]<<  endl;
    }

    return 0;
}

/*

7
11
0 1 2
0 5 3
0 3 5
1 5 4
1 4 1
1 2 7
2 4 3
2 6 4
3 4 1
3 6 1
4 6 3

*/