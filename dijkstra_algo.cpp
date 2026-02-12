# include <bits/stdc++.h>
using namespace std;

#define INF 999

// ------------------------ DIJSKSTRA ------------------------

int V, src, cost[100][100];
int dist[100];
bool visited[100] = {0};

void innit() {
    for (int i = 0; i < V; i++) {
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
            if (cost[nearest][adj] != INF && dist[adj] < dist[nearest]+cost[nearest][adj]) {
                dist[adj] = dist[nearest]+cost[nearest][adj];
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
}