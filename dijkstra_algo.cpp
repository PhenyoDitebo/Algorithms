// -------------------------------- DIJSKSTRA -------------------------------
# include <bits/stdc++.h>
using namespace std;

#define INF 999


// ----------------------------- HELPER VARIABLES ---------------------------

// in graph theory, we need a way to represent nodes and the cost to travel between them
// for example, if cost[0][1] = 5, that means the edge from node 0 -> 1 weights 5.
// dist[100] keeps track of the current best distance from the source to every other node.
// visted[100] will be a bool array to ensure we don't process the same node twice once
// the shortest path has been confirmed.
// parent[100] will be used to reconstruct the actual path (from end node to start node)

int V, src, cost[100][100];
int dist[100];
bool visited[100] = {0};
int parent[100];

// ------------------------------- INITIALIZATION ------------------------------

// before algo starts, we first must assume all nodes

void init() {
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        dist[i] = INF;
    dist[src] = 0;
    }
}

int getNearest() {
    int minValue = INF;
    int minnode = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < minValue) {
            minValue = dist[i];
            minnode = i;
        }
    }
    return minnode;
}

void dijkstra() {
    for (int i = 0; i < V; i++) {
        int nearest = getNearest();
        visited[nearest] = true;

        for (int adj = 0; adj < V; adj++) {
            if (cost[nearest][adj] != INF && dist[adj] > dist[nearest]+cost[nearest][adj]) {
                dist[adj] = dist[nearest]+cost[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }
}



int main(void) {
    cin >> V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> cost[i][j];
        }
    }

    cin >> src; 
    init();
    dijkstra();
}