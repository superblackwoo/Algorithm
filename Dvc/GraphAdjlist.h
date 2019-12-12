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
public:
	static const int MAX_NUM_NODE = 13;
	list_node *list[MAX_NUM_NODE];

	void add_list_node(int index, string name);
	void add_arc_node(int list_index, int arc_node_index);
};
#endif // !GRAPHADJLIST_H_

