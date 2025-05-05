#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adjList; 
    vector<tuple<int, int, int>> edges;     
public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v, int w) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            cout << "Invalid vertices.\n";
            return;
        }
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
        edges.push_back({w, u, v});
        cout << "Edge added between " << u << " and " << v << " with weight " << w << ".\n";
    }

    void display() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (auto [v, w] : adjList[i]) {
                cout << "(" << v << ", " << w << ") ";
            }
            cout << endl;
        }
    }

    void primMST() {
        vector<bool> inMST(V, false);
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        key[0] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = -1;
            for (int i = 0; i < V; i++)
                if (!inMST[i] && (u == -1 || key[i] < key[u]))
                    u = i;

            inMST[u] = true;

            for (auto [v, w] : adjList[u]) {
                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }

        cout << "\nPrim's MST:\n";
        for (int i = 1; i < V; i++)
            cout << parent[i] << " - " << i << " : " << key[i] << endl;
    }

    int findSet(int v, vector<int>& parent) {
        if (parent[v] == v)
            return v;
        return parent[v] = findSet(parent[v], parent);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findSet(u, parent);
        v = findSet(v, parent);
        if (u != v) {
            if (rank[u] < rank[v])
                parent[u] = v;
            else if (rank[u] > rank[v])
                parent[v] = u;
            else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end());
        vector<int> parent(V), rank(V, 0);

        for (int i = 0; i < V; i++)
            parent[i] = i;

        cout << "\nKruskal's MST:\n";
        for (auto [w, u, v] : edges) {
            if (findSet(u, parent) != findSet(v, parent)) {
                cout << u << " - " << v << " : " << w << endl;
                unionSet(u, v, parent, rank);
            }
        }
    }

    void dijkstra(int start) {
        if (start < 0 || start >= V) {
            cout << "Invalid source vertex.\n";
            return;
        }

        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);
        dist[start] = 0;

        for (int i = 0; i < V - 1; i++) {
            int u = -1;
            for (int j = 0; j < V; j++)
                if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                    u = j;

            visited[u] = true;

            for (auto [v, w] : adjList[u]) {
                if (!visited[v] && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        cout << "\nShortest distances from vertex " << start << ":\n";
        for (int i = 0; i < V; i++)
            cout << "To " << i << " = " << dist[i] << endl;
    }
};

int main() {
    int vertices, choice, u, v, w;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Prim's Algorithm\n";
        cout << "4. Kruskal's Algorithm\n";
        cout << "5. Dijkstra's Algorithm\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source, destination and weight: ";
                cin >> u >> v >> w;
                g.addEdge(u, v, w);
                break;
            case 2:
                g.display();
                break;
            case 3:
                g.primMST();
                break;
            case 4:
                g.kruskalMST();
                break;
            case 5:
                cout << "Enter source vertex for Dijkstra: ";
                cin >> u;
                g.dijkstra(u);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
