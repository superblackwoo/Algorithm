#include<string>
#include<stdlib.h>
#include "GraphAdjlist.h"
#include <iostream>
using namespace std;

void GraphAdjlist::add_list_node(int index, string namea) {
	if (index < MAX_NUM_NODE) {
		list_node* new_node;
		if (!(new_node = (list_node*)malloc(sizeof(list_node)))) {
			cout << "fail to malloc" << endl;
			exit(0);
		}
		cout << "fail to malloc" << endl;
		new_node->name = namea;
		cout << "fail to malloc" << endl;
		new_node->first = NULL;
		list[index] = new_node;
	}
	else
		cout<<"index OVERFLOW"<<endl;
}
void GraphAdjlist::add_arc_node(int list_index, int arc_node_index) {
	arc_node* new_arcnode, * last_arc_node;// , * f;
	if (!(new_arcnode = (arc_node*)malloc(sizeof(arc_node)))) {
		cout << "fail to malloc" << endl;
		exit(0);
	}
	if (!(last_arc_node = (arc_node*)malloc(sizeof(arc_node)))) {
		cout << "fail to malloc" << endl;
		exit(0);
	}
	new_arcnode->adjindex = arc_node_index;
	new_arcnode->weight = 0;
	new_arcnode->next = NULL;
	//f = list[list_index].first;
	if (list[list_index]->first!=NULL) {  //如果边表的first上已经有结点
		last_arc_node->next = list[list_index]->first; //last_arc_node指向list[list_index]
		while (last_arc_node->next != NULL)
			last_arc_node->next = last_arc_node->next->next;  //找到最小的结点为止
		last_arc_node->next = new_arcnode;
	}
	else {
		list[list_index]->first = new_arcnode;
	}
}
