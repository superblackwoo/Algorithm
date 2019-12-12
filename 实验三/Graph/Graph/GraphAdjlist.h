#pragma once
#ifndef GRAPHADJLIST_H_
#define GRAPHADJLIST_H_
#include<string>
#include<vector>
using namespace std;

class GraphAdjlist {

	struct arc_node
	{
		int adjindex; //�õ��ڱ߱�����±�
		int weight;
		arc_node* next;
	};
	struct list_node
	{
		string name;
		arc_node* first; // �߱��еĽڵ�ָ��ĵ�һ����
	};
	vector<vector<int>> adj_matrix;
public:
	static const int MAX_NUM_NODE = 13;
	list_node list[MAX_NUM_NODE];
	//list[MAX_NUM_NODE] = (list_node*)malloc(MAX_NUM_NODE * sizeof(list_node));

	void add_list_node(int index, const string &name);
	void add_arc_node(int list_index, int arc_node_index);
	void add_arc_node(int list_index, int arc_node_index, int weight);
	void print_adjlist();
	void print_adjlist(GraphAdjlist graph);
	void DFS(int start, vector <int> &visited, vector<int> &order);
	void BFS(int start, vector <int>& visited, vector<int>& order);
	void Djikstra(int start, int end,vector<int>& visited_DJ, vector<int>& distance, vector<int>& visited_order);
};
#endif // !GRAPHADJLIST_H_
