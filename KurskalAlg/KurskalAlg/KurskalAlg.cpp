// KurskalAlg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<stack>
using namespace std;

class Graph {
	int nodes; //No of nodes in the graph
	int **A; //A is the adjacency matrix => the graph datastructure
	int **B;
	
	
public:
	Graph(int nodes) {
		this->nodes = nodes;
		A = new int*[nodes];
		B = new int*[nodes];
		for (int i = 0; i<nodes; ++i) {
			A[i] = new int[nodes];
			B[i] = new int[nodes];
		}
		for (int i = 0; i<nodes; ++i)
			for (int j = 0; j<nodes; ++j) {
				A[i][j] = 0;
				B[i][j] = 0;
			}	
	}

	void printAdjacencyMatrix() {
		for (int i = 0; i<nodes; ++i) {
			for (int j = 0; j<nodes; ++j) {
				cout << B[i][j] << " ";
			}
			cout << endl;
		}
	}

	

	int getMinimumUnvisitedNode(bool* visited, int* costArray) {
		int minIndex = 1;
		for (int i = 1; i <= nodes; ++i) {
			if (visited[i] == false && costArray[i] <= costArray[minIndex]) {
				minIndex = i;
			}
		}
		return minIndex;
	}

	bool isAdjacent(int node1, int node2) {
		return B[node1 - 1][node2 - 1] != 0;
	}

	int getWeight(int node1, int node2) {
		return A[node1 - 1][node2 - 1];
	}

	void addEdge(int node1, int node2, int weight) {
		A[node1 - 1][node2 - 1] = A[node2 - 1][node1 - 1] = weight;
	}

	void formEdgeBetween(int node1, int node2) {
		B[node1 - 1][node2 - 1] = B[node2 - 1][node1 - 1] = 1;
	}

	bool isEdgeChosenBetween(int node1, int node2) {
		return B[node1 - 1][node2 - 1];
	}

	bool depthFirstSearch(int node1, int node2) {
		stack<int> s;
		bool hasAdjacent = false;
		bool *visited = new bool[nodes + 1];
		for (int i = 0; i <= nodes; ++i)
			visited[i] = false;
		s.push(node1);
		visited[node1] = true;
		while (!s.empty()) {
			int topNode = s.top();
			hasAdjacent = false;
			for (int i = 1; i <= nodes; ++i) {
				if (isAdjacent(topNode, i) && visited[i] == false) {
					hasAdjacent = true;
					if (i == node2)
						return true;
					s.push(i);
					visited[i] = true;
					//cout<<i<<" ";
					break;
				}
			}
			if (!hasAdjacent)
				s.pop();

		}
		delete[] visited;
		return false;
	}

	bool isConnected(int node1, int node2) {
		return depthFirstSearch(node1, node2);
	}

	//gets the edge having the minimum weight
	
	
	//Without loss of generality, lets start with the first node
	void findMinimumSpanningTree() {
		bool hasAdjacent = false;
		bool *visited = new bool[nodes + 1];
		for (int i = 0; i <= nodes; ++i)
			visited[i] = false;
		int n = nodes;
		int We = 0;
		cout << "";
		cout << "Minimum spanning tree:" << endl;
		while (--n) {
			int minWeight = 100;
			
			int minNode1 = 100;
			int minNode2 = 100;
			for (int i = 0; i<nodes; ++i) {
				for (int j = 0; j<nodes; ++j) {
					if (A[i][j] != 0 && A[i][j]<minWeight && !isEdgeChosenBetween(i + 1, j + 1) && !isConnected(i + 1, j + 1)) {
						minWeight = A[i][j];
						minNode1 = i + 1;
						minNode2 = j + 1;
					}
				}
			}
			formEdgeBetween(minNode1, minNode2);
			cout << minNode1 << " ---- " << minNode2 << " { " << minWeight << " } " << endl;
			We += minWeight;
			
			
		}
		cout << "Weight of the graph is "<<We <<endl;
		
	

	}

	
	
	~Graph() {
		for (int i = 0; i < nodes; ++i)
			delete[] A[i];
		delete[] A;
	}
};

int main() {
	Graph g(5);
	g.addEdge(1, 5, 1);
	g.addEdge(1, 4, 1);
	g.addEdge(4, 5, 1);
	g.addEdge(5, 3, 4);
	g.addEdge(5, 2, 2);
	g.addEdge(2, 3, 3);
	

	g.findMinimumSpanningTree();
	
	g.printAdjacencyMatrix();


	system("pause");
	return 0;
}

