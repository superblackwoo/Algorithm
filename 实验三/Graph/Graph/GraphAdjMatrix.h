#pragma once
#ifndef GRAPHADJMATRIX_H_
#define GRAPHADJMATRIX_H_
#include<string>
#include<vector>
using namespace std;

class GraphAdjMatrix
{
private:
	vector<vector<int>> adj_matrix;
public:
	void init_adj_matrix(int num_of_node);
	void add_node_to_matrix(int start, int end, int weight);
	void print_matrix();
	void BellmanFord(int start);
};
#endif // !GRAPHADJMATRIX_H_
