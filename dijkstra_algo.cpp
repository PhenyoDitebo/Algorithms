# include <bits/stdc++.h>
using namespace std;

// ------------------------ DIJSKSTRA ------------------------

int V, src, cost[100][100];


int main(void) {
    cin >> V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> cost[i][j];
        }
    }

    cin >> src; 
}