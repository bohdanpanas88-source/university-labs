#include <iostream>

struct Queue {
    int data[100];
    int head = 0, tail = 0;
    void push(int val) { data[tail++] = val; }
    int pop() { return data[head++]; }
    bool isEmpty() { return head == tail; }
};

struct Stack {
    int data[100];
    int topIndex = -1;
    void push(int val) { data[++topIndex] = val; }
    int pop() { return data[topIndex--]; }
    bool isEmpty() { return topIndex == -1; }
};

class Graph {
private:
    int numVertices;
    int** adjMatrix;

public:
    Graph(int vertices) : numVertices(vertices) {
        adjMatrix = new int* [vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    void addEdge(int u, int v) {
        if (u > 0 && u <= numVertices && v > 0 && v <= numVertices) {
            adjMatrix[u - 1][v - 1] = 1;
            adjMatrix[v - 1][u - 1] = 1;
        }
    }

    void BFS(int start) {
        bool visited[20] = { false };
        Queue q;

        visited[start - 1] = true;
        q.push(start);

        std::cout << "BFS (from " << start << "): ";
        while (!q.isEmpty()) {
            int curr = q.pop();
            std::cout << curr << " ";

            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[curr - 1][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i + 1);
                }
            }
        }
        std::cout << "\n";
    }

    void DFS(int start) {
        bool visited[20] = { false };
        Stack s;

        s.push(start);

        std::cout << "DFS (from " << start << "): ";
        while (!s.isEmpty()) {
            int curr = s.pop();

            if (!visited[curr - 1]) {
                std::cout << curr << " ";
                visited[curr - 1] = true;
            }

            for (int i = numVertices - 1; i >= 0; i--) {
                if (adjMatrix[curr - 1][i] == 1 && !visited[i]) {
                    s.push(i + 1);
                }
            }
        }
        std::cout << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Graph& g) {
        os << "Adjacency matrix:\n  ";
        for (int i = 1; i <= g.numVertices; i++) os << i << " ";
        os << "\n";
        for (int i = 0; i < g.numVertices; i++) {
            os << i + 1 << " ";
            for (int j = 0; j < g.numVertices; j++) {
                os << g.adjMatrix[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }
};

int main() {
    Graph g(6);

    g.addEdge(1, 6);
    g.addEdge(6, 2);
    g.addEdge(6, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    std::cout << g << "\n";

    g.BFS(1);
    g.DFS(1);

    return 0;
}
