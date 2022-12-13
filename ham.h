#include <vector>

bool isSafe(int v, int graph[5][5], std::vector <int> path, int pos);

void FindHamCycle(int graph[5][5], int pos, std::vector<int> path, bool visited[], int N, int versh);

void hamCycle(int graph[5][5], int N, int versh, FILE* F1);

void printgraph(int graph[5][5]);

void printgraph(int** graph, int n);

void hamCycle(int** graph, int N, int versh);

void FindHamCycle(int** graph, int pos, std::vector<int> path, bool visited[], int N, int versh);

bool isSafe(int v, int** graph, std::vector<int> path, int pos);
