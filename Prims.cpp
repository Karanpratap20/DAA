#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> graph;

vector<bool> visited; 

struct CompareWeight {
    bool operator()(const pii& a, const pii& b) {
        return a.second > b.second;
    }
};

void addEdge(graph& g, int u, int v, int weight) {
    g[u].push_back(make_pair(v, weight));
    g[v].push_back(make_pair(u, weight));
}

void primMST(const graph& g, int startVertex) {
    priority_queue<pii, vector<pii>, CompareWeight> pq;

    int numVertices = g.size();
    vector<int> parent(numVertices, -1);
    vector<int> key(numVertices, INT_MAX);
    visited.resize(numVertices, false);

    pq.push(make_pair(startVertex, 0));
    key[startVertex] = 0;

    while (!pq.empty()) {
        int u = pq.top().first;
        pq.pop();

        visited[u] = true;

        for (const auto& neighbor : g[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!visited[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push(make_pair(v, weight));
            }
        }
    }

    // Printing the MST
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 1; i < numVertices; ++i) {
        cout << "(" << parent[i] << " - " << i << ")\n";
    }
}

int main() {
    int numVertices = 7; // Number of vertices in the graph

    // Create an adjacency list representation of the graph
    graph g(numVertices);

    // Add edges to the graph
    addEdge(g, 0, 1, 7);
    addEdge(g, 0, 3, 5);
    addEdge(g, 1, 2, 8);
    addEdge(g, 1, 3, 9);
    addEdge(g, 1, 4, 7);
    addEdge(g, 2, 4, 5);
    addEdge(g, 3, 4, 15);
    addEdge(g, 3, 5, 6);
    addEdge(g, 4, 5, 8);
    addEdge(g, 4, 6, 9);
    addEdge(g, 5, 6, 11);

    int startVertex = 0; // Starting vertex for MST

    primMST(g, startVertex);
    return 0;
}