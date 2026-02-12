// -------------------------------- DIJSKSTRA -------------------------------
# include <bits/stdc++.h>
using namespace std;

// ----------------------------- HELPER VARIABLES ---------------------------

// in graph theory, we need a way to represent nodes and the cost to travel between them
// will be using an adjaceny matrix to represent the graph.
// for example, if cost[0][1] = 5, that means the edge from node 0 -> 1 weights 5.
// dist[100] keeps track of the current best distance from the source to every other node.
// visted[100] will be a bool array to ensure we don't process the same node twice once
// the shortest path has been confirmed.
// parent[100] will be used to reconstruct the actual path (from end node to start node)

// V - Vertices (nodes)

#define INF 999
int V, src, cost[100][100];
int dist[100]; // will tell how far the node indexed is from the src node.
bool visited[100] = {false}; // this ensures you only process each node exactly once.
int parent[100]; // this will be used to breadcrumb back to the src node.

// ------------------------------- INITIALIZATION ----------------------------------

// before algo starts, we first must assume all nodes are infinitly far away, except the
// starting point (node)
// we need to make the code set dist[i] = INF, where i is the index of the node.
// the source node (src) is set to 0 because we have no distance to cover from the start.

void init() {
    for (int i = 0; i < V; i++) {
        parent[i] = i; // to wipe the tracking clean, avoid clashes with diff node calculations
        dist[i] = INF;
    }
    dist[src] = 0;
}

// ------------------------------ FIND BEST CANDIDATE ------------------------------

// Dijkstra is a greedy algo, meaning in every step, it looks for the unvisited node with
// the smallest distance. It loops through all nodes, checks if visited[i] is false and 
// will find the one with the minValue.

int getNearest() {
    int minValue = INF;
    int minnode = -1; // -1 for none found.

    for (int i = 0; i < V; i++) { // for all nodes we have defined, 
        if (!visited[i] && dist[i] < minValue) { // look for the smallest distance from src 
            // by continously comparing the nodes against each other.
            minValue = dist[i];
            minnode = i;
        }
    }
    return minnode; // if this returns -1, it means the graph is disconnected.
}

// ----------------------------------- RELAXATION ----------------------------------

// this is the process of updating the distance to a neighbour. 
// if the path to a neighbour through the current node is shorter than the previously known
// path, we should update it.

void dijkstra() {
    for (int i = 0; i < V; i++) { // algo will run once for every node in our graph.
        int nearest = getNearest();
        visited[nearest] = true; // nearest node is now marked as visited.

        for (int adj = 0; adj < V; adj++) {
            if (cost[nearest][adj] != INF && dist[adj] > dist[nearest]+cost[nearest][adj]) {
                dist[adj] = dist[nearest]+cost[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }
}


int main(void) {

    // add the adjacency matrix for the information we will sort out.
    cin >> V; // how many nodes are there?

    cout << "Node\tDistance\tParent" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\t\t" << parent[i] << endl;
        for (int j = 0; j < V; j++) {
            cin >> cost[i][j];
        }
    }

    cin >> src; // type in the start node (src)
    init();
    dijkstra();
}